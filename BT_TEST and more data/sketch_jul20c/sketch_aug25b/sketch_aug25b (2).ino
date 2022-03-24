// set pin numbers joystick axes
const int xAxis = A0;         // joystick X axis 
const int yAxis = A1;         // joystick Y axis

int responseDelay = 50;        // response delay of the mouse, in ms
const int centerValue = 512;
const int range = 200;
const int upperBond = centerValue + range;
const int lowerBond = centerValue - range;

// RGB LED brightness
byte red = 0;
byte green = 0;
byte blue = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read the two axes:
  int xReading = readAxis(A0);
  int yReading = readAxis(A1);

  // Trigger when the joystick aren't in the center
  if( xReading != 0 || yReading != 0 ) {
    // Red color
    if(xReading == 1 && yReading == 0 && red < 255) red += 5;
    if(xReading == -1 && yReading == 0 && red > 0) red -= 5;

    // Green color
    if(xReading == -1 && yReading == 1 && green < 255) green += 5;
    if(xReading == 1 && yReading == -1 && green > 0) green -= 5;

    // Blue color
    if(xReading == 0 && yReading == 1 && blue < 255) blue += 5;
    if(xReading == 0 && yReading == -1 && blue > 0) blue -= 5;

    // all color
    if(xReading == 1 && yReading == 1 ) {
      if( red < 255 ) red += 5;
      if( green < 255 ) green += 5;
      if( blue < 255) blue += 5; 
    }
    if(xReading == -1 && yReading == -1) {
      if( red > 0 ) red -= 5; 
      if( green > 0 ) green -= 5; 
      if( blue > 0 ) blue -= 5;
    }

    byte value[3] = {(byte)red, (byte)green, (byte)blue};
    Serial.write(value, 3);
    Serial.flush();
  }

  delay(responseDelay);
}

/*
 * Determin increment or decrement
 * 1: increment
 * 0: nothing happen
 * -1: decrement
 */
int readAxis(int thisAxis) {
  // read the analog input:
  int reading = analogRead(thisAxis);
  if( reading > upperBond )
    return 1;
  else if( reading < lowerBond )
    return -1;
  else
    return 0;
}
