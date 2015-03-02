#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class MainMenu : public Drawable
{
	Texture Tex_JVsAi;
	Texture Tex_JVsAi_Selected;
	Texture Tex_AiVsAi;
	Texture Tex_AiVsAi_Selected;

	RectangleShape Bt_JVsAi;
	RectangleShape Bt_AiVsAi;

	enum State {MouseHover_JVA,MouseHover_AVA,None};
	State state;
public:
	MainMenu();
	~MainMenu();
	void UpdateState(Vector2i Cursor);
	virtual void draw(RenderTarget& target, RenderStates states) const;
	

};

