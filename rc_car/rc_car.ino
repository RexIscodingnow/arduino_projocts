#include <AFMotor.h>
String inputString="";
boolean first = true; 
char command;
char junk;
int vel = 0; 
int motorDirection = 1;

//creates two objects to control the terminal 3 and 4 of motor shield 
AF_DCMotor motor1(3); 
AF_DCMotor motor2(4); 
 

void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module. (230400 is much better)
}

void loop(){
  if(Serial.available() > 0){ 
    delay(10);// chage to delay(1); if 230400 baudrate used.
     while(Serial.available())
    {
      char command = Serial.read(); //read the input
      inputString += command;        //make a string of the characters coming on serial
    }
    while (Serial.available() > 0)  
    {  first = false;
      junk = Serial.read() ; }      // clear the serial buffer 

      Stop();
      inputString.toUpperCase();
      Serial.println(inputString);
      
  
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
  motor1.setSpeed(vel); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(vel); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motorDirection = 1;
}

void right()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE); //turn motor1 off
  motor2.setSpeed(vel); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motorDirection = 2;
}

void left()
{
  motor1.setSpeed(vel); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(0);
  motor2.run(RELEASE); //turn motor2 off
  motorDirection = 3;
}

void down()
{
  motor1.setSpeed(vel); 
  motor1.run(BACKWARD); //rotate the motor counterclockwise
  motor2.setSpeed(vel); 
  motor2.run(BACKWARD); //rotate the motor counterclockwise
  motorDirection = 4;
}

void Stop()
{
  motor1.setSpeed(0);
  motor2.run(RELEASE); //turn motor1 off
  motor2.setSpeed(0);
  motor2.run(RELEASE); //turn motor2 off
}
