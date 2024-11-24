/*
舵机参数编程
*/

#include <SCServo.h>

int LEDpin = 13;
HLSCL hlscl;

void setup()
{
  pinMode(LEDpin, OUTPUT);
  //Serial1.begin(1000000, SERIAL_8N1, 18, 17);//esp32-s3
  Serial1.begin(1000000);//mega2560
  hlscl.pSerial = &Serial1;
  delay(1000);
  digitalWrite(LEDpin, LOW);
  hlscl.unLockEprom(1);//打开EPROM保存功能
  hlscl.writeByte(1, HLSCL_ID, 2);//ID
  hlscl.LockEprom(2);//关闭EPROM保存功能
  digitalWrite(LEDpin, HIGH);
}

void loop()
{

}
