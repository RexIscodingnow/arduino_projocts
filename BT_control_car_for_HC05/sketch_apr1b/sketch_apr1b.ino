/*
 * arduino hc-05 slave code for remote control car
 * hc-05車子
 */

 #include <Servo.h>
 Servo servo;
 boolean motor_1 = false;
 boolean motor_2 = false;
 int pos;
 
 void setup() {
   Serial.begin(9600); //hc-05傳輸用(對應AT command設定)
   servo.attach(6);    // 轉向用的伺服馬達
   pinMode(3, OUTPUT); // L298N的[ENA或ENB]的轉速控制腳位
   pinMode(4, OUTPUT); 
   pinMode(5, OUTPUT);  
 }
 
 void loop() {
   if(Serial.available() > 0){
     int state = Serial.read();  // state作為讀取遙控器送來的資料
     
     if(state >= 0 && state <= 180){  // 轉向用的伺服馬達的讀取數值
       pos = state;                   
     }
     if(state == 182){      
       motor_1 = true;
       motor_2 = false;
       analogWrite(3, 255);    //轉速控制範圍=> 0 ~ 255
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