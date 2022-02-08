# SAMD21-DS18B20

### A lightweight driver for MKR-series Arduino's and other SAMD21 circuits
![image](https://user-images.githubusercontent.com/36161882/152974959-75739593-c6b8-4f46-b9b4-2f2302a2ecad.png)

## Use case
If you're working on a project with a newer Arduino with the DS18B20 sensor, and you'll only have **one** sensor connected to your device, this lightweight driver might be for you.

I developed this lightweight library for the DS18B20 temperature sensor tailored specifically for the Arm® Cortex®-M0 32-bit SAMD21 processor.
It was just a fun project to learn the OneWire protocol whilst also mitigating the need to import the huge OneWire library with DallasTemperature since I'm only ever going to use **one** sensor for my project which rendered a lot of code in those libraries unecessary for me and my little device with not-so-much memory to spare for luggage code.

I wanted to make it very easy to use and easy to read, should you need or want to change something in it yourself.

A few platforms that I'm aware of which use this silicon are:

* Arduino MKR1010 WiFi 
* Arduino MKR1310 Wan
* Arduino MKR1000 WiFi
* Arduino MKR GSM 1400
* MKR Vidor 4000

## Example

```c++

// Arduino MKR1010

// You must provide which group and port you've connected the sensor to on your board. 
// The DS18B20.h file in this repository has a table for this which you can look up.

DS18B20 tempSensor = DS18B20(TEMP_PORT_GROUP, PORT_PA16);
float temp;

void setup()
{
  tempSensor.begin();
}

void loop()
{
  // Celcius
  temp = tempSensor.GetTemperature('C');
  temp = tempSensor.GetTemperature();    // Defaults to Celcius
  
  // Fahrenheit
  temp = tempSensor.GetTemperature('F');
  
  // Code ...
}
```
See another example [here](https://github.com/dotchetter/SAMD21-DS18B20/blob/main/examples/TestDS18B20.ino)


## Limitations
* This driver only supports **one** DS18B20 connected to the device at a time.
* No temperature below 0 Celcius is reported - it stops at 0.0c. (If you feel like adding this feature, make a PR! :)  )

## Disclaimers
This driver has not been industrially tested and is for hobby purposes only. I, the author, do not condone the use of this driver in any health -or business critical use case and thus leave zero guarantees for that the values are correct at all times.
