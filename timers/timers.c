#include "timers.h"

static timer_t* lastTimerHandle = NULL;
static uint8_t numTimers = 0;


void TIMERS_TimerOverflowInterruptCallback () {
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

void TIMERS_RegisterTimer(timer_t* timerHandle, uint32_t period_ms, timerCallback_t timerCallback) {
    static bool firstTimerRegistered = false;
    static timer_t* prevTimerHandle;

    if (!firstTimerRegistered) {
        firstTimerRegistered = true;
        prevTimerHandle = NULL;
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

uint8_t TIMERS_GetTimerCount () {
    return numTimers;
}

void TIMERS_EnableTimer (timer_t* timerHandle) {
    timerHandle->enabled = true;
}

void TIMERS_DisableTimer (timer_t* timerHandle) {
    timerHandle->enabled = false;
}
