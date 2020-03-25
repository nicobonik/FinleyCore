#include <Esplora.h>

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(2000000);
  Serial.begin(2000000);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  
  int joystickX = Esplora.readJoystickX() + 512;
  byte xByte[2];
  xByte[0] = joystickX/256;
  xByte[1] = joystickX%256;
  Serial1.write(xByte, 2);
  Serial.print(joystickX - 512);
  Serial.print(", ");

  int joystickY = Esplora.readJoystickY() + 512;
  byte yByte[2];
  yByte[0] = joystickY/256;
  yByte[1] = joystickY%256;
  Serial1.write(yByte, 2);
  Serial.print(joystickY - 512);
  Serial.print(", ");

//  int slider = Esplora.readSlider();
//  byte sliderByte[2];
//  sliderByte[0] = slider/256;
//  sliderByte[1] = slider%256;
//  Serial1.write(sliderByte, 2);
//  Serial.print(slider);
//  Serial.print(", ");
//
//
//  int upButton = Esplora.readButton(SWITCH_UP);
//  if(upButton == LOW) {
//    Serial1.write(1);
//    Serial.print(1);
//    Serial.println();  
//  } else{
//    Serial1.write(0);
//    Serial.print(0);
//    Serial.println();
//  }

  int comOnline = Serial1.read();

  if(comOnline >= 1){
    Esplora.writeRGB(0, 5, 0);
  } else{
    Esplora.writeRGB(255, 0, 0);  
  }
  
  delay(20);
}