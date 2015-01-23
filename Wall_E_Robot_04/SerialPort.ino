void SerialComPort(){
  if (Serial2.available() > 0){
    Serial.print("BT->Arduino: ");
    Serial.write(Serial2.read());
    Serial.println("");
    }
  if (Serial.available() > 0){ 
    Serial.print("Arduino->BT: ");
    Serial2.write(Serial.read());
    Serial.println("");
    }
}

void BTComPort(){
  if (Serial2.available() > 0){
    //unsigned char BTSerialInput=Serial2.read();
    char BTSerialInput=(char)Serial2.read();
    //byte BTSerialInput=Serial2.read();
    char SerialChar[10]={0x00};
    
    LCD5510.gotoXY(0,5);
    LCD5510.LcdString("KeyPadIn: ");  
    Serial.print("KeyPadIn: ");
    Serial.write(BTSerialInput);
    LCD5510.gotoXY(65,5);
    //LCD5510.LcdString(BTSerialInput); 
      switch (BTSerialInput)
      {
      case '0':
      
      break;
      case '1':
        Hello();
      break;
      case '2':
         Cheers();         
      break;
      case '3':
        ChaCha(); 
      break;
      case '4':
        ChaCha1();      
      break;
      case '5':
        Cheers();
      break;
      case '6':
        ChaCha(); 
        ChaCha1();
        Cheers(); 
      break;
      case '7':
        HeadTest();
      break;
      case '8':
        Motion_1();
      break;
      case '9':
        Motion_2();
      break;
      case '#':
       LCD5510.clearDisplay();
       ServoInitial(); 
      break;
      }

  }
  if (Serial.available() > 0){ 
    Serial.println("Arduino->BT: ");
    Serial2.write(Serial.read());
  }

}
