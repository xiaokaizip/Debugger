#include "function.h"
#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "image.h"
#include "logo.h"
#include  "hz16x16.h"		  //����16X16
#include  "hz32x32.h"


u8 key = 0;

//--�����Բ��
void LCD_DrawFullCircle(uint16_t Xpos,uint16_t Ypos,uint16_t Radius,uint16_t Color)
{
	uint16_t x,y,r=Radius;
	for(y=Ypos - r;y<Ypos +r;y++)
	{
		for(x=Xpos - r;x<Xpos+r;x++)
		{
			if(((x-Xpos)*(x-Xpos)+(y-Ypos)*(y-Ypos)) <= r*r)
			{
				LCD_DrawPoint(x,y,Color);
			}
		}
	}
}

//--��ʾԲ��
void Dis_Circle(void)
{
		static u16 i = 0;
	  LCD_Clear(WHITE);
		while(1)
		{
				switch(i)
				{
					case 0:
								POINT_COLOR=RED;
								LCD_Draw_Circle(100, 150, 50);
								break;
					case 1:
								POINT_COLOR=GREEN;
								LCD_Draw_Circle(100+i*25, 150-i*25, 50);
								break;
					case 2:
								POINT_COLOR=BLUE;
								LCD_Draw_Circle(100+i*25, 150-i*25, 50);
								break;
					case 3:
								POINT_COLOR=YELLOW;
								LCD_Draw_Circle(100+i*25, 150-i*25, 50);
								break;
					case 4:
								POINT_COLOR=MAGENTA;
								LCD_Draw_Circle(100+i*25, 150-i*25, 50);
								break;
				}
				delay_ms(1000);	
				i++;
				if(i>=5)
				{
						i=0;
						return;
				}
			
		}

}
//--��ʾ���Բ��
void Dis_FullCircle(void)
{
		static u16 i = 0;
	  LCD_Clear(WHITE);
		while(1)
		{
				switch(i)
				{
					case 0:
								LCD_DrawFullCircle(100, 150, 50,RED);
								break;
					case 1:
								LCD_DrawFullCircle(100+i*25, 150-i*25, 50,GREEN);
								break;
					case 2:
								LCD_DrawFullCircle(100+i*25, 150-i*25, 50,BLUE);
								break;
					case 3:
								LCD_DrawFullCircle(100+i*25, 150-i*25, 50,YELLOW);
								break;
					case 4:
								LCD_DrawFullCircle(100+i*25, 150-i*25, 50,MAGENTA);
								break;
				}
				delay_ms(1000);	
				i++;
				if(i>=5)
				{
						i=0;
						return;
				}
			
		}

}



//--��ʾ����
void Dis_Rectangle(void)
{
		static u16 i = 0;
	  LCD_Clear(WHITE);
		while(1)
		{
				switch(i)
				{
					case 0:
								POINT_COLOR=RED;
								LCD_DrawRectangle(50, 250, 150, 150);
								break;
					case 1:
								POINT_COLOR=GREEN;
								LCD_DrawRectangle(50+i*20, 250-i*20, 150+i*20, 150-i*20);
								break;
					case 2:
								POINT_COLOR=BLUE;
								LCD_DrawRectangle(50+i*20, 250-i*20, 150+i*20, 150-i*20);
								break;
					case 3:
								POINT_COLOR=YELLOW;
								LCD_DrawRectangle(50+i*20, 250-i*20, 150+i*20, 150-i*20);
								break;
					case 4:
								POINT_COLOR=MAGENTA;
								LCD_DrawRectangle(50+i*20, 250-i*20, 150+i*20, 150-i*20);
								break;
				}			   		 
				delay_ms(1000);	
				i++;
				if(i>=5)
				{
						i=0;
						return;
				}
		}
		
}
//--��ʾ��䷽��ͼ��
void Dis_Fill(void)
{
	  static u16 i = 0;
	  LCD_Clear(WHITE);
		while(1)
		{
				switch(i)
				{
					case 0:
								LCD_Fill(50, 150, 150, 250,RED);
								break;
					case 1:
								LCD_Fill(50+i*20, 150-i*20, 150+i*20, 250-i*20,GREEN);
								break;
					case 2:
								LCD_Fill(50+i*20, 150-i*20, 150+i*20, 250-i*20,BLUE);
								break;
					case 3:
								LCD_Fill(50+i*20, 150-i*20, 150+i*20, 250-i*20,YELLOW);
								break;
					case 4:
								LCD_Fill(50+i*20, 150-i*20, 150+i*20, 250-i*20,MAGENTA);
								break;
				}			   		 
				delay_ms(1000);	
				i++;
				if(i>=5)
				{
						i=0;
						return;
				}
		}
}




