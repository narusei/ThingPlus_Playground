#include <Adafruit_LPS35HW.h>


Adafruit_LPS35HW lps35hw = Adafruit_LPS35HW();

#define LPS_CS  10
#define LPS_SCK  13
#define LPS_MISO 12
#define LPS_MOSI 11

#define _DEBUG_

float pressure;
float temperature;

void setup() {
  // put your setup code here, to run once:
  #ifdef _DEBUG_
    Serial.begin(9600);
    while(!Serial);
  #endif

  if (!lps35hw.begin_I2C()) {
  //if (!lps35hw.begin_SPI(LPS_CS)) {
  //if (!lps35hw.begin_SPI(LPS_CS, LPS_SCK, LPS_MISO, LPS_MOSI)) {
    while (1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  temperature = lps35hw.readTemperature();
  pressure = lps35hw.readPressure();
  #ifdef _DEBUG_
    Serial.print("temperature : ");
    Serial.println(temperature);
    Serial.print("pressure : ");
    Serial.println(pressure);
  #endif

  delay(1000);
}
