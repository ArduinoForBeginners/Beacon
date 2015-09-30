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
    void setName(String name);
    void setInterval(int interval);
  private:
    int _rx;
    int _tx;
    const String AT = "AT"; // 모듈과의 연결 상태 확인
    const String AT_RENEW = "AT+RENEW"; // 모듈 초기화
    const String AT_RESET = "AT+RESET"; // 모듈 리셋
    const String AT_SET_INTERVAL = "AT+ADVI"; // 통신 주기 설정 : AT+ADVIX
    const String AT_SET_NAME = "AT+MARJ0x"; // 메이저 값 설정 : AT+MARJ0xXXXX
    const String AT_SET_NAME = "AT+MINO0x"; // 마이너 값 설정 : AT+MARJ0xXXXX
};
 
#endif