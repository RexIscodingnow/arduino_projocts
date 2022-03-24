/*
 * 爪子&顯示
 * arduino nano
 */
#include <Servo.h>            //常見的函式庫，應該不用說了(嗎?)
#include <Wire.h>             //lcd
#include <LiquidCrystal_I2C.h>  //函式庫
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //他的address
Servo servo;
long c;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2); 
  servo.attach(9);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,OUTPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(6,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);  
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,INPUT);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("hello");
  lcd.setCursor(0,1);
  lcd.print("claw machine");
  delay(1000);
  lcd.clear();  
}

void loop() {
 int i=analogRead(A0); //調整電壓(12~34 or 35volt) 
  //下方為與arduino nano以杜邦線作訊號傳輸(皆為按鈕)
  //nano pins:D2  D3  D6  
  //與之對應   |   |   |     ("|"為上下對應)
  //UNO  pins:D11 D13 D12 
  if(digitalRead(2)==HIGH){ //取物鈕
    analogWrite(5,i);       
  }
  if(digitalRead(3)==HIGH){ //*[二收]*
    analogWrite(5,i);
  }  
  if(digitalRead(7)==HIGH){//計數金額
    c++;
    servo.write(89);  //原為設計在錢道使用(好像是多餘的(?))
    delay(900);
   }
  if(digitalRead(4)==HIGH){//天車原點
    servo.write(30);  //原為設計在錢道使用(好像是多餘的(?))
    analogWrite(5,0);
  }
  else if(digitalRead(8)==HIGH){  //電眼
    c=0;
  }
  if(digitalRead(6)==HIGH){  //天車歸位
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    digitalWrite(A1,LOW);
    digitalWrite(A2,HIGH);     
  }
  if(digitalRead(10)==LOW){  //歸位停止
   // digitalWrite(12,LOW);
   // digitalWrite(13,LOW);
    digitalWrite(A1,LOW);
    digitalWrite(A2,LOW);    
  }
  if(digitalRead(11)==LOW){  //歸位停止
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
   // digitalWrite(A1,LOW);
   // digitalWrite(A2,LOW);    
  }
 if(c==19){      //已達保證取物金額 
   if(digitalRead(2)==HIGH){
     analogWrite(5,1023);
   }
   if(digitalRead(3)==HIGH){
     analogWrite(5,1023);
  }
   servo.write(91);
   lcd.setCursor(10,1);
   lcd.print("Don't put money");
 }
  else if(c==0){ //假如歸零
  servo.write(35);
  lcd.clear();   //清除計數
  lcd.setCursor(0,0);
  lcd.print("coin");
  lcd.setCursor(0,1);
  lcd.print(c);
  lcd.setCursor(2,1);
  lcd.print("/19 coins");    
  }
  delay(50);     //debounce(開關金屬彈跳debug)
  //下為顯示該數據(次數)
  lcd.setCursor(0,0);
  lcd.print("coin");
  lcd.setCursor(0,1);
  lcd.print(c);
  lcd.setCursor(2,1);
  lcd.print("/19 coins");
}
