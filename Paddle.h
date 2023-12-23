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
private:
	sf::RectangleShape shape;
	float SPEED = 5;
	const float PADDLE_SPEED = 200.0f;
};