#include <IRremote.h>
#include <Servo.h>
int RECV_PIN = 4;
IRrecv irrecv(RECV_PIN);
decode_results results;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int servoPos1=0;
int servoPos2=0;
int servoPos3=0;
int servoPos4=0;
void setup() {
 servo1.attach(6);
 servo2.attach(9);
 servo3.attach(10);
 servo4.attach(11);   
 irrecv.enableIRIn();  
}

void loop() {
 if (irrecv.decode(&results)) {
 switch (results.value){
 
  case 0x526AD9:  //1
  servoPos1 = 90;
  servo1.write(servoPos1); 
  break;
  
  case 0x528AD7:  //1
   if (servoPos1 > 10) { 
   servoPos1 -= 10; 
   servo1.write(servoPos1); //減10度(愈接近0)
   }
  break;
  
  case 0x516AE9:  //1
  if (servoPos1 < 170) { 
   servoPos1 += 10; 
   servo1.write(servoPos1);//加10度(愈接近180)
   }
  break;
 }
 switch (results.value){
  
  case 0x50AAF5:  //2
  servoPos2 = 90;
  servo2.write(servoPos2);   
  break;
  
  case 0x532ACD:  //2
  if (servoPos2 > 10) { 
  servoPos2 -= 10; 
  servo2.write(servoPos2); //減10度(愈接近0)  
  }
  break;
  
  case 0x51AAE5:  //2
  if (servoPos2 < 170) { 
  servoPos2 += 10; 
  servo2.write(servoPos2);//加10度(愈接近180)
  }  
  break; 
 }
 switch (results.value){
  
  case 0x53AAC5:  //3
  servoPos3 = 90;
  servo3.write(servoPos3);   
  break;
  
  case 0x506AF9: //3 ,52AAD5
  if (servoPos3 > 10) { 
  servoPos3 -= 10; 
  servo3.write(servoPos3); //減10度(愈接近0)  
  }
  break;      
  
  case 0x52AAD5:  //3 ,506AF9
  if (servoPos3 < 170) { 
  servoPos3 += 10; 
  servo3.write(servoPos3);//加10度(愈接近180)
  }   
  break;
 }
 switch (results.value){
  case 0x52EAD1: //4
  servoPos4 = 90;
  servo4.write(servoPos4);  
  break;
  
  case 0x52CAD3: //4
  if (servoPos4 > 10) { 
  servoPos4 -= 20; 
  servo4.write(servoPos4); //減10度(愈接近0)  
  }  
  break;
  
  case 0x520ADF: //4
  if (servoPos4 < 170) { 
  servoPos4 += 20; 
  servo4.write(servoPos4);//加10度(愈接近180)
  }  
  break;               
  }
  irrecv.resume(); // 準備接收下一筆資料
 }
}
