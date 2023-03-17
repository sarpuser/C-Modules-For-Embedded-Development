/*
 * File:   timers.h
 * Author: Sarp User
 *
 * Created on January 25, 2023, 1:28 PM
 */

#ifndef TIMERS_H
#define	TIMERS_H

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

void TIMERS_TimerOverflowInterruptCallback ();

void TIMERS_RegisterTimer (timer_t* timerHandle, uint32_t period_ms, timerCallback_t timerCallback);

uint8_t TIMERS_GetTimerCount ();

void TIMERS_EnableTimer (timer_t* timerHandle);

void TIMERS_DisableTimer (timer_t* timerHandle);

#endif	/* TIMERS_H */