void HeadControl(int Head_Angle){
  if (Head_Angle >= -45 && Head_Angle <= 45){
      Head=Init_Head+Head_Angle; 
      ServoHead.write(Head);
      Serial.print("Head Angle: ");
      Serial.println(ServoHead.read());
      LCDDisplayServo (); 
      KeyPadMotion();
     }
     else{
       Serial.println("Head angle error.");
       }
}

void HeadLoop(int AngleMax,int AngleMin, int DelayTime){
  HeadAngle=ServoHead.read()-Init_Head;
  while(HeadAngle<=AngleMax){
    Head=Init_Head+HeadAngle;
    ServoHead.write(Head);
    HeadAngle++;
    delay(DelayTime);
    Serial.print("Head Angle: ");
    Serial.println(ServoHead.read());    
    LCDDisplayServo ();    
    KeyPadMotion();
    }
  
  while(HeadAngle>=AngleMin){
    Head=Init_Head+HeadAngle;
    ServoHead.write(Head);
    HeadAngle--;
    delay(DelayTime);
    Serial.print("Head Angle: ");
    Serial.println(ServoHead.read());
    LCDDisplayServo ();    
    KeyPadMotion();
    }
}

void RightHandControl(int RightAngleX, int RightAngleY, int RightAngleZ){
  if ((RightAngleX >= 0 || RightHandX >= 180) && (RightHandY >= 0 || RightHandY >= 180) && (RightHandZ >= 0 || RightHandZ >= 180)){
    RightHandX=RightAngleX+Init_RightHandX;
    ServoRightX.write(RightHandX);
    RightHandY=Init_RightHandY-RightAngleY;
    ServoRightY.write(RightHandY);    
    RightHandZ=RightAngleZ+Init_RightHandZ;
    ServoRightWrist.write(RightHandZ);    
    }
  Serial.print("RightHand Angle(X,Y,Z): ");
  Serial.print(RightHandX);
  Serial.print(", ");
  Serial.print(RightHandY);
  Serial.print(", ");
  Serial.println(RightHandZ);
  LCDDisplayServo ();  
  KeyPadMotion();
}

void LeftHandControl(int LeftAngleX, int LeftAngleY, int LeftAngleZ){
  if ((LeftHandX >= 0 || LeftHandX >= 180) && (LeftAngleY >= 0 || LeftAngleY >= 180) && (LeftAngleZ >= 0 || LeftAngleZ >= 180)){
    LeftHandX=abs(LeftAngleX-Init_LeftHandX); 
    ServoLeftX.write(LeftHandX);
    LeftHandY=abs(LeftAngleY-Init_LeftHandY);
    ServoLeftY.write(LeftHandY);
    LeftHandZ=abs(LeftAngleZ-Init_LeftHandZ);
    ServoLeftWrist.write(LeftHandZ);
    }
  Serial.print("LeftHand Angle(X,Y,Z): ");
  Serial.print(LeftHandX);
  Serial.print(", ");
  Serial.print(LeftHandY);
  Serial.print(", ");
  Serial.println(LeftHandZ);
  LCDDisplayServo ();  
  KeyPadMotion();
}

void PairOfHands(int RightAngleX, int RightAngleY, int RightAngleZ, int LeftAngleX, int LeftAngleY, int LeftAngleZ){
  if ((RightAngleX >= 0 || RightHandX >= 180) && (RightHandY >= 0 || RightHandY >= 180) && (RightHandZ >= 0 || RightHandZ >= 180) && (LeftHandX >= 0 || LeftHandX >= 180) && (LeftAngleY >= 0 || LeftAngleY >= 180) && (LeftAngleZ >= 0 || LeftAngleZ >= 180)){
    RightHandX=RightAngleX+Init_RightHandX;
    ServoRightX.write(RightHandX);
    RightHandY=Init_RightHandY-RightAngleY;
    ServoRightY.write(RightHandY);    
    RightHandZ=RightAngleZ+Init_RightHandZ;
    ServoRightWrist.write(RightHandZ);    
    LeftHandX=Init_LeftHandX-LeftAngleX; 
    ServoLeftX.write(LeftHandX);
    LeftHandY=Init_LeftHandY-LeftAngleY;
    ServoLeftY.write(LeftHandY);
    LeftHandZ=Init_LeftHandZ-LeftAngleZ;
    ServoLeftWrist.write(LeftHandZ);
    }
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
  LCDDisplayServo ();
  KeyPadMotion();
  
}

