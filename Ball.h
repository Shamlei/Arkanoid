#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
class Ball
{
public:
	Ball(float xPosition, float yPosition);
	~Ball();

	void update(float deltaTime);
	
	//getters
	float getXPosition() { return m_shape.getPosition().x; }
	float getYPosition() { return m_shape.getPosition().y; }
	float getTopPosition() { return getYPosition() - m_shape.getRadius(); }
	float getBottomPosition() { return getYPosition() + m_shape.getRadius(); }
	float getLeftPosition() { return getXPosition() - m_shape.getRadius(); }
	float getRightPosition() { return getXPosition() + m_shape.getRadius(); }
	sf::CircleShape& getShape() { return m_shape; }
private:
	sf::Vector2f m_velocity{ -200.0f,-200.0f };
	sf::CircleShape m_shape;
	sf::Vector2f m_position;
};

