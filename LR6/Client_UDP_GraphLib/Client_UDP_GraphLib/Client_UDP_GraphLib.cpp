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
    cout << "width= " << draw.getWidth() << endl;
    cout << "height= " << draw.getHeight() << endl;
    draw.setOrientation(4);
    draw.drawRect(100, 100, 70, 30, RGB(150, 150, 150));
    Sleep(5000);
    draw.setOrientation(1);
    Sleep(5000);
    draw.setOrientation(2);
    Sleep(5000);
    draw.setOrientation(3);
    Sleep(5000);
    draw.setOrientation(4);
    Sleep(5000);
    return 0;
}