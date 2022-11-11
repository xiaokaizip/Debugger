#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "image.h"
#include "function.h"
#include "timer.h"
#include "24cxx.h"
#include "w25qxx.h"
#include "touch.h"

 
/************************************************
 ����ҫԪ��Ƽ�STM32������ ����9341����4�ߴ��ڽӿ�LCDҺ����
 TFTLCD��ʾʵ��  
 ������ʾ��������ҫԪ��Ƽ���ӭ�����У�Ӣ����ʾ���׵׺��֣�-0-9   A-Z a-z(�׵����֣�-����/ʫ/�ʣ��׵����֣�
 ˢ������������ʾ�� �ڵװ�����ʾ��˾���֣���ʾ����Ϣ-��-��-��-��-��-  ������-��ɫ-��Բ-��ɫ-ͼƬ��һ֡����ͼƬ��
 WK_UP:��ͣ��KEY0:�Ϸ���KEY1:�·� 
 ���ڣ�2020-11-04
 
 �򿪺궨�� #define tpTest�У��˳����Ǵ�����ʾ����
 ע�ͺ궨�� #define tpTest�У��˳�������ʾ��ʾ����
 ���ڣ�2021-01-04
 
************************************************/

//#define tpTest 

//�����Ļ�������Ͻ���ʾ"RST"
void Load_Drow_Dialog(void)
{
	LCD_Clear_S(WHITE);	//����   
 	POINT_COLOR=BLUE;	//��������Ϊ��ɫ 
	LCD_ShowString(lcddev.width-24,0,200,16,16,"RST");//��ʾ��������
  POINT_COLOR=RED;	//���û�����ɫ 
}

//���败�������Ժ���
void rtp_test(void)
{
	u8 i=0;	  
	while(1)
	{
		tp_dev.scan(0); 		 
		if(tp_dev.sta&TP_PRES_DOWN)			//������������
		{	
		 	if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
			{	
				if(tp_dev.x[0]>(lcddev.width-24)&&tp_dev.y[0]<16)Load_Drow_Dialog();//���
				else TP_Draw_Big_Point(tp_dev.x[0],tp_dev.y[0],RED);		//��ͼ	  			   
			}
		}else delay_ms(10);	//û�а������µ�ʱ�� 	    
		if(key==KEY0_PRES)	//KEY0����,��ִ��У׼����
		{			
			key = 0;
			LED1=!LED1;
			LCD_Clear(WHITE);//����
		  TP_Adjust();  	//��ĻУ׼  
			Load_Drow_Dialog();
		}
		i++;
		if(i%20==0)LED0=!LED0;
	}
}



 int main(void)
 {	 
	
 	u8 x=0;
	u8 Color_Read[20];//��Ŷ�ȡ������ɫֵ	 
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
 	LED_Init();			     //LED�˿ڳ�ʼ��
	Lcd_Init();
	KEY_Init();	
 	tp_dev.init();
	TIM3_Int_Init(10,7199);//10Khz�ļ���Ƶ�ʣ�������10Ϊ1ms 
	POINT_COLOR=RED;
	 
	 #ifdef tpTest
					Load_Drow_Dialog();	 			
					rtp_test(); 						//����������
	 #else
					 while(1) 
					{		 
							Lcd_Test();
					} 	 
	 #endif
	 
  

}
 
