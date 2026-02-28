#include <Arduino.h>

float temperature;
float humidity;

// ----- Simulated Sensor -----
void readSensor()
{
    // fake values (simulation)
    temperature = random(25, 40);
    humidity = random(40, 80);
}

// ----- Status Logic -----
String checkStatus(float temp)
{
    if(temp < 30)
        return "NORMAL";
    else if(temp < 35)
        return "WARM";
    else
        return "HOT";
}

// ----- Main Setup -----
void setup()
{
    Serial.begin(115200);
}

// ----- Main Loop -----
void loop()
{
    readSensor();

    String status = checkStatus(temperature);

    Serial.print("Temp: ");
    Serial.print(temperature);
    Serial.print(" C | Humidity: ");
    Serial.print(humidity);
    Serial.print("% | Status: ");
    Serial.println(status);

    delay(2000);
}
