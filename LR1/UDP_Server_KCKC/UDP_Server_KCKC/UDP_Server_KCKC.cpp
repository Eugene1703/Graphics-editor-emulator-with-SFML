#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#pragma comment ( lib, "ws2_32.lib" )
#include <iostream>
#include <winsock2.h>
#include <string>
#include <Windows.h>
#include <sstream>
#include"parser.h"
#define PORT 7777   
using namespace std;

int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool end_prog = false;
    char buff[1024], buff_[1024];
    if (WSAStartup(0x202, (WSADATA*)&buff[0]))
    {
        printf("WSAStartup error: %d\n", WSAGetLastError());
        return -1;
    };
    SOCKET Socket;
    Socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (Socket == INVALID_SOCKET)
    {
        printf("Socket() error: %d\n", WSAGetLastError());
        WSACleanup();
        return -1;
    };

    sockaddr_in local_addr;
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = INADDR_ANY;
    local_addr.sin_port = htons(PORT);

    if (bind(Socket, (sockaddr*)&local_addr, sizeof(local_addr)))
    {
        printf("bind error: %d\n", WSAGetLastError());
        system("pause");
        closesocket(Socket);
        WSACleanup();
        return -1;
    };
    while (!end_prog)
    {
        sockaddr_in client_addr;
        int client_addr_size = sizeof(client_addr);
        int bsize = recvfrom(Socket, &buff[0], sizeof(buff) - 1, 0, (sockaddr*)&client_addr, &client_addr_size);
        if (bsize == SOCKET_ERROR) {
            printf("recvfrom() error: %d\n", WSAGetLastError());
        };
        HOSTENT* hst;
        hst = gethostbyaddr((char*)&client_addr.sin_addr, 4, AF_INET);
        printf("+%s [%s:%d] new DATAGRAM!\n", (hst) ? hst->h_name : "Unknown host", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        buff[bsize - 1] = ' ';
        buff[bsize] = 0;
        printf("C=>S:%s\n", &buff[0]);
        string cmd = &buff[0];
        string err;
        parser my_parser;
        my_parser.parse(const_cast<char*>(cmd.c_str()));
        if (my_parser.my_answer.check)
        {
            cout << "Команда (" << my_parser.my_answer.comm_id << ") виконана і має наступні параметри:" << endl;
            switch (my_parser.my_answer.comm_id)
            {
            case CLEAR_DISPLAY:
                break;
            case DRAW_PIXEL:
                cout << "x0 = " << my_parser.my_answer.x0 << endl;
                cout << "y0 = " << my_parser.my_answer.y0 << endl;
                break;
            case DRAW_LINE:
                cout << "x0 = " << my_parser.my_answer.x0 << endl;
                cout << "y0 = " << my_parser.my_answer.y0 << endl;
                cout << "x1 = " << my_parser.my_answer.x1 << endl;
                cout << "y1 = " << my_parser.my_answer.y1 << endl;
                break;
            case DRAW_RECTANGLE:
                cout << "x0 = " << my_parser.my_answer.x0 << endl;
                cout << "y0 = " << my_parser.my_answer.y0 << endl;
                cout << "w = " << my_parser.my_answer.w << endl;
                cout << "h = " << my_parser.my_answer.h << endl;
                break;
            case DRAW_FILL_RECTANGLE:
                cout << "x0 = " << my_parser.my_answer.x0 << endl;
                cout << "y0 = " << my_parser.my_answer.y0 << endl;
                cout << "w = " << my_parser.my_answer.w << endl;
                cout << "h = " << my_parser.my_answer.h << endl;
                break;
            case DRAW_ELLIPSE:
                cout << "x0 = " << my_parser.my_answer.x0 << endl;
                cout << "y0 = " << my_parser.my_answer.y0 << endl;
                cout << "radius_x = " << my_parser.my_answer.radius_x << endl;
                cout << "radius_y = " << my_parser.my_answer.radius_y << endl;
                break;
            case DRAW_FILL_ELLIPSE:
                cout << "x0 = " << my_parser.my_answer.x0 << endl;
                cout << "y0 = " << my_parser.my_answer.y0 << endl;
                cout << "radius_x = " << my_parser.my_answer.radius_x << endl;
                cout << "radius_y = " << my_parser.my_answer.radius_y << endl;
                break;
            case DRAW_CIRCLE:
                cout << "x0 = " << my_parser.my_answer.x0 << endl;
                cout << "y0 = " << my_parser.my_answer.y0 << endl;
                cout << "radius = " << my_parser.my_answer.radius << endl;
                break;
            case DRAW_FILL_CIRCLE:
                cout << "x0 = " << my_parser.my_answer.x0 << endl;
                cout << "y0 = " << my_parser.my_answer.y0 << endl;
                cout << "radius = " << my_parser.my_answer.radius << endl;
                break;
            case DRAW_ROUNDED_RECTANGLE:
                cout << "x0 = " << my_parser.my_answer.x0 << endl;
                cout << "y0 = " << my_parser.my_answer.y0 << endl;
                cout << "w = " << my_parser.my_answer.w << endl;
                cout << "h = " << my_parser.my_answer.h << endl;
                cout << "radius =" << my_parser.my_answer.radius << endl;
                break;
            case DRAW_FILL_ROUNDED_RECTANGLE:
                cout << "x0 = " << my_parser.my_answer.x0 << endl;
                cout << "y0 = " << my_parser.my_answer.y0 << endl;
                cout << "w = " << my_parser.my_answer.w << endl;
                cout << "h = " << my_parser.my_answer.h << endl;
                cout << "radius =" << my_parser.my_answer.radius << endl;
                break;
            case DRAW_TEXT:
                cout << "x0 = " << my_parser.my_answer.x0 << endl;
                cout << "y0 = " << my_parser.my_answer.y0 << endl;
                cout << "font= " << my_parser.my_answer.font << endl;
                cout << "length= " << my_parser.my_answer.length << endl;
                cout << "text=" << my_parser.my_answer.text << endl;
                break;
            case DRAW_IMAGE:
                cout << "x0 = " << my_parser.my_answer.x0 << endl;
                cout << "y0 = " << my_parser.my_answer.y0 << endl;
                cout << "w = " << my_parser.my_answer.w << endl;
                cout << "h = " << my_parser.my_answer.h << endl;
                break;
            case SET_ORIENTATION:
                cout << "orientation = " << my_parser.my_answer.orientation;
                break;
            case GET_WIDTH:
                cout << "Width = " << my_parser.my_answer.width;
                break;
            case GET_HEIGHT:
                cout << "Height = " << my_parser.my_answer.height;
                break;
            }
            if (my_parser.my_answer.comm_id != GET_HEIGHT && my_parser.my_answer.comm_id !=GET_WIDTH && my_parser.my_answer.comm_id !=SET_ORIENTATION && my_parser.my_answer.comm_id!=DRAW_TEXT)
            {
                cout << "Color_R = " << my_parser.my_answer.R << endl;
                cout << "Color_G = " << my_parser.my_answer.G << endl;
                cout << "Color_B = " << my_parser.my_answer.B << endl;
            }
        }
        if (my_parser.my_answer.check == false)
        {
            err = my_parser.my_answer.error;
            cout << err << endl;
            strcpy(buff_, err.c_str());
        }
        else strcpy(buff_, "\nКоманда виконана\n\n");
        int bsize_;
        bsize_ = strlen(buff_);
        sendto(Socket, &buff_[0], bsize_, 0, (sockaddr*)&client_addr, sizeof(client_addr));
    }
    return 0;
}
