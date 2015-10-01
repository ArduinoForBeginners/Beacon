#include <Beacon.h>

Beacon beacon(2,3);

void setup() {

  delay(1000);
  beacon.renew(); // Beacon initialize
  delay(100);
  beacon.reset(); // Beacon reset
}

void loop() {
  // put your main code here, to run repeatedly:

}
