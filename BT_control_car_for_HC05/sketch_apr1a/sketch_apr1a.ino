#include "arduino_secrets.h"

/*
 * arduino hc-05 master code for remote control car
 * hc-05éæ§å¨
 */

void setup() {
  Serial.begin(9600); //hc-05å³è¼¸ç¨(å°æAT commandè¨­å®)
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(A0, INPUT);
}

void loop() {
  if(digitalRead(2) == LOW){    // åå¾æ§å¶
    Serial.write(182);
  }
  if(digitalRead(3) == LOW){    // åå¾æ§å¶
    Serial.write(183);
  }  
  if(digitalRead(2) == HIGH && digitalRead(3) == HIGH){
    Serial.write(181);
  }
  Serial.write(analogRead(A0)/11); // è½åæ§å¶
 delay(20);
}