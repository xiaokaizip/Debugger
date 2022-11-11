
/*TFT����ICΪ  ILI9341



����xpt2046
SPI����  MOSI-P4^0  MISO-P4^1  SCLK-P4^3
CS-P4^4   PENIRQ-P3^7


      SPI��������ʵ��
      ˵��  STC15  �����Լ���Ӳ��SPI����  ���ľ��彲���� STC15F2K60S2.pdf �ֲ��852ҳ��ʼ
	        Ĭ�ϵ�SPI������P1���� ����P1�������Ժ���õ�����AD���� ���ԴӴ˳���ʼ�ͽ�SPI
			������ P4.1 P4.2 P4.3 ������STC15���й��ܣ�
			����õ�STC15��Ƭ����Ӳ��SPI ��ô��main��ʼ��ʱ���Ҫ���ú�SPI����   
			����������	Init_SPI();  ����ʼ��SPI  ע���������ʼ�� SPI�����Ṥ����������

			xpt2046  �Ǵ���оƬ  �����Ĵ���оƬ�Ŀ��� ��������ǵ���ģ��SPI�� ��ʹ�乤����  
		  ���� STC15Ӳ���SPI������ xpt2046����  
			����������ҪĿ����Ϊ�˽�ʡ IO�� Ҳ����һ�ֹ��ܵ���չ 
			���������һ���˽� SPIӲ�����xpt2046  ����ο�  xpt2046 SPIͨѶ.doc  ����� XPT2046��������.pdf 
			�����ﶼд�ĺ���ϸ���������ǾͲ�����˵���ˡ�


			�������� �������� ��ʼ��SPI  ��ѭ�� �ж��Ƿ��д������� ������жϴ�����ӦTFT������  Ȼ�󻭵�  �ﵽ���������Ч��

			���ڴ���У׼ ���ǽ��ں���ĳ��򽲽�

*/


#include  "stc15f2k60s2.h"		  //STC15ͷ�ļ�
#include  "def.h"	    		  //�궨�� ���ú���
#include  "delay.h"				  //��ʱ����
#include  "tft.h"			      //TFT IC�ײ�����
#include  "gui.h"
#include  "spi.h"
#include  "xpt2046.h"
#include "tft.h"



void IO_init(void)
{
  P0M0 = 0X00;
  P0M1 = 0X00;

  P1M0 = 0X00;
  P1M1 = 0X00;

  P2M0 = 0X00;
  P2M1 = 0X00;

  P3M0 = 0X00;
  P3M1 = 0X00;

  P4M0 = 0X02;
  P4M1 = 0X00; 
	
  P5M0 = 0X08;
  P5M1 = 0X00;  
	
  P6M0 = 0X00;
  P6M1 = 0X00; 
	
  P7M0 = 0X00;
  P7M1 = 0X00;   
}



void main()
{ 
  struct TFT_Pointer Tp_pix;	        //���崥�������ṹ��
  u8 t; 
  IO_init();				   //��� IAP15W4K61S4  IO�ڳ�ʼ��
  Lcd_Init();                //tft��ʼ��
  Init_SPI(); 			     //SPI��ʼ��
  GUI_Clear(Cyan);			 //��ɫ����  
  GUI_sprintf_hzstr16x(0,0,"spi touch test",Blue,White);
  while(1)
  {
    Tp_pix=TFT_Cm();	                            // ɨ�败����
    if(Tp_pix.flag==1)                              //�Ƿ��д����¼� ���� 
    { 
			LED = !LED;
	 Address_set(Tp_pix.x,Tp_pix.y,Tp_pix.x+2,Tp_pix.y+2);			//3*3����Ϊһ����Ԫ��	
	 for(t=0;t<9;t++)				
	  Lcd_Write_Data(Red);
	}
//	    LED = !LED;
  
  }
    	
}






