/*************************************************************************
System initail config
Serial for Arduino default port
  baudrate: 115200
Serial2 for Bluetooth HS-6 module
  baudrate: 115200
Initial   
**************************************************************************/
void SystemInitial(){
  Serial.begin(115200);
  Serial2.begin(115200);
  Serial.println("Initial system.....");
  Serial2.println("Serial2 for Bluetooth initail.....");
  Serial.println("Setup Server pin define.");
  ServoRightX.attach(righthandx);
  ServoRightY.attach(righthandy);
  ServoRightWrist.attach(righthandwrist);
  ServoLeftX.attach(lefthandx);
  ServoLeftY.attach(lefthandy);
  ServoLeftWrist.attach(lefthandwrist);
  ServoHead.attach(head);
  ServoInitial();
  InitialRTC ();

  //MotorAInitial(2,3,4,5,6,7);  
  
#if LCDType == 0 
  lcd.begin(16, 2); 
  lcd.clear(); 
  lcd.setCursor(0,0);
  lcd.print("Initial system done");
#else  
  LCD5510.lcdBegin();
  LCD5510.clearDisplay();
  LCD5510.gotoXY(0,0);
  LCD5510.LcdString("Initial done");  
#endif
  delay(1000);
}
/*************************************************************************
*************************************************************************/
void ServoInitial(){
  Serial.println("Initial Server orignal degree.");
  RightHandX=RightAngleX+Init_RightHandX;
  RightHandY=Init_RightHandY-RightAngleY;
  RightHandZ=RightAngleZ+Init_RightHandZ;
  LeftHandX=Init_LeftHandX-LeftAngleX;
  LeftHandY=Init_LeftHandY-LeftAngleY;
  LeftHandZ=Init_LeftHandZ-LeftAngleZ;
  Head=Init_Head+HeadAngle;

  ServoRightX.write(Init_RightHandX);
  if (ServoRightX.read() == Init_RightHandX){
     Serial.println("ServoRightX ready.");  
    }
    else{
      Serial.println("ServoRightX not ready.");
      }

  ServoRightY.write(Init_RightHandY);
  if (ServoRightY.read() == Init_RightHandY){
     Serial.println("ServoRightY ready.");  
    }
    else {
      Serial.println("ServoRightY not ready."); 
      }

  ServoRightWrist.write(Init_RightHandZ);
  if (ServoRightWrist.read() == Init_RightHandZ){
     Serial.println("ServoRightWrist ready.");  
    }
    else {
      Serial.println("ServoRightWrist not ready.");  
      }
  
  ServoLeftX.write(Init_LeftHandX);
  if (ServoLeftX.read() == Init_LeftHandX){
     Serial.println("ServoLeftX ready.");  
    }
    else {
      Serial.println("ServoLeftX not ready.");
      }

  ServoLeftY.write(Init_LeftHandY);
  if (ServoLeftY.read() == Init_LeftHandY){
     Serial.println("ServoLeftY ready.");  
    }  
    else {
      Serial.println("ServoLeftY not ready."); 
      }

  ServoLeftWrist.write(Init_LeftHandZ);
  if (ServoLeftWrist.read() == Init_LeftHandZ){
     Serial.println("ServoLeftWrist ready.");  
    }   
    else {
      Serial.println("ServoLeftWrist ready."); 
      }
  ServoHead.write(Init_Head);
  if (ServoHead.read() == Init_Head){
     Serial.println("ServoLeftWrist ready.");  
    }   
    else {
      Serial.println("ServoLeftWrist ready."); 
      }
}
/*************************************************************************
*************************************************************************/
void LCDDisplayServo (){
  #if LCDType == 0
    RightHandX=ServoRightX.read() + Init_RightHandX;
    RightHandY=Init_RightHandY - ServoRightY.read();
    RightHandZ=Init_RightHandZ - ServoRightWrist.read();
    LeftHandX=Init_LeftHandX-ServoLeftX.read();
    LeftHandY=Init_LeftHandY-ServoLeftY.read();
    LeftHandZ=Init_LeftHandZ-ServoLeftWrist.read();
    Head=Init_Head+HeadAngle;
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Right X:");
    lcd.setCursor(8,1);
    lcd.print(RightHandX); 
    lcd.setCursor(11,1);
    lcd.print("Y:");
    lcd.setCursor(13,1);
    lcd.print(RightHandY);    

    lcd.setCursor(0,0);
    lcd.print("Left X:");
    lcd.setCursor(7,0);
    lcd.print(LeftHandX); 
    lcd.setCursor(11,0);
    lcd.print("Y:");
    lcd.setCursor(13,0);
    lcd.print(LeftHandY);   
  
  #else 
    char RHX[5],RHY[5],RHZ[5],LHX[5],LHY[5],LHZ[5],HeadChar[5];
    RightHandX=ServoRightX.read() + Init_RightHandX;
    RightHandY=Init_RightHandY - ServoRightY.read();
    RightHandZ=ServoRightWrist.read() - Init_RightHandZ;
    LeftHandX=Init_LeftHandX-ServoLeftX.read();
    LeftHandY=Init_LeftHandY-ServoLeftY.read();
    LeftHandZ=Init_LeftHandZ-ServoLeftWrist.read();
    Head=ServoHead.read()-Init_Head;
    
    LCD5510.gotoXY(0,0);
    LCD5510.LcdString("Right(X,Y,Z) ");
    LCD5510.gotoXY(0,1);
    LCD5510.LcdString("    ");
    LCD5510.gotoXY(0,1);
    LCD5510.LcdString(itoa(RightHandX,RHX,10));
    LCD5510.gotoXY(25,1);
    LCD5510.LcdString("    ");
    LCD5510.gotoXY(25,1);
    LCD5510.LcdString(itoa(RightHandY,RHY,10));
    LCD5510.gotoXY(50,1);
    LCD5510.LcdString("    ");
    LCD5510.gotoXY(50,1);
    LCD5510.LcdString(itoa(RightHandZ,RHZ,10));
    LCD5510.gotoXY(0,2);
    LCD5510.LcdString("Left(X,Y,Z) ");
    LCD5510.gotoXY(0,3);
    LCD5510.LcdString("    ");
    LCD5510.gotoXY(0,3);
    LCD5510.LcdString(itoa(LeftHandX,LHX,10));
    LCD5510.gotoXY(25,3);
    LCD5510.LcdString("    ");
    LCD5510.gotoXY(25,3);
    LCD5510.LcdString(itoa(LeftHandY,LHY,10));
    LCD5510.gotoXY(50,3);
    LCD5510.LcdString("    ");
    LCD5510.gotoXY(50,3);
    LCD5510.LcdString(itoa(LeftHandZ,LHZ,10));
    LCD5510.gotoXY(0,4);
    LCD5510.LcdString("Head:");
    LCD5510.gotoXY(35,4);  
    LCD5510.LcdString("    ");
    LCD5510.gotoXY(35,4); 
    LCD5510.LcdString(itoa(Head,HeadChar,10)); 
  #endif  

}
/*************************************************************************
*************************************************************************/
void ServoLog(){
  Serial.print("RightHand Angle(X,Y,Z): ");
  Serial.print(RightHandX);
  Serial.print(", ");
  Serial.print(RightHandY);
  Serial.print(", ");
  Serial.println(RightHandZ);
  Serial.print("LeftHand Angle(X,Y,Z): ");
  Serial.print(LeftHandX);
  Serial.print(", ");
  Serial.print(LeftHandY);
  Serial.print(", ");
  Serial.println(LeftHandZ);  
  Serial.print("Head Angle: ");
  Serial.println(ServoHead.read());
}

