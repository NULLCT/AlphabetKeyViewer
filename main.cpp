#include "keyop.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
  window.setFramerateLimit(60);

  sf::Font font;
  if (!font.loadFromFile("firacode.otf")) {
    cerr << "font cannot load\n";
    return -1;
  }
  
  sf::Text text;
  text.setFont(font);
  text.setString("testaaa");
  text.setCharacterSize(18);
  text.setFillColor(sf::Color::Black);
  text.setOrigin(sf::Vector2f(-3, 3));

  vector<Key> keys('z' - 'a' + 1);

  string s;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();

      if (event.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::A <= event.key.code && event.key.code <= sf::Keyboard::Z) {
          keys[event.key.code].setStatusPush();
          s += 'a' + event.key.code;
        }
        else if (sf::Keyboard::BackSpace == event.key.code) {
          if(s.size() != 0) s.pop_back();
        }
        else if (sf::Keyboard::Enter == event.key.code) {
          s += "\n";
        }else if (sf::Keyboard::Space == event.key.code){
          s += " ";
        }
      }

      else if (event.type == sf::Event::KeyReleased) {
        if (sf::Keyboard::A <= event.key.code && event.key.code <= sf::Keyboard::Z) {
          keys[event.key.code].setStatusRelease();
        }
      }
    }

    window.clear(sf::Color::Black);

    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(18,18));

    for (int i = 0; i < keys.size(); i++) {
      rect.setPosition(i * 20, 300);
      window.draw(rect);

      if (keys[i].getStatus()) {
        text.setString(sf::String(char('a'+i)));
        text.setPosition(i * 20, 300);
        text.setFillColor(sf::Color::Black);
        window.draw(text);
      }
    }

    text.setString(s);
    text.setFillColor(sf::Color::White);
    text.setPosition(0, 0);
    window.draw(text);

    window.display();
  }

  cout << s << "\n";

  return 0;
}