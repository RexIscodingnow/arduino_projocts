#include <Servo.h>
#include <IRremote.h>
int RECV_PIN = 6;
IRrecv irrecv(RECV_PIN);
decode_results results;
Servo servo;
Servo servo1;
Servo servo2;
Servo servo3;
int servoPos=0;
int servoPos1=0;
int servoPos2=0;
int servoPos3=0;
void setup() {
 irrecv.enableIRIn(); // Start the receiver
 servo.attach(3);
 servo1.attach(5);
 servo2.attach(9); 
 servo3.attach(10); 
}

void loop() {
if (irrecv.decode(&results)) {
switch (results.value) { 

case 0x526AD9: // 按鍵「0」時停止不轉
servoPos = 89;
servo.write(servoPos); 
break;

case 0x528AD7: // 按鍵「往左快轉」...
if (servoPos > 10) { 
servoPos -= 10; 
servo.write(servoPos); //減10度(愈接近0)
}
break;

case 0x516AE9: // 按鍵「往右快轉」...
if (servoPos < 170) { 
servoPos += 10; 
servo.write(servoPos);//加10度(愈接近180)
}
break;
}
if (irrecv.decode(&results)) {
switch (results.value) { 

case 0x53AAC5: // 按鍵「0」時停止不轉
servoPos1 = 89;
servo1.write(servoPos1); 
break;

case 0x51AAE5: // 按鍵「往左快轉」...
if (servoPos1 > 10) { 
servoPos1 -= 10; 
servo1.write(servoPos1); //減10度(愈接近0)
}
break;

case 0x532ACD: // 按鍵「往右快轉」...
if (servoPos1 < 170) { 
servoPos1 += 10; 
servo1.write(servoPos1);//加10度(愈接近180)
}
break;
}
if (irrecv.decode(&results)) {
switch (results.value) { 

case 0x50AAF5: // 按鍵「0」時停止不轉
servoPos2 = 89;
servo2.write(servoPos2); 
break;

case 0x506AF9: // 按鍵「往左快轉」...
if (servoPos2 > 10) { 
servoPos2 -= 10; 
servo2.write(servoPos2); //減10度(愈接近0)
}
break;

case 0x52AAD5: // 按鍵「往右快轉」...
if (servoPos2 < 170) { 
servoPos2 += 10; 
servo2.write(servoPos2);//加10度(愈接近180)
}
break;
}
if (irrecv.decode(&results)) {
switch (results.value) { 

case 0x522ADD: // 按鍵「0」時停止不轉
servoPos3 = 89;
servo3.write(servoPos3); 
break;

case 0x512AED: // 按鍵「往左快轉」...
if (servoPos3 > 10) { 
servoPos3 -= 10; 
servo3.write(servoPos3); //減10度(愈接近0)
}
break;

case 0x502AFD: // 按鍵「往右快轉」...
if (servoPos3 < 170) { 
servoPos3 += 10; 
servo3.write(servoPos3);//加10度(愈接近180)
}
break;
}
irrecv.resume(); // 準備接收下一筆資料
}
}
}
}
}
