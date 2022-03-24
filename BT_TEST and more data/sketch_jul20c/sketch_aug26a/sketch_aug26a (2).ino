#include <AFMotor.h>
#include <Servo.h>
AF_DCMotor motor1(2);
Servo servo;
int servoPos=0;
int val=0;
void setup() {
 servo.attach(10); // put your setup code here, to run once:
 pinMode(A0,INPUT);
 pinMode(A1,INPUT);
}

void loop() {
 servoPos=analogRead(A0);
 int val1=map(servoPos,0,1023,0,180);
 servo.write(val1);
 val=analogRead(A1);
 int val2=map(val,0,1023,0,255);
 motor1.setSpeed(val2);
 motor1.run(FORWARD);// put your main code here, to run repeatedly:
}
