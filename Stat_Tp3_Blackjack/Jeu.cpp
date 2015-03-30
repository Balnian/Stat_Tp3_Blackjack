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
			if (event.mouseButton.button == Mouse::Left && Menu.state == Menu.MouseHover_JVJ && event.type == Event::MouseButtonReleased)
			{
				state = AiSetUp;
				nbAi = AiSetUp::NbAI::Zero;
				MenuAi.setNombre(nbAi);
			}
			else if (event.mouseButton.button == Mouse::Left && Menu.state == Menu.MouseHover_JVA && event.type == Event::MouseButtonReleased)
			{
				state = AiSetUp;
				nbAi = AiSetUp::NbAI::Un;
				MenuAi.setNombre(nbAi);
			}
			else if (event.mouseButton.button == Mouse::Left && Menu.state == Menu.MouseHover_AVA && event.type == Event::MouseButtonReleased)
			{
				state = AiSetUp;
				nbAi = AiSetUp::NbAI::Deux;
				MenuAi.setNombre(nbAi);
			}

			break;
		case Jeu::AiSetUp:

			if (nbAi == AiSetUp::NbAI::Zero)
			{
				Joueurs.emplace_back( JoueurHumain());
				Joueurs.emplace_back( JoueurHumain());
				state = Play;
			}
			MenuAi.UpdateState(Mouse::getPosition(window));
			for (size_t i = 0; i < nbAi; i++)
			{
				if (event.mouseButton.button == Mouse::Left && MenuAi.State[i] == AiSetUp::BtDifState::MouseHover_Continuer && event.type == Event::MouseButtonReleased)
				{
					switch (nbAi)
					{
					case AiSetUp::NbAI::Un:
						Joueurs.emplace_back(JoueurHumain());
						Joueurs.emplace_back(MenuAi.getSetUp(AiSetUp::NbAI::Un));
						break;
					case AiSetUp::NbAI::Deux:
						Joueurs.emplace_back(MenuAi.getSetUp(AiSetUp::NbAI::Un));
						Joueurs.emplace_back(MenuAi.getSetUp(AiSetUp::NbAI::Deux));
						break;
					default:
						Joueurs.emplace_back(JoueurHumain());
						Joueurs.emplace_back(JoueurHumain());
						break;
					}
					state = Play;
				}
				else if (event.mouseButton.button == Mouse::Left && MenuAi.State[i] == AiSetUp::BtDifState::MouseHover_Compte && event.type == Event::MouseButtonReleased)
				{
					MenuAi.Compte[i] = !MenuAi.Compte[i];
				}
				else if (event.mouseButton.button == Mouse::Left && MenuAi.State[i] == AiSetUp::BtDifState::MouseHover_Courageux && event.type == Event::MouseButtonReleased)
				{
					MenuAi.Choix[i] = JoueurIA::TypeAI::courageux;
				}
				else if (event.mouseButton.button == Mouse::Left && MenuAi.State[i] == AiSetUp::BtDifState::MouseHover_Moyen && event.type == Event::MouseButtonReleased)
				{
					MenuAi.Choix[i] = JoueurIA::TypeAI::moyen;
				}
				else if (event.mouseButton.button == Mouse::Left && MenuAi.State[i] == AiSetUp::BtDifState::MouseHover_Prudent && event.type == Event::MouseButtonReleased)
				{
					MenuAi.Choix[i] = JoueurIA::TypeAI::prudent;
				}
			}
			
			
			break;
		case Jeu::Play:
			Partie.UpdateState(Mouse::getPosition(window));
			break;
		case Jeu::PauseMenu:
			Pause.UpdateState(Mouse::getPosition(window));
			if (event.mouseButton.button == Mouse::Left && Pause.state == Pause.MouseHover_Continuer && event.type == Event::MouseButtonReleased)
			{
				state = LastState;
			}
			if (event.mouseButton.button == Mouse::Left && Pause.state == Pause.MouseHover_MainMenu && event.type == Event::MouseButtonReleased)
			{
				state = MainMenu;
			}
			else if (event.mouseButton.button == Mouse::Left && Pause.state == Pause.MouseHover_Quitter && event.type == Event::MouseButtonReleased)
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
					state = LastState;
				}
				else
				{
					LastState = state;
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
		target.draw(MenuAi);
		break;
	case Jeu::Play:
		target.draw(Partie);
		break;
	case Jeu::ResultatPartie:
		/*A implémenter*/
		break;
	case Jeu::PauseMenu:
		switch (LastState)
		{
		case Jeu::Loading:
			target.draw(spinner);
			break;
		case Jeu::MainMenu:
			target.draw(Menu);
			break;
		case Jeu::AiSetUp:
			target.draw(MenuAi);
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
	Pause.loadResource();
	MenuAi.loadResource();
	Partie.loadResource();
	Paquet.loadResource();
	state = MainMenu;	
}