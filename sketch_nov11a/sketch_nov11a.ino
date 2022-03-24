#include <SoftwareSerial.h>
#include <Servo.h> 
Servo base;         //Create an object servo base
Servo shoulder;     //Create an object servo shoulder
Servo elbow;        //Create an object servo elbow
Servo gripper;      //Create an object servo gripper

char ServoID;                 //Variable for Servo ID
int hasilButton;              //Variable button pressed results
int nilaiBase;                //Variable servo base value
int nilaiShoulder;            //Variable servo Shoulder value
int nilaiElbow;               //Variable servo Elbow value
int nilaiGripper;             //Variable servo Gripper value 
const int increment = 5;      //Increase degree (B+, S+, E+, G+)
const int decrement = 5;      //Decrease degree (B-, S-, E-, G-)
String readString;            //Read string values
SoftwareSerial BT(12,13);     //Bluetooth RX TX on pins 12 and 13

void setup() {
  Serial.begin(9600);     //Set the Serial Baudrate 9600
  BT.begin(9600);        //Set Baudrate Bluetooth accordance with your bluetooth module
  pinMode(13,OUTPUT);  //Set pin 13 as output
  
  base.attach(6);         //Set the servo base of the pin 6
  shoulder.attach(9);     //Set the servo shoulder of the pin 9
  elbow.attach(11);        //Set the servo elbow of the pin 11
  gripper.attach(10);
  //Set the servo gripper of the pin 10
  base.write(90);         //Start positioning servo base to 90 degrees
  shoulder.write(90);     //Start positioning servo shoulder to 90 degrees
  elbow.write(90);        //Start positioning servo elbow to 90 degrees
  gripper.write(90);      //Start positioning servo gripper to 90 degrees
}

void loop() {
  if (BT.available()) {      //If bluetooth available
  Serial.println("BT available");
    hasilButton = BT.read();              //Set hasilButton = Bluetooth Read
      Serial.println("BT hasilButton " + hasilButton);

    ServoID = BT.read();                  //Set ServoID = Bluetooth Read
      Serial.println("BT ServoID " + ServoID);

    base.write(nilaiBase);                //Set the degree of servo according nilaiBase
    shoulder.write(nilaiShoulder);        //Set the degree of servo according nilaiShoulder
    elbow.write(nilaiElbow);              //Set the degree of servo according nilaiElbow
    gripper.write(nilaiGripper);          //Set the degree of servo according nilaiGripped

    if(hasilButton == 'X'){               //If the button = X (X can customize the application MeArm Controller)
      digitalWrite(13, LOW);              //Turn off the led on pin 13
    }
    if(hasilButton == 'Z'){               //If the button = Z (Z can customize the application MeArm Controller)
      digitalWrite(13, HIGH);             //Turn on the led on pin 13
    }
    if(hasilButton == 'a'){               //If the button = a (a can customize the application MeArm Controller)
      nilaiBase-=decrement;               //Servo base value - value decrement
    }
    else if(hasilButton == 'A'){          //If the button = A (A can customize the application MeArm Controller)
      nilaiBase+=increment;               //Servo base value + value increment
    }
    if(hasilButton == 's'){               //If the button = s (s can customize the application MeArm Controller)
      nilaiShoulder-=decrement;           //Servo base shoulder - value decrement
    }
    else if(hasilButton == 'S'){          //If the button = S (S can customize the application MeArm Controller)
      nilaiShoulder+=increment;           //Servo shoulder value + value increment
    }
    if(hasilButton == 'e'){               //If the button = e (e can customize the application MeArm Controller)
      nilaiElbow-=decrement;              //Servo base elbow - value decrement
    }
    else if(hasilButton == 'E'){          //If the button = E (E can customize the application MeArm Controller)
      nilaiElbow+=increment;              //Servo shoulder value + value increment
    }
    if(hasilButton == 'g'){               //If the button = g (g can customize the application MeArm Controller)
      nilaiGripper-=decrement;            //Servo base gripper - value decrement
    }
    else if(hasilButton == 'G'){          //If the button = G (G can customize the application MeArm Controller)
      nilaiGripper+=increment;            //Servo gripper value + value increment
    }
      
    if(ServoID=='1'){                     //If ServoID = 1 
      baseServo_slider();                 //Call subroutine baseServo_slider
    }
    
    if(ServoID=='2'){                     //If ServoID = 2
      shoulderServo_slider();             //Call subroutine shoulderServo_slider
    }
    
    if(ServoID=='3'){                     //If ServoID = 3
      elbowServo_slider();                //Call subroutine elbowServo_slider
    }
    if(ServoID=='4'){                     //If ServoID = 4
      gripperServo_slider();              //Call subroutine gripperServo_slider
    }
  }  
}
  
void baseServo_slider(){
        delayMicroseconds(300);   
        while (BT.available()) {             
          char c = BT.read();
          readString += c;
        }
        if (readString.length() >0) {
          Serial.print("Base : ");
          Serial.println(readString.toInt());
          nilaiBase = (readString.toInt());         //nilaiBase = readString from android
          base.write(readString.toInt());           //Set the degree of servo base according to the value ReadString
          readString="";
        }
}

void shoulderServo_slider(){
        delayMicroseconds(300); 
        while (BT.available()) { 
          char c = BT.read();  
          readString += c;         
        }
        if (readString.length() >0) { 
          Serial.print("Shoulder : ");
          Serial.println(readString.toInt()); 
          nilaiShoulder = (readString.toInt());    //nilaiShoulder = readString from android
          shoulder.write(readString.toInt());      //Set the degree of servo shoulder according to the value ReadString
          readString=""; 
        } 
}

void elbowServo_slider(){
        delayMicroseconds(300); 
        while (BT.available()) { 
          char c = BT.read();  
          readString += c;        
        }
        if (readString.length() >0) { 
          Serial.print("Elbow : ");
          Serial.println(readString.toInt());  
          nilaiElbow = (readString.toInt());     //nilaiElbow = readString from android
          elbow.write(readString.toInt());       //Set the degree of servo elbow according to the value ReadString
          readString=""; 
        } 
}

void gripperServo_slider(){
        delayMicroseconds(300); 
        while (BT.available()) { 
          char c = BT.read();  
          readString += c;        
        }
        if (readString.length() >0) {
          Serial.print("Gripper : "); 
          Serial.println(readString.toInt());
          nilaiGripper = (readString.toInt());     //nilaiGripper = readString from android  
          gripper.write(readString.toInt());       //Set the degree of servo gripper according to the value ReadString
          readString=""; 
        } 
}
