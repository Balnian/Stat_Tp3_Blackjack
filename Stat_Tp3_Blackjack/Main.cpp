#include <SFML/Graphics.hpp>
#include "Jeu.h"
using namespace sf;

int main()
{
	Jeu BlackJack;
	RenderWindow window(VideoMode(1200, 700), "SFML works!");

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			
			BlackJack.UpdateState(Mouse::getPosition(window));
		}

		window.clear();
		window.draw(BlackJack);
		window.display();
	}

	return 0;
}