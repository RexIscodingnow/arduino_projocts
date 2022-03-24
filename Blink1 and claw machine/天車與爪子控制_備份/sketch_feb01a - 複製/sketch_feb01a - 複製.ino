/*
 * 天車移動
 * arduino UNO
 */
int x = 0;//x軸
int b = 0;
int b2 = 0;
int y = 0;//y軸
int b3 = 0;
int b4 = 0;
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);//搖
  pinMode(A1,INPUT);//桿
  pinMode(2,OUTPUT);//  馬
  pinMode(3,OUTPUT);//  達
  pinMode(6,INPUT); //限位  6 pin
  pinMode(7,INPUT); //開關 &7 pin
  pinMode(4,OUTPUT);//  馬
  pinMode(5,OUTPUT);//  達
  pinMode(8,INPUT); //限位  8 pin
  pinMode(9,INPUT); //開關 &9 pin
  pinMode(16,OUTPUT); //上&
  pinMode(17,OUTPUT); //下爪
  pinMode(10,INPUT); //下
  pinMode(11,INPUT); //上
  pinMode(12,INPUT); //停
  pinMode(13,INPUT); //二收 
}
void loop() {
  x = analogRead(A0);  //搖
  b = digitalRead(6);  //桿
  b2 = digitalRead(7); //joystick
  Serial.println(b);
  Serial.println(b2);
  Serial.println(x);
  y = analogRead(A1);  //搖
  b3 = digitalRead(8); //桿
  b4 = digitalRead(9); //joystick
  Serial.println(b3);
  Serial.println(b4);
  Serial.println(y);
  if (x > 900) {       //(不包括)[900]~1023
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
  }
  else if (x < 250) {   //0~[250](不包括)
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
  }
  else if (x >= 250 and x <= 900) { //250~900[包括]
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }

  if (b == false) {       //限位開關1
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
  else if (b2 == false) { //限位開關2
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
  if (y > 900) {       //(不包括)[900]~1023
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }
  else if (y < 250) {  //0~[250](不包括)
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }
  else if (y >= 250 and y <= 900) { //250~900[包括]
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  if (b3 == false) {      //限位開關3
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else if (b4 == false) { //限位開關4
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  //下方為與arduino nano以杜邦線作訊號傳輸(皆為按鈕)
  //nano pins:D2  D3  D6  
  //與之對應   |   |   |     ("|"為上下對應)
  //UNO  pins:D11 D13 D12
  Serial.println(digitalRead(10)); //下爪
  Serial.println(digitalRead(11)); //上爪
  Serial.println(digitalRead(12)); //上停
  Serial.println(digitalRead(13)); //二收
  if (digitalRead(10) == HIGH) { //下爪
    digitalWrite(16, HIGH);
    digitalWrite(17, LOW);
  }
  else if (digitalRead(11) == HIGH) { //上爪
    digitalWrite(16, LOW);
    digitalWrite(17, HIGH);
  }
  else if (digitalRead(12) == LOW) { //上停
    digitalWrite(16, LOW);
    digitalWrite(17, LOW);
  }
  else if (digitalRead(13) == HIGH) { //*[二收]* 提前往上跑
    digitalWrite(16, LOW); //2020/10/11 8:28 p.m.
    digitalWrite(17, LOW); //新
    delay(500);            //增
    digitalWrite(16, LOW);
    digitalWrite(17, HIGH);
  }
  delay(50);
}
