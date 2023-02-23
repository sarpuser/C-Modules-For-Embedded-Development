#include "timers.h"

static timer_t* lastTimerHandle = NULL;
static uint8_t numTimers = 0;


void timerOverflowInterrupt () {
    timer_t* currentTimerHandle = lastTimerHandle;
    while (currentTimerHandle != NULL) {
        if (currentTimerHandle->enabled && --(currentTimerHandle->count) == 0) {
            currentTimerHandle->timerCallback();
            currentTimerHandle->count = currentTimerHandle->period_ms;
            currentTimerHandle->triggered = true;
        }
        currentTimerHandle = currentTimerHandle->prevTimerHandle;
    }
}

void defaultTimerCallback () {
    // Put Default Timer Callback code here
}

void registerTimer(timer_t* timerHandle, uint32_t period_ms, timerCallback_t timerCallback) {
    static bool firstTimerRegistered = false;
    static timer_t* prevTimerHandle;

    if (!firstTimerRegistered) {
        firstTimerRegistered = true;
        prevTimerHandle = NULL;
    }

    if (timerCallback == NULL) {
        timerCallback = defaultTimerCallback;
    }

    timerHandle->prevTimerHandle = prevTimerHandle;
    timerHandle->enabled = false;
    timerHandle->period_ms = period_ms;
    timerHandle->count = period_ms;
    timerHandle->timerCallback = timerCallback;
    timerHandle->triggered = false;

    prevTimerHandle = timerHandle;
    lastTimerHandle = timerHandle;
    numTimers++;
}

uint8_t getTimerCount () {
    return numTimers;
}

void enableTimer (timer_t* timerHandle) {
    timerHandle->enabled = true;
}

void disableTimer (timer_t* timerHandle) {
    timerHandle->enabled = false;
}