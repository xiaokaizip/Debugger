
#ifndef HZ16x16_H
#define HZ16x16_H


// ------------------  汉字字模的数据结构定义 ------------------------ //
 struct  typFNT_HZ16                      // 汉字字模数据结构 
{
       unsigned char  Index[3];          // 汉字内码索引		   存放内码  如"硕"  但是一个字要两个字节表示
       unsigned char   Msk[32];          // 点阵码数据 	  存放内码后对应的 点阵序列  每个字需要32个字节的点阵序列
};

/////////////////////////////////////////////////////////////////////////
// 汉字字模表                                                          //
// 汉字库: 宋体16.dot,横向取模左高位,数据排列:从左到右从上到下         //
/////////////////////////////////////////////////////////////////////////
/*这个结构，很简单的：一个是内码，一个点阵序列，
以前的点阵库是按内码顺序放的，不需要内码索引的，
如果只放部分汉字，就需要内码索引了。
一般内码两个字节就行了，多用1个字节是加了个尾0而已，
这样，汉字内码处直接放汉字字符串就可；	  */

struct  typFNT_HZ16 codeHZ_16[] =          // 数据表 
{

/*--  文字:  深  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"深",0x00,0x00,0x27,0xFC,0x14,0x04,0x14,0xA4,0x81,0x10,0x42,0x08,0x40,0x40,0x10,0x40,
0x17,0xFC,0x20,0x40,0xE0,0xE0,0x21,0x50,0x22,0x48,0x2C,0x46,0x20,0x40,0x00,0x40,

/*--  文字:  圳  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"圳",0x11,0x04,0x11,0x24,0x11,0x24,0x11,0x24,0x11,0x24,0xFD,0x24,0x11,0x24,0x11,0x24,
0x11,0x24,0x11,0x24,0x11,0x24,0x1D,0x24,0xE1,0x24,0x42,0x24,0x02,0x04,0x04,0x04,

/*--  文字:  耀  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"耀",0x10,0x00,0x11,0xDC,0x90,0x44,0x55,0x54,0x58,0xCC,0x11,0x54,0xFC,0x00,0x28,0x48,
0x28,0xFE,0x29,0x90,0x2A,0xFC,0x28,0x90,0x2A,0xFC,0x4C,0x90,0x48,0xFE,0x80,0x80,

/*--  文字:  元  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"元",0x00,0x00,0x3F,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFE,0x04,0x40,0x04,0x40,
0x04,0x40,0x04,0x40,0x08,0x40,0x08,0x42,0x10,0x42,0x20,0x42,0x40,0x3E,0x80,0x00,

/*--  文字:  鸿  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"鸿",0x00,0x10,0x80,0x20,0x40,0x7C,0x1F,0x44,0x84,0x64,0x44,0x54,0x44,0x44,0x04,0x4C,
0x24,0x40,0x44,0x7E,0xC4,0x02,0x47,0x02,0x5C,0x7A,0x48,0x02,0x40,0x0A,0x00,0x04,

/*--  文字:  科  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"科",0x08,0x10,0x1D,0x10,0xF0,0x90,0x10,0x90,0x10,0x10,0xFD,0x10,0x10,0x90,0x38,0x90,
0x34,0x10,0x50,0x1E,0x53,0xF0,0x90,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,

/*--  文字:  技  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"技",0x10,0x20,0x10,0x20,0x10,0x20,0x13,0xFE,0xFC,0x20,0x10,0x20,0x10,0x20,0x15,0xFC,
0x18,0x84,0x30,0x88,0xD0,0x48,0x10,0x50,0x10,0x20,0x10,0x50,0x51,0x88,0x26,0x06,



/*--  文字:  ，  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"，",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x30,0x00,0x10,0x00,0x20,0x00,0x00,0x00,

/*--  文字:  。  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"。",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x30,0x00,0x48,0x00,0x48,0x00,0x30,0x00,0x00,0x00,0x00,0x00,



/*--  文字:  白  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"白",0x01,0x00,0x02,0x00,0x04,0x00,0x3F,0xF8,0x20,0x08,0x20,0x08,0x20,0x08,0x20,0x08,
0x3F,0xF8,0x20,0x08,0x20,0x08,0x20,0x08,0x20,0x08,0x20,0x08,0x3F,0xF8,0x20,0x08,

/*--  文字:  发  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"发",0x01,0x00,0x11,0x10,0x11,0x08,0x22,0x00,0x3F,0xFC,0x02,0x00,0x04,0x00,0x07,0xF8,
0x0A,0x08,0x09,0x08,0x11,0x10,0x10,0xA0,0x20,0x40,0x40,0xA0,0x03,0x18,0x1C,0x06,

/*--  文字:  三  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"三",0x00,0x00,0x00,0x00,0x7F,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xF8,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFE,0x00,0x00,0x00,0x00,

/*--  文字:  千  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"千",0x00,0x10,0x00,0xF8,0x3F,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0xFF,0xFE,
0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,

/*--  文字:  丈  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"丈",0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x7F,0xFC,0x00,0x80,0x10,0x80,0x10,0x80,
0x08,0x80,0x04,0x80,0x02,0x80,0x01,0x00,0x02,0x80,0x04,0x40,0x18,0x30,0xE0,0x0E,

/*--  文字:  缘  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"缘",0x10,0x80,0x10,0xFC,0x21,0x04,0x21,0xF8,0x48,0x08,0xFB,0xFE,0x10,0x40,0x20,0xA2,
0x43,0x34,0xF8,0x58,0x40,0x94,0x03,0x34,0x18,0x52,0xE0,0x90,0x43,0x50,0x00,0x20,

/*--  文字:  愁  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"愁",0x0E,0x20,0x78,0x20,0x08,0x24,0x08,0xA4,0xFE,0xA8,0x19,0x20,0x2C,0x50,0x4A,0x50,
0x88,0x88,0x09,0x04,0x0A,0x02,0x01,0x00,0x28,0x88,0x28,0xA4,0x48,0x24,0x07,0xE0,

/*--  文字:  似  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"似",0x10,0x08,0x11,0x08,0x10,0x88,0x24,0x48,0x24,0x48,0x64,0x08,0x64,0x08,0xA4,0x08,
0x24,0x10,0x24,0x10,0x24,0x10,0x25,0x28,0x26,0x24,0x24,0x44,0x20,0x82,0x21,0x02,

/*--  文字:  个  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"个",0x01,0x00,0x01,0x00,0x02,0x80,0x04,0x40,0x08,0x20,0x10,0x10,0x21,0x08,0xC1,0x06,
0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,

/*--  文字:  长  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"长",0x08,0x00,0x08,0x10,0x08,0x20,0x08,0x40,0x08,0x80,0x09,0x00,0x08,0x00,0xFF,0xFE,
0x0A,0x00,0x09,0x00,0x08,0x80,0x08,0x40,0x09,0x20,0x0A,0x18,0x0C,0x06,0x08,0x00,

/*--  文字:  数  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"数",0x08,0x20,0x49,0x20,0x2A,0x20,0x08,0x3E,0xFF,0x44,0x2A,0x44,0x49,0x44,0x88,0xA4,
0x10,0x28,0xFE,0x28,0x22,0x10,0x42,0x10,0x64,0x28,0x18,0x28,0x34,0x44,0xC2,0x82,

/*--  文字:  据  --*/
/*--  新宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"据",0x20,0x00,0x23,0xFC,0x22,0x04,0x22,0x04,0xFB,0xFC,0x22,0x20,0x22,0x20,0x2B,0xFE,
0x32,0x20,0xE2,0x20,0x22,0xFC,0x22,0x84,0x22,0x84,0x24,0x84,0xA4,0xFC,0x48,0x84,

};


#endif