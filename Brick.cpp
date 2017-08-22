#include "Brick.h"






Brick::Brick(float xPosition, float yPosition)
{
	m_shape.setPosition(xPosition, yPosition);
	m_shape.setFillColor(sf::Color::Red);
	m_shape.setSize(sf::Vector2f(100, 35));
	m_boundingBox = m_shape.getGlobalBounds();

}

Brick::~Brick()
{
}
