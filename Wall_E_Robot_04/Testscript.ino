void HeadTest(){
  HeadAngles(0);
  delay(500);  
  HeadAngles(45);
  delay(500);  
  HeadAngles(-45);
  delay(500);  
  HeadAngles(0);
  delay(500);
  
  HeadLoop(45, -45, 10);
  //HeadLoop(0, 0, 10);
  //HeadLoop(0, -10, 10);
  //HeadLoop(20, 20, 50);
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
  int i = 0, j = 10;
  for (i ; i <= 90 ; i++){
    RightHandStep(i, i, i, j, j, j);
    }
} 

void Hello(){
  int i=0, j=300;
  while (i<=3){
    RightHandAngles(90,0,0);
    HeadAngles(45);
    delay(j);
    RightHandAngles(90,30,0);
    HeadAngles(-45);
    delay(j);
    i++;
    }
  ServoInitial();

}
void Cheers(){
  int i=0, j=150;
  PairOfHands(90, 0, 0, 90, 0, 0);
  while (i <= 3){
    delay(j);
    HeadAngles(45);
    PairOfHands(90, 90, 0, 90, 90, 0);
    delay(j);
    PairOfHands(90, 0, 0, 90, 0, 0);    
    HeadAngles(-45);
    delay(j);
    i++;
    }
  ServoInitial();
}

void ChaCha(){
  int i=0, j=200;
  while (i <= 3){
    PairOfHands(90, 0, 0, 0, 0, 0);
    HeadAngles(45);
    delay(j);
    PairOfHands(0, 0, 0, 90, 0, 0);
    HeadAngles(-45);
    delay(j);  
    i++;
  }
  ServoInitial();
}

void ChaCha1(){
  int i=0, j=250;
  while (i <= 3){
    PairOfHands(90, 0, 90, 0, 0, 0);
    HeadAngles(45);
    delay(j);
    PairOfHands(0, 0, 0, 90, 0, 90);
    HeadAngles(-45);
    delay(j);  
    i++;
    }
  HeadAngles(0);
  i=0;
  while(i <= 3){
    PairOfHands(45, 90, 0, 0, 0, 0);
    HeadAngles(-45);
    delay(j);
    PairOfHands(45, 0, 0, 45, 90, 0); 
    HeadAngles(45);
    delay(j);
    i++; 
    }


  ServoInitial();


}
