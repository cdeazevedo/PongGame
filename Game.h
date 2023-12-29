#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"
//Game class that manages the main game loop, window creation, event handling, and drawing.
// Inside the game loop, update and render instances of the Paddle class.
// The window should close when the user clicks the close button.
enum GameState { start, active, inactive };

class Game
{
public:
	Game();
	void run();

private:
	
	//void processEvents();
	//void update();
	//void render();
	void sCollisions();
	void score(std::string player);

	void processStartEvents();
	void processActiveEvents();
	void processScoreEvents();

	void updateStartEvents();
	void updateActiveEvents();
	void updateScoreEvents();

	void renderStartEvents();
	void renderActiveEvents();
	void renderScoreEvents();
	
private:
	int WINDOW_WIDTH{ 800 };
	int WINDOW_HEIGHT{ 600 };
	GameState currentState;
	sf::Color backgroundColor;
	sf::RenderWindow window;
	sf::Font scoreFont;
	sf::Font welcomeFont;
	sf::Clock clock;
	sf::Text playerOneScoreText;
	sf::Text playerTwoScoreText;
	sf::Text welcomeText;
	Paddle paddle1;
	Paddle paddle2;
	Ball ball;
	float deltaTime;
	int playerOneScore = 0;
	int playerTwoScore = 0;
	
};

