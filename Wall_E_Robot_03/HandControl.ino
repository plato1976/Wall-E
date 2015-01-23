/*
void LeftHand(){
  switch (buttonkey.KeyValue())
    {
      case 0:
        {
          LeftAngleY++;
          if (LeftAngleY >= 180){
            Serial.println("Over angle range 180 degree");   
            LeftAngleY = 180;
            }
            else {
              ServoLeftY.write(LeftHandY);
              Serial.print("ServoLeftY angle: ");
              Serial.println(ServoLeftY.read());
              }
          break;
        }

      case 1:
        {
          LeftAngleX++;
          if (LeftAngleX > 180){
            Serial.println("Over angle range 180 degree");   
            LeftAngleX = 180;
            }
            else {
              ServoLeftX.write(LeftHandX);
              Serial.print("ServoLeftX angle: ");
              Serial.println(ServoLeftX.read());
              }
          break;
        }
      case 2:
        {
          LeftAngleX--;
          if (LeftAngleX < 0){
             LeftAngleX = 0;
             Serial.println("Angle under 0 degree");
             }
             else{
               ServoLeftX.write(LeftHandX);
               Serial.print("ServoLefttX angle:");
               Serial.println(ServoLeftX.read());
               }
          break;
        }
      case 3:
        {
           LeftAngleY--;
           if (LeftAngleY < 0){
             Serial.println("Angle under 0 degree");
             LeftAngleY = 0;
            }
            else{
              ServoLeftY.write(LeftHandY);
              Serial.print("ServoLeftY angle:");
              Serial.println(ServoLeftY.read());
              }
        break;
        }
      case 4:
        {
        break;
        }  
    }
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Left X:");
  lcd.setCursor(7,0);
  lcd.print(LeftAngleX); 

  lcd.setCursor(11,0);
  lcd.print("Y:");
  lcd.setCursor(13,0);
  lcd.print(LeftAngleY); 
}
void RightHand(){
  switch (buttonkey.KeyValue())
    {
      case 0:
        {
          RightAngleY++;
          if (RightAngleY >= 180){
            Serial.println("Over angle range 180 degree");   
            RightAngleY = 180;
            }
            else {
              ServoRightY.write(RightHandY);
              Serial.print("ServoRightY angle: ");
              Serial.println(ServoRightY.read());
              }
          break;
        }

      case 1:
        {
          RightAngleX++;
          if (RightAngleX > 180){
            Serial.println("Over angle range 180 degree");   
            RightAngleX = 180;
            }
            else {
              ServoRightX.write(RightHandX);
              Serial.print("ServoRightX angle: ");
              Serial.println(ServoRightX.read());
              }
          break;
        }
      case 2:
        {
          RightAngleX--;
          if (RightAngleX < 0){
             RightAngleX = 0;
             Serial.println("Angle under 0 degree");
             }
             else{
               ServoRightX.write(RightHandX);
               Serial.print("ServoRightX angle:");
               Serial.println(ServoRightX.read());
               }
          break;
        }
      case 3:
        {
           RightAngleY--;
           if (RightAngleY < 0){
             Serial.println("Angle under 0 degree");
             RightAngleY = 0;
            }
            else{
              ServoRightY.write(RightHandY);
              Serial.print("ServoRightY angle:");
              Serial.println(ServoRightY.read());
              }
        break;
        }
      case 4:
        {
        break;
        }  
    }
  //lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Right X:");
  lcd.setCursor(7,1);
  lcd.print(RightAngleX); 

  lcd.setCursor(11,1);
  lcd.print("Y:");
  lcd.setCursor(13,1);
  lcd.print(RightAngleY);  
}
  

*/

