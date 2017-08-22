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

void Ball::update(float deltaTime, Paddle &paddle, std::vector<Brick> &bricks)
{
	sf::FloatRect playerBox(paddle.getBoundingBox());
	m_boundingBox = m_shape.getGlobalBounds();
	m_position = m_shape.getPosition();

	// Collision check with paddle
	if (m_boundingBox.intersects(playerBox))
	{
		if (getXPosition() < paddle.getMiddlePosition())
		{
			m_velocity.x = -200.0f;
			m_velocity.y *= -1;
		}
		else
		{
			m_velocity.x = 200.0f;
			m_velocity.y *= -1;
		}
	}
	
	
/*

// Collision check with bricks
for (int i = 0; i < bricks.size(); i++)
{
if (m_boundingBox.intersects(bricks[i].getBoundingBox()))
{
bricks.erase(bricks.begin() + i);
bricks[i].~Brick();
}
}


*/
	// Collision check with Y window
	if (getTopPosition() <= -20 || getBottomPosition() >= 780)
		m_velocity.y *= -1;

	// Collision check with X window
	if (getLeftPosition() <= -20 || getRightPosition() >= 1180)
		m_velocity.x *= -1;

	// Move the ball 
	m_shape.move(m_velocity * deltaTime);

}

