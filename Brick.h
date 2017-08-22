#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>

class Brick
{
public:
	Brick(float xPosition, float yPosition);
	~Brick();
	Brick();
	sf::RectangleShape& getShape() { return m_shape; }
	sf::FloatRect& getBoundingBox() { return m_boundingBox; }
	float getXPosition() { return m_shape.getPosition().x; }
	float getYPosition() { return m_shape.getPosition().y; }
	float getLeftPosition() { return getXPosition() - m_shape.getScale().x; }
	float getRightPosition() { return getXPosition() + m_shape.getSize().x; }
	float getDownPosition() { return getXPosition() + m_shape.getSize().x; }
	float getMiddleXPosition() { return getRightPosition() - 50.0f; }
	float getMiddleYPosition() { return getDownPosition() - 17.5f; }
private:
	sf::RectangleShape m_shape;
	sf::FloatRect m_boundingBox;
	bool destroyed;
};

