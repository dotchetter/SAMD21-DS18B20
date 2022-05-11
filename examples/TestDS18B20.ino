
#include "DS18B20.h"

// Check the table in "DS18B20.h" if you need help with picking these values. 
// It will depend on where you connect the sensor to your device.
#define TEMP_PORT_GROUP      0
#define TEMP_PINMASK         PORT_PA16

// In this case, the data cable to the DS18B20 sensor is connected to physical port 8 on an MKR1010.
DS18B20 tempSensor = DS18B20(TEMP_PORT_GROUP, TEMP_PINMASK);

void setup()
{
    Serial.begin(38400);
    tempSensor.begin();
}

void loop()
{
    Serial.println(tempSensor.GetTemperature('C'));
    delay(1000);
}
