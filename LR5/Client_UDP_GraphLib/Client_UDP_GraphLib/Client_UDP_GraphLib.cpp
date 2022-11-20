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
    draw.drawText(200, 200, (char*)"SEMIOSHKO E O CS-20-1 DSEA", RGB(150, 150, 100), 100, 24);
    return 0;
}