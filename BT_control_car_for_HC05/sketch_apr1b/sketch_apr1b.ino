#include "arduino_secrets.h"

/*
 * arduino hc-05 slave code for remote control car
 * hc-05è»å­
 */

#include <Servo.h>
Servo servo;
boolean motor_1 = false;
boolean motor_2 = false;
int pos;

void setup() {
  Serial.begin(9600); //hc-05å³è¼¸ç¨(å°æAT commandè¨­å®)
  servo.attach(6);    // è½åç¨çä¼ºæé¦¬é
  pinMode(3, OUTPUT); // L298Nç[ENAæENB]çè½éæ§å¶è³ä½
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT);  
}

void loop() {
  if(Serial.available() > 0){
    int state = Serial.read();  // stateä½çºè®åéæ§å¨éä¾çè³æ
    
    if(state >= 0 && state <= 180){  // è½åç¨çä¼ºæé¦¬éçè®åæ¸å¼
      pos = state;                   
    }
    if(state == 182){      
      motor_1 = true;
      motor_2 = false;
      analogWrite(3, 255);    //è½éæ§å¶ç¯å=> 0 ~ 255
    }
    if(state == 181){     
      motor_1 = false;
      motor_2 = false;
    }
    if(state == 183){      
      motor_1 = false;
      motor_2 = true;
      analogWrite(3, 255);
    }
  }
 digitalWrite(4, motor_1);
 digitalWrite(5, motor_2);
 servo.write(pos);
}