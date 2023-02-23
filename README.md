# C Modules for Embedded Development

This library consists of useful C modules that can be used for embedded projects. This README includes documentation for each of the different modules included in this library.

## Table of Contents

- [MPU6050 Motion Sensor](#MPU6050)
- [Timers](#Timers)

## MPU6050

This module is a header file that contains the I2C address, register addresses and configurations, and some default values for the MPU6050 3 Axis Accelerometer and Gyroscope. <br>
- (MPU6050 Datasheet)[https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf]
- (MPU6050 Register Map)[https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Register-Map1.pdf]

## Timers

This module is meant as a wrapper to the timer peripherals in microcontrollers. It is used to set multiple timers at different periods using only one timer peripheral. It is assumed that the peripheral timer is set up to trigger an overflow interrupt every 1 ms. <br>
<br>
- `void timerOverflowInterrupt (void)`: This function should be registered as the callback function to the overflow interrupt of the timer peripheral. <br>
- `void defaultTimerCallback (void)`: This the default callback function to the user defined timers. This function will be called if there is no other callback function provided during initial registration. Empty function by default. <br>
- `uint8_t registerTimer(timer_t* timerHandle, uint32_t period_ms, timerCallback_t timerCallback)`: This function is used to add timers of different periods to the timer peripheral. To use this function, a timer should be created using `timer_t timerName` and its address should be passed to the `timerHandle` argument, along with the period in ms, and a pointer to the callback function. NULL or 0 can be passed in lieu of a callback function to make the timer call back to `defaultTimerCallback`. This function returns the total number of timers created. <br>
- `void enableTimer (timer_t* timerHandle)`: Enables specified timer.
- `void disableTimer (timer_t* timerHandle)`: Disables specified timer.

### Example using AVR128DB48 with TCA0 timer peripheral (main.c)

	void toggleLED () {}

	int main {
		uint8_t numTimers = 0;
		timer_t ledTimer250ms;
		TCA0_OverflowCallbackRegister(timerOverflowInterrupt); // TCA0_OverflowCallbackRegister is a built in function for the AVR-Dx devices
		numTimers = registerTimer(&ledTimer250ms, 250, toggleLED);
		TCA0_Start(); //Starts TCA0 Peripheral Timer
		enableTimer(&LedTimer);

		while (1) {} // Main program loop
	}