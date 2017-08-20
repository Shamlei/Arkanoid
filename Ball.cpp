#include "Ball.h"




Ball::Ball(float xPosition, float yPosition)
{
	m_shape.setRadius(20.0f);
	m_shape.setPosition(xPosition, yPosition);
	m_shape.setFillColor(sf::Color::Blue);
}

Ball::~Ball()
{
}

void Ball::update(float deltaTime)
{
	m_position = m_shape.getPosition();
	if (getTopPosition() <= -20 || getBottomPosition() >= 780)
		m_velocity.y *= -1;
	if (getLeftPosition() <= -20 || getRightPosition() >= 1180)
		m_velocity.x *= -1;
	m_shape.move(m_velocity * deltaTime);
	std::cout << m_position.y << std::endl;
}

