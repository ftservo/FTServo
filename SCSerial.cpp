/*
 * SCSerial.h
 * 飞特串行舵机硬件接口层程序
 * 日期: 2024.4.2
 * 作者: 
 */

#include "SCSerial.h"

SCSerial::SCSerial()
{
	IOTimeOut = 10;
	pSerial = NULL;
}

SCSerial::SCSerial(u8 End):SCS(End)
{
	IOTimeOut = 10;
	pSerial = NULL;
}

SCSerial::SCSerial(u8 End, u8 Level):SCS(End, Level)
{
	IOTimeOut = 10;
	pSerial = NULL;
}

int SCSerial::readSCS(unsigned char *nDat, int nLen, unsigned long TimeOut)
{
	int Size = 0;
	int ComData;
	unsigned long t_begin = millis();
	unsigned long t_user;
	while(1){
		ComData = pSerial->read();
		if(ComData!=-1){
			if(nDat){
				nDat[Size] = ComData;
			}
			Size++;
		}
		if(Size>=nLen){
			break;
		}
		t_user = millis() - t_begin;
		if(t_user>TimeOut){
			break;
		}
	}
	return Size;
}

int SCSerial::readSCS(unsigned char *nDat, int nLen)
{
	int Size = 0;
	int ComData;
	unsigned long t_begin = millis();
	unsigned long t_user;
	while(1){
		ComData = pSerial->read();
		if(ComData!=-1){
			if(nDat){
				nDat[Size] = ComData;
			}
			Size++;
			t_begin = millis();
		}
		if(Size>=nLen){
			break;
		}
		t_user = millis() - t_begin;
		if(t_user>IOTimeOut){
			break;
		}
	}
	return Size;
}

int SCSerial::writeSCS(unsigned char *nDat, int nLen)
{
	if(nDat==NULL){
		return 0;
	}
	return pSerial->write(nDat, nLen);
}

int SCSerial::writeSCS(unsigned char bDat)
{
	return pSerial->write(&bDat, 1);
}

void SCSerial::rFlushSCS()
{
	while(pSerial->read()!=-1);
}

void SCSerial::wFlushSCS()
{
}