#include<Servo.h>
#include<AFMotor.h>
Servo servo;
AF_Stepper motor1(48,2);
int botton=0;
void setup() {
   servo.attach(10); // put your setup code here, to run once:
   motor1.setSpeed(300);
   pinMode(3,INPUT);
}

void loop() {
   botton=digitalRead(3);
   if(botton!=HIGH){// put your main code here, to run repeatedly:
    while(1){
     digitalWrite(7,LOW);      
     digitalWrite(4,HIGH); 
     delay(100);
     digitalWrite(4,LOW);        
     digitalWrite(5,HIGH);
     delay(100);
     digitalWrite(5,LOW);        
     digitalWrite(6,HIGH);      
     delay(100);
     digitalWrite(6,LOW);        
     digitalWrite(7,HIGH);      
     delay(100);
    }     
   }
}
