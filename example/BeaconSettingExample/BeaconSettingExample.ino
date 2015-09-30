#include <Beacon.h>

Beacon beacon(2,3);

void setup() {
  
  beacon.renew(); // Beacon initialize
  beacon.reset(); // Beacon reset

  /*--------- Beacon Setting ---------*/
  beacon.setName("Hello Beacon"); // Set beacon name
  beacon.setInterval(5); // Set interval of sending BLE about 546.25ms
  beacon.setAdvertisingType(3); // Set non-connectable
  beacon.setIbeaconMode(1) // Turn on iBeacon mode
  beacon.setIbeaconDeploy(2) // Set iBeacon broadcast mode

  beacon.reset(); // Beacon reset
}

void loop() {
  // put your main code here, to run repeatedly:

}
