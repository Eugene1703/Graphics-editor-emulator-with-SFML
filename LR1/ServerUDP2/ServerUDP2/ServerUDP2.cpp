#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#pragma comment ( lib, "ws2_32.lib" )
#include<SFML/Graphics.hpp>
#include <iostream>
#include <winsock2.h>
#include <string>
#include <Windows.h>
#include <sstream>
#include "Parser.h"
#define PORT 7777   
int R, G, B;
using namespace std;
using namespace sf;
class checker {
public:
    int const WIDTH = 1280;
    int const HEIGHT = 720;
    string* err;
    char** words;
    void error_line() {
        *err = *err + "\n";
    }
    int min_of_2(int a, int b)
    {
        if (a < b) return a;
        else return b;
    }
    int char_to_int(char str[]) {
        int out = 0, err_ = 0;
        for (int i = 0; i < strlen(str); i++) {
            int buf = (int)str[i] - (int)'0';
            if (buf <= 9 && buf >= 0) {
                out = out * 10 + buf;
            }
            else err_ = 1;
        }
        if (err_ == 1) return -999;
        return out;
    }
    template <typename T>
    string int_to_string(T Number)
    {
        std::ostringstream ss;
        ss << Number;
        return ss.str();
    }
    bool check_coords(int x, int y) {
        if (x == -999 || x < 0 || x > WIDTH) {
            *err = *err + "X має належити проміжку від 0 до " + int_to_string(WIDTH) + ";\n";
            error_line();
            return false;
        }
        if (y == -999 || y < 0 || y > HEIGHT) {
            *err = *err + "Y має належити проміжку від 0 до " + int_to_string(HEIGHT) + ";\n";
            error_line();
            return false;
        }
        return true;
    }
    int color_convert(char my_string[2])
    {
        int color = 0, buff = 0, length = strlen(my_string) - 1;
        for (int i = length; my_string[i] != '\0'; i--)
        {
            if (my_string[i] == '0') buff = 0;
            else if (my_string[i] == '1') buff = 1;
            else if (my_string[i] == '2') buff = 2;
            else if (my_string[i] == '3') buff = 3;
            else if (my_string[i] == '4') buff = 4;
            else if (my_string[i] == '5') buff = 5;
            else if (my_string[i] == '6') buff = 6;
            else if (my_string[i] == '7') buff = 7;
            else if (my_string[i] == '8') buff = 8;
            else if (my_string[i] == '9') buff = 9;
            else if (my_string[i] == 'a') buff = 10;
            else if (my_string[i] == 'b') buff = 11;
            else if (my_string[i] == 'c') buff = 12;
            else if (my_string[i] == 'd') buff = 13;
            else if (my_string[i] == 'e') buff = 14;
            else if (my_string[i] == 'f') buff = 15;
            color = color + buff * pow(16, i);
            length--;
        }
        return color;
    }
    void setColor(char* my_string)
    {
        char buff[2];
        buff[0] = my_string[0]; buff[1] = my_string[1];
        R = color_convert(buff);
        buff[0] = my_string[2]; buff[1] = my_string[3];
        G = color_convert(buff);
        buff[0] = my_string[4]; buff[1] = my_string[5];
        B = color_convert(buff);
    }
    bool check_width(int w, int h, int x, int y) {
        if (check_coords(x, y)) {
            if (w == -999 || w <= 0 || (w + x) > WIDTH) {
                *err = *err + "Width має належити проміжку від 0 до " + int_to_string(WIDTH - x) + ";\n";
                error_line();
                return false;
            }
            if (h == -999 || h <= 0 || (h + y) > HEIGHT) {
                *err = *err + "Height має належити проміжку від 0 до " + int_to_string(HEIGHT - y) + ";\n";
                error_line();
                return false;
            }
            return true;
        }
        else return false;
    }
    bool check_radius(int rad, int x, int y) {
        if (check_coords(x, y)) {
            if (rad == -999 || rad <= 0 || (rad + x) > WIDTH || (x - rad) <= 0 || (rad + y) > HEIGHT || (y - rad) <= 0) {
                *err = *err + "Радіус має належити проміжку від 1 до " + int_to_string(min_of_2(min_of_2(x, y), min_of_2(WIDTH - x, HEIGHT - y))) + ";\n";
                error_line();
                return false;
            }
            return true;
        }
        else return false;
    }
    bool check_widthradius(int w, int h, int x, int y, int rad) {
        if (w > rad * 2 && h > rad * 2) {
            if (check_coords(x, y)) {
                if (w == -999 || w <= 0 || (w + x) > WIDTH) {
                    *err = *err + "Width  має належити проміжку від 1 до " + int_to_string(WIDTH - x) + ";\n";
                    error_line();
                    return false;
                }
                if (h == -999 || h <= 0 || (h + y) > HEIGHT) {
                    *err = *err + "Height  має належити проміжку від 1 до " + int_to_string(HEIGHT - y) + ";\n";
                    error_line();
                    return false;
                }
                return true;
            }
        }
        else {
            *err = *err + "Радиус  має належити проміжку від 1 до " + int_to_string(min_of_2(w / 2, h / 2)) + ";\n";
            error_line();
        }
        return false;
    }
    bool check_color(char col[], int* col_i) {
        int col_int = 0, err_ = 0;
        if (strlen(col) == 6)
        {
            for (int i = 0; i < strlen(col); i++)
            {
                if (true/*((col[i] >= '0') && (col[i] >= '9')) || ((col[i] >= 'A') && (col[i] >= 'F')) || ((col[i] >= 'a') && (col[i] >= 'f'))*/) {
                    err_ = 0;
                }
                else err_ = 1;
            }
        }
        if (err_ == 0) {
            setColor(col);
            return true;
        }
        *err = *err + "Помилка в заданні кольору\n";
        error_line();
        return false;
    }
    bool clear(char** words, int cnt) {
        if (cnt == 2)
        {
            int col_int;
            if (check_color(words[1], &col_int)) {
                cout << "Очищення дисплею " << endl;
                /*setcfg();
                FillRect(hdc, &rect, hbr);
                print();*/
                return true;
            }
        }
    }
    /* void print()
     {
         BitBlt(hdc, 0, 0, rect.right, rect.bottom, hBufferDC, 0, 0, SRCCOPY);
     }
     void setcfg()
     {
         HGDIOBJ original = NULL;
         original = SelectObject(hdc, GetStockObject(DC_PEN));
         SelectObject(hdc, GetStockObject(DC_BRUSH));
         SetDCBrushColor(hdc, RGB(R, G, B));
         SetDCPenColor(hdc, RGB(R, G, B));
     }*/
    bool draw_pixel(char** words, int cnt) {
        if (cnt == 4)
        {
            int x = char_to_int(words[1]), y = char_to_int(words[2]);
            int col_int;
            if (check_coords(x, y))
                if (check_color(words[3], &col_int))
                {
                    cout << "Заливка пикселю (" << x << "; " << y << ") :  color: " << R << " " << G << " " << B << endl;
                    /*  setcfg();
                      LineTo(hdc, x + 1, y + 1);*/
                    return true;
                }
        }
        error_line();
        return false;
    }
    bool draw_line(char** words, int cnt) {
        if (cnt == 6)
        {
            int x = char_to_int(words[1]), y = char_to_int(words[2]), x1 = char_to_int(words[3]), y1 = char_to_int(words[4]);
            int col_int;
            if (check_coords(x, y) && check_coords(x1, y1))
                if (check_color(words[5], &col_int))
                {
                    cout << "Малювання лінії A:(" << x << "; " << y << "); B:(" << x1 << "; " << y1 << "); color: " << R << " " << G << " " << B << endl;
                    /* setcfg();
                     LineTo(hdc, x1, y1);*/
                    return true;
                }
        }
        *err = *err + "Помилка: \n";
        error_line();
        return false;
    }

