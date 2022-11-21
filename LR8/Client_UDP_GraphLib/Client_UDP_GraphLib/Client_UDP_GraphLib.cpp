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
    int x0 = 10, font = 24,width = draw.getWidth();
    Sleep(1000);
    while (true) 
    {
        draw.fillScreen(RGB(0, 0, 0));
        draw.drawText(x0, 100, (char*)"SEMIOSHKO E O CS-20-1 DSEA", RGB(150, 150, 150), 110, font);
        x0 += font;
        if (x0 >= width) 
        {
            break;
        }
        Sleep(100);
    }
    return 0;
}