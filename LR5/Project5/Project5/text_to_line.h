
#include "line.h"
#include <string>
#include <SFML/Graphics.hpp>
using namespace sf;
int text_to_line(RenderWindow *window, string text, int x, int y, int r, int g, int b,int font) 
{
    double x1, y1, x0, y0,space =5;
	for (int i = 0; i < text.length(); i++) 
	{
		switch (text[i]) 
		{
        case ' ':
        {
            x += font + 2*space;
            break;
        }
        case 'S':
        case 's':
        {
            x0 = x; y0 = y; x1 = (x + font) - (font / 3); y1 = y0;
            LineShape line_1(Vector2f(x0, y0), Vector2f(x1, y1));
            line_1.setFillColor(Color(r, g, b));
            window->draw(line_1);
            x0 = x1; y0 = y1; x1 = x + font; y1 = y - font / 4;
            LineShape line_2(Vector2f(x0, y0), Vector2f(x1, y1));
            line_2.setFillColor(Color(r, g, b));
            window->draw(line_2);
            x0 = x1; y0 = y1; x1 = x; y1 = y - font / 2;
            LineShape line_3(Vector2f(x0, y0), Vector2f(x1, y1));
            line_3.setFillColor(Color(r, g, b));
            window->draw(line_3);
            x0 = x1; y0 = y1; x1 = x + font / 3; y1 = y - font;
            LineShape line_4(Vector2f(x0, y0), Vector2f(x1, y1));
            line_4.setFillColor(Color(r, g, b));
            window->draw(line_4);
            x0 = x1; y0 = y1; x1 = (x + font); y1 = y - font;
            LineShape line_5(Vector2f(x0, y0), Vector2f(x1, y1));
            line_5.setFillColor(Color(r, g, b));
            window->draw(line_5);
            x += font+space;
            break;
        }
        case 'E':
        case 'e':
        {
            x0 = x; y0 = y; x1 = x0 + font; y1 = y;
            LineShape line_6(Vector2f(x0, y0), Vector2f(x1, y1));
            line_6.setFillColor(Color(r, g, b));
            window->draw(line_6);
            x0 = x; y0 = y; x1 = x; y1 = y - font;
            LineShape line_7(Vector2f(x0, y0), Vector2f(x1, y1));
            line_7.setFillColor(Color(r, g, b));
            window->draw(line_7);
            x0 = x1; y0 = y1; x1 = x + font; y1 = y0;
            LineShape line_8(Vector2f(x0, y0), Vector2f(x1, y1));
            line_8.setFillColor(Color(r, g, b));
            window->draw(line_8);
            x0 = x; y0 = y - font / 2; x1 = x0 + font; y1 = y0;
            LineShape line_9(Vector2f(x0, y0), Vector2f(x1, y1));
            line_9.setFillColor(Color(r, g, b));
            window->draw(line_9);
            x += font+space;
            break;
        }
        case 'M':
        case 'm':
        {
            x0 = x; y0 = y; x1 = x0; y1 = y - font;
            LineShape line_m_1(Vector2f(x0, y0), Vector2f(x1, y1));
            line_m_1.setFillColor(Color(r, g, b));
            window->draw(line_m_1);
            x0 = x1; y0 = y1; x1 = x + font / 2.0; y1 = y - font / 2.0;
            LineShape line_m_2(Vector2f(x0, y0), Vector2f(x1, y1));
            line_m_2.setFillColor(Color(r, g, b));
            window->draw(line_m_2);
            x0 = x1; y0 = y1; x1 = x + font; y1 = y - font;
            LineShape line_m_3(Vector2f(x0, y0), Vector2f(x1, y1));
            line_m_3.setFillColor(Color(r, g, b));
            window->draw(line_m_3);
            x0 = x1; y0 = y1; x1 = x0; y1 = y;
            LineShape line_m_4(Vector2f(x0, y0), Vector2f(x1, y1));
            line_m_4.setFillColor(Color(r, g, b));
            window->draw(line_m_4);
            x += font + space;
            break;
        }
        case 'D':
        case 'd':
        {
            x0 = x; y0 = y; x1 = x0; y1 = y - font;
            LineShape line_d_1(Vector2f(x0, y0), Vector2f(x1, y1));
            line_d_1.setFillColor(Color(r, g, b));
            window->draw(line_d_1);
            x0 = x1; y0 = y1; x1 = x+font/2; y1 = y0;
            LineShape line_d_2(Vector2f(x0, y0), Vector2f(x1, y1));
            line_d_2.setFillColor(Color(r, g, b));
            window->draw(line_d_2);
            x0 = x; y0 = y; x1 = x + font / 2; y1 = y0;
            LineShape line_d_3(Vector2f(x0, y0), Vector2f(x1, y1));
            line_d_3.setFillColor(Color(r, g, b));
            window->draw(line_d_3);
            x0 = x+font/2; y0 = y-font; x1 = x + font; y1 = (y+y-font)/2;
            LineShape line_d_4(Vector2f(x0, y0), Vector2f(x1, y1));
            line_d_4.setFillColor(Color(r, g, b));
            window->draw(line_d_4);
            x0 = x+font/2; y0 = y; x1 = x + font; y1 = (y+y-font)/2;
            LineShape line_d_5(Vector2f(x0, y0), Vector2f(x1, y1));
            line_d_5.setFillColor(Color(r, g, b));
            window->draw(line_d_5);
            x += font + space;
            break;
        }
        case 'A':
        case 'a':
        {
            x0 = x; y0 = y;x1 = x + font/2; y1 = y - font;
            LineShape line_a_1(Vector2f(x0, y0), Vector2f(x1, y1));
            line_a_1.setFillColor(Color(r, g, b));
            window->draw(line_a_1);
            x0 = x1;y0 = y1;x1 = x + font; y1 = y;
            LineShape line_a_2(Vector2f(x0, y0), Vector2f(x1, y1));
            line_a_2.setFillColor(Color(r, g, b));
            window->draw(line_a_2);
            x0 = (x + font/2 +x)/ 2.0;y0 = ((y - font) + y) / 2.0; x1 = ((x +font) + (x + font/2)) / 2.0; y1 = (y + (y - font)) / 2.0;
            LineShape line_a_3(Vector2f(x0, y0), Vector2f(x1, y1));
            line_a_3.setFillColor(Color(r, g, b));
            window->draw(line_a_3);
            x += font+space;
            break;
        }
        case '1':
        {
            x0 = x; y0 = y - font + (font / 4); x1 = x + font; y1 = y - font;
            LineShape line_1_1(Vector2f(x0, y0), Vector2f(x1, y1));
            line_1_1.setFillColor(Color(r, g, b));
            window->draw(line_1_1);
            x0 = x1; y0 = y1; x1 = x0; y1 = y;
            LineShape line_1_2(Vector2f(x0, y0), Vector2f(x1, y1));
            line_1_2.setFillColor(Color(r, g, b));
            window->draw(line_1_2);
            x += font + space;
            break;
        }
        case '2':
        {
            x0 = x; y0 = y - font; x1 = x+font; y1 = y0;
            LineShape line_2_1(Vector2f(x0, y0), Vector2f(x1, y1));
            line_2_1.setFillColor(Color(r, g, b));
            window->draw(line_2_1);
            x0 = x1; y0 =y1; x1 = x0; y1 = y - font / 2;
            LineShape line_2_2(Vector2f(x0, y0), Vector2f(x1, y1));
            line_2_2.setFillColor(Color(r, g, b));
            window->draw(line_2_2);
            x0 = x1; y0 = y1; x1 = x; y1 = y - font / 2;
            LineShape line_2_3(Vector2f(x0, y0), Vector2f(x1, y1));
            line_2_3.setFillColor(Color(r, g, b));
            window->draw(line_2_3);
            x0 = x1; y0 = y1; x1 = x0; y1 = y;
            LineShape line_2_4(Vector2f(x0, y0), Vector2f(x1, y1));
            line_2_4.setFillColor(Color(r, g, b));
            window->draw(line_2_4);
            x0 = x1; y0 = y1; x1 = x+font; y1 = y0;
            LineShape line_2_5(Vector2f(x0, y0), Vector2f(x1, y1));
            line_2_5.setFillColor(Color(r, g, b));
            window->draw(line_2_5);
            x += font + space;
            break;
        }
        case 'C':
        case 'c':
        {
            x0 = x+font; y0 = y-font; x1 = x0-(font -font/3); y1 = y0+ font/3;
            LineShape line_c_1(Vector2f(x0, y0), Vector2f(x1, y1));
            line_c_1.setFillColor(Color(r, g, b));
            window->draw(line_c_1);
            x0 = x1; y0 =y1; x1 = x0; y1 = y - font / 3;
            LineShape line_c_2(Vector2f(x0, y0), Vector2f(x1, y1));
            line_c_2.setFillColor(Color(r, g, b));
            window->draw(line_c_2);
            x0 = x1; y0 = y1; x1 = x+font; y1 = y;
            LineShape line_c_3(Vector2f(x0, y0), Vector2f(x1, y1));
            line_c_3.setFillColor(Color(r, g, b));
            window->draw(line_c_3);
            x += font + space;
            break;
        }
        case '0': 
        {
            x0 = x; y0 = y - font / 2; x1 = x0 + font / 2; y1 = y - font;
            LineShape line_0_1(Vector2f(x0, y0), Vector2f(x1, y1));
            line_0_1.setFillColor(Color(r, g, b));
            window->draw(line_0_1);
            x0 = x1; y0 = y1; x1 = x + font; y1 = y - font/2;
            LineShape line_0_2(Vector2f(x0, y0), Vector2f(x1, y1));
            line_0_2.setFillColor(Color(r, g, b));
            window->draw(line_0_2);
            x0 = x1; y0 = y1; x1 = x + font/2; y1 = y;
            LineShape line_0_3(Vector2f(x0, y0), Vector2f(x1, y1));
            line_0_3.setFillColor(Color(r, g, b));
            window->draw(line_0_3);
            x0 = x1; y0 = y1; x1 = x; y1 = y-font/2;
            LineShape line_0_4(Vector2f(x0, y0), Vector2f(x1, y1));
            line_0_4.setFillColor(Color(r, g, b));
            window->draw(line_0_4);
            x += font + space;
            break;
        }
        case'K':
        case'k':
        {
            x0 = x; y0 = y; x1 = x0; y1 = y - font;
            LineShape line_k_1(Vector2f(x0, y0), Vector2f(x1, y1));
            line_k_1.setFillColor(Color(r, g, b));
            window->draw(line_k_1);
            x0 = x; y0 = (y+y-font)/2; x1 = x0+font; y1 = y-font;
            LineShape line_k_2(Vector2f(x0, y0), Vector2f(x1, y1));
            line_k_2.setFillColor(Color(r, g, b));
            window->draw(line_k_2);
            x0 = x; y0 = (y + y - font) / 2; x1 = x0 + font; y1 = y;
            LineShape line_k_3(Vector2f(x0, y0), Vector2f(x1, y1));
            line_k_3.setFillColor(Color(r, g, b));
            window->draw(line_k_3);
            x += font + space;
            break;
        }
        case 'H':
        case 'h':
        {
            x0 = x; y0 = y; x1 = x0; y1 = y - font;
            LineShape line_h_1(Vector2f(x0, y0), Vector2f(x1, y1));
            line_h_1.setFillColor(Color(r, g, b));
            window->draw(line_h_1);
            x0 = x + font; y0 = y; x1 = x0; y1 = y - font;
            LineShape line_h_2(Vector2f(x0, y0), Vector2f(x1, y1));
            line_h_2.setFillColor(Color(r, g, b));
            window->draw(line_h_2);
            x0 = x; y0 = (y+y-font)/2; x1 = x0+font; y1 = y0;
            LineShape line_h_3(Vector2f(x0, y0), Vector2f(x1, y1));
            line_h_3.setFillColor(Color(r, g, b));
            window->draw(line_h_3);
            x += font + space;
            break;
        }
        case '-':
        {
            x0 = x; y0 = y - font / 2; x1 = x+font; y1 = y0;
            LineShape line_dash(Vector2f(x0, y0), Vector2f(x1, y1));
            line_dash.setFillColor(Color(r, g, b));
            window->draw(line_dash);
            x += font + space;
            break;
        }
        case 'I':
        case 'i':
        {
            x0 = x; y0 = y; x1 = x0; y1 = y - font;
            LineShape line_i_1(Vector2f(x0, y0), Vector2f(x1, y1));
            line_i_1.setFillColor(Color(r, g, b));
            window->draw(line_i_1);
            x += space;
            break;
        }
        case 'O':
        case 'o':
        {
            x0 = x; y0 = y; x1 = x0; y1 = y - font;
            LineShape line_o_1(Vector2f(x0, y0), Vector2f(x1, y1));
            line_o_1.setFillColor(Color(r, g, b));
            window->draw(line_o_1);
            x0 = x1; y0 = y1; x1 = x + font; y1 = y - font;
            LineShape line_o_2(Vector2f(x0, y0), Vector2f(x1, y1));
            line_o_2.setFillColor(Color(r, g, b));
            window->draw(line_o_2);
            x0 = x1; y0 = y1; x1 = x + font; y1 = y;
            LineShape line_o_3(Vector2f(x0, y0), Vector2f(x1, y1));
            line_o_3.setFillColor(Color(r, g, b));
            window->draw(line_o_3);
            x0 = x; y0 = y; x1 = x + font; y1 = y;
            LineShape line_o_4(Vector2f(x0, y0), Vector2f(x1, y1));
            line_o_4.setFillColor(Color(r, g, b));
            window->draw(line_o_4);
            x += font + space;
            break;
        }
        default:
        {
            x0 = x; y0 = y; x1 = x0; y1 = y - font;
            LineShape line_err_1(Vector2f(x0, y0), Vector2f(x1, y1));
            line_err_1.setFillColor(Color(r, g, b));
            window->draw(line_err_1);
            x0 = x1; y0 =y1; x1 = x + font; y1 = y-font;
            LineShape line_err_2(Vector2f(x0, y0), Vector2f(x1, y1));
            line_err_2.setFillColor(Color(r, g, b));
            window->draw(line_err_2);
            x0 = x1; y0 = y1; x1 = x + font; y1 = y;
            LineShape line_err_3(Vector2f(x0, y0), Vector2f(x1, y1));
            line_err_3.setFillColor(Color(r, g, b));
            window->draw(line_err_3);
            x0 = x; y0 = y; x1 = x + font; y1 = y;
            LineShape line_err_4(Vector2f(x0, y0), Vector2f(x1, y1));
            line_err_4.setFillColor(Color(r, g, b));
            window->draw(line_err_4);
            x0 = x; y0 = y; x1 = x + font; y1 = y - font;
            LineShape line_err_5(Vector2f(x0, y0), Vector2f(x1, y1));
            line_err_5.setFillColor(Color(r, g, b));
            window->draw(line_err_5);
            x0 = x; y0 = y - font; x1 = x + font; y1 = y;
            LineShape line_err_6(Vector2f(x0, y0), Vector2f(x1, y1));
            line_err_6.setFillColor(Color(r, g, b));
            window->draw(line_err_6);
            x += font + space;
            break;
        }
		}
	}
    return x;
}