//--��ʾlogo
void Dis_Logo(void)
{
		u16 x =0,y=0;
		u32 index=0;      
    Address_set(0,0,99,96);//���ù��λ�� 
	
		for(y=0;y<97;y++)
		{
			for(x=0;x<100;x++)
			{
				  index++;
					Lcd_Write_Data((u16)(((u16)gImage_logo[index*2+1]<<8)+gImage_logo[index*2]));
			}
		}
//		


}

//--��ʾһ��ͼƬ
void Dis_Image(void)
{
		
	u16 x =0,y=0;
	u32 index=0; 
	  Address_set(0,0,127,159);
		for(y=0;y<160;y++)
		{
			for(x=0;x<128;x++)
			{
				  index++;
				  Lcd_Write_Data((u16)(((u16)gImage_9[index*2+1]<<8)+gImage_9[index*2]));	
			}
		}
}


void Dis_Fill_Full(void)
{
		LCD_Fill(0, 0, 53, 160,BLUE);
		LCD_Fill(0, 120, 53, 240,MAGENTA);
	
		LCD_Fill(53, 0, 160, 160,RED);
		LCD_Fill(53, 120, 160, 240,YELLOW);
	
		LCD_Fill(160, 0, 266, 160,GREEN);
		LCD_Fill(160, 120, 266, 240,GBLUE);
	
		LCD_Fill(266, 0, 320, 160,BRED);
		LCD_Fill(266, 120, 320, 240,BRRED);
}


void Lcd_Test(void)
{
	static u8 i = 0;
	static u8 Dis_Cnt = 0;
	static u8 Wakeup_Cnt = 0;
	u8 lcd_id[12];			//���LCD ID�ַ���
//	i=11;
	switch(i)
	{
		case 0:
						LCD_Clear(BLACK);
						Dis_Logo();
						POINT_COLOR = WHITE;
						BACK_COLOR = 	BLACK;
						GUI_sprintf_hz16x(4,100,"ҫԪ��Ƽ�",WHITE,BLACK);	//
//						LCD_ShowString(0,100,320,16,16,"Product specification:2.8/3.2 inch"); 
//						LCD_ShowString(0,120,320,16,16,"LCD Action Area:48.6mm x 64.84mm"); 
//						LCD_ShowString(0,140,320,16,16,"Resoluting:320 RGB x 240");  
//						LCD_ShowString(0,160,320,16,16,"Display Mode: Transmissive"); 
//						LCD_ShowString(0,180,320,16,16,"Input Data:MCU 16-bit Parallel interface"); 
////						LCD_ShowString(0,200,320,16,16,"Viewing:12 o'clock"); 
						LCD_ShowString(4,120,320,16,16,"Drive:"); 
						LCD_ShowString(4+6*8,120,320,16,16,"7735");		//��ʾLCD ID
						LCD_ShowString(4,140,320,16,16,"15889732276"); 						
						break;
		case 1:	LCD_Clear(BLACK);break;
		case 2: LCD_Clear(WHITE);break;
		case 3: LCD_Clear(RED);break;
		case 4: LCD_Clear(GREEN);break;
		case 5: LCD_Clear(BLUE);break;
		case 6: Dis_Rectangle();break;
		case 7: Dis_Fill();break;		
		case 8: Dis_Circle();break;
		case 9: Dis_FullCircle();break;
		case 10: Dis_Fill_Full();break;
		case 11: Dis_Image();break;
		
			
	}	
	
	delay_ms(1000);	   		 
	delay_ms(500);
	if(Wakeup_Cnt == 0)
	{
			i++;
//			if(i>=12)
			if(i>=12)
			{
				i=0;
			}			
	    LED0=!LED0;			
	}
	else
	{
			i= 0xff;
	}
	
	if(key)
	{						   
		switch(key)
		{				 
			case WKUP_PRES:	//����LED1��ת ��ͣ
										LED0=!LED0;		
										Wakeup_Cnt++;
										if(Wakeup_Cnt == 1)//--��һ�ΰ��� ��ͣ
										{
												Dis_Cnt = i;
												i = 0xff;
												LED0 = 1;
										}
										else if(Wakeup_Cnt >= 2)//--�ڶ��ΰ��»ָ�
										{
											  Wakeup_Cnt = 0;
												i = Dis_Cnt+1;
												LED0 = 0;
										}
										key = 0;		
										break; 
			case KEY1_PRES:	//����LED1��ת	 ��һ��
										LED0=!LED0;		
										i++;
										Dis_Cnt++;
										if(Dis_Cnt >= 12)
										{
												Dis_Cnt = 0;
										}
										i = Dis_Cnt;
										key = 0;
										break;
			case KEY0_PRES:	//ͬʱ����LED0,LED1��ת ��һ��	
										LED0=!LED0;	
										if(Dis_Cnt == 0)
										{
												Dis_Cnt = 12;
										}
										i = Dis_Cnt;
										i--;	
										Dis_Cnt--;
										key = 0;
										break;
		}
	}	
		   		 
	
	
	
}


