/*
  Beacon.h - Library for beacon code.
  Created by Jaison Oh, September 22, 2015.
  Released into the public domain.
*/
#ifndef Beacon_h
#define Beacon_h
 
#include "Arduino.h"
#include <SoftwareSerial.h>

class Beacon
{
  public:
    Beacon(int rx, int tx);
    void isConnecting(void);
    void reset(void);
    void renew(void);
    void setName(String name);
    void setInterval(int interval);
    void setMajor(unsigned int major);
    void setMinor(unsigned int minor);
    void setAdvertisingType(int type);
    void setIbeaconMode(boolean enable);
    void setIbeaconDeploy(int type);
    void setAutoSleep(boolean enable);
  private:
    int _rx;
    int _tx;
};
 
#endif