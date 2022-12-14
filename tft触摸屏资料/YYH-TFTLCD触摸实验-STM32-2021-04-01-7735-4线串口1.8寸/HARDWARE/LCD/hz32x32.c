


#ifndef HZ32x32_H
#define HZ32x32_H


// ------------------  汉字字模的数据结构定义 ------------------------ //
struct  typFNT_HZ32                 // 汉字字模数据结构 
{
       unsigned char  Index[3];               // 汉字内码索引	
       unsigned char   Msk[128];                        // 点阵码数据 
};

/////////////////////////////////////////////////////////////////////////
// 汉字字模表                                                          //
// 汉字库: 宋体32.dot,横向取模左高位,数据排列:从左到右从上到下         //
/////////////////////////////////////////////////////////////////////////
struct  typFNT_HZ32 codeHZ_32[] =          // 数据表 
{

/*--  文字:  耀  --*/
/*--  新宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
"耀",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x30,0x18,0x03,0xCF,0xFF,0xFC,
0x03,0x86,0x3F,0x38,0x63,0xB7,0x3B,0xB8,0x73,0xBF,0xBB,0xF8,0x3B,0xFB,0xB9,0xF8,
0x3B,0xF3,0xF9,0xF8,0x3F,0xE1,0xF9,0xF8,0x1F,0xC7,0xBF,0xB8,0x1B,0x8F,0x3F,0x38,
0x03,0x84,0xFC,0x38,0x03,0xB9,0xEF,0x00,0xFF,0xFD,0xE7,0x10,0x6F,0xC3,0xC7,0x38,
0x0F,0xC3,0xFF,0xFC,0x0F,0xC7,0x8E,0x00,0x0F,0xC7,0x8E,0x00,0x0F,0xCF,0x8E,0x70,
0x0D,0xDF,0xFF,0xF8,0x1D,0xDF,0x8E,0x00,0x1D,0xDF,0x8E,0x20,0x1D,0xFB,0x8E,0x70,
0x1D,0xF3,0xFF,0xF8,0x19,0xF3,0x8E,0x00,0x39,0xE3,0x8E,0x08,0x30,0xC3,0x8E,0x1C,
0x70,0x03,0xFF,0xFE,0x60,0x03,0x80,0x00,0x40,0x03,0x80,0x00,0x00,0x00,0x00,0x00,

/*--  文字:  元  --*/
/*--  新宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
"元",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xC0,
0x03,0xFF,0xFF,0xE0,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x78,
0x3F,0xFF,0xFF,0xFC,0x18,0x1C,0x78,0x00,0x00,0x1C,0x78,0x00,0x00,0x1C,0x78,0x00,
0x00,0x1C,0x78,0x00,0x00,0x3C,0x78,0x00,0x00,0x3C,0x78,0x00,0x00,0x38,0x78,0x00,
0x00,0x38,0x78,0x0C,0x00,0x78,0x78,0x0C,0x00,0x70,0x78,0x1C,0x00,0xF0,0x78,0x1C,
0x00,0xE0,0x78,0x1C,0x01,0xE0,0x78,0x1C,0x03,0xC0,0x78,0x1E,0x07,0x80,0x3F,0xFE,
0x0F,0x00,0x3F,0xFC,0x3C,0x00,0x00,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

/*--  文字:  鸿  --*/
/*--  新宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
"鸿",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x07,0x00,0x1E,0x00,0x07,0x00,
0x0F,0x00,0x0E,0x00,0x07,0x00,0x0C,0x30,0x03,0x00,0x7F,0xF8,0x00,0xC3,0x70,0x78,
0x01,0xFF,0xF0,0x70,0x61,0xBC,0x7E,0x70,0x79,0x9C,0x77,0x70,0x3D,0x9C,0x77,0x70,
0x1F,0x9C,0x73,0x70,0x1B,0x1C,0x70,0x70,0x03,0x1C,0x77,0xF0,0x03,0x1C,0x71,0xE0,
0x07,0x1C,0x70,0x80,0x06,0x1C,0x70,0x18,0x06,0x1C,0xFF,0xFC,0x0E,0x1F,0xF0,0x3C,
0x7E,0x3F,0x00,0x3C,0x3F,0xF8,0x00,0x3C,0x1F,0xE0,0x03,0xBC,0x0E,0xCF,0xFF,0xF8,
0x0E,0x06,0x00,0x38,0x1E,0x00,0x00,0x38,0x1E,0x00,0x00,0x38,0x1E,0x00,0x0C,0x78,
0x1E,0x00,0x0F,0xF8,0x1E,0x00,0x03,0xF0,0x00,0x00,0x01,0xE0,0x00,0x00,0x00,0x00,

/*--  文字:  科  --*/
/*--  新宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
"科",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x01,0xC0,0x00,0x1C,0x01,0xE0,
0x00,0xFE,0x01,0xC0,0x0F,0xF8,0x01,0xC0,0x3E,0xE0,0xC1,0xC0,0x00,0xE0,0x71,0xC0,
0x00,0xE0,0x79,0xC0,0x00,0xE0,0x3D,0xC0,0x00,0xE0,0x19,0xC0,0x00,0xEE,0x19,0xC0,
0x7F,0xFF,0x01,0xC0,0x31,0xE0,0x01,0xC0,0x01,0xE0,0xE1,0xC0,0x01,0xE0,0x71,0xC0,
0x03,0xF8,0x79,0xC0,0x03,0xFC,0x39,0xC8,0x07,0xFE,0x11,0xDE,0x0F,0xEE,0x01,0xFE,
0x0E,0xE6,0x3F,0xC0,0x1C,0xE7,0xF9,0xC0,0x38,0xE7,0x01,0xC0,0x70,0xE0,0x01,0xC0,
0x60,0xE0,0x01,0xC0,0x00,0xE0,0x01,0xC0,0x00,0xE0,0x01,0xC0,0x00,0xE0,0x01,0xC0,
0x00,0xE0,0x01,0xC0,0x00,0xE0,0x01,0xC0,0x00,0xC0,0x01,0xC0,0x00,0x00,0x00,0x00,

/*--  文字:  技  --*/
/*--  新宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
"技",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x80,0x1C,0x00,0x03,0xE0,0x1F,0x00,
0x03,0xC0,0x1E,0x00,0x03,0xC0,0x1E,0x00,0x03,0xC0,0x1E,0x00,0x03,0xC0,0x1E,0x00,
0x03,0xD8,0x1E,0x38,0x7F,0xFF,0xFF,0xFC,0x23,0xC1,0x1E,0x00,0x03,0xC0,0x1E,0x00,
0x03,0xC0,0x1E,0x00,0x03,0xC0,0x1E,0x00,0x03,0xDC,0x1E,0x70,0x03,0xFF,0xFF,0xF8,
0x03,0xE1,0xC0,0xF0,0x1F,0xC0,0xC0,0xE0,0x7F,0xC0,0xC0,0xE0,0x3B,0xC0,0xE1,0xC0,
0x33,0xC0,0x61,0xC0,0x03,0xC0,0x73,0x80,0x03,0xC0,0x3F,0x80,0x03,0xC0,0x3F,0x00,
0x03,0xC0,0x1E,0x00,0x03,0xC0,0x3E,0x00,0x03,0xC0,0x7F,0x80,0x33,0xC1,0xF3,0xE0,
0x3F,0xC7,0xC1,0xFE,0x0F,0x9F,0x00,0xFE,0x07,0x78,0x00,0x38,0x00,0x00,0x00,0x00,


/*--  文字:  带  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
"带",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC1,0x86,0x00,0x00,0xF1,0xE7,0x80,
0x00,0xF1,0xC7,0x00,0x00,0xE1,0xC7,0x00,0x00,0xE1,0xC7,0x38,0x3F,0xFF,0xFF,0xFC,
0x00,0xF1,0xC7,0x04,0x00,0xF1,0xC7,0x00,0x00,0xF1,0xC7,0x00,0x00,0xE1,0x87,0x00,
0x0C,0x00,0x00,0x1C,0x0F,0xFF,0xFF,0xFC,0x1C,0x01,0x80,0x3E,0x3C,0x01,0xC0,0x30,
0x7C,0x01,0xC0,0x60,0x39,0x81,0xC1,0xE0,0x01,0xFF,0xFF,0xE0,0x01,0xC1,0xC1,0xC0,
0x01,0xC1,0xC1,0xC0,0x01,0xC1,0xC1,0xC0,0x01,0xC1,0xC1,0xC0,0x01,0xC1,0xC1,0xC0,
0x01,0xC1,0xC1,0xC0,0x01,0xC1,0xC1,0xC0,0x01,0xC1,0xFF,0xC0,0x01,0xC1,0xCF,0x80,
0x01,0x81,0xC7,0x80,0x00,0x01,0xC0,0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x00,0x00,



/*--  文字:  进  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
"进",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x86,0x00,0x0C,0x01,0xE7,0x80,
0x0E,0x01,0xE7,0x80,0x07,0x81,0xC7,0x00,0x07,0x81,0xC7,0x00,0x03,0xC1,0xC7,0x30,
0x03,0x81,0xC7,0x38,0x00,0x3F,0xFF,0xFC,0x00,0x01,0xC7,0x00,0x00,0x01,0xC7,0x00,
0x03,0x01,0xC7,0x00,0x07,0x81,0xC7,0x00,0xFF,0xC1,0xC7,0x00,0x03,0x81,0xC7,0x18,
0x03,0x81,0xC7,0x3C,0x03,0xFF,0xFF,0xF6,0x03,0x81,0xC7,0x80,0x03,0x81,0xC7,0x80,
0x03,0x83,0xC7,0x80,0x03,0x83,0x87,0x80,0x03,0x87,0x07,0x80,0x03,0x87,0x07,0x80,
0x07,0x8E,0x07,0x80,0x1F,0xDC,0x07,0x80,0x7C,0xF0,0x07,0x80,0x78,0x78,0x06,0x00,
0x30,0x3F,0xFF,0xFE,0x00,0x07,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,



/*--  文字:  入  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
"入",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,
0x00,0x7C,0x00,0x00,0x00,0xCF,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x03,0x80,0x00,
0x00,0x03,0x80,0x00,0x00,0x03,0xC0,0x00,0x00,0x07,0xC0,0x00,0x00,0x07,0xC0,0x00,
0x00,0x07,0xE0,0x00,0x00,0x0F,0xE0,0x00,0x00,0x0E,0xF0,0x00,0x00,0x1E,0x70,0x00,
0x00,0x1C,0x78,0x00,0x00,0x3C,0x38,0x00,0x00,0x38,0x3C,0x00,0x00,0x78,0x1C,0x00,
0x00,0x70,0x1E,0x00,0x00,0xE0,0x0F,0x00,0x01,0xC0,0x07,0x80,0x03,0xC0,0x03,0xC0,
0x07,0x80,0x03,0xE0,0x0F,0x00,0x01,0xF8,0x1C,0x00,0x00,0xFE,0x38,0x00,0x00,0x78,
0x70,0x00,0x00,0x10,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,


/*--  文字:  的  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
"的",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x18,0x00,0x01,0xF0,0x1E,0x00,
0x01,0xE0,0x1E,0x00,0x01,0xC0,0x3C,0x00,0x01,0xC0,0x38,0x00,0x19,0x8C,0x38,0x00,
0x1F,0x1E,0x70,0x38,0x1F,0xFF,0x7F,0xFC,0x1C,0x1E,0xE0,0x38,0x1C,0x1E,0xE0,0x38,
0x1C,0x1F,0xC0,0x38,0x1C,0x1F,0x80,0x38,0x1C,0x1F,0x60,0x38,0x1C,0x1F,0x70,0x38,
0x1C,0x1E,0x38,0x38,0x1F,0xFE,0x3C,0x38,0x1C,0x1E,0x1C,0x38,0x1C,0x1E,0x1C,0x38,
0x1C,0x1E,0x1C,0x78,0x1C,0x1E,0x00,0x78,0x1C,0x1E,0x00,0x78,0x1C,0x1E,0x00,0x78,
0x1C,0x1E,0x00,0x78,0x1C,0x1E,0x00,0x78,0x1C,0x1E,0x00,0x70,0x1F,0xFE,0x1C,0xF0,
0x1C,0x1E,0x0F,0xF0,0x1C,0x1C,0x03,0xE0,0x18,0x00,0x01,0xC0,0x00,0x00,0x00,0x00,



/*--  文字:  世  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
"世",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x07,0x07,0xC0,
0x00,0x07,0x87,0x80,0x07,0x87,0x07,0x80,0x07,0x87,0x03,0x80,0x07,0x87,0x03,0x80,
0x07,0x87,0x03,0x80,0x07,0x87,0x03,0x80,0x07,0x87,0x03,0x9C,0x07,0x87,0x03,0xBE,
0x7F,0xFF,0xFF,0xF6,0x07,0x87,0x03,0x80,0x07,0x87,0x03,0x80,0x07,0x87,0x03,0x80,
0x07,0x87,0x03,0x80,0x07,0x87,0x03,0x80,0x07,0x87,0x03,0x80,0x07,0x87,0x03,0x80,
0x07,0x87,0x03,0x80,0x07,0x87,0x03,0x80,0x07,0x87,0xFF,0x80,0x07,0x87,0x03,0x80,
0x07,0x87,0x03,0x00,0x07,0x86,0x00,0x00,0x07,0x80,0x00,0x00,0x07,0x80,0x00,0x1C,
0x07,0x80,0x00,0x3E,0x07,0xFF,0xFF,0xE6,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,


/*--  文字:  界  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
"界",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x80,0x01,0xC0,
0x03,0xFF,0xFF,0xE0,0x03,0x81,0xC1,0xC0,0x03,0x81,0xC1,0xC0,0x03,0x81,0xC1,0xC0,
0x03,0xFF,0xFF,0xC0,0x03,0x81,0xC1,0xC0,0x03,0x81,0xC1,0xC0,0x03,0x81,0xC1,0xC0,
0x03,0x81,0xC1,0xC0,0x03,0xFF,0xFF,0xC0,0x03,0x8F,0x31,0x80,0x00,0x0E,0x18,0x00,
0x00,0x1C,0x1C,0x00,0x00,0x38,0x0F,0x00,0x00,0x7C,0x1F,0xC0,0x01,0xFE,0x1F,0xFE,
0x03,0x9C,0x1C,0x7C,0x0E,0x1C,0x1C,0x18,0x78,0x1C,0x1C,0x00,0x00,0x3C,0x1C,0x00,
0x00,0x38,0x1C,0x00,0x00,0x38,0x1C,0x00,0x00,0x70,0x1C,0x00,0x00,0xE0,0x1C,0x00,
0x01,0xC0,0x1C,0x00,0x07,0x00,0x1C,0x00,0x3C,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,


/*--  文字:  欢  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x32   --*/
"欢",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x38,0x00,
0x00,0x00,0x38,0x00,0x00,0x08,0x70,0x00,0x3F,0xFC,0x70,0x00,0x3F,0xFC,0x60,0x00,
0x00,0x38,0x60,0x18,0x00,0x38,0xFF,0xFC,0x30,0x38,0xC0,0x3C,0x18,0x30,0xC8,0x38,
0x0C,0x71,0x8E,0x30,0x06,0x71,0x8C,0x60,0x03,0x63,0x1E,0x00,0x03,0xE3,0x1E,0x00,
0x01,0xC6,0x1E,0x00,0x01,0xE0,0x1E,0x00,0x01,0xE0,0x1A,0x00,0x03,0xF0,0x1B,0x00,
0x03,0x78,0x3B,0x00,0x07,0x38,0x33,0x00,0x06,0x3C,0x73,0x80,0x0C,0x1C,0x61,0x80,
0x0C,0x1C,0xE1,0xC0,0x18,0x0D,0xC0,0xE0,0x30,0x01,0x80,0xF0,0x60,0x07,0x00,0x78,
0x00,0x0E,0x00,0x3E,0x00,0x38,0x00,0x1E,0x00,0x60,0x00,0x10,0x00,0x00,0x00,0x00,

/*--  文字:  迎  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x32   --*/
"迎",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x0E,0x00,0x70,0x00,
0x07,0x00,0xF8,0x00,0x03,0x9B,0xE0,0x10,0x03,0x9F,0x0F,0xFC,0x03,0x8C,0x0C,0x38,
0x00,0x0C,0x0C,0x38,0x00,0x0C,0x0C,0x38,0x00,0x0C,0x0C,0x38,0x03,0x0C,0x0C,0x38,
0x7F,0x8C,0x0C,0x38,0x23,0x8C,0x0C,0x38,0x03,0x0C,0x0C,0x38,0x03,0x0C,0x0C,0x38,
0x03,0x0C,0x0C,0x38,0x03,0x0C,0x2C,0x38,0x03,0x0D,0xEC,0x38,0x03,0x1F,0x8C,0x38,
0x03,0x1F,0x0D,0xF8,0x03,0x0E,0x0C,0xF0,0x03,0x08,0x0C,0x70,0x07,0x00,0x0C,0x00,
0x1F,0x80,0x0C,0x00,0x3C,0xE0,0x0C,0x00,0x78,0x78,0x00,0x00,0x30,0x3F,0xFF,0xFE,
0x00,0x0F,0xFF,0xFC,0x00,0x00,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

/*--  文字:  你  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x32   --*/
"你",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0xC0,0x00,0x00,0x78,0xF0,0x00,
0x00,0xF0,0xF0,0x00,0x00,0xE1,0xE0,0x00,0x01,0xC1,0xC0,0x00,0x01,0xC1,0x80,0x10,
0x01,0x83,0x80,0x38,0x03,0x83,0xFF,0xFC,0x03,0x87,0x00,0x38,0x07,0xC6,0x1C,0x70,
0x07,0x8C,0x1C,0x60,0x0D,0x8C,0x1C,0x40,0x1D,0x98,0x1C,0x00,0x19,0x93,0x1C,0x00,
0x31,0x83,0xDD,0x80,0x61,0x83,0x9C,0xC0,0x41,0x83,0x9C,0x60,0x01,0x87,0x1C,0x70,
0x01,0x87,0x1C,0x38,0x01,0x8E,0x1C,0x3C,0x01,0x8C,0x1C,0x1C,0x03,0x9C,0x1C,0x1C,
0x03,0x98,0x1C,0x1C,0x03,0xB0,0x1C,0x0C,0x03,0xA0,0x1C,0x08,0x03,0xA1,0x3C,0x00,
0x03,0x81,0xFC,0x00,0x03,0x80,0x78,0x00,0x03,0x00,0x30,0x00,0x00,0x00,0x00,0x00,

/*--  文字:  ！  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x32   --*/
"！",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0xF0,0x00,0x00,
0x00,0xF0,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0xF0,0x00,0x00,
0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x00,0x00,
0x00,0x60,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x60,0x00,0x00,
0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x01,0xF0,0x00,0x00,
0x01,0xF0,0x00,0x00,0x01,0xF0,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

 	
};

#endif




		
