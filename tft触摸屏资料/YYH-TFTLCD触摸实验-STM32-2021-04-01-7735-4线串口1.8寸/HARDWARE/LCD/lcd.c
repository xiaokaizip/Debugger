#include "lcd.h"
#include "stdlib.h"
#include "font.h" 
#include "usart.h"	 
#include "delay.h"	
#include "image.h"


//LCD�Ļ�����ɫ�ͱ���ɫ	   
u16 POINT_COLOR=0x0000;	//������ɫ
u16 BACK_COLOR=0xFFFF;  //����ɫ 
  
//����LCD��Ҫ����
//Ĭ��Ϊ����
_lcd_dev lcddev;
	 
	 
	 
//========================================================
void  Lcd_WR_Reg(u16 c)
{
     int i;
     LCD_A0_CLR;
     LCD_CS_CLR;
     for(i=0;i<8;i++)
     {
     if(c &0x80)
     {
     LCD_SDA_SET;
     }
     else LCD_SDA_CLR;
     LCD_SCL_CLR;
     LCD_SCL_SET;
     c <<=1;
     }	 
     LCD_CS_SET;	
}
	 
	 
void LCD_WriteData(u16 dat)
{
      int i;
      LCD_A0_SET;
      LCD_CS_CLR;
      for(i=0;i<8;i++)
      {
      if(dat&0x80)
      {
      LCD_SDA_SET;
      }
      else LCD_SDA_CLR;
			 LCD_SCL_CLR;
			 LCD_SCL_SET;
      dat<<=1;
      }	 
      LCD_CS_SET;
}	 
//�������� 
void Lcd_Write_Data(u16 dat16)
{
  LCD_WriteData(dat16>>8);
  LCD_WriteData(dat16);
}	 
	 
	 
	 //�������귶Χ		
//x1 y1  ��ʼλ��
//x2 y2  ����λ��
void Address_set(u16 x1,u16 y1,u16 x2,u16 y2)
{	     
      //  xq=0;yq=0;
		Lcd_WR_Reg(0X2A); 
		LCD_WriteData(x1>>8); 
		LCD_WriteData(x1&0XFF);
		LCD_WriteData(x2>>8); 
		LCD_WriteData(x2&0XFF);

		Lcd_WR_Reg(0X2B); 
		LCD_WriteData(y1>>8); 
		LCD_WriteData(y1&0XFF);
		LCD_WriteData(y2>>8); 
		LCD_WriteData(y2&0XFF);
	  Lcd_WR_Reg(0X2C);      //��ʼд��GRAM
 
}
	 
	 
//Һ����ʼ��
void Lcd_Init(void)
{
	
			GPIO_InitTypeDef GPIO_InitStructure;
			
			RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC,ENABLE);	//ʹ��FSMCʱ��
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOG,ENABLE);//ʹ��PORTB,D,E,G�Լ�AFIO���ù���ʱ��

		 
			GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;				 //PB0 ������� ����
			GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_Init(GPIOB, &GPIO_InitStructure);
			
			
			
			GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13;				 //PB0 ������� ����
			GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_Init(GPIOE, &GPIO_InitStructure);
			
			GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11;				 //PB0 ������� ����
			GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_Init(GPIOF, &GPIO_InitStructure);

