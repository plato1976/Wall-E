/*************************************************************************
*************************************************************************/
void KeyPadIn(){
  // 讀取 Keypad 的輸入
  char key = keypad.getKey();  
 
  // NO_KEY 代表沒有按鍵被按下
  if (key != NO_KEY){
    // 假如有按鍵被按下，就印出按鍵對應的字元
    LCD5510.clearDisplay();
    Serial.println(key);    
    //return &key;
    }
}
/*************************************************************************
*************************************************************************/
void KeyPadMotion(){
  char key = keypad.getKey();  
  if (key != NO_KEY){
    LCD5510.gotoXY(0,5);
    LCD5510.LcdString("KeyPadIn: ");  
    LCD5510.gotoXY(65,5);  
    Serial.print("KeyPadIn: ");
    switch (key)
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

  
}
