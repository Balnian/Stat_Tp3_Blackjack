#pragma once

#include <SFML/Graphics.hpp>
#include "MainMenu.h"

using namespace sf;

class Jeu : public Drawable
{
	Texture backgroundImg;
	MainMenu Menu;
	enum State {MainMenu, AiSetUp, Play, PauseMenu, Quit};
	State state;
	enum NbAi {Un, Deux};
	NbAi nbAi;
public:
	RectangleShape background;
	Jeu();
	~Jeu();
	void UpdateState(Window &window);
	virtual void draw(RenderTarget& target, RenderStates states) const;
	bool IsAlive();
};

