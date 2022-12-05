#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define NOMINMAX
#include <iostream>
#include <winsock2.h>
#pragma comment ( lib, "ws2_32.lib" )
#include <Windows.h>
#include "parser.h"
#include "draw.h"
#include "SFML/Network.hpp"
using namespace std;
using namespace sf;
#define PORT 7777  
int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool end_prog = false;
    int Display_R=255, Display_G=255, Display_B=255;
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
        parser my_parser(720, 1280);
        string cmd[1000], cmd_buff[1000];
        int i = 0,outline_th=5;
        RenderWindow window(VideoMode(my_parser.my_answer.width, my_parser.my_answer.height), "Semioshko KCKC");
        View view;
        view.setRotation(0);
        while (window.isOpen())
        {
            sockaddr_in client_addr;
            int client_addr_size = sizeof(client_addr);
            int bsize = recvfrom(Socket, buff, sizeof(buff) - 1, 0, (sockaddr*)&client_addr, &client_addr_size);
            if (bsize > 0)
            {
                HOSTENT* hst;
                hst = gethostbyaddr((char*)&client_addr.sin_addr, 4, AF_INET);
                printf("+%s [%s:%d] new DATAGRAM!\n", (hst) ? hst->h_name : "Unknown host", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                buff[bsize] = '\0';
                printf("C=>S:%s\n", &buff[0]);
                cmd[i] = &buff[0];
                cmd_buff[i] = cmd[i];
                string err;
                window.clear(Color(Display_R, Display_G, Display_B));
                for (int k = 0; k <= i; k++)
                {
                    my_parser.parse(const_cast<char*>(cmd[k].c_str()));
                    cmd[k] = cmd_buff[k];

                    if (my_parser.my_answer.check)
                    {

                        cout << "Команда (" << my_parser.my_answer.comm_id << ") виконана і має наступні параметри:" << endl;
                        switch (my_parser.my_answer.comm_id)
                        {
                        case CLEAR_DISPLAY:
                            window.clear(Color(my_parser.my_answer.R, my_parser.my_answer.G, my_parser.my_answer.B));
                            Display_R = my_parser.my_answer.R;
                            Display_G = my_parser.my_answer.G;
                            Display_B = my_parser.my_answer.B;
                            break;
                        case DRAW_PIXEL:
                        {
                            cout << "x0 = " << my_parser.my_answer.x0 << endl;
                            cout << "y0 = " << my_parser.my_answer.y0 << endl;
                            RectangleShape pixel = draw_pixel(Vector2f(my_parser.my_answer.x0, my_parser.my_answer.y0), my_parser.my_answer.R, my_parser.my_answer.G, my_parser.my_answer.B);
                            window.draw(pixel);
                            break;
                        }
                        case DRAW_LINE:
                        {
                            cout << "x0 = " << my_parser.my_answer.x0 << endl;
                            cout << "y0 = " << my_parser.my_answer.y0 << endl;
                            cout << "x1 = " << my_parser.my_answer.x1 << endl;
                            cout << "y1 = " << my_parser.my_answer.y1 << endl;
                            Vertex line[] =
                            {
                                Vertex(Vector2f(my_parser.my_answer.x0,my_parser.my_answer.y0)),
                                Vertex(Vector2f(my_parser.my_answer.x1,my_parser.my_answer.y1))
                            };
                            line->color = Color(my_parser.my_answer.R, my_parser.my_answer.G, my_parser.my_answer.B);
                            window.draw(line, 2, Lines);
                            break;
                        }
                        case DRAW_RECTANGLE:
                        {
                            cout << "x0 = " << my_parser.my_answer.x0 << endl;
                            cout << "y0 = " << my_parser.my_answer.y0 << endl;
                            cout << "w = " << my_parser.my_answer.w << endl;
                            cout << "h = " << my_parser.my_answer.h << endl;
                            RectangleShape rectangle = draw_rectangle(Vector2f(my_parser.my_answer.w, my_parser.my_answer.h), Vector2f(my_parser.my_answer.x0, my_parser.my_answer.y0), Display_R, Display_G, Display_B, outline_th, my_parser.my_answer.R, my_parser.my_answer.G, my_parser.my_answer.B);
                            window.draw(rectangle);
                            break;
                        }
                        case DRAW_FILL_RECTANGLE:
                        {
                            cout << "x0 = " << my_parser.my_answer.x0 << endl;
                            cout << "y0 = " << my_parser.my_answer.y0 << endl;
                            cout << "w = " << my_parser.my_answer.w << endl;
                            cout << "h = " << my_parser.my_answer.h << endl;
                            RectangleShape rectangle = draw_rectangle(Vector2f(my_parser.my_answer.w, my_parser.my_answer.h), Vector2f(my_parser.my_answer.x0, my_parser.my_answer.y0), my_parser.my_answer.R, my_parser.my_answer.G, my_parser.my_answer.B);
                            window.draw(rectangle);
                            break;
                        }
                        case DRAW_ELLIPSE:
                        {
                            cout << "x0 = " << my_parser.my_answer.x0 << endl;
                            cout << "y0 = " << my_parser.my_answer.y0 << endl;
                            cout << "radius_x = " << my_parser.my_answer.radius_x << endl;
                            cout << "radius_y = " << my_parser.my_answer.radius_y << endl;
                            ConvexShape ellipse = draw_ellipse(my_parser.my_answer.radius_x, my_parser.my_answer.radius_y, my_parser.my_answer.x0, my_parser.my_answer.y0, Display_R, Display_G, Display_B, outline_th, my_parser.my_answer.R, my_parser.my_answer.G, my_parser.my_answer.B);
                            window.draw(ellipse);
                            break;
                        }
                        case DRAW_FILL_ELLIPSE:
                        {
                            cout << "x0 = " << my_parser.my_answer.x0 << endl;
                            cout << "y0 = " << my_parser.my_answer.y0 << endl;
                            cout << "radius_x = " << my_parser.my_answer.radius_x << endl;
                            cout << "radius_y = " << my_parser.my_answer.radius_y << endl;
                            ConvexShape ellipse = draw_ellipse(my_parser.my_answer.radius_x, my_parser.my_answer.radius_y, my_parser.my_answer.x0, my_parser.my_answer.y0, my_parser.my_answer.R, my_parser.my_answer.G, my_parser.my_answer.B);
                            window.draw(ellipse);
                            break;
                        }
                        case DRAW_CIRCLE:
                        {
                            cout << "x0 = " << my_parser.my_answer.x0 << endl;
                            cout << "y0 = " << my_parser.my_answer.x0 << endl;
                            cout << "radius = " << my_parser.my_answer.radius << endl;
                            CircleShape circle = draw_circle(my_parser.my_answer.radius, my_parser.my_answer.x0, my_parser.my_answer.y0, Display_R, Display_G, Display_B, outline_th, my_parser.my_answer.R, my_parser.my_answer.G, my_parser.my_answer.B);
                            window.draw(circle);
                            break;
                        }
                        case DRAW_CHAR:
                        {
                            cout << "x0 = " << my_parser.my_answer.x0 << endl;
                            cout << "y0 = " << my_parser.my_answer.y0 << endl;
                            cout << "size= " << my_parser.my_answer.font << endl;
                            cout << "char=" << my_parser.my_answer.text << endl;
                            double bg_w = (my_parser.my_answer.font * my_parser.my_answer.text.length()) / 1.66;
                            RectangleShape rectangle = draw_rectangle(Vector2f(bg_w, my_parser.my_answer.font), Vector2f(my_parser.my_answer.x0, my_parser.my_answer.y0+4), my_parser.my_answer.bg_r, my_parser.my_answer.bg_g, my_parser.my_answer.bg_b);
                            Text text = draw_text(my_parser.my_answer.x0, my_parser.my_answer.y0, my_parser.my_answer.font, my_parser.my_answer.text, my_parser.my_answer.R, my_parser.my_answer.G, my_parser.my_answer.B);
                            window.draw(rectangle);
                            window.draw(text);
                            break;
                        }
                        case LOAD_SPRITE:
                        {
                            cout << "Завантажено спрайт з індексом: " << my_parser.my_answer.sprite_index << endl;
                            cout << "w = " << my_parser.my_answer.w << endl;
                            cout << "h = " << my_parser.my_answer.h << endl;
                            cout << "data: " << endl;
                            int ind = my_parser.my_answer.sprite_index - 1;
                            for (int i = 0; i < my_parser.my_sprite[ind].data_length; i++)
                            {
                                cout << my_parser.my_sprite[ind].data_arr[i] << " ";
                            }
                            cout << endl;
                            break;
                        }
                        case SHOW_SPRITE:
                        {
                            int ind = my_parser.my_answer.sprite_index-1;
                            int k = 0;
                            for (int i = 0; i < my_parser.my_sprite[ind].w; i++)
                            {
                                int x0 = my_parser.my_answer.x0;
                                for (int j = 0; j < my_parser.my_sprite[ind].h; j++)
                                {
                                    RectangleShape pixel = draw_pixel(Vector2f(x0, my_parser.my_answer.y0), my_parser.my_sprite[ind].data_arr[k], my_parser.my_sprite[ind].data_arr[k + 1], my_parser.my_sprite[ind].data_arr[k + 2]);
                                    window.draw(pixel);
                                    k += 3;
                                    x0 += 5;
                                }
                                my_parser.my_answer.y0 += 5;
                            }
                            break;
                        }
                        case DRAW_TEXT:
                        {
                            cout << "x0 = " << my_parser.my_answer.x0 << endl;
                            cout << "y0 = " << my_parser.my_answer.y0 << endl;
                            cout << "size= " << my_parser.my_answer.font << endl;
                            cout << "text=" << my_parser.my_answer.text << endl;
                            double bg_w = (my_parser.my_answer.font * my_parser.my_answer.text.length()) / 1.66;
                            RectangleShape rectangle = draw_rectangle(Vector2f(bg_w, my_parser.my_answer.font), Vector2f(my_parser.my_answer.x0, my_parser.my_answer.y0 + 4), my_parser.my_answer.bg_r, my_parser.my_answer.bg_g, my_parser.my_answer.bg_b);
                            Text text = draw_text(my_parser.my_answer.x0, my_parser.my_answer.y0, my_parser.my_answer.font, my_parser.my_answer.text, my_parser.my_answer.R, my_parser.my_answer.G, my_parser.my_answer.B);
                            window.draw(rectangle);
                            window.draw(text);
                            break;
                        }
                        case DRAW_IMAGE:
                        {
                            int ind = my_parser.my_answer.sprite_index;
                            cout << "x0 = " << my_parser.my_answer.x0 << endl;
                            cout << "y0 = " << my_parser.my_answer.y0 << endl;
                            cout << "w = " << my_parser.my_answer.w << endl;
                            cout << "h = " << my_parser.my_answer.h << endl;
                            int k = 0;
                            for (int i = 0; i < my_parser.my_answer.w; i++)
                            {
                                int x0 = my_parser.my_answer.x0;
                                for (int j = 0; j < my_parser.my_answer.h; j++)
                                {
                                    RectangleShape pixel = draw_pixel(Vector2f(x0, my_parser.my_answer.y0), my_parser.my_sprite[ind].data_arr[k], my_parser.my_sprite[ind].data_arr[k + 1], my_parser.my_sprite[ind].data_arr[k + 2]);
                                    window.draw(pixel);
                                    k += 3;
                                    x0 += 5;
                                }
                                my_parser.my_answer.y0 += 5;
                            }
                            break;
                        }
                        case SET_ORIENTATION:
                            cout << "orientation = " << my_parser.my_answer.orientation;

                            view.setRotation(my_parser.my_answer.orientation);
                            break;
                        case GET_WIDTH:
                            cout << "Width = " << my_parser.my_answer.width;
                            break;
                        case GET_HEIGHT:
                            cout << "Height = " << my_parser.my_answer.height;
                            break;
                        }
                        if (my_parser.my_answer.comm_id != DRAW_CHAR && my_parser.my_answer.comm_id != GET_HEIGHT && my_parser.my_answer.comm_id != GET_WIDTH && my_parser.my_answer.comm_id != SET_ORIENTATION && my_parser.my_answer.comm_id != DRAW_TEXT && my_parser.my_answer.comm_id != SHOW_SPRITE && my_parser.my_answer.comm_id != LOAD_SPRITE)
                        {
                            cout << "Color_R = " << my_parser.my_answer.R << endl;
                            cout << "Color_G = " << my_parser.my_answer.G << endl;
                            cout << "Color_B = " << my_parser.my_answer.B << endl;
                        }
                    }
                }
                if (my_parser.my_answer.check == false)
                {
                    err = my_parser.my_answer.error;
                    cout << err << endl;
                    strcpy(buff_, err.c_str());
                }
                else
                    if (my_parser.my_answer.comm_id == DRAW_CHAR || my_parser.my_answer.comm_id == DRAW_TEXT)
                    {
                        int x_ = my_parser.my_answer.x0 + (my_parser.my_answer.font * my_parser.my_answer.text.length()) / 1.66;
                        string b = to_string(x_);
                        strcpy(buff_, b.c_str());
                        cout << buff_ << endl;
                        int bsize_;
                        bsize_ = strlen(buff_);
                        sendto(Socket, &buff_[0], bsize_, 0, (sockaddr*)&client_addr, sizeof(client_addr));
                        window.setView(view);
                        window.display();
                        i++;
                    }
                    else 
                    {
                        strcpy(buff_, "\nКоманда виконана\n\n");
                        int bsize_;
                        bsize_ = strlen(buff_);
                        sendto(Socket, &buff_[0], bsize_, 0, (sockaddr*)&client_addr, sizeof(client_addr));
                        window.setView(view);
                        window.display();
                        i++;
                    }
                
            }
        }
    }
    return 0;
}