//			LCD_RES_SET; 
//			delay_ms(10);;                                                              //Delay 1ms 
//			LCD_RES_CLR; 
//			delay_ms(200);                                                              //Delay 1ms 
//			LCD_RES_SET; 
//			delay_ms(200);                                                              //Delay 120ms 
//			LCD_CS_CLR;
//			//************* Start Initial Sequence **********// 
//			Lcd_WR_Reg(0xCF);  
//			LCD_WriteData(0x00); 
//			LCD_WriteData(0xD9); 
//			LCD_WriteData(0X30); 
//			 
//			Lcd_WR_Reg(0xED);  
//			LCD_WriteData(0x64); 
//			LCD_WriteData(0x03); 
//			LCD_WriteData(0X12); 
//			LCD_WriteData(0X81); 
//			 
//			Lcd_WR_Reg(0xE8);  
//			LCD_WriteData(0x85); 
//			LCD_WriteData(0x10); 
//			LCD_WriteData(0x78); 
//			 
//			Lcd_WR_Reg(0xCB);  
//			LCD_WriteData(0x39); 
//			LCD_WriteData(0x2C); 
//			LCD_WriteData(0x00); 
//			LCD_WriteData(0x34); 
//			LCD_WriteData(0x02); 
//			 
//			Lcd_WR_Reg(0xF7);  
//			LCD_WriteData(0x20); 
//			 
//			Lcd_WR_Reg(0xEA);  
//			LCD_WriteData(0x00); 
//			LCD_WriteData(0x00); 
//			 
//			Lcd_WR_Reg(0xC0);    //Power control 
//			LCD_WriteData(0x21);   //VRH[5:0] 
//			 
//			Lcd_WR_Reg(0xC1);    //Power control 
//			LCD_WriteData(0x12);   //SAP[2:0];BT[3:0] 
//			 
//			Lcd_WR_Reg(0xC5);    //VCM control 
//			LCD_WriteData(0x32); 
//			LCD_WriteData(0x3C); 
//			 
//			Lcd_WR_Reg(0xC7);    //VCM control2 
//			LCD_WriteData(0XC1); 
//			 
//			Lcd_WR_Reg(0x36);    // Memory Access Control 
//			LCD_WriteData(0x08); //--����
////			LCD_WriteData(0x68); //--����
//			 
//			Lcd_WR_Reg(0x3A);   
//			LCD_WriteData(0x55); 

//			Lcd_WR_Reg(0xB1);   
//			LCD_WriteData(0x00);   
//			LCD_WriteData(0x18); 
//			 
//			Lcd_WR_Reg(0xB6);    // Display Function Control 
//			LCD_WriteData(0x0A); 
//			LCD_WriteData(0xA2); 

//			 
//			 
//			Lcd_WR_Reg(0xF2);    // 3Gamma Function Disable 
//			LCD_WriteData(0x00); 
//			 
//			Lcd_WR_Reg(0x26);    //Gamma curve selected 
//			LCD_WriteData(0x01); 
//			 
//			Lcd_WR_Reg(0xE0);    //Set Gamma 
//			LCD_WriteData(0x0F); 
//			LCD_WriteData(0x20); 
//			LCD_WriteData(0x1E); 
//			LCD_WriteData(0x09); 
//			LCD_WriteData(0x12); 
//			LCD_WriteData(0x0B); 
//			LCD_WriteData(0x50); 
//			LCD_WriteData(0XBA); 
//			LCD_WriteData(0x44); 
//			LCD_WriteData(0x09); 
//			LCD_WriteData(0x14); 
//			LCD_WriteData(0x05); 
//			LCD_WriteData(0x23); 
//			LCD_WriteData(0x21); 
//			LCD_WriteData(0x00); 
//			 
//			Lcd_WR_Reg(0XE1);    //Set Gamma 
//			LCD_WriteData(0x00); 
//			LCD_WriteData(0x19); 
//			LCD_WriteData(0x19); 
//			LCD_WriteData(0x00); 
//			LCD_WriteData(0x12); 
//			LCD_WriteData(0x07); 
//			LCD_WriteData(0x2D); 
//			LCD_WriteData(0x28); 
//			LCD_WriteData(0x3F); 
//			LCD_WriteData(0x02); 
//			LCD_WriteData(0x0A); 
//			LCD_WriteData(0x08); 
//			LCD_WriteData(0x25); 
//			LCD_WriteData(0x2D); 
//			LCD_WriteData(0x0F); 
//			
			//			LCD_RES_SET; 