    bool draw_rectangle(char** words, int cnt) {
        if (cnt == 6)
        {
            int x = char_to_int(words[1]), y = char_to_int(words[2]), w = char_to_int(words[3]), h = char_to_int(words[4]);
            int col_int;
            if (check_width(w, h, x, y))
                if (check_color(words[5], &col_int))
                {
                    cout << "Прямокутник A:(" << x << "; " << y << "); width: " << w << "; height: " << h << "; color: " << R << " " << G << " " << B << endl;
                    int x1 = x + w, y1 = y;
                    /*   setcfg();
                       Rectangle(hdc, x, y, x + w, y + h);*/
                    return true;
                }
        }
        *err = *err + "Помилка \n";
        error_line();
        return false;
    }
    bool fill_rectangle(char** words, int cnt) {
        if (cnt == 6)
        {
            int x = char_to_int(words[1]), y = char_to_int(words[2]), w = char_to_int(words[3]), h = char_to_int(words[4]);
            int col_int;
            if (check_width(w, h, x, y))
                if (check_color(words[5], &col_int))
                {
                    cout << "Заповнений прямокутник A:(" << x << "; " << y << "); width: " << w << "; height: " << h << "; color: " << R << " " << G << " " << B << endl;
                    /*   setcfg();
                       Rectangle(hdc, x, y, x + w, y + h);*/
                    return true;
                }
        }
        *err = *err + "Помилка \n";
        error_line();
        return false;
    }
    bool draw_ellipse(char** words, int cnt) {
        if (cnt == 6)
        {
            int x = char_to_int(words[1]), y = char_to_int(words[2]), rad_x = char_to_int(words[3]), rad_y = char_to_int(words[4]);
            int col_int;
            int x1 = x, y1 = y;
            if (check_radius(rad_x, x, y) && check_radius(rad_y, x, y))
                if (check_color(words[5], &col_int))
                {
                    cout << "Еліпс A:(" << x << "; " << y << "); radius_x: " << rad_x << "; radius_y: " << rad_y << "; color: " << R << " " << G << " " << B << endl;
                    /* setcfg();*/
                     //for (x1 = x - rad_x; x1 <= x + rad_x; x1++) {
                     //   /* LineTo(hdc, x1, y + sqrt(rad_x * rad_x - (x - x1) * (x - x1)));*/
                     //}
                     //for (x1 = x - rad_x; x1 <= x + rad_x; x1++) {
                     //   /* LineTo(hdc, x1, y - sqrt(rad_x * rad_x - (x - x1) * (x - x1)));*/
                     //}
                    return true;
                }
        }
        *err = *err + "Помилка\n";
        error_line();
        return false;
    }
    bool fill_ellipse(char** words, int cnt) {
        if (cnt == 6)
        {
            int x = char_to_int(words[1]), y = char_to_int(words[2]), rad_x = char_to_int(words[3]), rad_y = char_to_int(words[4]);
            int col_int;
            if (check_radius(rad_x, x, y) && check_radius(rad_y, x, y))
                if (check_color(words[5], &col_int))
                {
                    cout << "Еліпс A:(" << x << "; " << y << "); radius_x: " << rad_x << "; radius_y: " << rad_y << "; color: " << R << " " << G << " " << B << endl;
                    return true;
                }
        }
        *err = *err + "Помилка\n";
        error_line();
        return false;
    }
    bool draw_circle(char** words, int cnt) {
        if (cnt == 5)
        {
            int x = char_to_int(words[1]), y = char_to_int(words[2]), rad = char_to_int(words[3]);
            int col_int;
            if (check_radius(rad, x, y))
                if (check_color(words[4], &col_int))
                {
                    cout << "Коло A:(" << x << "; " << y << "); radius: " << rad << "; color: " << R << " " << G << " " << B << endl;
                    return true;
                }
        }
        *err = *err + "Помилка)\n";
        error_line();
        return false;
    }
    bool fill_circle(char** words, int cnt) {
        if (cnt == 5)
        {
            int x = char_to_int(words[1]), y = char_to_int(words[2]), rad = char_to_int(words[3]);
            int col_int;
            if (check_radius(rad, x, y))
                if (check_color(words[4], &col_int))
                {
                    cout << "Заповнене коло A:(" << x << "; " << y << "); radius: " << rad << "; color: " << R << " " << G << " " << B << endl;
                    return true;
                }
        }
        *err = *err + "Помилка\n";
        error_line();
        return false;
    }
    bool draw_rounded_rectangle(char** words, int cnt) {
        if (cnt == 7)
        {
            int x = char_to_int(words[1]), y = char_to_int(words[2]), w = char_to_int(words[3]), h = char_to_int(words[4]), rad = char_to_int(words[5]);
            int col_int;
            if (check_widthradius(w, h, x, y, rad))
                if (check_color(words[6], &col_int))
                {
                    cout << "Прямокутник A:(" << x << "; " << y << "); width: " << w << "; height: " << h << "; radius: " << rad << "; color: " << R << " " << G << " " << B << endl;
                    return true;
                }
        }
        *err = *err + "Помилка\n";
        error_line();
        return false;
    }