void RightHandStep(int RightAngleSetX, int RightAngleSetY, int RightAngleSetZ, int RightDelaySetX, int RightDelaySetY, int RightDelaySetZ){
  int i=0, j=0, k=0, RightAngleReadX, RightStepX, RightAngleReadY, RightStepY ;
  if (RightAngleSetX <= 180 && RightAngleSetY <= 180) {
    RightStepX=ServoRightX.read()-RightAngleSetX;
    RightStepY=Init_RightHandY-ServoRightY.read()-RightAngleSetY;
    if (RightStepX <= 0 && RightStepY <= 0 ){
      Serial.print("Step: ");
      Serial.println(RightStepX);
      Serial.print("Step: ");
      Serial.println(RightStepY);
      LCDDisplayServo ();
      RightAngleReadX=ServoRightX.read();
      RightAngleReadY=ServoRightY.read();
      //delay(10);	  
      while (i <= abs(RightStepX)){
        RightHandX = i + RightAngleReadX + Init_RightHandX;
        ServoRightX.write(RightHandX);
        delay(RightDelaySetX);
        i++;
        Serial.print("negative: ");
        Serial.println(RightHandX);
        LCDDisplayServo ();    
        KeyPadMotion();    
        }
      while (j <= abs(RightStepY)){
        RightHandY = abs(j - RightAngleReadY);
        ServoRightY.write(RightHandY);
        delay(RightDelaySetY);
        j++;
        Serial.print("negative: ");
        Serial.println(RightHandY);
        LCDDisplayServo (); 
        KeyPadMotion();      
        }      
      }
      else {
        Serial.print("Step: ");
        Serial.println(RightStepX);
        Serial.print("Step: ");
        Serial.println(RightStepY);
        RightAngleReadX=ServoRightX.read();
        RightAngleReadY=ServoRightY.read();      
        LCDDisplayServo ();  
        KeyPadMotion();      
	//delay(10);
        //positive-> goto zero

        while ( i <= abs(RightStepX)){
          RightHandX = RightAngleReadX + Init_RightHandX - i;
          ServoRightX.write(RightHandX);
          delay(RightDelaySetX);
          i++;
          Serial.print("positive: ");
          Serial.println(RightHandX);
          LCDDisplayServo ();          
          KeyPadMotion();
          }
        while ( j <= abs(RightStepY)){
          RightHandY = abs(RightAngleReadY + j);
          ServoRightY.write(RightHandY);
          delay(RightDelaySetY);
          j++;
          Serial.print("positive: ");
          Serial.println(RightHandY);
          LCDDisplayServo ();          
          KeyPadMotion();
          }		  
      }  
    }
    else {
      Serial.println("Over range 180 degree!");
      }  
}

void LeftHandStep(int LeftAngleSetX, int LeftAngleSetY, int LeftAngleSetZ, int LeftDelaySetX, int LeftDelaySetY, int LeftDelaySetZ){
  int i=0, j=0, k=0, LeftAngleReadX, LeftStepX, LeftAngleReadY, LeftStepY;
  if (LeftAngleSetX <= 180 && LeftAngleSetY <= 180){
    LeftStepX=Init_LeftHandX-ServoLeftX.read()-LeftAngleSetX;
    LeftStepY=Init_LeftHandY-ServoLeftY.read()-LeftAngleSetY;
    if (LeftStepX <= 0){
      Serial.print("Step: ");
      Serial.println(LeftStepX);
      Serial.print("Step: ");
      Serial.println(LeftStepY);
      LeftAngleReadX=ServoLeftX.read();
      LeftAngleReadY=ServoLeftY.read();
      LCDDisplayServo ();      
      KeyPadMotion();
      //delay(10);
      while (i <= abs(LeftStepX)){
        LeftHandX = abs(i - LeftAngleReadX);
        ServoLeftX.write(LeftHandX);
        delay(LeftDelaySetX);
        i++;
        Serial.print("negative: ");
        Serial.println(LeftHandX);
        LCDDisplayServo ();        
        KeyPadMotion();
        }
      while (j <= abs(LeftStepY)){
        LeftHandY = abs(j - LeftAngleReadY);
        ServoLeftY.write(LeftHandY);
        delay(LeftDelaySetY);
        j++;
        Serial.print("negative: ");
        Serial.println(LeftHandY);
        LCDDisplayServo ();        
        KeyPadMotion();
        }
	  }
      else {
        Serial.print("Step: ");
        Serial.println(LeftStepX);
        Serial.print("Step: ");
        Serial.println(LeftStepY);
        LeftAngleReadX=ServoLeftX.read();
        LeftAngleReadY=ServoLeftY.read();
        LCDDisplayServo ();        	
        KeyPadMotion();
        //delay(1000);
        while ( (i <= abs(LeftStepX)) || (j <= abs(LeftStepY))){
          LeftHandX = abs(LeftAngleReadX + i);
          ServoLeftX.write(LeftHandX);
          delay(LeftDelaySetX);
          i++;
          j++;
          Serial.print("positive: ");
          Serial.println(LeftHandX);
          LCDDisplayServo ();
          KeyPadMotion();
          }

        while ( j <= abs(LeftStepY)){
          LeftHandY = abs(LeftAngleReadY + j);
          ServoLeftY.write(LeftHandY);
          delay(LeftDelaySetY);
          j++;
          Serial.print("positive: ");
          Serial.println(LeftHandY);
          LCDDisplayServo ();
          KeyPadMotion();
          }

      }  
    }
    else {
      Serial.println("Over range 180 degree!");
      }	  
}





