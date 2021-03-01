#include <DHT.h>

DHT dht1(2, DHT22);
DHT dht2(4, DHT22);

int const stopPin = 6;
int stopFlag = 0;

float hum;
float temp;

void setup()
{
    pinMode(stopPin, INPUT);
    Serial.begin(9600);
    dht1.begin();
    dht2.begin();
}

void loop()
{
    delay(2000);

// ocitavanje vlaznosti s dva DHT22 senzora
    hum = dht1.readHumidity();
    Serial.print(hum);
    Serial.print(":");
    hum = dht2.readHumidity();
    Serial.print(hum);
    Serial.print(":")

// ocitavanje temperature s dva DHT22 senzora

temp = dht1.readTemperature();
Serial.print(temp);
Serial.print(":");
temp = dht2.readTemperature();
Serial.print(temp);
Serial.print(":");

stopFlag = digitalRead(stopPin);
    if (stopFlag == LOW) {
        Serial.println(temp);
    } else {
        Serial.print(temp);
        Serial.println(":999");
    }
}
