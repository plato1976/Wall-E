/*************************************************************************
Wall E program for Arduino Mega 2560 development board 
**************************************************************************/
/*************************************************************************
LCD Type define
  0 for 16X2 LCD.
  1 for Nokia 5510 LCD.
Tempture sensor type
**************************************************************************/
#define  LCDType            1  
#define  TempSensorType     0

/*************************************************************************
Nokia 5510 LCD Display pin define
  SCE    Chip select
  RST    Reset
  DC     Mode select-Select between command mode (low) and data mode (high).
  DN     Serial data in
  CLK    Serial clock
  BL     LED backlight supply
**************************************************************************/
#define NokiaSCE            44
#define NokiaRST            42
#define NokiaDC             40
#define NokiaDN             38
#define NokiaCLK            36
#define NokiaBL             34

/*************************************************************************
Motor driver pin define
------------------------Motor control A-----------------------------------
  MotorARightEn
  MotorAIN1
  MotorAIN2
  MotorAIN3
  MotorAIN4
  MotorALeftEn
------------------------Motor control B-----------------------------------
  MotorBRightEn
  MotorBIN1
  MotorBIN2
  MotorBIN3
  MotorBIN4
  MotorBLeftEn
**************************************************************************/
#define MotorARightEn       6
#define MotorAIN1           2
#define MotorAIN2           3
#define MotorAIN3           4
#define MotorAIN4           5
#define MotorALeftEn        7

/*************************************************************************
DS1302 RTC pin define
  CE / RST      Chip select
  IO / DAT      Data
  SCLK / CLK    Serial clock
  
  
  CE_PIN, IO_PIN, SCLK_PIN
**************************************************************************/
#define  CE_PIN    22
#define  IO_PIN    23
#define  SCLK_PIN  24

/*************************************************************************
Servo pin define
**************************************************************************/
#define  righthandx  46
#define  righthandy  48
#define  righthandwrist  50
#define  lefthandx  47
#define  lefthandy  49
#define  lefthandwrist  51
#define  head   52

/*************************************************************************
Bluetooth module UART pin define
**************************************************************************/
//#define  BT_Tx  16
//#define  BT_Rx  17

/*************************************************************************
LED Matrix pin define
**************************************************************************/
#define  Matrix_Number   1
#define  Matrix_DataIn   25
#define  Matrix_CLK      29
#define  Matrix_CS       27


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <Servo.h>         //Sevo 
#include <OneWire.h>
#include <LiquidCrystal.h>
#include <DS1302.h>
#include <SPI.h>
#include <Nokia5510LCD.h>
#include <Keypad.h>
#include <MotorControl.h>
#include "LedControl.h"

/*************************************************************************
Define Servo Fuction
**************************************************************************/
Servo  ServoRightX;
Servo  ServoRightY;
Servo  ServoRightWrist;
Servo  ServoLeftX;
Servo  ServoLeftY;
Servo  ServoLeftWrist;
Servo  ServoHead;

int RightAngleX=0, RightAngleY=0, RightAngleZ=0, LeftAngleX=0, LeftAngleY=0, LeftAngleZ=0, HeadAngle=0;

int  Init_RightHandX=0, Init_RightHandY=180, Init_RightHandZ=0,
     Init_LeftHandX=180, Init_LeftHandY=180, Init_LeftHandZ= 180,
     Init_Head=45 ;

int RightHandX=0, RightHandY=0, RightHandZ=0, LeftHandX=0, LeftHandY=0, LeftHandZ=0, Head=0;

/*************************************************************************
Define Liquid Crystal Display
**************************************************************************/
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

/*************************************************************************
Define Nokia 5510 LCD function
**************************************************************************/
Nokia5510LCD  LCD5510=Nokia5510LCD(NokiaSCE, NokiaRST, NokiaDC,NokiaDN, NokiaCLK, NokiaBL);;

/*************************************************************************
Define Keypad Function
**************************************************************************/ 
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

/*************************************************************************
Define MotorControl Function
**************************************************************************/ 
MotorControl  MotorA=MotorControl(MotorARightEn,MotorALeftEn, MotorAIN1, MotorAIN2, MotorAIN3, MotorAIN4);

/*************************************************************************
Define DS1302 Function
**************************************************************************/ 
char RTCbuf[50];
char RTCday[10];
DS1302 rtc(CE_PIN, IO_PIN, SCLK_PIN);

/*************************************************************************
Define LED Matrix Function
**************************************************************************/
LedControl LED_Matrix = LedControl(Matrix_DataIn, Matrix_CLK, Matrix_CS, Matrix_Number);

/*************************************************************************
**************************************************************************/
int DelayTime=200;

void setup() {
  SystemInitial();
  
  
}

void loop() {
  //SerialComPort();
  //BTComPort();
  //KeyPadMotion();
  //delay(500);
  //MotorTest();
  PrintTime();
  delay(1000);
  
  
 

}


