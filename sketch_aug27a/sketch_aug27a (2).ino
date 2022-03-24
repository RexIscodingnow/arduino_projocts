int sensor = 0;

void setup() {
 pinMode(3,OUTPUT);
 pinMode(14,INPUT);
}

void loop() {
 sensor = analogRead(14)/10;
 analogWrite(3,sensor);
}
