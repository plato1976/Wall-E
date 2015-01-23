void ComPort(){
  if (Serial2.available())
    Serial.write(Serial2.read());
  if (Serial.available())  
    Serial2.write(Serial.read());
}
