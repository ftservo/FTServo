#include <SCServo.h>

SMS_STS sms_sts;

void setup()
{
  //Serial1.begin(115200);//sms舵机波特率115200
  Serial1.begin(1000000);//sts舵机波特率1000000
  sms_sts.pSerial = &Serial1;
  delay(1000);
}

void loop()
{
  //舵机(ID1)以最高速度V=60*0.732=43.92rpm，加速度A=50*8.7deg/s^2，运行至P1=4095位置
  sms_sts.WritePosEx(1, 4095, 2400, 50);
  delay((4095-0)*1000/(60*50) + (60*50)*10/(50) + 50);//[(P1-P0)/(V*50)]*1000+[(V*50)/(A*100)]*1000 + 50(误差)

  //舵机(ID1)以最高速度V=60*0.732=43.92rpm，加速度A=50*8.7deg/s^2，运行至P0=0位置
  sms_sts.WritePosEx(1, 0, 2400, 50);
  delay((4095-0)*1000/(60*50) + (60*50)*10/(50) + 50);//[(P1-P0)/(V*50)]*1000+[(V*50)/(A*100)]*1000 + 50(误差)
}
