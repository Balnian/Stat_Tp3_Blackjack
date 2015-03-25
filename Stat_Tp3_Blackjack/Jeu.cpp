#include "Jeu.h"
#include <iostream>

Jeu::Jeu() :ResourcesLoaded(false), Loader(&Jeu::LoadResources,this)
{
	Loader.launch();
	state = Loading;
	SpinState = 0;
	access = 0;
	backgroundImg.loadFromFile("Images/Table.jpg");
	background.setTexture(&backgroundImg);
	background.setPosition(0, 0);
	background.setSize(Vector2f(1200, 700));

	spinnerImg.loadFromFile("Images/loading.png");
	spinner.setTexture(&spinnerImg);
	spinner.setOrigin(Vector2f(512 / 2, 512 / 2));
	spinner.setSize(Vector2f(512, 512));
	spinner.setPosition(1200 / 2 , 700 / 2 );
	spinner.scale(Vector2f(0.25, 0.25));
	
}

void Jeu::UpdateState(Window &window)
{
	
	Event event;
	while (window.pollEvent(event))
	{
		switch (state)
		{
		case Jeu::Loading:
			if (access >= 7)
			{

				access = 0;
				if (SpinState >= 8)
					SpinState = 0;

				spinner.setTextureRect(Rect<int>(512 * (SpinState % 4), 512 * (SpinState / 4), 512, 512));

				++SpinState;
				
			}
			access++;
			
			break;
		case Jeu::MainMenu:
			Menu.UpdateState(Mouse::getPosition(window));
			if (event.mouseButton.button == Mouse::Right && Menu.state == Menu.MouseHover_JVJ)
			{
				state = AiSetUp;
				nbAi = Zero;
			}
			else if (event.mouseButton.button == Mouse::Right && Menu.state == Menu.MouseHover_JVA)
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
			switch (nbAi)
			{
			case Un:
				Joueurs.emplace_back(new JoueurHumain());
				Joueurs.emplace_back(new JoueurIA());
				break;
			case Deux:
				Joueurs.emplace_back(new JoueurIA());
				Joueurs.emplace_back(new JoueurIA());
				break;
			default:
				Joueurs.emplace_back(new JoueurHumain());
				Joueurs.emplace_back(new JoueurHumain());
				break;
			}
			break;
		case Jeu::Play:
			Partie.UpdateState(Mouse::getPosition(window));
			break;
		case Jeu::PauseMenu:
			Pause.UpdateState(Mouse::getPosition(window));
			if (event.mouseButton.button == Mouse::Right && Menu.state == Pause.MouseHover_MainMenu)
			{
				state = MainMenu;
			}
			else if (event.mouseButton.button == Mouse::Right && Pause.state == Pause.MouseHover_Quitter)
			{
				state = Quit;
			}
			break;
		case ResultatPartie:
			break;
		case Jeu::Quit:
			
			break;
		default:
			break;
		}
		static bool noRepeat = true;
		if (Keyboard::isKeyPressed(Keyboard::Escape) )
		{
			if (noRepeat)
			{
				if (state == PauseMenu)
				{
					state = Pause.getLastState();
				}
				else
				{
					Pause.setLastState(state);
					state = PauseMenu;
				}
				noRepeat = false;
			}

		}
		else
		{
			noRepeat = true;
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
	case Jeu::Loading:
		target.draw(spinner);
		break;
	case Jeu::MainMenu:
		target.draw(Menu);
		break;
	case Jeu::AiSetUp:
		/*A implémenter*/
		break;
	case Jeu::Play:
		target.draw(Partie);
		break;
	case Jeu::ResultatPartie:
		/*A implémenter*/
		break;
	case Jeu::PauseMenu:
		switch (Pause.getLastState())
		{
		case Jeu::Loading:
			target.draw(spinner);
			break;
		case Jeu::MainMenu:
			target.draw(Menu);
			break;
		case Jeu::AiSetUp:
			/*A implémenter*/
			break;
		case Jeu::Play:
			target.draw(Partie);
			break;
		case Jeu::ResultatPartie:
			/*A implémenter*/
			break;
		default:
			break;
		}
				
		target.draw(Pause);
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

void Jeu::LoadResources()
{	
	Menu.loadResource();
	Partie.loadResource();
	state = MainMenu;	
}