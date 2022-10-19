#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <SFML/Graphics.hpp>
using namespace sf;
#pragma comment ( lib, "ws2_32.lib" )
#include<SFML/Graphics.hpp>
RenderWindow window(VideoMode(1280, 720), "Semioshko KCKC");
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
                window.clear(Color(0, 0, 0, 255));
                return true;
            }
        }
    }
    bool draw_pixel(char** words, int cnt) {
        if (cnt == 4)
        {
            int x = char_to_int(words[1]), y = char_to_int(words[2]);
            int col_int;
            if (check_coords(x, y))
                if (check_color(words[3], &col_int))
                {
                    cout << "Заливка пикселю (" << x << "; " << y << ") :  color: " << R << " " << G << " " << B << endl;
                    RectangleShape pixel(Vector2f(1, 1));
                    pixel.setPosition(x, y);
                    pixel.setFillColor(Color(R, G, B));
                    pixel.setOutlineThickness(1.F);
                    pixel.setOutlineColor(Color(R, G, B));
                    window.draw(pixel);
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
                    RectangleShape line(Vector2f(y1-y, x1-x));
                    line.rotate(50.f);
                    line.setFillColor(Color(R,G,B));
                    line.setPosition(x, y);
                    window.draw(line);
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
                    RectangleShape rectangle(Vector2f(w, h));
                    rectangle.setPosition(x, y);
                    rectangle.setFillColor(Color(0, 0, 0));
                    rectangle.setOutlineThickness(1.F);
                    rectangle.setOutlineColor(Color(R, G, B));
                    window.draw(rectangle);
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
                    RectangleShape fillrectangle(Vector2f(w, h));
                    fillrectangle.setPosition(x, y);
                    fillrectangle.setFillColor(Color(R, G, B));
                    fillrectangle.setOutlineThickness(1.F);
                    fillrectangle.setOutlineColor(Color(R, G, B));
                    window.draw(fillrectangle);
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
                    ConvexShape ellipse;
                    ellipse.setPointCount(70);

                    for (unsigned short i = 0; i < 70; ++i) {
                        float rad = (360 / 70 * i) / (360 / 3.14 / 2);
                        float x = cos(rad) * rad_x;
                        float y = sin(rad) * rad_y;

                        ellipse.setPoint(i,Vector2f(x, y));
                    };

                    ellipse.setPosition(x,y);
                    ellipse.setFillColor(Color(0,0,0));
                    ellipse.setOutlineThickness(1.F);
                    ellipse.setOutlineColor(Color(R, G, B));
                    window.draw(ellipse);
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
                    ConvexShape ellipse;
                    ellipse.setPointCount(70);

                    for (unsigned short i = 0; i < 70; ++i) {
                        float rad = (360 / 70 * i) / (360 / 3.14 / 2);
                        float x = cos(rad) * rad_x;
                        float y = sin(rad) * rad_y;

                        ellipse.setPoint(i, Vector2f(x, y));
                    };

                    ellipse.setPosition(x, y);
                    ellipse.setFillColor(Color(R, G, B));
                    ellipse.setOutlineThickness(1.F);
                    ellipse.setOutlineColor(Color(R, G, B));
                    window.draw(ellipse);
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
                    CircleShape circle(rad);
                    circle.setPosition(x, y);
                    circle.setFillColor(Color(0, 0, 0));
                    circle.setOutlineThickness(1.F);
                    circle.setOutlineColor(Color(R, G, B));
                    window.draw(circle);
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
                    CircleShape fillcircle(rad);
                    fillcircle.setPosition(x, y);
                    fillcircle.setFillColor(Color(R, G, B));
                    fillcircle.setOutlineThickness(1.F);
                    fillcircle.setOutlineColor(Color(R, G, B));
                    window.draw(fillcircle);
                    return true;
                }
        }
        *err = *err + "Помилка\n";
        error_line();
        return false;
    }
#define POINTS 10
    sf::ConvexShape& RoundedRectangle(float x, float y, float rectWidth, float rectHeight, float radius)
    {
        sf::ConvexShape* rrect = new ConvexShape();
        float X = 0, Y = 0;
        for (int i = 0; i < POINTS; i++)
        {
            X += radius / POINTS;
            Y = sqrt(radius * radius - X * X);
            rrect->setPoint(0, Vector2f( X + x + rectWidth - radius, y - Y + radius));
        }
        Y = 0;
        for (int i = 0; i < POINTS; i++)
        {
            Y += radius / POINTS;
            X = sqrt(radius * radius - Y * Y);
            rrect->setPoint(1, Vector2f(x + rectWidth + X - radius, y + rectHeight - radius + Y));
        }
        X = 0;
        for (int i = 0; i < POINTS; i++)
        {
            X += radius / POINTS;
            Y = sqrt(radius * radius - X * X);
            rrect->setPoint(2, Vector2f(x + radius - X, y + rectHeight - radius + Y));
        }
        Y = 0;
        for (int i = 0; i < POINTS; i++)
        {
            Y += radius / POINTS;
            X = sqrt(radius * radius - Y * Y);
            rrect->setPoint(2, Vector2f(x - X + radius, y + radius - Y));
        }
        rrect->setPosition(x, y);
        return *rrect;

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
                    window.draw(RoundedRectangle(x, y, w, h, rad));
                    
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
                    window.draw(RoundedRectangle(x, y, w, h, rad));
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
            int count = 0, x = char_to_int(words[1]), y = char_to_int(words[2]), my_font = char_to_int(words[3]), lenght = char_to_int(words[4]);
            string my_text;
            for (int i = 5; i < cnt - 1; i++)
            {
                my_text = my_text + words[i] + " ";
                count += (strlen(words[i]) + 1);
            }
            int col_int;
            if (count <= lenght) {
                if (my_font != -999) {
                    if (check_coords(x, y))
                        if (check_color(words[cnt - 1], &col_int))
                        {
                            cout << "Текст А: (" << x << "; " << y << "); font: " << my_font << "; length: " << lenght << "; text: ''" << my_text << "''; color: " << R << " " << G << " " << B << endl;
                            Text text;
                            Font font;
                            text.setPosition(x, y);
                            text.setFont(font);
                            text.setString(my_text);
                            text.setFillColor(Color(R, G, B));
                            window.draw(text);
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
        window.clear(Color(0, 0, 0, 255));
        int count = 0;
        string command[1000];
        string com_buf[1000];
        int i = 0;
        while (!end_prog)
        {
            while (window.isOpen())
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
                command[i] = &buff[0];
                com_buf[i] = command[i];
                printf("C=>S:%s\n", &buff[0]);
                string err;
                checker a;
                int bsize_;
                if (err != "\n") {
                    cout << err << endl;
                    strcpy(buff_, err.c_str());
                }
                else strcpy(buff_, "\nКоманда виконана\n\n");
                bsize_ = strlen(buff_);
                sendto(Socket, &buff_[0], bsize_, 0, (sockaddr*)&client_addr, sizeof(client_addr));
                for(int k=0;k<=i;k++)
                {
                    a.do_cmd(const_cast<char*>(command[k].c_str()), &end_prog, &err);
                    command[k] = com_buf[k];
                }
                window.display();
                i++;
                
            }
            
        }
    return 0;
}
    