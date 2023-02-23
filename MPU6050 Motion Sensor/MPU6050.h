/*
 * File:   MPU6050.h
 * Author: Sarp User
 *
 * Created on December 2, 2022, 3:57 PM
 */

#ifndef MPU6050_H
#define	MPU6050_H
#endif	/* MPU6050_H */

// Default Values
#define ACCEL_LSB_PER_G 16384

// I2C Client Address
#define MPU6050_I2C_ADDRESS 0b1101001

// WHOAMI Register - Contains Client Address
#define MPU6050_WHOAMI 0x75

// Data Registers
#define ACCEL_XOUT_H_ADDR 0x3B

// PWR_MGMT_1 Configuration Register
#define PWR_MGMT_1_ADDR 0x6B
#define PWR_MGMT_1_RESET_ENABLE_bm 0x80
#define PWR_MGMT_1_SLEEP_ENABLE_bm 0x40
#define PWR_MGMT_1_CYCLE_ENABLE_bm 0x20