    bool fill_rounded_rect(char** words, int cnt) {
        if (cnt == 7)
        {
            int x = char_to_int(words[1]), y = char_to_int(words[2]), w = char_to_int(words[3]), h = char_to_int(words[4]), rad = char_to_int(words[5]);
            int col_int;
            if (check_widthradius(w, h, x, y, rad))
                if (check_color(words[6], &col_int))
                {
                    cout << "Заповнений прямокутник A:(" << x << "; " << y << "); width: " << w << "; height: " << h << "; radius: " << rad << "; color: " << R << " " << G << " " << B << endl;
                    return true;
                }
        }
        *err = *err + "Помилка\n";
        error_line();
        return false;
    }
    bool draw_text(char** words, int cnt) {
        if (cnt >= 7)
        {
            int count = 0, x = char_to_int(words[1]), y = char_to_int(words[2]), font = char_to_int(words[3]), lenght = char_to_int(words[4]);
            string text;
            for (int i = 5; i < cnt - 1; i++)
            {
                text = text + words[i] + " ";
                count += (strlen(words[i]) + 1);
            }
            int col_int;
            if (count <= lenght) {
                if (font != -999) {
                    if (check_coords(x, y))
                        if (check_color(words[cnt - 1], &col_int))
                        {
                            cout << "Текст А: (" << x << "; " << y << "); font: " << font << "; length: " << lenght << "; text: ''" << text << "''; color: " << R << " " << G << " " << B << endl;
                            return true;
                        }
                }
                else {
                    *err = *err + "Помилка";
                    error_line();
                }
            }
        }
        *err = *err + "Помилка\n";
        error_line();
        return false;
    }

