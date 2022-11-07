
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
int main(int argc, char* argv[])
{
    
    RenderWindow window(VideoMode(1280, 720), "Semioshko KCKC");
    while (window.isOpen())
    {
        window.clear(Color(255, 255, 255));
        CircleShape circle(50);
        circle.setPosition(100, 50);
        circle.setFillColor(Color(100, 40, 50));
        circle.setOutlineThickness(5);
        circle.setOutlineColor(Color(15, 150, 50));
        window.draw(circle);
        
        RectangleShape rectangle(Vector2f(70, 100));// 70 - ширина 100 - висота
        rectangle.setPosition(100, 200);
        rectangle.setFillColor(Color(255, 255, 255));
        rectangle.setOutlineThickness(5);
        rectangle.setOutlineColor(Color(15, 15, 15));
        window.draw(rectangle);

        RectangleShape fill_rectangle(Vector2f(70, 100));
        rectangle.setPosition(200, 200);
        rectangle.setFillColor(Color(15, 15, 15));
        window.draw(rectangle);
        Vertex line[] =
        {
            Vertex(Vector2f(150,150)),
            Vertex(Vector2f(500,500))
        };
        line->color = Color(0, 0, 0);
        window.draw(line,2,Lines);
        window.display();
    }
    return 0;
}
