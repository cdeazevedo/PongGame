#pragma once
#include "SFML/Graphics.hpp"
#include "Paddle.h"
class Ball
{
public:
	Ball(float startX, float startY, float radius, sf::Vector2f velocity);
	void update();
	void draw(sf::RenderWindow& window);
	void move();
	sf::CircleShape shape;

	float SPEED = 15;
	sf::Vector2f velocity;
};