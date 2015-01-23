void ServoInitial(){

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
  char RHX[5],RHY[5],RHZ[5],LHX[5],LHY[5],LHZ[5],Heada[5];
  RightHandX=ServoRightX.read() + Init_RightHandX;
  RightHandY=Init_RightHandY - ServoRightY.read();
  RightHandZ=ServoRightWrist.read() - Init_RightHandZ;
  LeftHandX=Init_LeftHandX-ServoLeftX.read();
  LeftHandY=Init_LeftHandY-ServoLeftY.read();
  LeftHandZ=Init_LeftHandZ-ServoLeftWrist.read();
  Head=ServoHead.read()-Init_Head;
  
  //LCD5510.updateDisplay();
    
  LCD5510.gotoXY(0,0);
  LCD5510.LcdString("Right(X,Y,Z) ");
  LCD5510.gotoXY(0,1);
  LCD5510.LcdString(itoa(RightHandX,RHX,10));
  LCD5510.gotoXY(25,1);
  LCD5510.LcdString(itoa(RightHandY,RHY,10));
  LCD5510.gotoXY(50,1);
  LCD5510.LcdString(itoa(RightHandZ,RHZ,10));
  LCD5510.gotoXY(0,2);
  LCD5510.LcdString("Left(X,Y,Z) ");
  LCD5510.gotoXY(0,3);
  LCD5510.LcdString(itoa(LeftHandX,LHX,10));
  LCD5510.gotoXY(25,3);
  LCD5510.LcdString(itoa(LeftHandY,LHY,10));
  LCD5510.gotoXY(50,3);
  LCD5510.LcdString(itoa(LeftHandZ,LHZ,10));
  LCD5510.gotoXY(0,4);
  LCD5510.LcdString("Head:");
  LCD5510.gotoXY(35,4);  
  LCD5510.LcdString(itoa(Head,Heada,10)); 
  #endif  

}

void KeyPadIn(){
  // 讀取 Keypad 的輸入
  char key = keypad.getKey();
  
  // NO_KEY 代表沒有按鍵被按下
  if (key != NO_KEY){
    // 假如有按鍵被按下，就印出按鍵對應的字元
    Serial.println(key);
    }
}

void KeyPadMotion(){
  char key = keypad.getKey();
  //char *Keyaa=key;
  LCD5510.gotoXY(0,5);  
  LCD5510.LcdString("KeyPadIn: ");  
  LCD5510.gotoXY(65,5);  
  //LCD5510.LcdString(Key);
  Serial.print("KeyPadIn: ");
  Serial.println(key);
  switch (key)
    {
    case '0':
      
    break;
    case '1':
      Hello();
    break;
    case '2':
      Motion_1();         
    break;
    case '3':
      Motion_2();      
    break;
    case '4':
      HeadTest();
    break;
    case '5':
      Cheers();
    break;
    case '6':
    
    break;
    case '7':
    
    break;
    case '8':
    
    break;
    case '9':
    
    break;
    case '#':
     ServoInitial(); 
    break;
    }
  
}
