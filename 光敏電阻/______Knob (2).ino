#define pwmLED 3
#define boardLed 13
#define ADCInput 14

int value = 0;

void setup() {
 pinMode(pwmLED,OUTPUT); 
 pinMode(boardLed,OUTPUT);  
 pinMode(ADCInput,INPUT);  
}

void loop() {
 value = analogRead(ADCInput);
 
 if(value > 512) {
 digitalWrite(boardLed,false);            
 }else{
 digitalWrite(boardLed,true);   
 }
 if(value < 600) {
  analogWrite(pwmLED,map(value,0,1023,0,500)); 
 }else{ 
  analogWrite(pwmLED,0);
 }
}
