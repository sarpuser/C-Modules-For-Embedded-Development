/*
 * File:   timers.h
 * Author: Sarp User
 *
 * Created on January 25, 2023, 1:28 PM
 */

#ifndef TIMERS_H
#define	TIMERS_H
#endif	/* TIMERS_H */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef void (*timerCallback_t) (void);

typedef struct timers_s timer_t;

struct timers_s {
    timer_t* prevTimerHandle;
    volatile uint32_t period_ms;
    volatile uint32_t count;
    volatile bool enabled;
    timerCallback_t timerCallback;
    volatile bool triggered;
};

void timerOverflowInterrupt ();

void defaultTimerCallback ();

uint8_t registerTimer (timer_t* timerHandle, uint32_t period_ms, timerCallback_t timerCallback);

void enableTimer (timer_t* timerHandle);

void disableTimer (timer_t* timerHandle);