#include <IRremote.h>
#include <AFMotor.h>
#include <Servo.h>
AF_DCMotor motor1(3);
AF_DCMotor motor2(4);
int RECV_PIN = 5;
IRrecv irrecv(RECV_PIN);
decode_results results;
Servo servo;
int servoPos=0;
void setup() {
servo.attach(10);
irrecv.enableIRIn(); 
}

void loop() {
if (irrecv.decode(&results)) {
switch (results.value) { 

case 0x50CAF3: // 按鍵「0」時停止不轉
servoPos = 90;
servo.write(servoPos); 
break;

case 0x51CAE3: // 按鍵「往左快轉」...FF5AA5
if (servoPos > 10) { 
servoPos -= 20; 
servo.write(servoPos); //減10度(愈接近0)
}
break;

case 0x508AF7: // 按鍵「往右快轉」...FF10EF
if (servoPos < 170) { 
servoPos += 20; 
servo.write(servoPos);//加10度(愈接近180)
}
break;
}
switch (results.value) { 

case 0x53CAC3: // 按鍵「0」時停止不轉
motor1.setSpeed(0);
motor1.run(RELEASE);
motor2.setSpeed(0);
motor2.run(RELEASE);
break;

case 0x534ACB: // 按鍵「往左快轉」...
motor1.setSpeed(225);
motor1.run(FORWARD);
motor2.setSpeed(225);
motor2.run(FORWARD);
break;

case 0x536AC9: // 按鍵「往右快轉」...
motor1.setSpeed(225);
motor1.run(BACKWARD);
motor2.setSpeed(225);
motor2.run(BACKWARD);
break;
}
irrecv.resume(); // 準備接收下一筆資料
}
}
