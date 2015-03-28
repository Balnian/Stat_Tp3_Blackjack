#include "MenuPause.h"


MenuPause::MenuPause() :Overlay(Quads, 4)
{

	Overlay[0].position = Vector2f(0, 0);
	Overlay[0].color = Color::Color(128, 128, 128, 153);
	Overlay[1].position = Vector2f(1200, 0);
	Overlay[1].color = Color::Color(128, 128, 128, 153);
	Overlay[2].position = Vector2f(1200, 700);
	Overlay[2].color = Color::Color(128, 128, 128, 153);
	Overlay[3].position = Vector2f(0, 700);
	Overlay[3].color = Color::Color(128, 128, 128, 153);
}


MenuPause::~MenuPause()
{
}

void MenuPause::UpdateState(Vector2i Cursor)
{
	switch (state)
	{
	case MenuPause::MouseHover_MainMenu:
		Bt_MainMenu.setTexture(&Tex_MainMenu_Selected);
		Bt_Quitter.setTexture(&Tex_Quitter);
		break;
	case MenuPause::MouseHover_Quitter:
		Bt_MainMenu.setTexture(&Tex_MainMenu);
		Bt_Quitter.setTexture(&Tex_Quitter_Selected);
		break;
	default:
		Bt_MainMenu.setTexture(&Tex_MainMenu);
		Bt_Quitter.setTexture(&Tex_Quitter);
		break;
	}
}

void MenuPause::draw(RenderTarget& target, RenderStates states) const
{

	target.draw(Overlay);
}

void MenuPause::loadResource()
{
	Tex_MainMenu.loadFromFile("Images/Pause/MainMenu.png");
	Tex_MainMenu_Selected.loadFromFile("Images/Pause/MainMenu_Selected.png");

	Tex_Quitter.loadFromFile("Images/Commun/Quitter.png");
	Tex_Quitter.loadFromFile("Images/Commun/Quitter_Selected.png");
}
