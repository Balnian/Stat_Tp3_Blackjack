#pragma once

#include <SFML/Graphics.hpp>
#include "MenuPrincipal.h"
#include "MenuPause.h"
#include "Partie.h"
#include "JeuDeCarte.h"
#include "JoueurIA.h"
#include "JoueurHumain.h"
#include "AiSetUp.h"

using namespace sf;

class Jeu : public Drawable
{
	JeuDeCarte Paquet;
	vector<Joueur*> Joueurs;
	//Texture / Resources
	Texture backgroundImg;
	Texture spinnerImg;
	Thread Loader;
	bool ResourcesLoaded;
	//Object State
	MenuPrincipal Menu;
	MenuPause Pause;
	Partie Partie;
	AiSetUp MenuAi;
	//State
public:
	enum State { Loading, MainMenu, AiSetUp, Play, PauseMenu, ResultatPartie, Quit };
private:
	State state;
	State LastState;
	//Spinner
	int SpinState;
	int access;
	//Ai
	AiSetUp::NbAI nbAi;
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

