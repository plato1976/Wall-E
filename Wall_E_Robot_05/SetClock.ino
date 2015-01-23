/*************************************************************************
*************************************************************************/
void InitialRTC (){
  rtc.write_protect(false);
  rtc.halt(false);
   PrintTime();
}
/*************************************************************************
*************************************************************************/
void SetTime(int Year, int Month, int Day, int Hour, int Miniute, int Secend, int MicroSec){
  if (Year > 1900 && Year < 2500){
    Serial.print("Input Year: ");
    Serial.println(Year);
    }
    else if (Month >=1 && Month <=12){
      Serial.print("Input Month: ");
      Serial.println(Month);  
      }
    else if (Day >=1 && Day <=31){
      Serial.print("Input Day: ");
      Serial.println(Day);
      }
    else if (Hour >= 1 && Hour <= 24){
      Serial.print("Input Hour: ");
      Serial.println(Hour);      
      }
    else if (Miniute >= 1 &&  Miniute <=60){
      Serial.print("Input Miniute: ");
      Serial.println(Miniute);
      }
    else if (Secend >= 1 &&  Secend <=60){
      Serial.print("Input Secend: ");
      Serial.println(Secend);
      }
    else if (MicroSec >= 1 &&  MicroSec <=100){
      Serial.print("Input MicroSec: ");
      Serial.println(MicroSec);
      Time SetTime(Year, Month, Day, Hour, Miniute, Secend, MicroSec);
      }      
}

//void print_time(){
void PrintTime(){
  /* Get the current time and date from the chip */
  Time t = rtc.time();

  /* Name the day of the week */
  memset(RTCday, 0, sizeof(RTCday));  /* clear day buffer */
  switch (t.day) {
    case 1:
      strcpy(RTCday, "Sunday");
      break;
    case 2:
      strcpy(RTCday, "Monday");
      break;
    case 3:
      strcpy(RTCday, "Tuesday");
      break;
    case 4:
      strcpy(RTCday, "Wednesday");
      break;
    case 5:
      strcpy(RTCday, "Thursday");
      break;
    case 6:
      strcpy(RTCday, "Friday");
      break;
    case 7:
      strcpy(RTCday, "Saturday");
      break;
  }

  /* Format the time and date and insert into the temporary buffer */
  snprintf(RTCbuf, sizeof(RTCbuf), "%s %04d-%02d-%02d %02d:%02d:%02d",
           RTCday,
           t.yr, t.mon, t.date,
           t.hr, t.min, t.sec);

  /* Print the formatted string to serial so we can see the time */
  Serial.println(RTCbuf);
} 
  
 