//			delay_ms(10);;                                                              //Delay 1ms 
//			LCD_RES_CLR; 
//			delay_ms(200);                                                              //Delay 1ms 
//			LCD_RES_SET; 
//			delay_ms(200);                                                              //Delay 120ms 
//			LCD_CS_CLR;
			//------------------------------------ST7735R Reset Sequence-----------------------------------------// 
				LCD_RES_SET; 
				delay_ms (10);                                                              //Delay 1ms 
				LCD_RES_CLR; 
				delay_ms (10);                                                              //Delay 1ms 
				LCD_RES_SET; 
				delay_ms(200);                                                              //Delay 120ms 
				//--------------------------------End ST7735R Reset Sequence --------------------------------------// 
				 
				//--------------------------------End ST7735S Reset Sequence --------------------------------------// 
				Lcd_WR_Reg(0x11); //Sleep out 
				delay_ms(120);              //Delay 120ms 
				//------------------------------------ST7735S Frame Rate-----------------------------------------// 
				Lcd_WR_Reg(0xB1); 
				LCD_WriteData(0x05); 
				LCD_WriteData(0x3C); 
				LCD_WriteData(0x3C); 
				Lcd_WR_Reg(0xB2); 
				LCD_WriteData(0x05); 
				LCD_WriteData(0x3C); 
				LCD_WriteData(0x3C); 
				Lcd_WR_Reg(0xB3); 
				LCD_WriteData(0x05); 
				LCD_WriteData(0x3C); 
				LCD_WriteData(0x3C); 
				LCD_WriteData(0x05); 
				LCD_WriteData(0x3C); 
				LCD_WriteData(0x3C); 
				//------------------------------------End ST7735S Frame Rate---------------------------------// 
				Lcd_WR_Reg(0xB4); //Dot inversion 
				LCD_WriteData(0x03); 
				//------------------------------------ST7735S Power Sequence---------------------------------// 
				Lcd_WR_Reg(0xC0); 
				LCD_WriteData(0x28); 
				LCD_WriteData(0x08); 
				LCD_WriteData(0x04); 
				Lcd_WR_Reg(0xC1); 
				LCD_WriteData(0XC0); 
				Lcd_WR_Reg(0xC2); 
				LCD_WriteData(0x0D); 
				LCD_WriteData(0x00); 
				Lcd_WR_Reg(0xC3); 
				LCD_WriteData(0x8D); 
				LCD_WriteData(0x2A); 
				Lcd_WR_Reg(0xC4); 
				LCD_WriteData(0x8D); 
				LCD_WriteData(0xEE); 
				//---------------------------------End ST7735S Power Sequence-------------------------------------// 
				Lcd_WR_Reg(0xC5); //VCOM 
				LCD_WriteData(0x1A); 
				Lcd_WR_Reg(0x36); //MX, MY, RGB mode 
				LCD_WriteData(0xC0); 
				//------------------------------------ST7735S Gamma Sequence---------------------------------// 
				Lcd_WR_Reg(0xE0); 
				LCD_WriteData(0x04); 
				LCD_WriteData(0x22); 
				LCD_WriteData(0x07); 
				LCD_WriteData(0x0A); 
				LCD_WriteData(0x2E); 
				LCD_WriteData(0x30); 
				LCD_WriteData(0x25); 
				LCD_WriteData(0x2A); 
				LCD_WriteData(0x28); 
				LCD_WriteData(0x26); 
				LCD_WriteData(0x2E); 
				LCD_WriteData(0x3A); 
				LCD_WriteData(0x00); 
				LCD_WriteData(0x01); 
				LCD_WriteData(0x03); 
				LCD_WriteData(0x13); 
				Lcd_WR_Reg(0xE1); 
				LCD_WriteData(0x04); 
				LCD_WriteData(0x16); 
				LCD_WriteData(0x06); 
				LCD_WriteData(0x0D); 
				LCD_WriteData(0x2D); 
				LCD_WriteData(0x26); 
				LCD_WriteData(0x23); 
				LCD_WriteData(0x27); 
				LCD_WriteData(0x27); 
				LCD_WriteData(0x25); 
				LCD_WriteData(0x2D); 
				LCD_WriteData(0x3B); 
				LCD_WriteData(0x00); 
				LCD_WriteData(0x01); 
				LCD_WriteData(0x04); 
				LCD_WriteData(0x13); 
				//------------------------------------End ST7735S Gamma Sequence-----------------------------// 
				Lcd_WR_Reg(0x3A); //65k mode 
				LCD_WriteData(0x05); 
				Lcd_WR_Reg(0x29); //Display on 
			 
