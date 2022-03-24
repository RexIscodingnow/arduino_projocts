#include<Servo.h>
#include<AFMotor.h>
Servo servo;
AF_DCMotor motor(1);
AF_Stepper motor1(48,2);
int botton=0;
int speed1=0;
void setup() {
  Serial.begin(9600);
  servo.attach(10);
  pinMode(A0,INPUT);
  pinMode(4,INPUT);
  motor.setSpeed(225);
  motor1.setSpeed(300);// put your setup code here, to run once:
}
void loop() { 
   speed1=analogRead(A0);
   Serial.println(speed1);
   delay(1000);
   if(speed1==511){
    motor.run(RELEASE);
   }
   else if(speed1>511){
    motor.run(FORWARD);    
   }
   else if(speed1<511){
    motor.run(BACKWARD);    
   }   
   botton=digitalRead(4);
   if(botton==HIGH){ 
     motor1.step(4096,FORWARD,INTERLEAVE);
     delay(500);               
     motor1.step(4096,BACKWARD,INTERLEAVE); 
     delay(500);      
     } 
   else{
     motor1.step(0,RELEASE);
   }
}
