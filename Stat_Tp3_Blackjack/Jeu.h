#pragma once

#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "MenuPause.h"

using namespace sf;

class Jeu : public Drawable
{
	//Texture / Resources
	Texture backgroundImg;
	Texture spinnerImg;
	Thread Loader;
	bool ResourcesLoaded;
	//Object State
	MainMenu Menu;
	MenuPause Pause;
	//State
	enum State {Loading, MainMenu, AiSetUp, Play, PauseMenu, Quit};
	State state;
	//Spinner
	int SpinState;
	int access;
	//Ai
	enum NbAi {Un, Deux};
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