    bool draw_image(char** words, int cnt) {
        if (cnt >= 6)
        {
            int count = 0, x = char_to_int(words[1]), y = char_to_int(words[2]), w = char_to_int(words[3]), h = char_to_int(words[4]);
            int col_int, err_ = 0;
            string data;
            for (int i = 5; i < cnt; i++)
            {
                if (check_color(words[i], &col_int)) {
                    data = data + words[i] + " ";
                    count += 1;
                }
                else
                {
                    *err = *err + "Піксель №" + int_to_string(count + 1) + " не є 24 бітним кольором\n";
                    error_line();
                    err_ = 1;
                    break;
                }
            }
            if (err_ == 0)
                if ((w * h) == count) {
                    if (check_width(w, h, x, y))
                        if (w * h == count)
                            if (check_color(words[5], &col_int))
                            {
                                cout << "Рисунок A:(" << x << "; " << y << "); width: " << w << "; height: " << h << "; data: " << data << endl;
                                return true;
                            }
                }
                else
                {
                    *err = *err + "Height * Width (" + int_to_string(w * h) + ") не рівняється кількості пікселів: " + int_to_string(count) + "\n";
                    error_line();
                }
        }
        *err = *err + "Помилка\n";
        error_line();
        return false;
    }

    bool set_orientation(char** words, int cnt) {
        if (cnt == 2)
        {
            int col_int, angle = char_to_int(words[1]);
            if (angle != -999 && angle <= 3 && angle >= 0) {
                angle *= 90;
                cout << "Зміна орієнтації на " << angle << " градусів" << endl;
                return true;
            }
            else {
                *err = *err + "Помилка\n";
            }
        }
        else
        {
            *err = *err + "Помилка\n";
            error_line();
        }
        return false;
    }

