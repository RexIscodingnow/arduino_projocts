int redColor = 0, greenColor = 0, blueColor = 0;          // 三色LED燈顏色數值
int rLedPin = 9, gLedPin = 10, bLedPin = 11;              // 三色燈在Nano上的數位腳位

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(rLedPin, OUTPUT);
  pinMode(gLedPin, OUTPUT);
  pinMode(bLedPin, OUTPUT);

  // 此例所用的三色LED為共陽極
  analogWrite(rLedPin, 255-redColor);
  analogWrite(gLedPin, 255-greenColor);
  analogWrite(bLedPin, 255-blueColor);
}

void loop() {
  // 當資料超過 3 Bytes 時，將前 3 Bytes分別當成 Red, Green, Blue 顏色的數值(0~255)
  if (Serial.available() >= 3) {
    redColor = Serial.read();
    greenColor = Serial.read();
    blueColor = Serial.read();
        
    analogWrite(rLedPin, 255-redColor);
    analogWrite(gLedPin, 255-greenColor);
    analogWrite(bLedPin, 255-blueColor);
  }
}

