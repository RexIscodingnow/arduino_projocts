char junk;
String inputString="";
boolean first = true;   
int motorDirection = 1;
int motA1 = 5; 
int motB1 = 6; 
int motA2 = 9; 
int motB2 = 10; 
int vel = 0; 

void setup()                    
{
  Serial.begin(9600);           
  pinMode(motA1, OUTPUT);
  pinMode(motB1, OUTPUT);
  pinMode(motA2, OUTPUT);
  pinMode(motB2, OUTPUT);
}

void loop()
{
  
  if(Serial.available()){
    delay(1);
  while(Serial.available())
    {
      char inChar = Serial.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }
    while (Serial.available() > 0)  
    {  first = false;
      junk = Serial.read() ; }      // clear the serial buffer
      Stop();
    
   inputString.toUpperCase();

    if (inputString == "UP"){
      up();
    }else if (inputString == "DOWN"){
       down();
    }else if (inputString == "CENTER"){
       up();
    }else if (inputString == "LEFT" || inputString == "UPLEFT" || inputString == "DOWNLEFT"){
      left();
    }else if (inputString == "RIGHT" ||  inputString == "UPRIGHT" || inputString == "DOWNRIGHT"){
      right();
    }else if (inputString == "STOP"){
      Stop();
    }else if ((inputString.toInt()>=0)&&(inputString.toInt()<=255)){
      
       vel = inputString.toInt();
        
      if(motorDirection == 1){
        up();
     }
     if(motorDirection == 2){
        right();
      }
      if(motorDirection == 3){
        left();
      }
      if(motorDirection == 4){
      down();
    }
      }
  }
    inputString = "";
  }

  void up()
{
  analogWrite(motB2, 0); 
  analogWrite(motB1, 0); 
  analogWrite(motA2, vel); 
  analogWrite(motA1, vel);
  motorDirection = 1;
}

void right()
{
  analogWrite(motB2, vel); 
  analogWrite(motB1, 0); 
  analogWrite(motA2, 0); 
  analogWrite(motA1, vel);
  motorDirection = 2; 
}

void left()
{
 analogWrite(motB2, 0); 
  analogWrite(motB1, vel);
  analogWrite(motA1, 0);
  analogWrite(motA2, vel); 
  motorDirection = 3;
}

void down()
{
  analogWrite(motA2, 0); 
  analogWrite(motA1, 0);
  analogWrite(motB2, vel); 
  analogWrite(motB1, vel); 
  motorDirection = 4;
}


void Stop()
{
  analogWrite(motB2, 0); 
  analogWrite(motB1, 0); 
  analogWrite(motA2, 0); 
  analogWrite(motA1, 0); 
}
