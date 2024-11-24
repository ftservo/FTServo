/*
舵机参数编程
*/

#include <SCServo.h>

int LEDpin = 13;
SMS_STS sms_sts;

void setup()
{
  pinMode(LEDpin, OUTPUT);
  //Serial1.begin(115200);//sms舵机波特率115200
  Serial1.begin(1000000);//sts舵机波特率1000000
  sms_sts.pSerial = &Serial1;
  delay(1000);
  digitalWrite(LEDpin, LOW);
  sms_sts.unLockEprom(1);//打开EPROM保存功能
  sms_sts.writeByte(1, SMS_STS_ID, 2);//ID
  sms_sts.LockEprom(2);//关闭EPROM保存功能
  digitalWrite(LEDpin, HIGH);
}

void loop()
{

}
