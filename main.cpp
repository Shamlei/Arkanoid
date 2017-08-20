#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"
#include "Paddle.h"

int main()
{
	// window
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Arkanoid");
	
	// gameClock for deltaTime
	sf::Clock gameClock;
	sf::Time deltaTime;

	Ball ball(300, 300);
	Paddle paddle(500, 600);
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
		ball.update(deltaTime.asSeconds(),paddle.getBoundingBox());
		window.clear();
		window.draw(ball.getShape());
		window.draw(paddle.getShape());
		window.display();
	}

	return 0;
}