//--�ַ���ʾ
void Test_String(void)
{		
		GUI_sprintf_hz32x(32,0,"������ҫԪ��Ƽ�",RED,WHITE);	//
		GUI_sprintf_hz16x(90,32,"������ҫԪ��Ƽ�",RED,WHITE);	//		
	  LCD_ShowString(0,48,480,16,16,"Welcome to Shenzhen yaoyuanhong Technology");  
	  POINT_COLOR = GREEN;
	  LCD_ShowString(48,64,320,16,16,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");  
	  LCD_ShowString(48,80,320,16,16,"abcdefghijklmnopqrstuvwxyz");  
	
		GUI_sprintf_hz32x(48,100,"Ī�����������",BLUE,WHITE);	//
		GUI_sprintf_hz32x(48,136,"Ī�Թ�����ɳ����",BLUE,WHITE);	//
		GUI_sprintf_hz32x(48,172,"ǧ�����������࣬",BLUE,WHITE);	//
		GUI_sprintf_hz32x(48,208,"������ɳʼ����",BLUE,WHITE);	//
	
}





//��������ʾ
//˵������������ȡģ��������õ� ָ���ĺ��� ���ִ�С��16x16	 ��32���ֽڴ洢һ������
// 		�ⲿ�ֺ����Ǵ��ڳ���ռ� ���Ժ��ֵĶ���ֱ��Ӱ�����ռ��ʣ����
//      ��Ҫ�����ھ���ʾ����ָ���ĺ�����˵�Ͳ��õ����ֿ��� 
//x  y  Ҫ��ʾ���ֵ�����
//c[2]  ���ֵ����� һ�����������ֽڱ�ʾ
//dcolor ���ֵ���ɫ   bgcolor ������ɫ
void GUI_sprintf_hz1616(u16 x, u16  y, u8 c[2], u16 dcolor,u16 bgcolor)
{
	u8 i,j,k,m;									//������ʱ����
	u16 x0,y0;
	x0 = x;
  y0=y;	
	Address_set(x,y,x+16-1,y+16-1);      //ѡ������λ��	

	for (k=0;k<64;k++) 		  //64��ʾ�Խ����ֿ��еĸ�����ѭ����ѯ����	���������ȷ�� ȡ���ڴ���ĺ��ָ���	  
	{                        
	  if ((codeHZ_16[k].Index[0]==c[0])&&(codeHZ_16[k].Index[1]==c[1]))	    //Ѱ�Ҷ�Ӧ����	 һ��������Ҫ�����ֽ�
	  { 
    	for(i=0;i<32;i++) {								    //32���ֽ� ÿ���ֽڶ�Ҫһ����һ���㴦�� �����Ǵ�����32X8��
		   m=codeHZ_16[k].Msk[i];							//��ȡ��Ӧ�ֽ�����
		  for(j=0;j<8;j++) 									//��ʾһ���ֽ�  һ���ֽ�8λ Ҳ����8����
		   {
			 if((m&0x80)==0x80) 							//�ж��Ƿ���Ҫд��� 	 ����� ��������ɫ
			   LCD_Fast_DrawPoint(x,y,dcolor);				
			 else 											//������� Ϊ����ɫ  ����ɫ
			   LCD_Fast_DrawPoint(x,y,bgcolor);
			  m<<=1;										    //����һλ  �ж���һ��
			 
			 
				  x++;
					if((x-x0)==16)
					{
						x=x0;
						y++;
						if((y-y0)>=16)
						{
							return;
						}
					}
			 
		   } 
		  }
		}  
	  }	
	}



//��ʾ�ַ��� 
//x1 y1 ��ʾ�ĳ�ʼλ��
//*str Ҫ��ʾ������
//dcolor ��ʾ�ַ�����ɫ
//bgcolor ��ʾ�ַ��ı�����ɫ  
void GUI_sprintf_hz16x(u16 x1,u16 y1,u8 *str,u16 dcolor,u16 bgcolor)	  
{  
	 u8 l=0;
	while(*str)
	{	
	  if(*str>=0x80)		  //С��128   ascii ����������
	  {	  		  
	    GUI_sprintf_hz1616(x1+l*8,y1,(u8*)str,dcolor, bgcolor);
			str+=2;l+=2;
	  }
	}	
}



//��ʾ32x32��������
//(x��y) ����ʾ���ݵ����Ͻ����꣬c[2]��ʾ���ֵ������ֽ�
//dcolor ���ֵ���ɫ   bgcolor ������ɫ
//˵������ָ��λ������ʾһ��32x32�ĺ���
void GUI_sprintf_hz3232(u16 x, u16  y, u8 c[2], u16 dcolor,u16 bgcolor)
{
	u8 i,j,k;

	u16 x0,y0;
	x0 = x;
  y0=y;	

	Address_set(x,y,x+32-1,y+32-1);      //ѡ������λ��	
	for (k=0;k<100;k++) 	  //�Խ����ֿ⣨k���ֵ�ͺ��ֿ��к��ָ����йأ���ѭ����ѯ����
	{ 
	  if ((codeHZ_32[k].Index[0]==c[0])&&(codeHZ_32[k].Index[1]==c[1]))		//Ѱ��Ҫ��ʾ�ĺ���
	  { 
    	for(i=0;i<128;i++)													//1������Ҫ128���ֽڵ�����ʾ
		{
		  u8 m=codeHZ_32[k].Msk[i];											//һ���ֽ�һ���ֽڵ���ʾ
		  for(j=0;j<8;j++) 
		  {
			if((m&0x80)==0x80) //�ж��Ƿ���Ҫд��� 	 ����� ��������ɫ
			   LCD_Fast_DrawPoint(x,y,dcolor);				
			else 
			   LCD_Fast_DrawPoint(x,y,bgcolor);	//������� Ϊ����ɫ  ����ɫ
			m<<=1;
			 x++;
					if((x-x0)==32)
					{
						x=x0;
						y++;
						if((y-y0)>=32)
						{
							return;
						}
					}
		  }    
		}
	  }  
	}	
}





//��ʾ32x32���� ��32x16 ��ĸ��
//x1��y1����ʾ���ݵ����Ͻ����꣬
//dcolor ���ֵ���ɫ   bgcolor ������ɫ
//*str Ҫ��ʾ������
void GUI_sprintf_hz32x(u16 x1,u16 y1,u8 *str,u16 dcolor,u16 bgcolor)	 
{  
   u8 l=0;	  
   while(*str)
   {
	 if(*str>=0x80)		 	        
	 {
	   GUI_sprintf_hz3232(x1+l*8,y1,(u8*)str,dcolor,bgcolor);
	   l+=4;
	   str+=2;
	 }
   }
}




 
