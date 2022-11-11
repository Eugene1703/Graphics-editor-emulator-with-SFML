#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define red888(color) ((color & 0xF800) >> 8)
#define green888(color) ((color & 0x07E0) >> 3)
#define blue888(color) ((color & 0x001F) << 3)
#define PORT 7777 
#define SERVERADDR "127.0.0.1"
#include "GraphicsLib.h"
#include <winsock.h>
#pragma warning (disable:4996)
#pragma comment (lib, "ws2_32.lib")
#include<iostream>
#include <Windows.h>
class DrawWithGraphicsLib : public GraphicsLib 
{
public:DrawWithGraphicsLib(uint_least16_t w, uint_least16_t h) : GraphicsLib(w, h) 
	{

	}
	void fillScreen(uint_least16_t color) override 
	{
		snprintf(buff,length, "0 %x %x %x", red888(color),green888(color),blue888(color));
	}
	void drawPixel(int_least16_t x0, int_least16_t y0, uint_least16_t color) override 
	{
		snprintf(buff, length, "1 %d %d %x %x %x", x0, y0, red888(color), green888(color), blue888(color));
	}
	void drawLine(int_least16_t x0, int_least16_t y0, int_least16_t x1, int_least16_t y1, uint_least16_t color)  override
	{
		snprintf(buff, length, "2 %d %d %d %d %x %x %x", x0, y0, x1, y1 ,red888(color), green888(color), blue888(color));
	}
	void drawRect(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h, uint_least16_t color) override
	{
		snprintf(buff, length, "3 %d %d %d %d %x %x %x", x0, y0, w, h, red888(color), green888(color), blue888(color));
	}
	void fillRect(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h, uint_least16_t color) override
	{
		snprintf(buff, length, "4 %d %d %d %d %x %x %x", x0, y0, w, h, red888(color), green888(color), blue888(color));
	}
	void drawEllipse(int_least16_t x0, int_least16_t y0, int_least16_t r_x, int_least16_t r_y, uint_least16_t color) override
	{
		snprintf(buff, length, "5 %d %d %d %d %x %x %x", x0, y0, r_x, r_y, red888(color), green888(color), blue888(color));
	}
	void fillEllipse(int_least16_t x0, int_least16_t y0, int_least16_t r_x, int_least16_t r_y, uint_least16_t color) override 
	{
		snprintf(buff, length, "6 %d %d %d %d %x %x %x", x0, y0, r_x, r_y, red888(color), green888(color), blue888(color));
	}
	int_least16_t drawChar(int_least16_t x, int_least16_t y, char c, uint_least16_t color, uint_least16_t bg, uint_least8_t size) override
	{
		snprintf(buff, length, "B %d %d %x %x %x %d %d %c", x, y, red888(color), green888(color), blue888(color), size, bg, c);
		return x + size;
	}
	int_least16_t drawChar(int_least16_t x, int_least16_t y, unsigned char c, uint_least16_t color, uint_least16_t bg, uint_least8_t size) override
	{
		snprintf(buff, length, "B %d %d %x %x %x %d %d %c", x, y, red888(color), green888(color), blue888(color), size, bg, c);
		return x + size;
	}
	virtual int_least16_t drawText(int_least16_t x, int_least16_t y, const char* s, uint_least16_t color, uint_least16_t bg, uint_least8_t size)override
	{
		snprintf(buff, length, "B %d %d %x %x %x %d %d %s", x, y, red888(color), green888(color), blue888(color), size, bg, s);
		return x + size * bg;
	}
	void loadSprite(uint_least8_t index, int_least16_t width, int_least16_t height, char* data) 
	{
		snprintf(buff, length, "C %d %d %d %d %s", x_, y_, width, height, data);
	}
	void showSprite(uint_least8_t index, uint_least16_t x, uint_least16_t y) 
	{
		x_ = x;
		y_ = y;
	}
	static const unsigned char length = 200;
	char buff[length];
	int x_, y_;
};
