#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>

class Brick
{
public:
	Brick(float xPosition, float yPosition);
	~Brick();
	sf::RectangleShape& getShape() { return m_shape; }
	sf::FloatRect& getBoundingBox() { return m_boundingBox; }
private:
	sf::RectangleShape m_shape;
	sf::FloatRect m_boundingBox;
	bool destroyed;
};

