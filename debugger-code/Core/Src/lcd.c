//
// Created by 86136 on 2022/10/21.
//

#include "lcd.h"
#include "main.h"
#include "font.h"
#include "spi.h"

//LCD的画笔颜色和背景色
uint16_t POINT_COLOR = 0x0000;    //画笔颜色
uint16_t BACK_COLOR = 0xFFFF;  //背景色

//管理LCD重要参数
//默认为竖屏
_lcd_dev lcddev;


//========================================================
void Lcd_WR_Reg(uint8_t c) {
//    int i;
//    LCD_A0_CLR;
//    LCD_CS_CLR;
//    for (i = 0; i < 8; i++) {
//        if (c & 0x80) {
//            LCD_SDA_SET;
//        } else
//            LCD_SDA_CLR;
//        LCD_SCL_CLR;
//        LCD_SCL_SET;
//        c <<= 1;
//    }
//    LCD_CS_SET;

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_RESET);
    HAL_SPI_Transmit_DMA(&hspi3, &c, 1);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_SET);
}


void LCD_WriteData(uint8_t dat) {
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);

    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_RESET);
    HAL_SPI_Transmit_DMA(&hspi3, &dat, 1);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_SET);
}

//发送数据
void Lcd_Write_Data(uint16_t dat16) {
    LCD_WriteData(dat16 >> 8);
    LCD_WriteData(dat16);
}


//设置坐标范围		
//x1 y1  初始位置
//x2 y2  结束位置
void Address_set(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
    //  xq=0;yq=0;
    Lcd_WR_Reg(0X2A);
    LCD_WriteData(x1 >> 8);
    LCD_WriteData(x1 & 0XFF);
    LCD_WriteData(x2 >> 8);
    LCD_WriteData(x2 & 0XFF);

    Lcd_WR_Reg(0X2B);
    LCD_WriteData(y1 >> 8);
    LCD_WriteData(y1 & 0XFF);
    LCD_WriteData(y2 >> 8);
    LCD_WriteData(y2 & 0XFF);
    Lcd_WR_Reg(0X2C);      //开始写入GRAM

}


//液晶初始化
void Lcd_Init(void) {



//			LCD_RES_SET; 
//			HAL_Delay(10);;                                                              //Delay 1ms 
//			LCD_RES_CLR; 
//			HAL_Delay(200);                                                              //Delay 1ms 
//			LCD_RES_SET; 
//			HAL_Delay(200);                                                              //Delay 120ms 
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
//			LCD_WriteData(0x08); //--竖屏
////			LCD_WriteData(0x68); //--横屏
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
//			HAL_Delay(10);;                                                              //Delay 1ms 
//			LCD_RES_CLR; 
//			HAL_Delay(200);                                                              //Delay 1ms 
//			LCD_RES_SET; 
//			HAL_Delay(200);                                                              //Delay 120ms 
//			LCD_CS_CLR;
    //------------------------------------ST7735R Reset Sequence-----------------------------------------// 
    LCD_RES_SET;
    HAL_Delay(1);                                                              //Delay 1ms
    LCD_RES_CLR;
    HAL_Delay(1);                                                              //Delay 1ms
    LCD_RES_SET;
    HAL_Delay(120);                                                              //Delay 120ms
    //--------------------------------End ST7735R Reset Sequence --------------------------------------// 

    //--------------------------------End ST7735S Reset Sequence --------------------------------------// 
    Lcd_WR_Reg(0x11); //Sleep out 
    HAL_Delay(120);              //Delay 120ms 
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
//			HAL_Delay(120); 
//			Lcd_WR_Reg(0x29);    //Display on 

    //点亮背光


    lcddev.width = 128;
    lcddev.height = 160;
}


//清屏
//color是背景颜色。
//说明：使用背景颜色清除TFT模块屏幕的全部显示内容。
void GUI_Clear(uint16_t color) {
    uint16_t i;
    uint16_t j;
    Address_set(0, 0, 319, 239);
    for (i = 0; i < 240; i++) {
        for (j = 0; j < 320; j++) {
            Lcd_Write_Data(color);
        }

    }
}


//写寄存器函数
//regval:寄存器值
void LCD_WR_REG(uint8_t regval) {
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_RESET);
    HAL_SPI_Transmit_DMA(&hspi3, &regval, 1);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_SET);

}

//写LCD数据
//data:要写入的值
void LCD_WR_DATA(uint8_t data) {
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);

    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_RESET);
    HAL_SPI_Transmit_DMA(&hspi3, &data, 1);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_SET);
}

