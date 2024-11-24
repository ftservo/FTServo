/*
电机模式例子
*/

#include <SCServo.h>

SCSCL sc;

void setup()
{
  Serial1.begin(1000000);
  sc.pSerial = &Serial1;
  delay(1000);
  sc.PWMMode(1);//舵机切换到PWM开环调速度模式
}

void loop()
{
  //舵机(ID1)以最大50%扭矩正向旋转
  sc.WritePWM(1, 500);
  delay(2000);
  
  //舵机(ID1)停止旋转
  sc.WritePWM(1, 0);
  delay(2000);
  
  //舵机(ID1)以最大50%扭矩反向旋转
  sc.WritePWM(1, -500);
  delay(2000);
  
  //舵机(ID1)停止旋转
  sc.WritePWM(1,0);
  delay(2000);
}
