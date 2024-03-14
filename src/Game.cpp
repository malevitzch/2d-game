#include "../include/Game.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <algorithm>
#include <chrono>
sf::Vector2f normalize(sf::Vector2f v)
{
  float len = std::sqrt(v.x * v.x + v.y * v.y);
  if(len == 0.0)
  {
    return {0.0, 0.0};
  }
  v.x /= len;
  v.y /= len;
  return v;
}
sf::Vector2f clamp(sf::Vector2f v, sf::Vector2f xbounds, sf::Vector2f ybounds)
{
  return {std::min(std::max(xbounds.x, v.x), xbounds.y), std::min(std::max(ybounds.x, v.y), ybounds.y)};
}

void Game::processEvent(sf::Event event) //TODO: replace void with a type that holds user input
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

void Game::physicsUpdate(float dt)
{
  sf::Vector2f movement = {0, 0};
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
  {
    movement.y -= 1.0;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
  {
    movement.y += 1.0;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
  {
    movement.x -= 1.0;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
  {
    movement.x += 1.0;
  }

  float speed = 5;

  sf::Vector2f transform_vector = normalize({movement.x, movement.y});
  transform_vector = {transform_vector.x * speed, transform_vector.y * speed}; //TODO: Vector2f scalar multiplication function
  map.setOrigin(clamp({map.getOrigin().x + transform_vector.x,  map.getOrigin().y + transform_vector.y}, {0, 800}, {0, 800} )); //TODO: create a function that adds Vector2f
}
Game::Game() : window(sf::RenderWindow(sf::VideoMode(200, 200), "Game Window")) {}
void Game::run()
{  
  //interesting thing, paths are relative to the main 2d-game directory rather than the executable or the cpp file they are referenced invoid Game::processEvent(sf::Event event) 
  if(!map_texture.loadFromFile("assets/TestMap.png")) //TODO: add a library function that exctracts image assets by name eg. getImageAsset("TestMap")
  {
    std::cout<<"ERROR LOADING MAP";
    throw;
  }
  map.setTexture(map_texture);
  while (window.isOpen())
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    sf::Event event;
    while (window.pollEvent(event))
    {
      processEvent(event);
    }
    float dt = clock.getElapsedTime().asSeconds();
    physicsUpdate(dt);

    window.clear();
    window.draw(map);
    window.display();
  }
}
