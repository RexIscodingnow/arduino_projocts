#include <Servo.h>
#include <AFMotor.h>
Servo servo;
AF_DCMotor motor(1);
void setup() {
  servo.attach(10);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
}
void loop() {
  int val = analogRead(A0); 
  int value = analogRead(A1);
  int ser = map(val,0,1023,0,180);
  int fan = map(value,0,1023,0,255);
  servo.write(ser);
  motor.setSpeed(fan);
  motor.run(FORWARD);
}
