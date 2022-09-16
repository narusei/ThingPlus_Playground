#include <Wire.h>
#include <Adafruit_LPS35HW.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"

Adafruit_LPS35HW lps35hw = Adafruit_LPS35HW();
OpenLog myLog;

#define LPS_CS  10
#define LPS_SCK  13
#define LPS_MISO 12
#define LPS_MOSI 11

//#define _DEBUG_

float pressure;
float temperature;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();

  #ifdef _DEBUG_
    Serial.begin(9600);
    while(!Serial);
  #endif

  if (!lps35hw.begin_I2C()) {
  //if (!lps35hw.begin_SPI(LPS_CS)) {
  //if (!lps35hw.begin_SPI(LPS_CS, LPS_SCK, LPS_MISO, LPS_MOSI)) {
    while (1);
  }

  if(!myLog.begin()){
    #ifdef _DEBUG_
      Serial.println("SD begin failed");
    #endif
    while(1);
  }
  delay(15);

  char fileNamePacket[8] = "";
  
  int fileNameCount = 0;
  long sizeOfFile = 0;
  while (sizeOfFile > -1) {
    fileNameCount += 1;
    sprintf(fileNamePacket, "%04d.csv", fileNameCount);
    sizeOfFile = myLog.size(fileNamePacket);
    delay(100);
    
    #ifdef _DEBUG_
      Serial.print("Check File Name : ");
      Serial.println(fileNamePacket);
      if (sizeOfFile == -1) {
        Serial.println("File not exist. Create file.");
      } else {
        Serial.println("File exist. Retry cheking file name.");
      }
    #endif
  }

  bool isCreatedFile = false;
  long sizeOfCreateFile = 0;
  while (!isCreatedFile) {
    myLog.create(fileNamePacket);
    delay(100);

    sizeOfCreateFile = myLog.size(fileNamePacket);
    delay(100);
    if (sizeOfCreateFile == -1) {
      #ifdef _DEBUG_
        Serial.println("File not created");
      #endif
      isCreatedFile = false;
    } else {
      #ifdef _DEBUG_
        Serial.println("File created!");
      #endif
      isCreatedFile = true;
    }
  }

  myLog.append(fileNamePacket);
  delay(100);
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
  
  myLog.print(pressure);
  delay(15);
  myLog.print(",");
  delay(15);
  myLog.println(temperature);
  delay(15);
  myLog.syncFile();
  delay(15);

  #ifdef _DEBUG_
    Serial.println("SD written Done");
  #endif

  delay(1000);
}
