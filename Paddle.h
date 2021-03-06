#pragma once
#include "SFML\Graphics.hpp"

class Paddle
{
public:
	Paddle(float xPosition, float yPosition);
	~Paddle();

	void update(float deltaTime);

	//getters
	sf::RectangleShape& getShape() { return m_shape; }
	float getXPosition() { return m_shape.getPosition().x; }
	float getLeftPosition() { return getXPosition() - m_shape.getScale().x; } 
	float getRightPosition() { return getXPosition() + m_shape.getSize().x; } 
	float getMiddlePosition() { return getRightPosition() - 50.0f; }
	sf::FloatRect& getBoundingBox() { return m_boundingBox; }
private:
	sf::RectangleShape m_shape;
	float velocity{ 2.0f };
	sf::FloatRect m_boundingBox;
};

