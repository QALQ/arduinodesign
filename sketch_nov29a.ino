
 
// 引入IIC通讯所需的Wire库文件
// reference： http://www.taichi-maker.com/homepage/reference-index/arduino-library-index/wire-library/
#include <Wire.h>
 #include "Arduino_SensorKit.h"
 
// 引入驱动OLED0.96所需的库
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define SCREEN_WIDTH 128 // 设置OLED宽度,单位:像素
#define SCREEN_HEIGHT 64 // 设置OLED高度,单位:像素
 
// 自定义重置引脚,虽然教程未使用,但却是Adafruit_SSD1306库文件所必需的
#define OLED_RESET 4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
 
static const unsigned char PROGMEM poda1_bmp[] =

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x00,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x07,0xC0,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x00,0x01,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x60,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x01,0xB0,0x00,0x20,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x30,0x00,0xF8,0x00,0x00,0x03,0xD8,0x00,0x30,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x60,0x01,0xFC,0x00,0x00,0x03,0x98,0x00,0x10,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x40,0x01,0x9C,0x00,0x00,0x03,0x18,0x00,0x18,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x40,0x01,0x8C,0x00,0x00,0x03,0x18,0x00,0x08,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x40,0x01,0x0C,0x00,0x00,0x03,0x18,0x00,0x08,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xC0,0x01,0x04,0x00,0x00,0x03,0x38,0x00,0x0C,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x80,0x01,0x8C,0x00,0x00,0x01,0xF8,0x00,0x04,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x80,0x00,0xCC,0x00,0x00,0x00,0x30,0x00,0x04,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x80,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x0F,0xFF,0x00,0x00,0x00,0x02,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x02,0x02,0x00,0x00,0x00,0x02,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x03,0x06,0x00,0x00,0x00,0x06,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x01,0x9C,0x00,0x00,0x00,0x04,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x04,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x00,0x1F,0x03,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xFF,0xFF,0xF1,0xFE,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

static const unsigned char PROGMEM poda2_bmp[] =

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xC1,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xC0,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0xE1,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x01,0xB1,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x20,0xF8,0x00,0x00,0x03,0xD8,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x61,0xFC,0x00,0x00,0x03,0x98,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x41,0x9C,0x00,0x00,0x03,0x18,0x40,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x41,0x8C,0x00,0x00,0x03,0x18,0x60,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x41,0x0C,0x00,0x00,0x03,0x18,0x20,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xC1,0x04,0x00,0x00,0x03,0x38,0x30,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x81,0x8C,0x00,0x00,0x01,0xF8,0x10,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0xCC,0x00,0x00,0x00,0x30,0x18,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x78,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x07,0xFF,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x04,0x01,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x04,0x03,0x00,0x00,0x18,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x04,0x02,0x00,0x00,0x10,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x06,0x06,0x00,0x00,0x10,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x02,0x0C,0x00,0x00,0x18,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x03,0x98,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0xF0,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x20,0x0C,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x20,0x33,0x80,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x3F,0xE3,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

