#include "SFML/Graphics.hpp"
#include <cmath>
namespace sf
{
	class LineShape : public Shape
	{
	public:

		explicit LineShape(const Vector2f& point1, const Vector2f& point2) :
			m_direction(point2 - point1)
		{
			setPosition(point1);
			setThickness(2);
		}
		void setThickness(float thickness)
		{
			m_thickness = thickness;
			update();
		}
		float getThickness() const
		{
			return m_thickness;
		}
		float getLength() const
		{
			return std::sqrt(m_direction.x * m_direction.x + m_direction.y * m_direction.y);
		}
		unsigned int getPointCount() const
		{
			return 4;
		}
		Vector2f getPoint(unsigned int index) const
		{
			Vector2f unitDirection = m_direction / getLength();
			Vector2f unitPerpendicular(-unitDirection.y, unitDirection.x);
			Vector2f offset = (m_thickness / 2.f) * unitPerpendicular;
			switch (index)
			{
			default:
			case 0: return offset;
			case 1: return (m_direction + offset);
			case 2: return (m_direction - offset);
			case 3: return (-offset);
			}
		}
	private:

		Vector2f m_direction;
		float m_thickness;
	};
}
