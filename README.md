# FEETECH BUS Servo

> FEETECH BUS Servo library for Arduino and ESP32

## Table of Contents

<!-- TOC -->
* [FEETECH BUS Servo](#ft-series-servo)
  * [Table of Contents](#table-of-contents)
  * [Requirements](#requirements)
  * [Usage](#usage)
  * [Notes](#notes)
  * [Release](#release)
<!-- TOC -->

## Requirements

* arduino-1.6.10 or newer(https://www.arduino.cc/).

## Usage

For usage examples, see the [examples](./examples) directory.

## Notes

The code for the `SCServo` library is divided into the following
parts:

* communication layer: [src/SCS.cpp](src/SCS.cpp)
* hardware interface layer: [src/SCSerial.cpp](src/SCSerial.cpp)
* application layer:
  * corresponds to the three series of FEETECH BUS Servo
    * `SCSCL` application layer program: [src/SCSCL.h](src/SCSCL.h) and [src/SCSCL.cpp](src/SCSCL.cpp)
    * `SMS` and `STS` application layer program: [src/SMS_STS.h](src/SMS_STS.h) and [src/SMS_STS.cpp](src/SMS_STS.cpp)
    * `HLS` application layer program: [src/HLSCL.h](src/HLSCL.h) and [src/HLSCL.cpp](src/HLSCL.cpp)
* instruction definition header file: [src/INST.h](src/INST.h)
* communication layer program: [src/SCS.h](src/SCS.h) and [src/SCS.cpp](src/SCS.cpp)
* hardware interface program: [src/SCSerial.h](src/SCSerial.h) and [src/SCSerial.cpp](src/SCSerial.cpp)

Note that there are differences in the memory table definitions of different series of FEETECH BUS servos.

## Release

New (GitHub) releases of this library are automatically ingressed by the Arduino Library Manager.
