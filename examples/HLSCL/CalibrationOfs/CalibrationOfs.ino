/*
中位校准例子
*/

#include <SCServo.h>

HLSCL hlscl;

void setup()
{
  Serial.begin(115200);
  //Serial1.begin(1000000, SERIAL_8N1, 18, 17);//esp32-s3
  Serial1.begin(1000000);//mega2560
  hlscl.pSerial = &Serial1;
  delay(1000);
  hlscl.CalibrationOfs(1);
  delay(10);
}

void loop()
{
  int pos = hlscl.ReadPos(1);
  if(!hlscl.getLastError()){
    Serial.print("mid pos:");
    Serial.println(pos);
  }
  delay(1000);
}