    bool get(char** words, int cnt) {
        if (cnt == 2)
        {
            if (strcmp(words[1], "width") == 0) { *err = *err + "Ширина: " + int_to_string(WIDTH) + "\n"; return true; }
            else if (strcmp(words[1], "height") == 0) { *err = *err + "Висота: " + int_to_string(HEIGHT) + "\n"; return true; }
            else
            {
                *err = *err + "Помилка\n";
                error_line();
            }

        }
        else
        {
            *err = *err + "Помилка\n";
            error_line();
        }
        return false;
    }
    bool get_client_info(int cnt, bool* end_prog) {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        error_line();
        int buffer;
        buffer = char_to_int(words[0]);
        switch (buffer)
        {
        case 1:
            return clear(words, cnt);
            break;
        case 2:
            return draw_pixel(words, cnt);
            break;
        case 3:
            return draw_line(words, cnt);
            break;
        case 4:
            return draw_rectangle(words, cnt);
            break;
        case 5:
            return fill_rectangle(words, cnt);
            break;
        case 6:
            return draw_ellipse(words, cnt);
            break;
        case 7:
            return fill_ellipse(words, cnt);
            break;
        case 8:
            return draw_circle(words, cnt);
            break;
        case 9:
            return fill_circle(words, cnt);
            break;
        case 10:
            return draw_rounded_rectangle(words, cnt);
            break;
        case 11:
            return fill_rounded_rect(words, cnt);
            break;
        case 12:
            return draw_text(words, cnt);
            break;
        case 13:
            return draw_image(words, cnt);
            break;
        case 14:
            return set_orientation(words, cnt);
            break;
        case 15:
            return get(words, cnt);
            break;
        default:
            cout << buffer << endl;
            *err = *err + "Команду не знайдено\n";
            error_line();
            return false;
        }
    }
    bool lecs(char str[], bool* end_prog) {

        char* p = NULL;
        int i, count_ = 0;
        for (p = strtok(str, " "); p != NULL; p = strtok(NULL, " ")) {
            if ((words = (char**)realloc(words, sizeof(char*) * (count_ + 1))) == NULL) {
                printf("No memory to new word!\n");
                exit(1);
            }
            if ((words[count_] = _strdup(p)) == NULL) {
                printf("Can't duplicate word!\n");
                exit(1);
            }
            ++count_;
        }

        bool err_ = get_client_info(count_, end_prog);

        for (int i = 0; i < count_; ++i) {
            if (words[i] != NULL) {
                free(words[i]);
                words[i] = NULL;
            }
        }
        free(words);
        words = NULL;
        return err_;
    }
    bool do_cmd(char str[], bool* end_prog, string* er)
    {
        err = er;
        return lecs(str, end_prog);
    }

};
int main(int argc, char* argv[])
{
    RenderWindow window(VideoMode(200, 200), "Semioshko KCKC");
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
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
        string err;
        checker a;
        a.do_cmd(buff, &end_prog, &err);
        int bsize_;
        if (err != "\n") {
            cout << err << endl;
            strcpy(buff_, err.c_str());
        }
        else strcpy(buff_, "\nКоманда виконана\n\n");
        bsize_ = strlen(buff_);
        sendto(Socket, &buff_[0], bsize_, 0, (sockaddr*)&client_addr, sizeof(client_addr));
    }
    return 0;
}
