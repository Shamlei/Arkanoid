#pragma once
#include "SFML\Graphics.hpp"

class Paddle
{
public:
	Paddle(float xPosition, float yPosition);
	~Paddle();

	//getters
	sf::RectangleShape& getShape() { return m_shape; }
	
private:
	sf::RectangleShape m_shape;
	float velocity{ 2.0f };
};

