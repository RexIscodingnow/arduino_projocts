int apin=2;
int bpin=3;
int cpin=4;
int dpin=5;

void setup() {
  pinMode(apin,OUTPUT);
  pinMode(bpin,OUTPUT);
  pinMode(cpin,OUTPUT);
  pinMode(dpin,OUTPUT);    
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(apin,HIGH);
  delay(10);
  digitalWrite(apin,LOW);
  digitalWrite(bpin,HIGH);
  delay(10); 
  digitalWrite(bpin,LOW);
  digitalWrite(cpin,HIGH);
  delay(10); 
  digitalWrite(cpin,LOW);
  digitalWrite(dpin,HIGH);
  delay(10);
  digitalWrite(dpin,LOW);       
}
