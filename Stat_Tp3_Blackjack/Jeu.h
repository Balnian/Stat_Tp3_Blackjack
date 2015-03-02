#pragma once

#include <SFML/Graphics.hpp>
#include "MainMenu.h"

using namespace sf;

class Jeu : public Drawable
{
	Texture backgroundImg;
	MainMenu Menu;
public:
	RectangleShape background;
	Jeu();
	~Jeu();
	void UpdateState(Vector2i Cursor);
	virtual void draw(RenderTarget& target, RenderStates states) const;
};

