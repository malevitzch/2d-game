#ifndef GAME
#define GAME
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
class GameState
{
  private:
  public:
};

sf::Vector2f normalize(sf::Vector2f v);
sf::Vector2f clamp(sf::Vector2f v, sf::Vector2f xbounds, sf::Vector2f ybounds);
class Game
{
  private:
    sf::Texture map_texture;
    sf::Sprite map;
    sf::Clock clock;
    sf::RenderWindow window;
    void processEvent(sf::Event event);
    void physicsUpdate(float dt);
  public:
    Game();
    Game(GameState game_state);
    
    void run();
};

#endif
