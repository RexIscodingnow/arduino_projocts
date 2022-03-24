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
  
  case 0xFF9867:  //1
   if (servoPos1 > 10) { 
   servoPos1 -= 20; 
   servo1.write(servoPos1); //減10度(愈接近0)
   }
  break;
  
  case 0xFFB04F:  //1
  if (servoPos1 < 170) { 
   servoPos1 += 20; 
   servo1.write(servoPos1);//加10度(愈接近180)
   }
  break;
  
  case 0xFFA857:  //2
  servoPos2 = 90;
  servo2.write(servoPos2);   
  break;
  
  case 0xFF906F:  //2
  if (servoPos2 > 10) { 
  servoPos2 -= 20; 
  servo2.write(servoPos2); //減10度(愈接近0)  
  }
  break;
  
  case 0xFFC23D:  //2
  if (servoPos2 < 170) { 
  servoPos2 += 20; 
  servo2.write(servoPos2);//加10度(愈接近180)
  }  
  break; 
  
  case 0xFF02FD:  //3
  servoPos3 = 90;
  servo3.write(servoPos3);   
  break;
  
  case 0xFF22DD: //3
  if (servoPos3 > 10) { 
  servoPos3 -= 20; 
  servo3.write(servoPos3); //減10度(愈接近0)  
  }
  break;      
  
  case 0xFFE01F:  //3
  if (servoPos3 < 170) { 
  servoPos3 += 20; 
  servo3.write(servoPos3);//加10度(愈接近180)
  }   
  break;
  
  case 0xFF629D: //4
  servoPos4 = 90;
  servo4.write(servoPos4);  
  break;
  
  case 0xFFA25D: //4
  if (servoPos4 > 10) { 
  servoPos4 -= 20; 
  servo4.write(servoPos4); //減10度(愈接近0)  
  }  
  break;
  
  case 0xFFE21D: //4
  if (servoPos4 < 170) { 
  servoPos4 += 20; 
  servo4.write(servoPos4);//加10度(愈接近180)
  }  
  break;               
  }
 }
}
