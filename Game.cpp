#include "Game.h"
#include <iostream>


// TODO: read in parameters from data
Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pong Game"), paddle1(50, 300), paddle2(730, 300), ball(400,300,10, sf::Vector2f(-3,3)), deltaTime(0.0f) {
    // Initialize any other variables or settings here
    window.setFramerateLimit(60);
    if (!scoreFont.loadFromFile("pong-score.ttf"))
    {
        std::cerr << "Score font failed to load";
    }
    playerOneScoreText.setFont(scoreFont);
    playerOneScoreText.setString(std::to_string(playerOneScore));
    playerOneScoreText.setPosition(350, 30);
    playerOneScoreText.setFillColor(sf::Color::Cyan);
    

    playerTwoScoreText.setFont(scoreFont);
    playerTwoScoreText.setString(std::to_string(playerTwoScore));
    playerTwoScoreText.setPosition(450, 30);
    playerTwoScoreText.setFillColor(sf::Color::Cyan);
    
    if (!welcomeFont.loadFromFile("tech.ttf"))
    {
        std::cerr << "Welcome font failed to laod";
    }
    welcomeText.setFont(welcomeFont);
    currentState = start;
    
}

void Game::run()
{
    while (window.isOpen())
    {
        switch (currentState)
        {
        case start:
            processStartEvents();
            updateStartEvents();
            renderStartEvents();
            break;
        case active:
            processActiveEvents();
            updateActiveEvents();
            renderActiveEvents();
            sCollisions();
            break;
        case inactive:
            break;
        default:
            break;
        }
       // processEvents();
        
        /*update();
        render()*/;
    }
}

void Game::processStartEvents()
{
}

void Game::processActiveEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        auto deltaTime = clock.restart().asSeconds();
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        paddle1.move(up, deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        paddle1.move(down, deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
    {
        paddle2.move(up, deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))
    {
        paddle2.move(down, deltaTime);
    }
}

void Game::processScoreEvents()
{
}

void Game::updateStartEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void Game::updateActiveEvents()
{
    deltaTime = clock.restart().asSeconds();

    ball.move();
}

void Game::updateScoreEvents()
{
    
}

void Game::renderStartEvents()
{
    
    
    welcomeText.setString("Welcome to Pong\nPress SPACEBAR to play.");
    
 
    window.clear(backgroundColor);
    
    window.draw(welcomeText);
    window.display();
    
    
}

void Game::renderActiveEvents()
{
    
    window.clear(backgroundColor);
    paddle1.draw(window);
    paddle2.draw(window);
    ball.draw(window);
    window.draw(playerOneScoreText);
    window.draw(playerTwoScoreText);
    window.display();
}

void Game::renderScoreEvents()
{
}

void Game::sCollisions()
{
    // TODO: get all these numbers outa here and calcualte based on screen size data.
    //ball collisions with world
    if (ball.shape.getPosition().x <= 0) // hits left wall , score player 2
    {
        score("player2");
        
    }
    if (ball.shape.getPosition().x >= 800 + ball.shape.getRadius()) // hits right wall, score player 1
    {
        score("player1");
    }
    if (ball.shape.getPosition().y <= 0) // hits top, bounces 
    {
        ball.velocity.y *= -1;
    }
    if (ball.shape.getPosition().y >= 600 - 2 * ball.shape.getRadius()) // hits bottom, bounces
    {
        ball.velocity.y *= -1;
    }

    if (ball.shape.getGlobalBounds().intersects(paddle1.shape.getGlobalBounds())) // ball hits paddle 1
    {
        ball.velocity.x *= -1;
        //ball.velocity.y *= -1;
    }
    if (ball.shape.getGlobalBounds().intersects(paddle2.shape.getGlobalBounds())) // ball hits paddle 2
    {
        ball.velocity.x *= -1;
        //ball.velocity.y *= -1;
    }
}

void Game::score(std::string player)
{
    if (player == "player1")
    {
        playerOneScore++;
        playerOneScoreText.setString(std::to_string(playerOneScore));
        ball.shape.setPosition(400, 300);
        ball.velocity.x *= -1.02;
        ball.velocity.y *= -1;
    }
    if (player == "player2")
    {
        playerTwoScore++;
        playerTwoScoreText.setString(std::to_string(playerTwoScore));
        ball.shape.setPosition(400, 300);
        ball.velocity.x *= -1.02;       
        ball.velocity.y *= -1;
    }


}

