#include "Jeu.h"


Jeu::Jeu()
{
	state = MainMenu;
	backgroundImg.loadFromFile("Images/Table.jpg");
	background.setTexture(&backgroundImg);
	background.setPosition(0, 0);
	background.setSize(Vector2f(1200, 700));

}

void Jeu::UpdateState(Window &window)
{
	Event event;
	while (window.pollEvent(event))
	{
		switch (state)
		{
		case Jeu::MainMenu:
			Menu.UpdateState((Mouse::getPosition(window)));
			if (event.mouseButton.button == Mouse::Right && Menu.state == Menu.MouseHover_JVA)
			{
				state = AiSetUp;
				nbAi = Un;
			}
			else if (event.mouseButton.button == Mouse::Right && Menu.state == Menu.MouseHover_AVA)
			{
				state = AiSetUp;
				nbAi = Deux;
			}

			break;
		case Jeu::AiSetUp:
			break;
		case Jeu::Play:
			break;
		case Jeu::PauseMenu:
			break;
		case Jeu::Quit:
			break;
		default:
			break;
		}


		if (event.type == Event::Closed)
			state = Quit;


	}

}

void Jeu::draw(RenderTarget& target, RenderStates states) const
{
	// You can draw other high-level objects
	target.draw(background);
	switch (state)
	{
	case Jeu::MainMenu:
		target.draw(Menu);
		break;
	case Jeu::AiSetUp:
		break;
	case Jeu::Play:
		break;
	case Jeu::PauseMenu:
		break;
	case Jeu::Quit:
		break;
	default:
		break;
	}
	

}

Jeu::~Jeu()
{
}

bool Jeu::IsAlive()
{
	return state != Quit;
}