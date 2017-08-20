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

void Paddle::update(float deltaTime)
{
	m_boundingBox = m_shape.getGlobalBounds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && getLeftPosition() > 0)
	{
		m_shape.move(-200.0f * deltaTime, 0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && getRightPosition() < 1200)
	{
		m_shape.move(200.0f * deltaTime, 0.0f);
	}
}