//写寄存器
//LCD_Reg:寄存器地址
//LCD_RegValue:要写入的数据
void LCD_WriteReg(uint16_t LCD_Reg, uint16_t LCD_RegValue) {
    LCD_WR_REG(LCD_Reg);//写入要写的寄存器序号	
    LCD_WR_DATA(LCD_RegValue);//写入数据	  
}


//当mdk -O1时间优化时需要设置
//延时i
void opt_delay(uint8_t i) {
    while (i--);
}

//LCD开启显示
void LCD_DisplayOn(void) {
    LCD_WR_REG(0X29);    //开启显示
}

//LCD关闭显示
void LCD_DisplayOff(void) {
    LCD_WR_REG(0X28);    //关闭显示
}


//画点
//x,y:坐标
//POINT_COLOR:此点的颜色
void LCD_DrawPoint(uint16_t x, uint16_t y, uint16_t color) {
    Address_set(x, y, x, y);//设置光标位置
    Lcd_Write_Data(color);
}

//快速画点
//x,y:坐标
//color:颜色
void LCD_Fast_DrawPoint(uint16_t x, uint16_t y, uint16_t color) {
    Lcd_Write_Data(color);
}


//清屏函数
//color:要清屏的填充色
void LCD_Clear_S(uint16_t color) {
    uint16_t i;
    uint8_t j;
    Address_set(0, 0, 127, 159);
    for (i = 0; i < 128; i++) {
        for (j = 0; j < 160; j++) {
            Lcd_Write_Data(color);
        }

    }

}

//清屏函数
//color:要清屏的填充色
void LCD_Clear(uint16_t color) {
    uint16_t i;
    uint8_t j;
    Address_set(0, 0, 129, 161);
    for (i = 0; i < 130; i++) {
        for (j = 0; j < 162; j++) {
            Lcd_Write_Data(color);
        }

    }

}

//在指定区域内填充单个颜色
//(sx,sy),(ex,ey):填充矩形对角坐标,区域大小为:(ex-sx+1)*(ey-sy+1)   
//color:要填充的颜色
void LCD_Fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t color) {
    uint16_t i, j;
    uint16_t xlen = 0;
    uint16_t ylen = 0;
    uint16_t temp;

    xlen = ex - sx + 1;
    ylen = ey - sy + 1;

    Address_set(sx, sy, ex, ey);
    for (i = 0; i < xlen; i++) {
        for (j = 0; j < ylen; j++) {
            Lcd_Write_Data(color);
        }

    }

}


//画线
//x1,y1:起点坐标
//x2,y2:终点坐标  
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
    uint16_t t;
    int xerr = 0, yerr = 0, delta_x, delta_y, distance;
    int incx, incy, uRow, uCol;
    delta_x = x2 - x1; //计算坐标增量
    delta_y = y2 - y1;
    uRow = x1;
    uCol = y1;
    if (delta_x > 0)incx = 1; //设置单步方向
    else if (delta_x == 0)incx = 0;//垂直线
    else {
        incx = -1;
        delta_x = -delta_x;
    }
    if (delta_y > 0)incy = 1;
    else if (delta_y == 0)incy = 0;//水平线
    else {
        incy = -1;
        delta_y = -delta_y;
    }
    if (delta_x > delta_y)distance = delta_x; //选取基本增量坐标轴
    else distance = delta_y;
    for (t = 0; t <= distance + 1; t++)//画线输出
    {
        LCD_DrawPoint(uRow, uCol, POINT_COLOR);//画点
        xerr += delta_x;
        yerr += delta_y;
        if (xerr > distance) {
            xerr -= distance;
            uRow += incx;
        }
        if (yerr > distance) {
            yerr -= distance;
            uCol += incy;
        }
    }
}

//画矩形
//(x1,y1),(x2,y2):矩形的对角坐标
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
    LCD_DrawLine(x1, y1, x2, y1);
    LCD_DrawLine(x1, y1, x1, y2);
    LCD_DrawLine(x1, y2, x2, y2);
    LCD_DrawLine(x2, y1, x2, y2);
}

//在指定位置画一个指定大小的圆
//(x,y):中心点
//r    :半径
void LCD_Draw_Circle(uint16_t x0, uint16_t y0, uint8_t r) {
    int a, b;
    int di;
    a = 0;
    b = r;
    di = 3 - (r << 1);             //判断下个点位置的标志
    while (a <= b) {
        LCD_DrawPoint(x0 + a, y0 - b, POINT_COLOR);             //5
        LCD_DrawPoint(x0 + b, y0 - a, POINT_COLOR);             //0
        LCD_DrawPoint(x0 + b, y0 + a, POINT_COLOR);             //4
        LCD_DrawPoint(x0 + a, y0 + b, POINT_COLOR);             //6
        LCD_DrawPoint(x0 - a, y0 + b, POINT_COLOR);             //1
        LCD_DrawPoint(x0 - b, y0 + a, POINT_COLOR);
        LCD_DrawPoint(x0 - a, y0 - b, POINT_COLOR);             //2
        LCD_DrawPoint(x0 - b, y0 - a, POINT_COLOR);             //7
        a++;
        //使用Bresenham算法画圆     
        if (di < 0)di += 4 * a + 6;
        else {
            di += 10 + 4 * (a - b);
            b--;
        }
    }
}

