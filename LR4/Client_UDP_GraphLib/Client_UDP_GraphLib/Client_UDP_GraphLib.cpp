
#include "DrawWithGraphicsLib.h"
#include <ctime>
using namespace std;
const char TEAM_blue = 0, TEAM_Yellow = 1;
int main()
{
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    DrawWithGraphicsLib draw(1280, 720);
    int x = 110, y = 110, w = 30, h = 40, r, g, b, team;
    while (true)
    {
        int blue_point = 0, yellow_point = 0;
        draw.fillScreen(RGB(255, 255, 255));
        draw.fillRect(100, 100, 120, 170, RGB(0, 0, 0));
        while (true)
        {
            team = rand() % 2;
            switch (team)
            {
            case TEAM_blue:
            {
                yellow_point = 0;
                r = 15, g = 43, b = 22;
                blue_point++;
                Sleep(1000);
                break;
            }
            case TEAM_Yellow:
            {
                blue_point = 0;
                r = 0, g = 255, b = 0;
                yellow_point++;
                Sleep(1000);
                break;
            }
            }
            draw.fillRect(x, y, w, h, RGB(r, g, b));
            y += 50;
            if (yellow_point == 3 || blue_point == 3)
            {
                draw.fillScreen(RGB(255, 255, 255));
                Sleep(1000);
                draw.drawText(500, 500, "Winner", RGB(r, g, b), 100, 40);
                Sleep(1000);
                x = 110; y = 110; Sleep(1000);
                break;

            }
            if (y > 210)
            {
                y = 110;
                {
                    if (x == 180) {
                        Sleep(1000); x = 110; break;
                    }
                    else x += 35;
                }
            }
            Sleep(1000);
        }
    }
    return 0;
}
