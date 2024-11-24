/*
异步写例子在SCS15中测试通过，如果测试其它型号SCS系列舵机请更改合适的位置、速度与延时参数。
*/

#include <SCServo.h>

SCSCL sc;

void setup()
{
  Serial1.begin(1000000);
  sc.pSerial = &Serial1;
  delay(1000);
}

void loop()
{
  //舵机(ID1/ID2)以最高速度V=1500*0.059=88.5rpm，运行至P1=1000位置
  sc.RegWritePos(1, 1000, 0, 1500);
  sc.RegWritePos(2, 1000, 0, 1500);
  sc.RegWriteAction();
  delay((1000-20)*1000/(1500) + 100);//[(P1-P0)/(V)]*1000 + 100(误差)
  
  //舵机(ID1/ID2)以最高速度V=1500*0.059=88.5rpm，运行至P0=20位置
  sc.RegWritePos(1, 20, 0, 1500);
  sc.RegWritePos(2, 20, 0, 1500);
  sc.RegWriteAction();
  delay((1000-20)*1000/(1500) + 100);//[(P1-P0)/(V)]*1000 + 100(误差)
}
