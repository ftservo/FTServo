/*
中位校准例子
*/

#include <SCServo.h>

int LEDpin = 13;
SMS_STS sm_st;

void setup()
{
  pinMode(LEDpin, OUTPUT);
  //Serial1.begin(115200);//sms舵机波特率115200
  Serial1.begin(1000000);//sts舵机波特率1000000
  sm_st.pSerial = &Serial1;
  delay(1000);
}

void loop()
{
  digitalWrite(LEDpin, LOW);
  sm_st.CalibrationOfs(1);
  digitalWrite(LEDpin, HIGH);
  while(1);
}
