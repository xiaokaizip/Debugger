#ifndef __FUNCTION_H
#define __FUNCTION_H	 
#include "sys.h"

extern u8 key;



void Lcd_Test(void);
void Dis_Logo(void);	


void GUI_sprintf_hz16x(u16 x1,u16 y1,u8 *str,u16 dcolor,u16 bgcolor);	 

void GUI_sprintf_hz32x(u16 x1,u16 y1,u8 *str,u16 dcolor,u16 bgcolor);
void Dis_Rectangle(void);
void Dis_Fill(void);
//--��ʾԲ��
void Dis_Circle(void);
//--��ʾ���Բ��
void Dis_FullCircle(void);

//--�ַ���ʾ
void Test_String(void);

void Dis_Fill_Full(void);
void Dis_Image(void);
#endif
