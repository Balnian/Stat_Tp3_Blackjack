#include <SFML/Graphics.hpp>
#include "Jeu.h"
using namespace sf;

int main()
{
	Jeu BlackJack;
	RenderWindow window(VideoMode(1200, 700), "BlackJack",Style::Titlebar | Style::Close);

	VertexArray Overlay(Quads, 4);
	Overlay[0].position = Vector2f(0, 0);
	Overlay[1].position = Vector2f(1200, 0);
	Overlay[2].position = Vector2f(1200, 700);
	Overlay[3].position = Vector2f(0, 700);
	srand(time(NULL));
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);
	while (window.isOpen() && BlackJack.IsAlive())
	{
		
		
		BlackJack.UpdateState(window);
		
		
		Overlay[0].color = Color::Color(rand(), rand(), rand(), 153);
		
		Overlay[1].color = Color::Color(rand(), rand(), rand(), 153);
		
		Overlay[2].color = Color::Color(rand(), rand(), rand(), 153);
		
		Overlay[3].color = Color::Color(rand(), rand(), rand(), 153);

		window.clear();
		window.draw(BlackJack);
		//window.draw(Overlay);
		window.display();
	}
	window.close();
	return 0;
}