#include "../include/Game.hpp"
#include <SFML/Graphics.hpp>

void Game::processEvent(sf::Event event) //todo: replace void with a type that holds user input
{
  if(event.type == sf::Event::Closed)
  {
    window.close();
  }
}

Game::Game() : window(sf::RenderWindow(sf::VideoMode(200, 200), "Game Window")) {}
void Game::run()
{  
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      processEvent(event);
    }
    window.clear();
    window.draw(shape);
    window.display();
  }
}
