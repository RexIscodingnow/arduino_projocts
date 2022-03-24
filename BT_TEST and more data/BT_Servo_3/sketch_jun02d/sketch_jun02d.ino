#include <SoftwareSerial.h>
SoftwareSerial BTSerial(0, 1);
void setup() {
  BTSerial.begin(9600);
}

void loop() {
  int x = analogRead(A0);
  int y = analogRead(A1);
  int vel = map (y, 0, 1023, 510, 0);
  int pos = map (x, 0, 1023, 0, 180);
  BTSerial.write(vel);
  BTSerial.write(pos);

}
