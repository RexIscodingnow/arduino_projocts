int a=0;
void setup() {
  Serial.begin(9600);
  pinMode(7,INPUT);// put your setup code here, to run once:
}

void loop() {
  a=digitalRead(7);// put your main code here, to run repeatedly:
  Serial.println(a);
  delay(300);
}
