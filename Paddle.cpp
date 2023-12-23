#include "Paddle.h"

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
	float speed = PADDLE_SPEED * deltaTime;
	switch (direction)
	{
	case up:
		shape.move(0.0f, -SPEED);
		break;
	case down:
		shape.move(0.0f, SPEED);
		break;
	default:
		break;
	}
	
}


