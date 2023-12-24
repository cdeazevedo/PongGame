#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"
//Game class that manages the main game loop, window creation, event handling, and drawing.
// Inside the game loop, update and render instances of the Paddle class.
// The window should close when the user clicks the close button.

class Game
{
public:
	Game();
	void run();
private:
	sf::Clock clock;
	void processEvents();
	void update();
	void render();

private:
	sf::Color backgroundColor;
	sf::RenderWindow window;
	Paddle paddle1;
	Paddle paddle2;
	float deltaTime;

};