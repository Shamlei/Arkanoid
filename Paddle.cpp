#include "Paddle.h"






Paddle::Paddle(float xPosition, float yPosition)
{
	m_shape.setPosition(xPosition, yPosition);
	m_shape.setFillColor(sf::Color::Green);
	m_shape.setSize(sf::Vector2f(100.0f, 20.0f));
}

Paddle::~Paddle()
{
}
