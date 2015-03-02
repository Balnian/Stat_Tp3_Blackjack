#include <SFML/Graphics.hpp>
#include "Jeu.h"
using namespace sf;

int main()
{
	Jeu BlackJack;
	RenderWindow window(VideoMode(1200, 700), "BlackJack",Style::Titlebar | Style::Close);

	while (window.isOpen() && BlackJack.IsAlive())
	{
		
		
		BlackJack.UpdateState(window);
		

		window.clear();
		window.draw(BlackJack);
		window.display();
	}
	window.close();
	return 0;
}