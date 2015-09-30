#include "Arduino.h"
#include "Beacon.h"
#include <SoftwareSerial.h>

#define SERIAL_WRITE(command)\
	for (int i=0; i<command.length(); i++) {\
		beaconSerial.write((byte) command[i]);\
	}

Beacon::Beacon(int rx, int tx) {
	SoftwareSerial beaconSerial(rx, tx);
	_rx = rx;
	_tx = tx;
}

void Beacon::isConnenting() {
	SERIAL_WRITE("AT");
}

void Beacon::reset() {
	SERIAL_WRITE("AT+RESET");
}

void Beacon::renew() {
	SERIAL_WRITE("AT+RENEW");
}

void Beacon::setName(String name) {
	Stirng beacon_name = "AT+NAME" + name;
	SERIAL_WRITE(beacon_name);
}

void Beacon::setInterval(int interval) {
	Stirng beacon_interval = "AT+ADVI" + String(interval);
	SERIAL_WRITE(beacon_interval);
}

void Beacon::setMajor(unsigned int major) {
	
	String beacon_major = "AT+MARJ0x";

	if (major > 16*16*16*16) {
		return;
	}
	else if (major >= 16*16*16) {
		beacon_major += String(major, HEX).toUpperCase();
	}
	else if (major >= 16*16) {
		beacon_major += "0"+ String(major, HEX).toUpperCase();
	}
	else if (major >= 16) {
		beacon_major += "00"+ String(major, HEX).toUpperCase();
	}
	else if (major >= 0) {
		beacon_major += "000"+ String(major, HEX).toUpperCase();
	}
	else {
		return;
	}

	SERIAL_WRITE(beacon_major);
}

void Beacon::setMinor(unsigned int minor) {
	
	String beacon_minor = "AT+MARJ0x";

	if (minor > 16*16*16*16) {
		return;
	}
	else if (minor >= 16*16*16) {
		beacon_minor += String(minor, HEX).toUpperCase();
	}
	else if (minor >= 16*16) {
		beacon_minor += "0"+ String(minor, HEX).toUpperCase();
	}
	else if (minor >= 16) {
		beacon_minor += "00"+ String(minor, HEX).toUpperCase();
	}
	else if (minor >= 0) {
		beacon_minor += "000"+ String(minor, HEX).toUpperCase();
	}
	else {
		return;
	}

	SERIAL_WRITE(beacon_minor);
}

/**
 * Set Advertising Type
 * AT+ADTY[Param]
 * Param : 0~3
 * 0 : Advertising scanned response (Default)
 * 1 : Only allow last device connect in 1.28s
 * 2 : Allow advertising and scan response
 * 3 : Only allow advertising, non-connectable
 */
void Beacon::setAdvertisingType(int type) {
	Stirng beacon_advertising_type = "AT+ADTY0";

	switch(type) {
		case 0:
			beacon_advertising_type = "AT+ADTY0";
			break;

		case 1:
			beacon_advertising_type = "AT+ADTY1";
			break;

		case 2:
			beacon_advertising_type = "AT+ADTY2";
			break;

		case 3:
			beacon_advertising_type = "AT+ADTY3";
			break;

		defalut: 
			beacon_advertising_type = "AT+ADTY0";
			break;
	}

	SERIAL_WRITE(beacon_advertising_type);
}

/**
 * Set Module iBeacon Switch
 * AT+IBEA[Param]
 * Param : 0~1
 * 0 : Turn off iBeacon (Default)
 * 1 : Turn on iBeacon 
 */
void Beacon::setIbeaconMode(boolean enable) {
	Stirng beacon_ibeacon_mode = "AT+IBEA0";
	if(enable) {
		beacon_ibeacon_mode = "AT+IBEA1";
	}
	SERIAL_WRITE(beacon_ibeacon_mode);
}

/**
 * Set iBeacon deploy mode
 * AT+DELO[Param]
 * Param : 1~2
 * 1 : Allow to broadcast and scanning (Default)
 * 2 : Only allow broadcast
 */
void Beacon::setIbeaconDeploy(int type) {
	Stirng beacon_ibeacon_deploy = "AT+DELO1";

	switch(type) {
		case 1:
			beacon_ibeacon_deploy = "AT+DELO1";
			break;

		case 2:
			beacon_ibeacon_deploy = "AT+DELO2";
			break;

		defalut: 
			beacon_ibeacon_deploy = "AT+DELO1";
			break;
	}

	SERIAL_WRITE(beacon_ibeacon_deploy);
}

/**
 * Set Module Sleep Type
 * AT+PWRM[Param]
 * Param : 0~1
 * 0 : Auto sleep
 * 1 : No auto sleep (Default)
 */
void Beacon::setAutoSleep(boolean enable) {
	Stirng beacon_auto_sleep = "AT+PWRM1";
	if(enable) {
		beacon_auto_sleep = "AT+PWRM0";
	}
	SERIAL_WRITE(beacon_auto_sleep);
}