static const unsigned char PROGMEM poda3_bmp[] =

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x07,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xC1,0xC0,0x00,0x1D,0x80,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x0E,0x00,0x00,0x70,0x00,0x70,0x00,0x10,0x80,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x0B,0x00,0x01,0xC0,0x00,0x18,0x00,0x10,0xC0,0x00,0xC0,0x00,
0x00,0x00,0x06,0x00,0x09,0x00,0x07,0x00,0x00,0x0E,0x00,0x18,0x40,0x00,0xC0,0x00,
0x00,0x00,0x07,0x00,0x09,0x80,0x0C,0x00,0x00,0x03,0x00,0x08,0x60,0x00,0x60,0x00,
0x00,0x00,0x07,0x80,0x08,0x80,0x18,0x00,0x00,0x01,0x80,0x08,0x20,0x00,0x30,0x00,
0x00,0x00,0x02,0xC0,0x08,0xC0,0x30,0x00,0x00,0x00,0xC0,0x08,0x10,0x00,0x3C,0x00,
0x00,0x00,0x02,0x40,0x18,0x60,0xE0,0x00,0x00,0x00,0x60,0x18,0x18,0x00,0x36,0x00,
0x00,0x00,0x06,0x40,0x10,0x31,0x80,0x00,0x00,0x00,0x30,0x30,0x06,0x00,0x13,0x00,
0x00,0x00,0x0C,0x40,0x10,0x13,0x00,0x00,0x00,0x00,0x18,0x60,0x03,0x00,0x11,0x80,
0x00,0x00,0x18,0x40,0x30,0x16,0x00,0x00,0x00,0x00,0x0B,0xC0,0x01,0x80,0x10,0x80,
0x00,0x00,0x70,0x40,0x60,0x1C,0x00,0x00,0x00,0x00,0x0E,0x00,0x00,0x80,0x30,0x80,
0x00,0x00,0xC0,0x40,0xC0,0x08,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x80,0xE0,0x80,
0x00,0x00,0x80,0x40,0x80,0x18,0x01,0x80,0x00,0x87,0x03,0x00,0x00,0x81,0x80,0x80,
0x00,0x00,0x80,0x60,0x80,0x10,0x1F,0x00,0x00,0xDC,0x01,0x00,0x00,0x82,0x00,0x80,
0x00,0x00,0x80,0x30,0x80,0x30,0x06,0x00,0x00,0x70,0x01,0x80,0x00,0x82,0x00,0xC0,
0x00,0x00,0xC0,0x18,0x80,0x20,0x0F,0x80,0x01,0xD8,0x00,0x80,0x00,0x82,0x00,0x40,
0x00,0x00,0x40,0x0C,0xC0,0x60,0x18,0xC0,0x07,0x0E,0x00,0xC0,0x00,0xC3,0x00,0x60,
0x00,0x00,0x40,0x04,0x40,0x40,0x70,0x60,0x04,0x03,0x00,0x40,0x00,0x71,0x00,0x30,
0x00,0x00,0x40,0x06,0x40,0x40,0x40,0x20,0x00,0x01,0x80,0x60,0x00,0x1F,0x00,0x10,
0x00,0x00,0x40,0x02,0xC0,0x40,0x00,0x00,0x00,0x00,0x80,0x20,0x00,0x00,0x00,0x18,
0x00,0x00,0x40,0x02,0x80,0xC0,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x0C,
0x00,0x00,0xC0,0x02,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x06,
0x00,0x03,0x80,0x03,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x03,
0x00,0x02,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x01,
0x00,0x02,0x00,0x00,0x00,0x80,0x00,0x07,0xC0,0x00,0x00,0x08,0x00,0x00,0x00,0x01,
0x00,0x03,0x00,0x00,0x00,0x80,0x00,0x1C,0x70,0x00,0x00,0x08,0x00,0x00,0x00,0x01,
0x00,0x01,0x80,0x00,0x00,0x80,0x00,0x30,0x10,0x00,0x00,0x08,0x00,0x00,0x00,0x01,
0x00,0x00,0xC0,0x00,0x00,0x80,0x00,0x20,0x18,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x40,0x00,0x00,0x80,0x00,0x60,0x08,0x00,0x00,0x18,0x00,0x00,0x00,0x00,
0x00,0x00,0x40,0x00,0x00,0x80,0x00,0x40,0x0C,0x00,0x00,0x10,0x00,0x00,0x00,0x00,
0x00,0x00,0x40,0x00,0x00,0x80,0x00,0xC0,0x0C,0x00,0x00,0x10,0x00,0x00,0x00,0x00,
0x00,0x00,0xC0,0x00,0x00,0x80,0x00,0x7F,0xF8,0x00,0x00,0x18,0x00,0x00,0x00,0x00,
0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x20,0x0C,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x20,0x33,0x80,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x3F,0xE3,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};



 
static const unsigned char PROGMEM poda4_bmp[] =

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x80,0x70,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x06,0xC0,0xDC,0x00,0x00,0x01,0x80,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x0C,0x63,0x07,0xC0,0x00,0x03,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x08,0x3A,0x03,0x40,0x00,0x03,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x01,0xA0,0x00,0x18,0x0E,0x00,0x60,0x00,0x3F,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x03,0x20,0x1F,0x90,0x00,0x00,0x20,0x00,0xE2,0x00,0x00,0x00,
0x00,0x00,0x01,0xC0,0x0E,0x20,0x30,0xF0,0x00,0x00,0x30,0x01,0x82,0x00,0x01,0x00,
0x00,0x03,0x03,0x40,0x08,0x20,0x20,0x00,0x00,0x00,0x10,0x06,0x1E,0x00,0x03,0x00,
0x00,0x03,0x06,0xC0,0x08,0x20,0x60,0x00,0x00,0x00,0x18,0x0C,0x10,0x00,0x03,0x80,
0x00,0x03,0x84,0x80,0x18,0x70,0x40,0x00,0x00,0x00,0x0C,0x18,0x18,0x00,0x02,0x80,
0x00,0x06,0xCC,0x80,0x10,0x11,0xC0,0x00,0x00,0x00,0x04,0x10,0x1C,0x00,0x02,0x80,
0x00,0x04,0x68,0x80,0x30,0x13,0x00,0x00,0x00,0x00,0x04,0x30,0x00,0x00,0x02,0x80,
0x00,0x04,0x38,0x80,0x20,0x16,0x00,0x00,0x00,0x00,0x06,0xE0,0x03,0x00,0x06,0xC0,
0x00,0x04,0x18,0x80,0x60,0x04,0x00,0x00,0x00,0x00,0x03,0xA0,0x01,0x80,0x1C,0x60,
0x00,0x04,0x00,0xC0,0x40,0x0C,0x06,0x00,0x00,0x06,0x02,0x00,0x00,0x80,0x70,0x20,
0x00,0x06,0x00,0x60,0xC0,0x08,0x03,0x00,0x00,0x0C,0x02,0x00,0x00,0x80,0xC0,0x60,
0x00,0x03,0x00,0x60,0x80,0x08,0x01,0x80,0x00,0x38,0x03,0x00,0x00,0x81,0x80,0xC0,
0x00,0x01,0x80,0x60,0x80,0x08,0x00,0xC0,0x00,0xF0,0x03,0x00,0x00,0x82,0x00,0x80,
0x00,0x01,0x80,0x30,0x80,0x08,0x0F,0x80,0x00,0x0C,0x01,0x00,0x00,0x82,0x00,0x80,
0x00,0x00,0x80,0x18,0x80,0x08,0x38,0x00,0x00,0x06,0x01,0x80,0x00,0x82,0x00,0xC0,
0x00,0x00,0xC0,0x0C,0xC0,0x08,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0xC3,0x00,0x60,
0x00,0x00,0x40,0x04,0x40,0x08,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x71,0x00,0x30,
0x00,0x00,0x40,0x06,0x40,0x08,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x1F,0x00,0x10,
0x00,0x00,0xC0,0x02,0xC0,0x08,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x18,
0x00,0x00,0xC0,0x02,0x80,0x18,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x0C,
0x00,0x00,0xC0,0x02,0x80,0x10,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x06,
0x00,0x00,0x80,0x03,0x80,0x30,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x03,
0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x01,
0x00,0x02,0x00,0x00,0x00,0xC0,0x00,0x07,0xC0,0x00,0x00,0x68,0x00,0x00,0x00,0x01,
0x00,0x03,0x00,0x00,0x00,0x80,0x00,0x1C,0x70,0x00,0x00,0x20,0x00,0x00,0x00,0x01,
0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x30,0x10,0x00,0x00,0x30,0x00,0x00,0x00,0x01,
0x00,0x00,0xC0,0x00,0x01,0x00,0x00,0x20,0x18,0x00,0x00,0x10,0x00,0x00,0x00,0x00,
0x00,0x00,0x40,0x00,0x01,0x00,0x00,0x60,0x08,0x00,0x00,0x10,0x00,0x00,0x00,0x00,
0x00,0x00,0x40,0x00,0x01,0x00,0x00,0x40,0x0C,0x00,0x00,0x18,0x00,0x00,0x00,0x00,
0x00,0x00,0x40,0x00,0x01,0x00,0x00,0xC0,0x0C,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0xC0,0x00,0x01,0x00,0x00,0x7F,0xF8,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x80,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x11,0xFE,0x1F,0x8F,0x80,0x00,0x0C,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xF0,0xF8,0xC3,0xF0,0x3C,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x1F,0xEC,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};


