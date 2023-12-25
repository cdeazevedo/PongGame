#include "Ball.h"
#include <iostream>
Ball::Ball(float startX, float startY, float radius, sf::Vector2f velocity)
 :velocity(velocity)
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
{   //TODO: a lot of this stuff should be in collision detection and handled by game.
	//TODO: make boundary objects that are invisible
	shape.move(velocity);
	
}


