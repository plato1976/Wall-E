//LCD Type: 0 for 16X2 LCD; 1 for Nokia 5510LCD

#define  LCDType            1  
#define  TempSensorType     0
#define  ServoArrayPin      [22,24,26,28,30,32];
#define  RTC                1
#define UARTConfig          0
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <Servo.h> 
#include <OneWire.h>
#include <LiquidCrystal.h>
#include <ButtonKey.h>
#include <DS1302.h>
#include<SPI.h>
#include<Nokia5510LCD.h>

Servo  ServoRightX;
Servo  ServoRightY;
Servo  ServoRightWrist;
Servo  ServoLeftX;
Servo  ServoLeftY;
Servo  ServoLeftWrist;
Servo  ServoHead;

ButtonKey buttonkey(0);  //adc-in pin = 0

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

Nokia5510LCD  LCD5510=Nokia5510LCD(44,42,40,38,36,34);

int RightAngleX=0, RightAngleY=0, RightAngleZ=0, LeftAngleX=0, LeftAngleY=0, LeftAngleZ=0, HeadAngle=0;

int  Init_RightHandX=0, Init_RightHandY=180, Init_RightHandZ=0,
     Init_LeftHandX=180, Init_LeftHandY=180, Init_LeftHandZ= 180,
     Init_Head=45 ;

int RightHandX=0, RightHandY=0, RightHandZ=0, LeftHandX=0, LeftHandY=0, LeftHandZ=0, Head=0;

int DelayTime=2000;
void setup() {

  Serial.begin(115200);
  Serial.println("Initial system.....");
  
  Serial2.begin(115200);


  lcd.begin(16, 2); 
  delay(50);
  
  LCD5510.lcdBegin();
  LCD5510.clearDisplay();
  
  ServoRightX.attach(46);
  ServoRightY.attach(48);
  ServoRightWrist.attach(50);
  ServoLeftX.attach(47);
  ServoLeftY.attach(49);
  ServoLeftWrist.attach(51);
  ServoHead.attach(52);

  ServoInitial();


  delay(1000);
 
  Serial.println("Initial system done");
  lcd.setCursor(0,0);
  lcd.print("Initial system done");
  lcd.clear();  

  
  
}

void loop() {
  ComPort();
  HeadTest();
  Motion_1();
  Motion_2();
 Hello();

}


