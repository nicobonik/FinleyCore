double robotX = 10;
double robotY = 0;
double theta = 0;

void setup(){
  
  Serial.begin(2000000);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){
  connectToEsplora(4);
  int r = random(0, 200);

  if(r < 100) {
    theta += 0.01;
  } else {
    theta -= 0.01;
  }
  
  theta += 0.01;

  robotX = 100 * cos(theta);
  robotY = 100 * sin(theta);

  //loop code here
//  delay(5);
  
}

int getIntFromSerial(){

  int intArray[2];
  intArray[0] = Serial.read();
  intArray[1] = Serial.read();

  return intArray[0]*256+intArray[1];
  
}

boolean getBoolFromSerial(){
  
  int i = Serial.read();

  if(i == 0){
    return false;  
  } else {
    return true;  
  }
  
}

void connectToEsplora(int byteNum){
  
  while(!(Serial.available() >= byteNum)) {
    digitalWrite(LED_BUILTIN, LOW);  
  }
  digitalWrite(LED_BUILTIN, HIGH);
  
  int joystickX = getIntFromSerial() - 512;
//  Serial.print("x: ");
  Serial.print(joystickX);

  int joystickY = getIntFromSerial() - 512;
  Serial.print(", ");
  Serial.print(joystickY);

  Serial.print(", ");
  Serial.print(robotX);
  Serial.print(", ");
  Serial.print(robotY);

  Serial.print(", ");
  Serial.print(theta);

//  int slider = getIntFromSerial();
//  Serial.print(", ");
//  Serial.print(slider);
//
//  boolean upButton = getBoolFromSerial();
//  Serial.print(", ");
//  Serial.print(upButton);

  Serial.println();
  
}