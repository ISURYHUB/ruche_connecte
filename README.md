# ruche_connecte

Bee Hive Monitoring System

This project was created to help my Physics and Chemistry teacher with his bee hive monitoring project. The goal of the project was to connect his bee hives to an Arduino-based system to obtain data such as humidity, temperature, number of bees entering and leaving the hive. The data would then be transmitted to the Ubidots service so that it could be tracked and visualized from anywhere in the world.
Hardware Requirements

To build this project, you will need the following hardware components:

    Arduino board (such as an Arduino Uno or Arduino Mega)
    LoRa radio module (such as RFM95)
    SHT31 temperature and humidity sensor
    Bee traffic sensor

# Software Requirements

The following software libraries are required for this project:

    RadioHead library for RF95 LoRa module
    I2C library for communicating with sensors
    Adafruit_Sensor.h library
    Adafruit_SHT31.h library

# Installation

To install the required software libraries, follow these steps:

    Download the RadioHead library from the following link: https://www.airspayce.com/mikem/arduino/RadioHead/
    Extract the contents of the downloaded zip file to your Arduino libraries folder (typically located at Documents\Arduino\libraries).
    Download the Adafruit_Sensor.h and Adafruit_SHT31.h libraries from the following link: https://github.com/adafruit/Adafruit_SHT31
    Extract the contents of the downloaded zip file to your Arduino libraries folder.

# Usage

To use this code, connect the SHT31 temperature and humidity sensor and bee traffic sensor to the appropriate pins on your Arduino board. Then, upload the provided code to your Arduino board using the Arduino IDE.

The code will capture temperature and humidity data from the SHT31 sensor, count bee traffic in and out of the hive using the bee traffic sensor, and transmit that data to Ubidots via LoRa radio every 5 minutes.

To view the data in Ubidots, you will need to set up an account on the Ubidots website and create a data source to receive the data from your Arduino.
Credits

This project was created by Ismaïl KRAMDI BOUZOUADA to help his Physics and Chemistry teacher with his bee hive monitoring project. The code was based on the RadioHead library for RF95 LoRa module and Adafruit_SHT31.h library.
