#pragma once

#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "MenuPause.h"
#include "Partie.h"
#include "JoueurIA.h"
#include "JoueurHumain.h"

using namespace sf;

class Jeu : public Drawable
{
	vector<Joueur*> Joueurs;
	//Texture / Resources
	Texture backgroundImg;
	Texture spinnerImg;
	Thread Loader;
	bool ResourcesLoaded;
	//Object State
	MainMenu Menu;
	MenuPause Pause;
	Partie Partie;
	//State
public:
	enum State { Loading, MainMenu, AiSetUp, Play, PauseMenu, ResultatPartie, Quit };
private:
	State state;
	//Spinner
	int SpinState;
	int access;
	//Ai
	enum NbAi {Zero, Un, Deux};
	NbAi nbAi;
	//ressour
public:
	
	RectangleShape background;
	RectangleShape spinner;
	Jeu();
	~Jeu();
	void UpdateState(Window &window);
	virtual void draw(RenderTarget& target, RenderStates states) const;
	bool IsAlive();
	void LoadResources();
};

