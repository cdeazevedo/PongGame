#pragma once
#include "SFML/Graphics.hpp"

enum moveDirection { up, down };

class Paddle
{
public:
	Paddle(float startX, float startY);
	void update();
	void draw(sf::RenderWindow& window);
	void move(moveDirection direction, float deltatTime);
	sf::RectangleShape shape;
private:
	
	float SPEED = 5; // should be read in from data
	const float PADDLE_SPEED = 200.0f; // should be read in from data
};