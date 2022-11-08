
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cmath>
using namespace std;
namespace sf 
{
    class RoundedRectangleShape : public Shape
    {
    public:
        RoundedRectangleShape(const Vector2f& size = Vector2f(0, 0), float radius = 0, unsigned int cornerPointCount = 5)
        {
            mySize = size;
            myRadius = radius;
            myCornerPointCount = cornerPointCount;
            update();
        }
        void setSize(const Vector2f& size) 
        { mySize = size; update(); }
        const Vector2f& getSize() const
        {
            return mySize;
        }
        void setCornersRadius(float radius) { myRadius = radius; update(); }
        const float getCornersRadius() const
        {
            return myRadius;
        }
        void setCornerPointCount(unsigned int count) { myCornerPointCount = count; update(); }
        size_t getPointCount()  const override { return myCornerPointCount * 4; }
        Vector2f getPoint(std::size_t index) const override {
            if (index >= myCornerPointCount * 4)
                return sf::Vector2f(0, 0);
            float deltaAngle = 90 / (myCornerPointCount - 1);
            Vector2f center;
            unsigned int centerIndex = index / myCornerPointCount;
            unsigned int offset = 0;
            static const float pi = 3.141592654;

            switch (centerIndex)
            {
            case 0: center.x = mySize.x - myRadius; center.y = myRadius; break;
            case 1: center.x = myRadius; center.y = myRadius; break;
            case 2: center.x = myRadius; center.y = mySize.y - myRadius; break;
            case 3: center.x = mySize.x - myRadius; center.y = mySize.y - myRadius; break;
            }

            return Vector2f(myRadius * cos(deltaAngle * (index - centerIndex) * pi / 180) + center.x,
                -myRadius * sin(deltaAngle * (index - centerIndex) * pi / 180) + center.y);
        }

    private:
        Vector2f mySize;
        float myRadius;
        unsigned int myCornerPointCount;
    };
}