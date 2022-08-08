/*
  An I2C based datalogger - Like the OpenLog but for I2C
  By: Nathan Seidle
  SparkFun Electronics
  Date: February 2nd, 2018
  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

  This example shows how to record various text and variables to Qwiic OpenLog

  To Use:
    Insert a formatted SD card into Qwiic OpenLog
    Attach Qwiic OpenLog to a RedBoard or Uno with a Qwiic cable
    Load this sketch onto the RedBoard
    Open a terminal window to see the Serial.print statements
    Then insert the SD card into a computer view the log file contents
*/

#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"
#define sdWriteSize 31
#define getDataSize 62

OpenLog myLog; //Create instance

uint8_t *myBuffer;
uint8_t bufferData[getDataSize] = {
  0x31, 0x68, 0x69, 0x73, 0x5f, 0x69, 0x73, 0x5f, 0x74, 0x65, 0x73, 0x74, 0x5f, 0x26, 0x5f, 0x33, 
  0x32, 0x5f, 0x62, 0x79, 0x74, 0x65, 0x5f, 0x64, 0x61, 0x74, 0x61, 0x5f, 0x74, 0x65, 0x73, 
  0x32, 0x68, 0x69, 0x73, 0x5f, 0x69, 0x73, 0x5f, 0x74, 0x65, 0x73, 0x74, 0x5f, 0x26, 0x5f, 0x33, 
  0x32, 0x5f, 0x62, 0x79, 0x74, 0x65, 0x5f, 0x64, 0x61, 0x74, 0x61, 0x5f, 0x74, 0x65, 0x73, 
};

void setup()
{
  Wire.begin();
  Serial.begin(115200);
  
  myBuffer = new uint8_t[sdWriteSize];
  myBuffer = bufferData;

  myLog.begin();
  myLog.append("test.bin");
  for(int i=0; i<2; i++){
    myLog.write(myBuffer, 31);
    Serial.println(*myBuffer, HEX);
    myBuffer += 31;
  }
  myLog.syncFile();
}

void loop()
{
}
