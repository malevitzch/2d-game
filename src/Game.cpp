#include "../include/Game.hpp"
#include <SFML/Graphics.hpp>

void Game::processEvent(sf::Event event) //todo: replace void with a type that holds user input
{
  if(event.type == sf::Event::Closed)
  {
    window.close();
  }
  if(event.type == sf::Event::KeyPressed)
  {
    switch(event.key.code) //inside this switch case we handle keycodes... 
    {
      case sf::Keyboard::X :
        window.close();
        break;
      default:
        break;
    }
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
