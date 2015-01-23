void HeadTest(){
  HeadControl(0);
  delay(500);  
  HeadControl(45);
  delay(500);  
  HeadControl(-45);
  delay(500);  
  HeadControl(0);
  delay(500);
  
  HeadLoop(45, -45, 100);
  HeadLoop(0, 0, 10);
  HeadLoop(0, -10, 10);
  HeadLoop(20, 20, 50);
  HeadLoop(0, 0, 10);
}

void Motion_1(){
  PairOfHands(90, 0, 0, 90, 0, 0);
  delay(DelayTime);
  PairOfHands(90, 90, 0, 90, 90, 0);
  delay(DelayTime);
  PairOfHands(0, 90, 0, 0, 90, 0);
  delay(DelayTime);  
  PairOfHands(0, 0, 0, 0, 0, 0);
  delay(DelayTime);
}
void Motion_2(){
  int a=0, b=0;
  for (a ; a<=90 ;a++){
    RightHandStep(a,a,0,10,50,0);
    }
  delay(DelayTime);
  //RightHandStep(0,0,0,0,0,0);
}  
  /*
  PairOfHands(0, 0, 0, 0, 0, 0);
  delay(1000); 
  PairOfHands(90, 0, 0, 90, 0, 0);
  delay(1000); 
  PairOfHands(90, 90, 0, 90, 90, 0);
  delay(1000); 

  RightHandStep(50,50,0,5,5,5);
  RightHandStep(0,0,0,5,5,5);  
  LeftHandStep(50,50,0,5,5,5);
  LeftHandStep(0,0,0,5,5,5);

  RightHandControl(180,0,0);
  delay(200);  
  RightHandControl(90,0,0);
  delay(200);  
  RightHandControl(0,0,0);
  delay(200);  
  RightHandControl(0,90,0);
  delay(200);  
  RightHandControl(0,180,0);
  delay(200);
  RightHandControl(0,0,0);
  delay(200);
  RightHandControl(0,0,90);
  delay(200);
  RightHandControl(0,0,180);
  delay(200);
  RightHandControl(0,0,0);  
  delay(200);

  LeftHandControl(0,0,0);
  delay(200);
  LeftHandControl(90,0,0);
  delay(200);
  LeftHandControl(180,0,0);
  delay(200);
  LeftHandControl(0,0,0);
  delay(200);
  LeftHandControl(0,90,0);
  delay(200);
  LeftHandControl(0,180,0);
  delay(200);
  LeftHandControl(0,0,0);
  delay(200);
  LeftHandControl(0,0,90);  
  delay(200);
  LeftHandControl(0,0,180);  
  delay(200);  
*/

