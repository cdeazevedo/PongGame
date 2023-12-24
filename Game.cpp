#include "Game.h"
#include <iostream>


// TODO: read in parameters from data
Game::Game() : window(sf::VideoMode(800, 600), "Pong Game"), paddle1(50, 300), paddle2(730, 300), ball(400,300,10, sf::Vector2f(-3,3)), deltaTime(0.0f) {
    // Initialize any other variables or settings here
    window.setFramerateLimit(60);
}

void Game::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
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

void Game::update()
{
    deltaTime = clock.restart().asSeconds();
    ball.move();
}

void Game::render()
{
    window.clear(backgroundColor);
    paddle1.draw(window);
    paddle2.draw(window);
    ball.draw(window);
    window.display();
}