//			Lcd_WR_Reg(0x11);    //Exit Sleep 
//			delay_ms(120); 
//			Lcd_WR_Reg(0x29);    //Display on 

	    LCD_LED=1;				//��������
			
			
			lcddev.width = 128;
			lcddev.height = 160;
}	  	 
	 
	 
	 
	 
	//����
//color�Ǳ�����ɫ��
//˵����ʹ�ñ�����ɫ���TFTģ����Ļ��ȫ����ʾ���ݡ�
void GUI_Clear(u16 color)
{
	u16 i;
	u16 j;
	Address_set(0,0,319,239);
    for(i=0;i<240;i++)
	 {
	    for (j=0;j<320;j++)
	   	{
        	 Lcd_Write_Data(color);
	    }

	  }
} 
	 
	 
	 
	 
//д�Ĵ�������
//regval:�Ĵ���ֵ
void LCD_WR_REG(u16 regval)
{   
     int i;
     LCD_A0_CLR;
     LCD_CS_CLR;
     for(i=0;i<8;i++)
     {
     if(regval &0x80)
     {
     LCD_SDA_SET;
     }
     else LCD_SDA_CLR;
     LCD_SCL_CLR;
     LCD_SCL_SET;
     regval <<=1;
     }	 
     LCD_CS_SET;
  	
}
//дLCD����
//data:Ҫд���ֵ
void LCD_WR_DATA(u16 data)
{	 
	int i;
	LCD_A0_SET;
	LCD_CS_CLR;
	for(i=0;i<8;i++)
	{
	if(data&0x80)
	{
	LCD_SDA_SET;
	}
	else LCD_SDA_CLR;
	 LCD_SCL_CLR;
	 LCD_SCL_SET;
	data<<=1;
	}	 
	LCD_CS_SET;	
}
					   
//д�Ĵ���
//LCD_Reg:�Ĵ�����ַ
//LCD_RegValue:Ҫд�������
void LCD_WriteReg(u16 LCD_Reg,u16 LCD_RegValue)
{	
	LCD_WR_REG(LCD_Reg);//д��Ҫд�ļĴ������	
	LCD_WR_DATA(LCD_RegValue);//д������	  
}	  






  

//��mdk -O1ʱ���Ż�ʱ��Ҫ����
//��ʱi
void opt_delay(u8 i)
{
	while(i--);
}
		 
//LCD������ʾ
void LCD_DisplayOn(void)
{					   
	LCD_WR_REG(0X29);	//������ʾ
}	 
//LCD�ر���ʾ
void LCD_DisplayOff(void)
{	   
	LCD_WR_REG(0X28);	//�ر���ʾ
}   
		 
    
//����
//x,y:����
//POINT_COLOR:�˵����ɫ
void LCD_DrawPoint(u16 x,u16 y,u16 color)
{
	 Address_set(x,y,x,y);//���ù��λ�� 
	 Lcd_Write_Data(color);
}
//���ٻ���
//x,y:����
//color:��ɫ
void LCD_Fast_DrawPoint(u16 x,u16 y,u16 color)
{
	  Lcd_Write_Data(color);
}	 


	 


