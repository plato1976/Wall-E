//LCD Type: 0 for 16X2 LCD.
//          1 for Nokia 5510 LCD.

#define  LCDType            1  
#define  TempSensorType     0
#define  ServoArrayPin      [22,24,26,28,30,32];
#define  RTC                1
#define UARTConfig          0


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <Servo.h>         //Sevo 
#include <OneWire.h>
#include <LiquidCrystal.h>
#include <DS1302.h>
#include<SPI.h>
#include<Nokia5510LCD.h>
#include <Keypad.h>
#include <MotorControl.h>

/*--------------------定義 Servo--------------------*/ 
Servo  ServoRightX;
Servo  ServoRightY;
Servo  ServoRightWrist;
Servo  ServoLeftX;
Servo  ServoLeftY;
Servo  ServoLeftWrist;
Servo  ServoHead;

/*--------------------定義 LiquidCrystal--------------------*/ 
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

/*--------------------定義 Nokia5510LCD--------------------*/ 
Nokia5510LCD  LCD5510=Nokia5510LCD(44,42,40,38,36,34);

int RightAngleX=0, RightAngleY=0, RightAngleZ=0, LeftAngleX=0, LeftAngleY=0, LeftAngleZ=0, HeadAngle=0;

int  Init_RightHandX=0, Init_RightHandY=180, Init_RightHandZ=0,
     Init_LeftHandX=180, Init_LeftHandY=180, Init_LeftHandZ= 180,
     Init_Head=45 ;

int RightHandX=0, RightHandY=0, RightHandZ=0, LeftHandX=0, LeftHandY=0, LeftHandZ=0, Head=0;


/*--------------------定義 Keypad 的按鍵--------------------*/ 
// 3x4 Keypad
const byte ROWS = 4; // 4 Rows
const byte COLS = 3; // 3 Columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};

// 定義 Keypad 連到 Arduino 的 PWM 接腳
byte rowPins[ROWS] = {39, 37, 35, 33}; // 連到 Keypad 的 4 個 Rows: Row0, Row1, Row2, Row3 
byte colPins[COLS] = {45, 43, 41};   // 連到 Keypad 的 3 個 Columns: Column0, Column1, Column2

// 建立 Keypad 物件
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int DelayTime=200;

void setup() {
  SystemInitial();
  
  
}

void loop() {
  //SerialComPort();
  BTComPort();
  KeyPadMotion();
  //delay(500);

  
  
  
 

}


