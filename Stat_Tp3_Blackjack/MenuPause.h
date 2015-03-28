#pragma once

#include <SFML/Graphics.hpp>

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

public:
	enum State { MouseHover_MainMenu, MouseHover_Quitter, None };
	State state;
	MenuPause();
	~MenuPause();
	void UpdateState(Vector2i Cursor);
	virtual void draw(RenderTarget& target, RenderStates states) const;
	void loadResource();
};

