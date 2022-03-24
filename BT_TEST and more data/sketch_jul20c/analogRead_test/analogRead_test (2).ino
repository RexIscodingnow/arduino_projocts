int r=0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  r = analogRead(A0);
  Serial.println(r);
  delay(500);
}
