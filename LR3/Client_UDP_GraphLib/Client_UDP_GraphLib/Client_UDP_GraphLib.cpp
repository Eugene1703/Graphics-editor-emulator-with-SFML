
#include "DrawWithGraphicsLib.h"
#include <ctime>
using namespace std;
const char TEAM_blue = 0, TEAM_Yellow = 1;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    DrawWithGraphicsLib draw(1280, 720);
    cout << "drawChar return:" << draw.drawChar(100, 200, 'C', RGB(150, 150, 100), 100, 24) << endl;
    cout << "drawText return:" << draw.drawText(200, 200, (char*)"Semioshko", RGB(150, 150, 100), 100, 40) << endl;
    draw.loadSprite(1, 2, 2, (char*)"ff aa cc bb ff aa ac bc aa ff ee be");
    draw.fillRect(300, 500, 100, 100, RGB(240, 220, 230));
    draw.drawLine(100, 100, 900, 900, RGB(150, 120, 200));
    draw.drawRect(500, 200, 50, 70, RGB(0, 255, 0));
    draw.drawEllipse(400, 400, 50, 90, RGB(255, 150, 111));
    draw.fillEllipse(500, 500, 90, 100, RGB(122, 15, 110)); 
    draw.showSprite(1, 100, 100);
    return 0;
}
