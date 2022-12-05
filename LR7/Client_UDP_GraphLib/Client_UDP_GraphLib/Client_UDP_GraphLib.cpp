
#include "DrawWithGraphicsLib.h"
#include <ctime>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    DrawWithGraphicsLib draw(1280, 720);
    draw.loadSprite(1, 2, 2, (char*)"ff aa cc bb ff aa ac bc aa ff ee be");
    draw.showSprite(1, 100, 100);
    return 0;
}
