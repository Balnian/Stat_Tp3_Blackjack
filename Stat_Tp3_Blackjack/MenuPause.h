#pragma once

#include <SFML/Graphics.hpp>
#include "Jeu.h"
using namespace sf;

class MenuPause : public Drawable
{
	VertexArray Overlay;
	Texture Tex_MainMenu;
	Texture Tex_MainMenu_Selected;

	Texture Tex_Quitter;
	Texture Tex_Quitter_Selected;

	RectangleShape Bt_MainMenu;
	RectangleShape Bt_Quitter;

	Jeu::State LastState;
public:
	enum Statep { MouseHover_MainMenu, MouseHover_Quitter, None };
	Statep state;
	MenuPause();
	~MenuPause();
	void UpdateState(Vector2i Cursor);
	virtual void draw(RenderTarget& target, RenderStates states) const;
	void loadResource();
	void setLastState(Jeu::State State);
	Jeu::State getLastState()const;
};

