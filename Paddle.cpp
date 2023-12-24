#include "Paddle.h"
#include <iostream>
Paddle::Paddle(float startX, float startY)
{
	shape.setSize(sf::Vector2f(20, 40));
	shape.setPosition(startX, startY);
}

void Paddle::update()
{
}

void Paddle::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void Paddle::move(moveDirection direction, float deltaTime)
{
	int upperBound = 0; // TODO: needs to be computed based on window size and size of paddle
	int lowerBound = 600-40; // TODO: needs to be computed based on window size and size of paddle
	float speed = PADDLE_SPEED * deltaTime;
	switch (direction)
	{
	case up:
		shape.move(0.0f, -SPEED);
		if (shape.getPosition().y <= upperBound)
		{
			shape.setPosition(shape.getPosition().x, upperBound);
		}
		break;
	case down:
		shape.move(0.0f, SPEED);
		if (shape.getPosition().y >= lowerBound)
		{
		shape.setPosition(shape.getPosition().x, lowerBound);
		}
		break;
	default:
		break;
	}
	
}


