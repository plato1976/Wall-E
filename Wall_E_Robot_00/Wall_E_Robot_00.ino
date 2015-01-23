#define  LCDType            0  
#define  TempSensorType     0
#define  KeyPadPin          0


#include <string.h>
#include <math.h>
#include <Servo.h> 
#include <OneWire.h>
#include <LiquidCrystal.h>
#include <BottonKey.h>



Servo  RightArmVertical;
Servo  RightArmHorizontal;
Servo  RightWrist;
Servo  LeftArmVertical;
Servo  LeftArmHorizontal;
Servo  LeftWrist;

//BottonKey  KP;

int pos = 0; 

void setup() {
  Serial.begin(115200);
  Serial.println("Initial System");
  //KeyPad.KeyuncSet(KeyPadPin);

}

void loop() {

  
}
