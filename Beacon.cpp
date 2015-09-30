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

void Beacon::setName(String name) {
	Stirng beacon_name = "AT+NAME" + name;
	SERIAL_WRITE(beacon_name);
}

void Beacon::setInterval(int interval) {
	Stirng beacon_interval = "AT+ADVI" + String(interval);
	SERIAL_WRITE(beacon_interval);
}

/**
 * 
 *
 */
void Beacon::setIbeaconMode(boolean enable) {
	Stirng beacon_ibeacon_mode = "AT+IBEA0";
	if(enable) {
		beacon_ibeacon_mode = "AT+IBEA1";
	}
	SERIAL_WRITE(beacon_interval);
}