static const unsigned char PROGMEM poda5_bmp[] =

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xC1,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xC0,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x0F,0xFF,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x18,0x00,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x60,0x7F,0xF0,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x1F,0x80,0x60,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x40,0x1F,0xE0,0x00,0x00,0xF8,0x20,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x30,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x0E,0x00,0x00,0x18,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x1E,0x1B,0x08,0x00,0x10,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x33,0x11,0x88,0x00,0x10,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x61,0xF0,0xF8,0x00,0x18,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x20,0x0C,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x20,0x33,0x80,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x3F,0xE3,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};



static const unsigned char PROGMEM poda6_bmp[] =

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xC1,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xC0,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x30,0x07,0xE0,0x00,0x1F,0xC3,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x20,0xF8,0x00,0x00,0x00,0x70,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x80,0x7F,0xFF,0x00,0x7F,0xFC,0x20,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x30,0x30,0x00,0x00,0x20,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x10,0xF8,0xF0,0x00,0x38,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x3F,0x8D,0x80,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x01,0x87,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x18,0x0C,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x0C,0x33,0x80,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x0F,0xE3,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
void setup()
{
    // 初始化OLED并设置其IIC地址为 0x3C
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    Serial.begin(9600);
    Environment.begin();
}
 
void loop()
{

    if(Environment.readTemperature()>28)
    {bmp2_display();}
    if((Environment.readTemperature()<28)||(Environment.readTemperature()>20))
    {bmp1_display();}
       if(Environment.readTemperature()<20)
    {bmp3_display();}
    Serial.print("Temperature = ");
  Serial.print(Environment.readTemperature()); //print temperature
  Serial.println(" C");
  
}
 
void bmp1_display(void)
{
 
    display.clearDisplay();
 

    display.drawBitmap(0,0,poda1_bmp, 128, 64, 1);
 
    display.display();
 
    delay(100);




    display.clearDisplay();
 

    display.drawBitmap(0,0,poda2_bmp, 128, 64, 1);
 
    display.display();
 
    delay(100);
}

void bmp2_display(void)
{
  
    display.clearDisplay();
 

    display.drawBitmap(0,0,poda3_bmp, 128, 64, 1);
 
  
    display.display();
 
    delay(100);



  
    display.clearDisplay();
 
  
    display.drawBitmap(0,0,poda4_bmp, 128, 64, 1);
 
  
    display.display();
 
    delay(100);
}

void bmp3_display(void)
{
   
    display.clearDisplay();
 
    display.drawBitmap(0,0,poda5_bmp, 128, 64, 1);
 

    display.display();
 
    delay(100);




    display.clearDisplay();
 

    display.drawBitmap(0,0,poda6_bmp, 128, 64, 1);
 

    display.display();
 
    delay(100);
}
