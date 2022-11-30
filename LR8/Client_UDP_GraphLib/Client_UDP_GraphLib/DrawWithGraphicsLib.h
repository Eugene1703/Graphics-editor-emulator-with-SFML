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
using namespace std;
class DrawWithGraphicsLib : public GraphicsLib
{
public:DrawWithGraphicsLib()
{
	if (!connect(buff, &my_sock))
	{
		exit(0);
	}
	HOSTENT* hst;
	dest_addr;
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(PORT);
	if (inet_addr(SERVERADDR))
		dest_addr.sin_addr.s_addr = inet_addr(SERVERADDR);
	else
		if (hst = gethostbyname(SERVERADDR))
			dest_addr.sin_addr.s_addr = ((unsigned long**)
				hst->h_addr_list)[0][0];
}
	  bool connect(char* buff, SOCKET* my_sock)
	  {
		  if (WSAStartup(0x202, (WSADATA*)&buff[0]))
		  {
			  printf("WSAStartup error: %d\n", WSAGetLastError());
			  return false;
		  }

		  *my_sock = socket(AF_INET, SOCK_DGRAM, 0);
		  if (*my_sock == INVALID_SOCKET)
		  {
			  printf("socket() error: %d\n", WSAGetLastError());
			  WSACleanup();
			  return false;
		  }
		  return true;
	  }
	  int_least16_t getWidth()
	  {
		  snprintf(buff, length, "E");
		  send(buff);
		  char answ_width[length];
		  recvfrom(my_sock, answ_width, sizeof(answ_width) - 1, 0, (sockaddr*)&dest_addr, &dest_addr_size);
		  int_least16_t width = strtol(answ_width, &end, 10);
		  return width;
	  }
	  int_least16_t getHeight()
	  {
		  snprintf(buff, length, "F");
		  send(buff);
		  char answ_height[length];
		  recvfrom(my_sock, answ_height, sizeof(answ_height) - 1, 0, (sockaddr*)&dest_addr, &dest_addr_size);
		  int_least16_t height = strtol(answ_height, &end, 10);
		  return height;
	  }
	  void fillScreen(uint_least16_t color) override
	  {
		  snprintf(buff, length, "0 %x %x %x", red888(color), green888(color), blue888(color));
		  send(buff);
	  }
	  void drawPixel(int_least16_t x0, int_least16_t y0, uint_least16_t color) override
	  {
		  snprintf(buff, length, "1 %d %d %x %x %x", x0, y0, red888(color), green888(color), blue888(color));
		  send(buff);
	  }
	  void drawLine(int_least16_t x0, int_least16_t y0, int_least16_t x1, int_least16_t y1, uint_least16_t color)  override
	  {
		  snprintf(buff, length, "2 %d %d %d %d %x %x %x", x0, y0, x1, y1, red888(color), green888(color), blue888(color));
		  send(buff);
	  }
	  void drawRect(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h, uint_least16_t color) override
	  {
		  snprintf(buff, length, "3 %d %d %d %d %x %x %x", x0, y0, w, h, red888(color), green888(color), blue888(color));
		  send(buff);
	  }
	  void fillRect(int_least16_t x0, int_least16_t y0, int_least16_t w, int_least16_t h, uint_least16_t color) override
	  {
		  snprintf(buff, length, "4 %d %d %d %d %x %x %x", x0, y0, w, h, red888(color), green888(color), blue888(color));
		  send(buff);
	  }
	  void drawEllipse(int_least16_t x0, int_least16_t y0, int_least16_t r_x, int_least16_t r_y, uint_least16_t color) override
	  {
		  snprintf(buff, length, "5 %d %d %d %d %x %x %x", x0, y0, r_x, r_y, red888(color), green888(color), blue888(color));
		  send(buff);
	  }
	  void fillEllipse(int_least16_t x0, int_least16_t y0, int_least16_t r_x, int_least16_t r_y, uint_least16_t color) override
	  {
		  snprintf(buff, length, "6 %d %d %d %d %x %x %x", x0, y0, r_x, r_y, red888(color), green888(color), blue888(color));
		  send(buff);
	  }
	  int_least16_t drawChar(int_least16_t x, int_least16_t y, char c, uint_least16_t color, uint_least16_t bg, uint_least8_t size) override
	  {
		  snprintf(buff, length, "8 %d %d %x %x %x %x %x %x %d %c", x, y, red888(color), green888(color), blue888(color), red888(bg), green888(bg), blue888(bg), size, c);
		  send(buff);
		  recvfrom(my_sock, answer, sizeof(answer) - 1, 0, (sockaddr*)&dest_addr, &dest_addr_size);
		  int x_ = strtol(answer, &end, 10);
		  return x_;
	  }
	  int_least16_t drawChar(int_least16_t x, int_least16_t y, unsigned char c, uint_least16_t color, uint_least16_t bg, uint_least8_t size) override
	  {
		  snprintf(buff, length, "8 %d %d %x %x %x %x %x %x %d %c", x, y, red888(color), green888(color), blue888(color),red888(bg),green888(bg),blue888(bg), size, c);
		  send(buff);
		  recvfrom(my_sock, answer, sizeof(answer) - 1, 0, (sockaddr*)&dest_addr, &dest_addr_size);
		  int x_ = strtol(answer, &end, 10);
		  return x_;
	  }
	  int_least16_t drawText(int_least16_t x, int_least16_t y, const char* s, uint_least16_t color, uint_least16_t bg, uint_least8_t size)override
	  {
		  size_t new_size = snprintf(NULL, 0, "B %d %d %x %x %x %x %x %x %d %s", x, y, red888(color), green888(color), blue888(color), red888(bg), green888(bg), blue888(bg), size, s) + sizeof('\0');
		  char*new_buff = new char[new_size];
		  snprintf(new_buff, new_size, "B %d %d %x %x %x %x %x %x %d %s", x, y, red888(color), green888(color), blue888(color), red888(bg), green888(bg), blue888(bg), size, s);
		  send(new_buff);
		  recvfrom(my_sock, answer, sizeof(answer) - 1, 0, (sockaddr*)&dest_addr, &dest_addr_size);
		  int x_ = strtol(answer, &end, 10);
		  delete[] new_buff;
		  return x_;
	  }
	  void loadSprite(uint_least8_t index, int_least16_t width, int_least16_t height, char* data)
	  {
		  snprintf(buff, length, "9 %d %d %d %s", index,width, height, data);
		  send(buff);
	  }
	  void showSprite(uint_least8_t index, uint_least16_t x, uint_least16_t y)
	  {
		  snprintf(buff, length, "A %d %d %d",index, x, y);
		  send(buff);
	  }
	  void setOrientation(int_least16_t orientation) 
	  {
		  snprintf(buff, length, "D %d", orientation );
		  send(buff);
	  }
	  ~DrawWithGraphicsLib() 
	  {
		  closesocket(my_sock);
		  WSACleanup();
	  }
	  void send(char* cmd)
	  {
		  cout << cmd << endl;
		  sendto(my_sock, cmd, strlen(cmd), 0, (sockaddr*)&dest_addr, sizeof(dest_addr));
	  }
private:
	static const unsigned char length = 200;
	char buff[length];
	char answer[length];
	char* end;
	sockaddr_in dest_addr;
	int dest_addr_size = sizeof(dest_addr);
	SOCKET my_sock;

};
