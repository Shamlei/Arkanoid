#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include <vector>
 void instantiateBricks(std::vector<Brick> &brickVector)
{
	
	float xPos(25.0f);
	float yPos(5.0f);
	for (int i = 0; i < 11; i++) // First row
	{
		brickVector.push_back(Brick(xPos, yPos));
		xPos += 105.0f;
	}
	xPos = 25.0f;
	yPos = 50.0f;
	
	
	
	for (int i = 0; i < 11; i++)
	{
		brickVector.push_back(Brick(xPos, yPos));
		xPos += 105.0f;
	}
	

}
 
void drawBricks(sf::RenderWindow &window, std::vector<Brick> &bricks)
{
	for (int i = 0; i < bricks.size(); i++)
	{
		window.draw(bricks[i].getShape());
	}
	
}

int main()
{

	// window
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Arkanoid");
	


	std::vector<Brick> brickVector;
	instantiateBricks(brickVector);
	
	// gameClock for deltaTime
	sf::Clock gameClock;
	sf::Time deltaTime;

	Ball ball(300, 300);
	Paddle paddle(500, 700);
	
	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		deltaTime = gameClock.restart();
		paddle.update(deltaTime.asSeconds());
		ball.update(deltaTime.asSeconds(),paddle, brickVector);
		window.clear();
		drawBricks(window, brickVector);
		window.draw(ball.getShape());
		window.draw(paddle.getShape());
		window.display();
		
		
	}
	
	return 0;
}