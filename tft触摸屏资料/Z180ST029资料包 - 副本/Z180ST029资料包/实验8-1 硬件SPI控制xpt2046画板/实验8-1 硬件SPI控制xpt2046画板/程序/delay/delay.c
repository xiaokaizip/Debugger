

#include "stc15f2k60s2.h"
#include "delay.h"

/*
24MHz��Ƶ�� 
��ʾ�����¿�
һ������ʱ������ 0.8us
*/

//2΢��	��ʱ
//�˺�������2us�ı�������
//t  2us�ı���
void delay2us(u16 us)
 {
  u16 i;
  u8 m;
  for(i=0;i<us;i++)
  for(m=0;m<3;m++);
 }



//4΢��	��ʱ
//�˺�������4us�ı�������
//t  4us�ı���
void delay4us(u16 us)
 {
  u16 i;
  u8 m;
  for(i=0;i<us;i++)
  for(m=0;m<5;m++);
 }  



//1���� ��ʱ
//ms 1ms�ı���
void delay1ms(u16 ms)
{
 u16 m;
 for(m=0;m<ms;m++)
 delay4us(250);
} 
  


void delaylow(u8 time)		   //����ר�� ��ʱ
{
 u8 i,j;
 for(i=0;i<time;i++)
  for(j=0;j<100;j++);
}



