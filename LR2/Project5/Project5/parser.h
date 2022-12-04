
#include <string>
using namespace std;
const unsigned char CLEAR_DISPLAY = 0,
DRAW_PIXEL = 1, DRAW_LINE = 2,
DRAW_RECTANGLE = 3, DRAW_FILL_RECTANGLE = 4,
DRAW_ELLIPSE = 5, DRAW_FILL_ELLIPSE = 6,
DRAW_CIRCLE = 7, DRAW_FILL_CIRCLE = 8,
DRAW_ROUNDED_RECTANGLE = 9, DRAW_FILL_ROUNDED_RECTANGLE = 10,
DRAW_TEXT = 11, DRAW_IMAGE = 12, SET_ORIENTATION = 13, GET_WIDTH = 14, GET_HEIGHT = 15;
class parser
{
public:
    parser(int h, int w)
    {
        my_answer.height = h;
        my_answer.width = w;
    }
    char* end;
    struct answer
    {
    public:
        int_least16_t comm_id, width, height, x0, y0, x1, y1, w, h, radius, radius_x, radius_y, R, G, B, font, length, orientation=0, my_orientation[4] = {0, 90,180,270 };
        string text;
        bool check;
        string error = "Помилка: ";
        int data_length;
        int* data_arr = new int[data_length];
    };
    answer my_answer;
    int count(char* buff)
    {
        string str = buff;
        int counter = 0, pos = str.find(' ');
        while (pos + 1)
        {
            ++counter;
            str.erase(0, pos + 1);
            pos = str.find(' ');
        }
        return counter + 1;
    }
    void parse(char* buff)
    {
        my_answer.check = true;
        int my_count = count(buff);
        if (my_count < 1)
        {
            my_answer.error += "Не вірно набрана команда"; my_answer.check = false;
        }
        else
        {
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
                case CLEAR_DISPLAY:
                    if (my_count != 4)
                    {
                        my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break;
                    }
                    else
                        break;
                case DRAW_PIXEL:
                    if (my_count != 6) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 10);
                        my_answer.y0 = strtol(end, &end, 10);
                        break;
                    }
                case DRAW_LINE:
                    if (my_count != 8) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 10);
                        my_answer.y0 = strtol(end, &end, 10);
                        my_answer.x1 = strtol(end, &end, 10);
                        my_answer.y1 = strtol(end, &end, 10);
                        break;
                    }
                case DRAW_RECTANGLE:
                    if (my_count != 8) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 10);
                        my_answer.y0 = strtol(end, &end, 10);
                        my_answer.w = strtol(end, &end, 10);
                        my_answer.h = strtol(end, &end, 10);
                        if (my_answer.h < 1 || my_answer.w < 1)
                        {
                            my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break;
                        }
                        break;
                    }
                case DRAW_FILL_RECTANGLE:
                    if (my_count != 8) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 10);
                        my_answer.y0 = strtol(end, &end, 10);
                        my_answer.w = strtol(end, &end, 10);
                        my_answer.h = strtol(end, &end, 10);
                        if (my_answer.h < 1 || my_answer.w < 1)
                        {
                            my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break;
                        }
                        break;
                    }
                case DRAW_ELLIPSE:
                    if (my_count != 8) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 10);
                        my_answer.y0 = strtol(end, &end, 10);
                        my_answer.radius_x = strtol(end, &end, 10);
                        my_answer.radius_y = strtol(end, &end, 10);
                        if (my_answer.radius_x < 1 || my_answer.radius_y < 1)
                        {
                            my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break;
                        }
                        break;
                    }
                case DRAW_FILL_ELLIPSE:
                    if (my_count != 8) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 10);
                        my_answer.y0 = strtol(end, &end, 10);
                        my_answer.radius_x = strtol(end, &end, 10);
                        my_answer.radius_y = strtol(end, &end, 10);
                        if (my_answer.radius_x < 1 || my_answer.radius_y < 1)
                        {
                            my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break;
                        }
                        break;
                    }
                case DRAW_CIRCLE:
                    if (my_count != 7) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 10);
                        my_answer.y0 = strtol(end, &end, 10);
                        my_answer.radius = strtol(end, &end, 10);
                        break;
                    }
                case DRAW_FILL_CIRCLE:
                    if (my_count != 7) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 10);
                        my_answer.y0 = strtol(end, &end, 10);
                        my_answer.radius = strtol(end, &end, 10);
                        break;
                    }
                case DRAW_ROUNDED_RECTANGLE:
                    if (my_count != 9) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {

                        my_answer.x0 = strtol(end, &end, 10);
                        my_answer.y0 = strtol(end, &end, 10);
                        my_answer.w = strtol(end, &end, 10);
                        my_answer.h = strtol(end, &end, 10);
                        my_answer.radius = strtol(end, &end, 10);
                        if (my_answer.h <1 || my_answer.w < 1)
                        {
                            my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break;
                        }
                        break;
                    }
                case DRAW_FILL_ROUNDED_RECTANGLE:
                    if (my_count != 9) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 10);
                        my_answer.y0 = strtol(end, &end, 10);
                        my_answer.w = strtol(end, &end, 10);
                        my_answer.h = strtol(end, &end, 10);
                        my_answer.radius = strtol(end, &end, 10);
                        if (my_answer.h < 1 || my_answer.w < 1)
                        {
                            my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break;
                        }
                        break;
                    }
                case DRAW_TEXT:
                    if (my_count != 9) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.x0 = strtol(end, &end, 10);
                        my_answer.y0 = strtol(end, &end, 10);
                        my_answer.R = strtol(end, &end, 16);
                        my_answer.G = strtol(end, &end, 16);
                        my_answer.B = strtol(end, &end, 16);
                        my_answer.font = strtol(end, &end, 10);
                        my_answer.length = strtol(end, &end, 10);
                        my_answer.text = end;
                        if (my_answer.length != my_answer.text.length()) 
                        {
                            my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break;
                        }
                    }
                    break;
                case DRAW_IMAGE:
                    {
                        my_answer.x0 = strtol(end, &end, 10);
                        my_answer.y0 = strtol(end, &end, 10);
                        my_answer.w = strtol(end, &end, 10);
                        my_answer.h = strtol(end, &end, 10);
                        if (my_answer.h < 1 || my_answer.w < 1)
                        {
                            my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break;
                        }
                        if (my_count != my_answer.w*my_answer.h*3 + 5) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                        my_answer.data_length = my_answer.w * my_answer.h * 3;
                        for (int i = 0; i < my_answer.data_length; i++) 
                        {
                            my_answer.data_arr[i] = strtol(end, &end, 16);
                        }
                        break;
                    }
                case SET_ORIENTATION:
                    if (my_count != 2) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                    {
                        my_answer.orientation = strtol(end, &end, 10);
                        if (my_answer.orientation < 1 || my_answer.orientation >4) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                        else 
                        {
                            my_answer.orientation = my_answer.my_orientation[my_answer.orientation - 1];
                        }
                        break;
                    }
                case GET_WIDTH:
                    if (my_count != 1) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                        break;
                case GET_HEIGHT:
                    if (my_count != 1) { my_answer.error += "Не вірно набрана команда"; my_answer.check = false; break; }
                    else
                        break;
                }
                if (my_answer.check)
                {
                    if (my_answer.comm_id != GET_HEIGHT && my_answer.comm_id != GET_WIDTH && my_answer.comm_id != SET_ORIENTATION && my_answer.comm_id != DRAW_TEXT && my_answer.comm_id != DRAW_IMAGE) {
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
    }
};