//在指定位置显示一个字符
//x,y:起始坐标
//num:要显示的字符:" "--->"~"
//size:字体大小 12/16/24
//mode:叠加方式(1)还是非叠加方式(0)
void LCD_ShowChar(uint16_t x, uint16_t y, uint8_t num, uint8_t size, uint8_t mode) {
    uint8_t temp, t1, t;
    uint16_t y0 = y;
    uint8_t csize = (size / 8 + ((size % 8) ? 1 : 0)) * (size / 2);        //得到字体一个字符对应点阵集所占的字节数
    num = num - ' ';//得到偏移后的值（ASCII字库是从空格开始取模，所以-' '就是对应字符的字库）

//	Address_set(x,y,x+size-1,y+size-1);
    for (t = 0; t < csize; t++) {
        if (size == 12)temp = asc2_1206[num][t];        //调用1206字体
        else if (size == 16)temp = asc2_1608[num][t];    //调用1608字体
        else if (size == 24)temp = asc2_2412[num][t];    //调用2412字体
        else return;                                //没有的字库
        for (t1 = 0; t1 < 8; t1++) {
            if (temp & 0x80)LCD_DrawPoint(x, y, POINT_COLOR);
            else if (mode == 0)LCD_DrawPoint(x, y, BACK_COLOR);
            temp <<= 1;
            y++;
            if (y >= 240)return;        //超区域了
            if ((y - y0) == size) {
                y = y0;
                x++;
                if (x >= 320)return;    //超区域了
                break;
            }
        }
    }
}

//m^n函数
//返回值:m^n次方.
uint32_t LCD_Pow(uint8_t m, uint8_t n) {
    uint32_t result = 1;
    while (n--)result *= m;
    return result;
}

//显示数字,高位为0,则不显示
//x,y :起点坐标	 
//len :数字的位数
//size:字体大小
//color:颜色 
//num:数值(0~4294967295);	 
void LCD_ShowNum(uint16_t x, uint16_t y, uint32_t num, uint8_t len, uint8_t size) {
    uint8_t t, temp;
    uint8_t enshow = 0;
    for (t = 0; t < len; t++) {
        temp = (num / LCD_Pow(10, len - t - 1)) % 10;
        if (enshow == 0 && t < (len - 1)) {
            if (temp == 0) {
                LCD_ShowChar(x + (size / 2) * t, y, ' ', size, 0);
                continue;
            } else enshow = 1;

        }
        LCD_ShowChar(x + (size / 2) * t, y, temp + '0', size, 0);
    }
}

//显示数字,高位为0,还是显示
//x,y:起点坐标
//num:数值(0~999999999);	 
//len:长度(即要显示的位数)
//size:字体大小
//mode:
//[7]:0,不填充;1,填充0.
//[6:1]:保留
//[0]:0,非叠加显示;1,叠加显示.
void LCD_ShowxNum(uint16_t x, uint16_t y, uint32_t num, uint8_t len, uint8_t size, uint8_t mode) {
    uint8_t t, temp;
    uint8_t enshow = 0;
    for (t = 0; t < len; t++) {
        temp = (num / LCD_Pow(10, len - t - 1)) % 10;
        if (enshow == 0 && t < (len - 1)) {
            if (temp == 0) {
                if (mode & 0X80)LCD_ShowChar(x + (size / 2) * t, y, '0', size, mode & 0X01);
                else LCD_ShowChar(x + (size / 2) * t, y, ' ', size, mode & 0X01);
                continue;
            } else enshow = 1;

        }
        LCD_ShowChar(x + (size / 2) * t, y, temp + '0', size, mode & 0X01);
    }
}

//显示字符串
//x,y:起点坐标
//width,height:区域大小  
//size:字体大小
//*p:字符串起始地址		  
void LCD_ShowString(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint8_t size, uint8_t *p) {
    uint8_t x0 = x;
    width += x;
    height += y;
    while ((*p <= '~') && (*p >= ' '))//判断是不是非法字符!
    {
        if (x >= width) {

            x = x0;
            y += size;
        }
        if (y >= height)break;//退出
        LCD_ShowChar(x, y, *p, size, 0);
        x += size / 2;
        p++;
    }
}





































