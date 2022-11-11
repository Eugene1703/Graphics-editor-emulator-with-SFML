
#include "DrawWithGraphicsLib.h"
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	DrawWithGraphicsLib draw(1280, 720);
    if (WSAStartup(0x202, (WSADATA*)&draw.buff[0]))
    {
        printf("WSAStartup error: %d\n", WSAGetLastError());
        return -1;
    }
    SOCKET my_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (my_sock == INVALID_SOCKET)
    {
        printf("socket() error: %d\n", WSAGetLastError());
        WSACleanup();
        return -1;
    }
    HOSTENT* hst;
    sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(PORT);
    if (inet_addr(SERVERADDR))
        dest_addr.sin_addr.s_addr = inet_addr(SERVERADDR);
    else
        if (hst = gethostbyname(SERVERADDR))
            dest_addr.sin_addr.s_addr = ((unsigned long**)
                hst->h_addr_list)[0][0];
        draw.fillScreen(RGB(255, 255, 255));
        std::cout << draw.buff << std::endl;
        sendto(my_sock, &draw.buff[0], strlen(&draw.buff[0]), 0, (sockaddr*)&dest_addr, sizeof(dest_addr));
    draw.drawLine(100, 100, 900, 900, RGB(150, 120, 200));
    std::cout << draw.buff << std::endl;
    sendto(my_sock, &draw.buff[0], strlen(&draw.buff[0]), 0, (sockaddr*)&dest_addr, sizeof(dest_addr));
    draw.drawRect(200, 200, 50, 70, RGB(0, 255, 0));
    std::cout << draw.buff << std::endl;
    sendto(my_sock, &draw.buff[0], strlen(&draw.buff[0]), 0, (sockaddr*)&dest_addr, sizeof(dest_addr));
    draw.drawPixel(250, 200, RGB(255, 0, 255));
    std::cout << draw.buff << std::endl;
    sendto(my_sock, &draw.buff[0], strlen(&draw.buff[0]), 0, (sockaddr*)&dest_addr, sizeof(dest_addr));
    draw.drawEllipse(400, 400, 50, 90, RGB(255, 150, 111));
    std::cout << draw.buff << std::endl;
    sendto(my_sock, &draw.buff[0], strlen(&draw.buff[0]), 0, (sockaddr*)&dest_addr, sizeof(dest_addr));
    draw.fillEllipse(500, 500, 90, 100, RGB(122, 15, 110));
    std::cout << draw.buff << std::endl;
    sendto(my_sock, &draw.buff[0], strlen(&draw.buff[0]), 0, (sockaddr*)&dest_addr, sizeof(dest_addr));
    draw.fillRect(700, 200, 200, 200, RGB(100, 100, 100));
    std::cout << draw.buff << std::endl;
    sendto(my_sock, &draw.buff[0], strlen(&draw.buff[0]), 0, (sockaddr*)&dest_addr, sizeof(dest_addr));
    draw.drawChar(300, 300, 'A', RGB(140, 120, 100), 1, 20);
    std::cout << draw.buff << std::endl;
    sendto(my_sock, &draw.buff[0], strlen(&draw.buff[0]), 0, (sockaddr*)&dest_addr, sizeof(dest_addr));
    draw.drawChar(400, 300, unsigned char('255'), RGB(140, 120, 100), 1, 20);
    std::cout << draw.buff << std::endl;
    sendto(my_sock, &draw.buff[0], strlen(&draw.buff[0]), 0, (sockaddr*)&dest_addr, sizeof(dest_addr));
    draw.drawText(500, 300, "Semioshko", RGB(140, 120, 100), 10, 20);
    std::cout << draw.buff << std::endl;
    sendto(my_sock, &draw.buff[0], strlen(&draw.buff[0]), 0, (sockaddr*)&dest_addr, sizeof(dest_addr));
    draw.showSprite(1,1000, 1000);
    draw.loadSprite(1, 2, 2, (char*)"ff aa cc bb ff aa ac bc aa ff ee be");
    std::cout << draw.buff << std::endl;
    sendto(my_sock, &draw.buff[0], strlen(&draw.buff[0]), 0, (sockaddr*)&dest_addr, sizeof(dest_addr));
    return 0;
}

