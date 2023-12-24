#include "Ball.h"

Ball::Ball(float startX, float startY, float radius, sf::Vector2f velocity)
 :initialVelocity(velocity)
{
	shape.setPosition(startX, startY);
	shape.setRadius(radius);
	
}

void Ball::update()
{
}

void Ball::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void Ball::move()
{
	shape.move(initialVelocity);

}
