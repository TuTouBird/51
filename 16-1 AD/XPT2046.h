#ifndef __XPT2046_H_
#define __XPT2046_H_


#define XPT2046_VBAT	0xAC
#define XPT2046_AUX		0xEC
#define XPT2046_XP		0x9C	//0xBC
#define XPT2046_YP		0xDC

unsigned int XPT2046_ReadAD(unsigned char Command);

#endif