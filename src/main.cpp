#include <SFML/Graphics.hpp>
#include <iostream>
void processEvent(sf::RenderWindow & window, sf::Event event)
{
  if(event.type == sf::Event::Closed)
  {
    window.close();
  }
} //in the future this function will return user input if the message contains such
int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Game Window");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            processEvent(window, event);
        }
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
