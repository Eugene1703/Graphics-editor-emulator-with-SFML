
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
class parser
{
public:

    char* end;
    struct answer
    {
    public:
        const int height = 720, width = 1280;
        int comm_id, x0, y0, x1, y1, w, h, radius, radius_x, radius_y, R, G, B, font, length, orientation;
        string text;
        bool check;
        string error = "Помилка: ";
    };
    answer my_answer;
    int count(char* buff)
    {
        string str = &buff[0];
        int counter = 0, pos = str.find(' ');
        while (pos + 1)
        {
            ++counter;
            str.erase(0, pos + 1);
            pos = str.find(' ');   
        }
        return counter;
    }
    void parse(char* buff)
    {
        my_answer.check = true;
        int my_count = count(&buff[0]);
        if (my_count < 1)
        {
            my_answer.error += "Не вірно набрана команда"; my_answer.check = false;
        }
        else {
            my_answer.comm_id = strtol(&buff[0], &end, 16);
            if (my_answer.comm_id > 15 || my_answer.comm_id < 0)
            {
                my_answer.check = false;
                my_answer.error += "Команду не знайдено";
            }
            else
            {
                switch (my_answer.comm_id)
                {
                case 0:
                    if (my_count != 4)
                    {
                        my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break;
                    }
                    else
                        break;
                case 1:
                    if (my_count != 6) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 0);
                        my_answer.y0 = strtol(end, &end, 0);
                        break;
                    }
                case 2:
                    if (my_count != 8) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 0);
                        my_answer.y0 = strtol(end, &end, 0);
                        my_answer.x1 = strtol(end, &end, 0);
                        my_answer.y1 = strtol(end, &end, 0);
                        break;
                    }
                case 3:
                    if (my_count != 8) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 0);
                        my_answer.y0 = strtol(end, &end, 0);
                        my_answer.w = strtol(end, &end, 0);
                        my_answer.h = strtol(end, &end, 0);
                        break;
                    }
                case 4:
                    if (my_count != 8) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 0);
                        my_answer.y0 = strtol(end, &end, 0);
                        my_answer.w = strtol(end, &end, 0);
                        my_answer.h = strtol(end, &end, 0);
                        break;
                    }
                case 5:
                    if (my_count != 8) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 0);
                        my_answer.y0 = strtol(end, &end, 0);
                        my_answer.radius_x = strtol(end, &end, 0);
                        my_answer.radius_y = strtol(end, &end, 0);
                        break;
                    }
                case 6:
                    if (my_count != 8) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 0);
                        my_answer.y0 = strtol(end, &end, 0);
                        my_answer.radius_x = strtol(end, &end, 0);
                        my_answer.radius_y = strtol(end, &end, 0);
                        break;
                    }
                case 7:
                    if (my_count != 7) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 0);
                        my_answer.y0 = strtol(end, &end, 0);
                        my_answer.radius = strtol(end, &end, 0);
                        break;
                    }
                case 8:
                    if (my_count != 7) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 0);
                        my_answer.y0 = strtol(end, &end, 0);
                        my_answer.radius = strtol(end, &end, 0);
                        break;
                    }
                case 9:
                    if (my_count != 9) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 0);
                        my_answer.y0 = strtol(end, &end, 0);
                        my_answer.w = strtol(end, &end, 0);
                        my_answer.h = strtol(end, &end, 0);
                        my_answer.radius = strtol(end, &end, 0);
                        break;
                    }
                case 10:
                    if (my_count != 9) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 0);
                        my_answer.y0 = strtol(end, &end, 0);
                        my_answer.w = strtol(end, &end, 0);
                        my_answer.h = strtol(end, &end, 0);
                        my_answer.radius = strtol(end, &end, 0);
                        break;
                    }
                case 11:
                    if (my_count != 9) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 0);
                        my_answer.y0 = strtol(end, &end, 0);
                        my_answer.R = strtol(end, &end, 16);
                        my_answer.G = strtol(end, &end, 16);
                        my_answer.B = strtol(end, &end, 16);
                        my_answer.font = strtol(end, &end, 0);
                        my_answer.length = strtol(end, &end, 0);
                        my_answer.text = end;
                    }
                    break;
                case 12:
                    if (my_count != 8) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 0);
                        my_answer.y0 = strtol(end, &end, 0);
                        my_answer.w = strtol(end, &end, 0);
                        my_answer.h = strtol(end, &end, 0);
                        break;
                    }
                case 13:
                    if (my_count != 2) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.orientation = strtol(end, &end, 0);
                        break;
                    }
                case 14:
                    if (my_count != 1) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                        break;
                case 15:
                    if (my_count != 1) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                        break;
                }
                if (my_answer.check)
                {
                    my_answer.R = strtol(end, &end, 16);
                    my_answer.G = strtol(end, &end, 16);
                    my_answer.B = strtol(end, &end, 16);
                    if (my_answer.R > 255 || my_answer.R < 0 || my_answer.G > 255 || my_answer.G < 0 || my_answer.B > 255 || my_answer.B < 0)
                    {
                        my_answer.check = false;
                        my_answer.error += "Помилка в заданні кольорів";
                    }
                }


            }
        }
    }
};