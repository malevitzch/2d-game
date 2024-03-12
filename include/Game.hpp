#ifndef GAME
#define GAME
#include <SFML/Graphics.hpp>
class GameState
{
  private:
  public:
};

class Game
{
  private:
    sf::RenderWindow window;
    void processEvent(sf::Event event); 
  public:
    Game();
    Game(GameState game_state);
    
    void run();
};

#endif