//��������
//color:Ҫ���������ɫ
void LCD_Clear_S(u16 color)
{
	u16 i;
	u8 j;
	Address_set(0,0,127,159);
    for(i=0;i<128;i++)
	 {
	    for (j=0;j<160;j++)
	   	{
        	 Lcd_Write_Data(color);
	    }

	  }
	
} 
//��������
//color:Ҫ���������ɫ
void LCD_Clear(u16 color)
{
	u16 i;
	u8 j;
	Address_set(0,0,129,161);
    for(i=0;i<130;i++)
	 {
	    for (j=0;j<162;j++)
	   	{
        	 Lcd_Write_Data(color);
	    }

	  }
	
} 

//��ָ����������䵥����ɫ
//(sx,sy),(ex,ey):�����ζԽ�����,�����СΪ:(ex-sx+1)*(ey-sy+1)   
//color:Ҫ������ɫ
void LCD_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 color)
{          
	u16 i,j;
	u16 xlen=0;
	u16 ylen=0;
	u16 temp;
	
		xlen = ex-sx+1;
		ylen = ey-sy+1;
		
		Address_set(sx,sy,ex,ey);
    for(i=0;i<xlen;i++)
		 {
				for (j=0;j<ylen;j++)
				{
						 Lcd_Write_Data(color);
				}

			}
		 
}  
  
  
//����
//x1,y1:�������
//x2,y2:�յ�����  
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2)
{
	u16 t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance; 
	int incx,incy,uRow,uCol; 
	delta_x=x2-x1; //������������ 
	delta_y=y2-y1; 
	uRow=x1; 
	uCol=y1; 
	if(delta_x>0)incx=1; //���õ������� 
	else if(delta_x==0)incx=0;//��ֱ�� 
	else {incx=-1;delta_x=-delta_x;} 
	if(delta_y>0)incy=1; 
	else if(delta_y==0)incy=0;//ˮƽ�� 
	else{incy=-1;delta_y=-delta_y;} 
	if( delta_x>delta_y)distance=delta_x; //ѡȡ�������������� 
	else distance=delta_y; 
	for(t=0;t<=distance+1;t++ )//������� 
	{  
		LCD_DrawPoint(uRow,uCol,POINT_COLOR);//���� 
		xerr+=delta_x ; 
		yerr+=delta_y ; 
		if(xerr>distance) 
		{ 
			xerr-=distance; 
			uRow+=incx; 
		} 
		if(yerr>distance) 
		{ 
			yerr-=distance; 
			uCol+=incy; 
		} 
	}  
}    
//������	  
//(x1,y1),(x2,y2):���εĶԽ�����
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2)
{
	LCD_DrawLine(x1,y1,x2,y1);
	LCD_DrawLine(x1,y1,x1,y2);
	LCD_DrawLine(x1,y2,x2,y2);
	LCD_DrawLine(x2,y1,x2,y2);
}
//��ָ��λ�û�һ��ָ����С��Բ
//(x,y):���ĵ�
//r    :�뾶
void LCD_Draw_Circle(u16 x0,u16 y0,u8 r)
{
	int a,b;
	int di;
	a=0;b=r;	  
	di=3-(r<<1);             //�ж��¸���λ�õı�־
	while(a<=b)
	{
		LCD_DrawPoint(x0+a,y0-b,POINT_COLOR);             //5
 		LCD_DrawPoint(x0+b,y0-a,POINT_COLOR);             //0           
		LCD_DrawPoint(x0+b,y0+a,POINT_COLOR);             //4               
		LCD_DrawPoint(x0+a,y0+b,POINT_COLOR);             //6 
		LCD_DrawPoint(x0-a,y0+b,POINT_COLOR);             //1       
 		LCD_DrawPoint(x0-b,y0+a,POINT_COLOR);             
		LCD_DrawPoint(x0-a,y0-b,POINT_COLOR);             //2             
  		LCD_DrawPoint(x0-b,y0-a,POINT_COLOR);             //7     	         
		a++;
		//ʹ��Bresenham�㷨��Բ     
		if(di<0)di +=4*a+6;	  
		else
		{
			di+=10+4*(a-b);   
			b--;
		} 						    
	}
} 									  
//��ָ��λ����ʾһ���ַ�
//x,y:��ʼ����
//num:Ҫ��ʾ���ַ�:" "--->"~"
//size:�����С 12/16/24
//mode:���ӷ�ʽ(1)���Ƿǵ��ӷ�ʽ(0)
void LCD_ShowChar(u16 x,u16 y,u8 num,u8 size,u8 mode)
{  							  
    u8 temp,t1,t;
	u16 y0=y;
	u8 csize=(size/8+((size%8)?1:0))*(size/2);		//�õ�����һ���ַ���Ӧ������ռ���ֽ���	
 	num=num-' ';//�õ�ƫ�ƺ��ֵ��ASCII�ֿ��Ǵӿո�ʼȡģ������-' '���Ƕ�Ӧ�ַ����ֿ⣩
	
//	Address_set(x,y,x+size-1,y+size-1);
	for(t=0;t<csize;t++)
	{   
		if(size==12)temp=asc2_1206[num][t]; 	 	//����1206����
		else if(size==16)temp=asc2_1608[num][t];	//����1608����
		else if(size==24)temp=asc2_2412[num][t];	//����2412����
		else return;								//û�е��ֿ�
		for(t1=0;t1<8;t1++)
		{			    
			if(temp&0x80)LCD_DrawPoint(x,y,POINT_COLOR);
			else if(mode==0)LCD_DrawPoint(x,y,BACK_COLOR);
			temp<<=1;
			y++;
			if(y>=240)return;		//��������
			if((y-y0)==size)
			{
				y=y0;
				x++;
				if(x>=320)return;	//��������
				break;
			}
		}  	 
	}  	    	   	 	  
}   
//m^n����
//����ֵ:m^n�η�.
u32 LCD_Pow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}			 
//��ʾ����,��λΪ0,����ʾ
//x,y :�������	 
//len :���ֵ�λ��
//size:�����С
//color:��ɫ 
//num:��ֵ(0~4294967295);	 
void LCD_ShowNum(u16 x,u16 y,u32 num,u8 len,u8 size)
{         	
	u8 t,temp;
	u8 enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/LCD_Pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				LCD_ShowChar(x+(size/2)*t,y,' ',size,0);
				continue;
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+(size/2)*t,y,temp+'0',size,0); 
	}
} 
//��ʾ����,��λΪ0,������ʾ
//x,y:�������
//num:��ֵ(0~999999999);	 
//len:����(��Ҫ��ʾ��λ��)
//size:�����С
//mode:
//[7]:0,�����;1,���0.
//[6:1]:����
//[0]:0,�ǵ�����ʾ;1,������ʾ.
void LCD_ShowxNum(u16 x,u16 y,u32 num,u8 len,u8 size,u8 mode)
{  
	u8 t,temp;
	u8 enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/LCD_Pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				if(mode&0X80)LCD_ShowChar(x+(size/2)*t,y,'0',size,mode&0X01);  
				else LCD_ShowChar(x+(size/2)*t,y,' ',size,mode&0X01);  
 				continue;
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+(size/2)*t,y,temp+'0',size,mode&0X01); 
	}
} 
//��ʾ�ַ���
//x,y:�������
//width,height:�����С  
//size:�����С
//*p:�ַ�����ʼ��ַ		  
void LCD_ShowString(u16 x,u16 y,u16 width,u16 height,u8 size,u8 *p)
{         
	u8 x0=x;
	width+=x;
	height+=y;
    while((*p<='~')&&(*p>=' '))//�ж��ǲ��ǷǷ��ַ�!
    {       
        if(x>=width){x=x0;y+=size;}
        if(y>=height)break;//�˳�
        LCD_ShowChar(x,y,*p,size,0);
        x+=size/2;
        p++;
    }  
}





































