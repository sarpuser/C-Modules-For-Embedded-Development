# C Modules for Embedded Development

This library consists of useful C modules that can be used for embedded projects. This README includes documentation for each of the different modules included in this library.

## Table of Contents

- [MPU6050 Motion Sensor](#MPU6050)
- [Timers](#Timers)

## Accel 8 Click Board Using MPU6050 6 Axis Accelerometer and Gyroscope

This module is a header file that contains the I2C address, register addresses and configurations, and some default values for the MikroE Accel 8 click board using the MPU6050 6 Axis Accelerometer and Gyroscope. <br>
- [MPU6050 Datasheet](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf)
- [MPU6050 Register Map](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Register-Map1.pdf)

## Timers

This module is meant as a wrapper to the timer peripherals in microcontrollers. It is used to set multiple timers at different periods using only one timer peripheral. It is assumed that the peripheral timer is set up to trigger an overflow interrupt every 1 ms. <br>
<br>
- `void TIMERS_TimerOverflowInterrupt (void)`: This function should be registered as the callback function to the overflow interrupt of the timer peripheral. <br>
- `uint8_t TIMERS_RegisterTimer(timer_t* timerHandle, uint32_t period_ms, timerCallback_t timerCallback)`: This function is used to add timers of different periods to the timer peripheral. To use this function, a timer should be created using `timer_t timerName` and its address should be passed to the `timerHandle` argument, along with the period in ms, and a pointer to the callback function. NULL or 0 can be passed in lieu of a callback function to make the timer call back to `defaultTimerCallback`. <br>
- `uint8_t TIMERS_GetTimerCount (void)`: Returns the number of timers registered
- `void TIMERS_EnableTimer (timer_t* timerHandle)`: Enables specified timer.
- `void TIMERS_DisableTimer (timer_t* timerHandle)`: Disables specified timer.
<br>

### Example using AVR128DB48 with TCA0 timer peripheral (main.c)

	void toggleLED () {}

	int main {
		uint8_t numTimers = 0;
		timer_t ledTimer250ms;
		TCA0_OverflowCallbackRegister(timerOverflowInterrupt); // TCA0_OverflowCallbackRegister is a built in function for the AVR-Dx devices
		TIMERS_RegisterTimer(&ledTimer250ms, 250, toggleLED);
		numTimers = TIMERS_GetTimerCount();
		TCA0_Start(); //Starts TCA0 Peripheral Timer
		TIMERS_EnableTimer(&LedTimer);

		while (1) {} // Main program loop
	}