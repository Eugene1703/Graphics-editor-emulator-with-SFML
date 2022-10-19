#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#pragma comment ( lib, "ws2_32.lib" )
#include <iostream>
#include <winsock2.h>
#include <iostream>
#include <string>
#include <Windows.h>
#define PORT 7777   
using namespace std;
#define SERVERADDR "127.0.0.1"
int main(int argc, char* argv[])
{
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char buff[10 * 1014];
    if (WSAStartup(0x202, (WSADATA*)&buff[0]))
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
    
    while (true)
    {
        cout << endl <<"Введіть команду:" << endl; 
        cout << "1 - Очистка дисплею" << endl;
        cout << "2 - Піксель" << endl;
        cout << "3 - Лінія" << endl;
        cout << "4 - Прямокутник" << endl;
        cout << "5 - Заповненний прямокутник" << endl;
        cout << "6 - Еліпс" << endl;
        cout << "7 - Заповенний еліпс" << endl;
        cout << "8 - Коло" << endl;
        cout << "9 - Заповнене коло" << endl;
        cout << "10 - Обрізаний прямокутник" << endl;
        cout << "11 - Заповнений обрізаний прямокутник" << endl;\
        cout << "12 - Текст" << endl;
        cout << "13 - Картинка" << endl;
        cout << "14 - Встановлення орієнтації" << endl;
        cout << "15 - Отримати висоту/ширину" << endl;
        fgets(&buff[0], sizeof(buff) - 1, stdin);
        sendto(my_sock, &buff[0], strlen(&buff[0]), 0, (sockaddr*)&dest_addr, sizeof(dest_addr));
        sockaddr_in server_addr;
        int server_addr_size = sizeof(server_addr);
        int n = recvfrom(my_sock, &buff[0], sizeof(buff) - 1, 0,
            (sockaddr*)&server_addr, &server_addr_size);
        if (n == SOCKET_ERROR)
        {
            printf("recvfrom() error:"\
                "%d\n", WSAGetLastError());
            closesocket(my_sock);
            WSACleanup();
            return -1;
        }
        buff[n] = 0;
        cout << endl << "Відповідь серверу :" << &buff[0] << endl;
    }
    closesocket(my_sock);
    WSACleanup();
    return 0;
}
