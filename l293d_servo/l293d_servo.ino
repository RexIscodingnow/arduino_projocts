#include <Servo.h>
Servo servo_pin_10;
int value = 0;
void setup() {
  servo_pin_10.attach(10);
  pinMode(14,INPUT);
}

void loop() {
  value = analogRead(14);
  value = map(value,0,1023,0,180);
  servo_pin_10.write(value);

}
