/*************************************************************************
*************************************************************************/
void MotorTest(){
  MotorA.MotorAForward(255);
  delay(1000);
  MotorA.MotorABack(255);
  delay(1000);
  MotorA.MotorATurnLeft(255);
  delay(1000);
  MotorA.MotorATurnRight(255);
  delay(1000);
  MotorA.MotorAStop();
  delay(1000);
}
