/*
Created by Cubetastic on 3.8.2017. Program that generates scrambles, counts inspection time, and times your solves.
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <CapacitiveSensor.h>//include the capacaitive sensor library
#include <EEPROM.h>//include library for storing and reading stuff in EEPROM

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);//include the LiquidCrystal library//initialize the lcd
CapacitiveSensor   touch1 = CapacitiveSensor(10, 3);//initialize the first touch sensor
CapacitiveSensor   touch2 = CapacitiveSensor(10, 7);//initialize the second touch sensor

int led1 = 13;//red led connected to pin 13
int led2 = 9;//green led connected to pin 9
int button1 = 8;//push button connected to pin 8, used for scrambling
int button2 = A1;//push button connected to pin A1, used for inspection
int buttonTimer = 0;//variable to count how long the button has been pressed
int callNotation = 0;//variable to call the notations from the array
int selected = 0;//variable to keep track of the selected option
int printed = 0;//variable to count the number of notations printed
int charUsed = 0;//variable to count the number of characters printed
int countdown = 16;
int limit = 0;
int count = 0;
long delayMs = 0;
boolean led2State = HIGH;//boolean to change the state of the led for blinking
boolean longPress = false;
boolean inspection;
boolean inspectionOk = true;
boolean timerOk = true;
boolean lineShifted = false;
String notation;
String verify;
String lastVerify;
String lastVerify2;
String lastVerify3;

char* notations1or2[18] = {"F", "F'", "F2", "B", "B'", "B2", "R", "R'", "R2", "L", "L'", "L2", "U", "U'", "U2", "D", "D'", "D2"};
                         // 0,   1,    2,    3,   4,    5,    6,   7,    8,    9,   10,   11,  12,   13,   14,  15,   16,   17
char* notations3[18] = {"f", "f'", "f2", "b", "b'", "b2", "r", "r'", "r2", "l", "l'", "l2", "u", "u'", "u2", "d", "d'", "d2"};
                      // 0,   1,    2,    3,   4,    5,    6,   7,    8,    9,   10,   11,  12,   13,   14,  15,   16,   17
char* notations4a[8] = {"R", "R'", "L", "L'", "U", "U'", "B", "B'"};
                      // 0,   1,    2,   3,    4,   5,    6,   7
char* notations4b[8] = {"r", "r'", "l", "l'", "u", "u'", "b", "b'"};
                      // 0,   1,    2,   3,    4,   5,    6,   7
String scramble[21];

//timer variables
long initialTime = 0;
long prevTime = 0;
int runMilliseconds = 0;
int runSeconds = 0;
int runMinutes = 0;
boolean firstTime = true;

void setup() {
  touch1.set_CS_AutocaL_Millis(0xFFFFFFFF);//turn off autocalibrate on channel 1 - just as an example
  lcd.begin (16, 2);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (button1, INPUT_PULLUP);
  pinMode (button2, INPUT_PULLUP);
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

int trueRandom(int num) {
  int x = random(num);
  int y = random(num);
  int z = random(num);
  int r = ((((x+y+z)*(x-y-z))-((x+y)*(y-z)))%num);
  return abs(r);
}

int lcdPrint() {
  char buf[13];
  sprintf(buf, "%2d:%02d.%02d", runMinutes, runSeconds, runMilliseconds);
  lcd.setCursor(0, 0);
  lcd.print(buf);
}

int timer() {
  long functionTime = millis()-initialTime;
  long allSeconds = functionTime/1000;
  long milliseconds = functionTime/10;
  long seconds = allSeconds%3600;
  runMinutes = seconds/60;
  runSeconds = seconds%60;
  runMilliseconds = milliseconds%100;
  if ((millis() - prevTime) >= 200) {
    led2State =! led2State;
    digitalWrite(led2, led2State);
    prevTime = millis();
  }
  lcdPrint();
}

int verify123() {
  verify = notation.substring(0, 1);
  if (verify == lastVerify) {//if something like FF, F'F', F2F2, FF', F'F, FF2 or F2F is generated
    if (callNotation <= 11) {
      callNotation = 13;
    }
    else {
      callNotation = 6;
    }
  }
  else if ((((lastVerify=="B") && (lastVerify2=="F")) || ((lastVerify=="F") && (lastVerify2=="B")) || ((lastVerify=="R") && (lastVerify2=="L")) || ((lastVerify=="L") && (lastVerify2=="R")) || ((lastVerify=="U") && (lastVerify2=="D")) || ((lastVerify=="D") && (lastVerify2=="U"))) && (lastVerify2 == verify)) {
    if (callNotation <= 11) {
      callNotation = 13;
    }
    else {
      callNotation = 6;
    }
  }
  else if ((((lastVerify=="b") && (lastVerify2=="f")) || ((lastVerify=="f") && (lastVerify2=="b")) || ((lastVerify=="r") && (lastVerify2=="l")) || ((lastVerify=="l") && (lastVerify2=="r")) || ((lastVerify=="u") && (lastVerify2=="d")) || ((lastVerify=="d") && (lastVerify2=="u"))) && (lastVerify2 == verify)) {
    if (callNotation <= 11) {
      callNotation = 13;
    }
    else {
      callNotation = 6;
    }
  }
  if (charUsed == 0) {
    lcd.clear();
  }
  if ((charUsed == 15) || (charUsed == 16)) {//if 16 spaces have been used and the next notation cannot be printed properly
    lcd.setCursor(0, 1);
  }
}

int verify4a() {
  notation = notations4a[callNotation];
  verify = notation.substring(0, 1);
  if (verify == lastVerify) {//if something like RR, R'R', RR', or R'R is generated
    if (callNotation <= 5) {
      callNotation = 6;
    }
    else {
      callNotation = 4;
    }
  }
  if (charUsed == 0) {
    lcd.clear();
  }
  if ((charUsed == 15) || (charUsed == 16)) {//if 16 spaces have been used and the next notation cannot be printed properly
    lcd.setCursor(0, 1);
    lineShifted = true;
  }
  notation = notations4a[callNotation];
}

int verify4b() {
  notation = notations4b[callNotation];
  verify = notation.substring(0, 1);
  if ((verify == lastVerify) || (verify == lastVerify2) || (verify == lastVerify3)) {
    if (callNotation <= 5) {
      callNotation = 6;
    }
    else {
      callNotation = 4;
    }
  }
  if (((charUsed == 15) || (charUsed == 16)) && (lineShifted == false)) {//if 16 spaces have been used and the next notation cannot be printed properly
    lcd.setCursor(0, 1);
  }
  verify = notation.substring(0, 1);
}

int characters(int divisor) {
  if (callNotation%divisor == 0) {
    charUsed = charUsed + 1;
  }
  else if ((callNotation%divisor == 1) || (callNotation%divisor == 2)) {
    charUsed = charUsed + 2;
  }
}

int print1or2() {
  if (printed == limit) {
    delay(delayMs);
    lcd.clear();
    selected = 0;
    buttonTimer = 0;
    printed = 0;
    charUsed = 0;
    longPress = false;
  }
  callNotation = trueRandom(18);//generates a random number
  notation = notations1or2[callNotation];
  verify123();
  notation = notations1or2[callNotation];
  verify123();
  notation = notations1or2[callNotation];
  lcd.print(notation);
  Serial.print(notation);
  characters(3);
  scramble[count] = notation;
  count++;
  lastVerify2 = lastVerify;
  lastVerify = verify;
  printed++;
}

void loop() {
  while (digitalRead(button2) == LOW) {
    inspection = EEPROM.read(256);
    inspection =! inspection;
    EEPROM.write(256, inspection);
    lcd.setCursor(0, 0);
    lcd.print("inspection:");
    lcd.setCursor(0, 1);
    if (EEPROM.read(256) == 1) {
      lcd.print("on");
      delay(1000);
    }
    if (EEPROM.read(256) == 0) {
      lcd.print("off");
      delay(1000);
    }
    lcd.clear();
    break;
  }
  while (digitalRead(button1) == LOW) {//While button is pressed, buttonTimer increases by 10 every 10 ms
    delay(10);
    buttonTimer = buttonTimer + 10;
  }
  if (buttonTimer < 1000 && buttonTimer != 0) {//if button was pressed shortly, increments selected variable by 1
    selected++;
    longPress = false;
    lcd.clear();
    buttonTimer = 0;
  }
  else if (buttonTimer > 1000) {//if button was pressed for a long time, makes the longPress variable true
    longPress = true;
    lcd.clear();
    buttonTimer = 0;
  }
  if (longPress == false) {
    if (selected == 0) {
      lcdPrint();
      if ((touch1.capacitiveSensor(30) > 1) && (touch2.capacitiveSensor(30) > 1)) {
        digitalWrite (led1, HIGH);
        long startTime = millis();
        while ((touch1.capacitiveSensor(30) > 1) && (touch2.capacitiveSensor(30) > 1)) {
          if ((millis()-startTime) >= 700) {
            digitalWrite (led2, HIGH);
          }
        }
        while ((millis()-startTime) >= 700) {
          while ((EEPROM.read(256) == 1) && (inspectionOk == true)) {
            countdown--;
            lcd.clear();
            lcd.print(countdown);
            led2State =! led2State;
            digitalWrite (led2, led2State);
            delay(1000);
            while ((countdown == 1) || ((touch1.capacitiveSensor(30) > 1) && (touch2.capacitiveSensor(30) > 1))) {
              digitalWrite (led2, HIGH);
              inspectionOk = false;
              countdown = 0;
            }
          }
          while (timerOk == true) {
            if (firstTime == true) {
              initialTime = millis();
              firstTime = false;
            }
            timer();
            if ((touch1.capacitiveSensor(30) > 1) && (touch2.capacitiveSensor(30) > 1)) {
              timerOk = false;
            }
          }
          lcdPrint();
          digitalWrite (led2, LOW);
          while ((touch1.capacitiveSensor(30) > 1) && (touch2.capacitiveSensor(30) > 1)) {
            digitalWrite (led1, HIGH);
          }
          digitalWrite (led1, LOW);
          if (digitalRead(button1) == LOW) {
            lcd.clear();
            charUsed = 0;
            for (size_t i = 0; i <= limit; i++) {
              if ((charUsed == 15) || (charUsed == 16)) {
                lcd.setCursor(0, 1);
              }
              notation = scramble[i];
              Serial.print(notation);
              lcd.print(notation);
              if (notation.length() == 1) {
                charUsed = charUsed + 1;
              }
              if (notation.length() == 2) {
                charUsed = charUsed + 2;
              }
            }
            delay(4000);
            lcd.clear();
          }
        }
      }
      digitalWrite (led1, LOW);
      digitalWrite (led2, LOW);
    }
    if (selected == 1) {//If the button is pressed one time, it displays "3x3x3"
      limit = 20;
      delayMs = 55000;
      lcd.setCursor(0, 0);
      lcd.print("3x3x3");
    }
    if (selected == 2) {//If the button is pressed two times, it displays "2x2x2"
      limit = 10;
      delayMs = 55000;
      lcd.setCursor(0, 0);
      lcd.print("2x2x2");
    }
    if (selected == 3) {//If the button is pressed three times, it displays "3x3x3 bld"
      limit = 20;
      lcd.setCursor(0, 0);
      lcd.print("3x3x3 bld");
    }
    if (selected == 4) {//If the button is pressed four times, it displays "Pyraminx"
      limit = 14;
      lcd.setCursor(0, 0);
      lcd.print("Pyraminx");
    }
    else if (selected > 4) {
      selected = 1;
    }
  }
  else if (longPress == true) {
    if (((selected == 1) || (selected == 2)) && (printed <= limit)) {
      print1or2();
    }
    if (selected == 3 && printed <= limit) {
      if (printed <= 18) {
        callNotation = trueRandom(18);//generates a random number
        notation = notations1or2[callNotation];
        verify123();
        notation = notations1or2[callNotation];
        verify123();
        notation = notations1or2[callNotation];
        lcd.print(notation);
        Serial.print(notation);
        characters(3);
        scramble[count] = notation;
        count++;
        lastVerify2 = lastVerify;
        lastVerify = verify;
        printed++;
      }
      else if (printed > 18) {
        if (printed == limit) {
          delay(55000);
          lcd.clear();
          selected = 0;
          buttonTimer = 0;
          printed = 0;
          charUsed = 0;
          longPress = false;
        }
        callNotation = trueRandom(18);//generates a random number
        notation = notations3[callNotation];
        verify123();
        notation = notations3[callNotation];
        verify123();
        notation = notations3[callNotation];
        lcd.print(notation);
        Serial.print(notation);
        scramble[count] = notation;
        count++;
        lastVerify = verify;
        printed++;
      }
    }
    if ((selected == 4) && (printed <= limit)) {
      if (printed <= 9) {
        callNotation = trueRandom(8);//generates a random number
        verify4a();
        verify4a();
        lcd.print(notation);
        Serial.print(notation);
        characters(2);
        scramble[count] = notation;
        count++;
        lastVerify = verify;
        printed++;
      }
      else if (printed > 9) {
        if (printed == limit) {
          delay(55000);
          lcd.clear();
          selected = 0;
          buttonTimer = 0;
          printed = 0;
          charUsed = 0;
          longPress = false;
        }
        callNotation = trueRandom(8);//generates a random number
        verify4b();
        verify4b();
        lcd.print(notation);
        characters(2);
        scramble[count] = notation;
        count++;
        lastVerify3 = lastVerify2;
        lastVerify2 = lastVerify;
        lastVerify = verify;
        printed++;
      }
    }
  }
}
