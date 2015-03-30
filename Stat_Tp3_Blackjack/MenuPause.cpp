#include "MenuPause.h"


MenuPause::MenuPause() :Overlay(Quads, 4), state(None)
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
	if (Bt_Continuer.getGlobalBounds().contains((Vector2f)Cursor))
		state = MouseHover_Continuer;
	else if (Bt_MainMenu.getGlobalBounds().contains((Vector2f)Cursor))
		state = MouseHover_MainMenu;
	else if (Bt_Quitter.getGlobalBounds().contains((Vector2f)Cursor))
		state = MouseHover_Quitter;
	else
		state = None;

	switch (state)
	{
	case MouseHover_Continuer:
		Bt_Continuer.setTexture(&Tex_Continuer_Selected);
		Bt_MainMenu.setTexture(&Tex_MainMenu);
		Bt_Quitter.setTexture(&Tex_Quitter);
		break;
	case MenuPause::MouseHover_MainMenu:
		Bt_Continuer.setTexture(&Tex_Continuer);
		Bt_MainMenu.setTexture(&Tex_MainMenu_Selected);
		Bt_Quitter.setTexture(&Tex_Quitter);
		break;
	case MenuPause::MouseHover_Quitter:
		Bt_Continuer.setTexture(&Tex_Continuer);
		Bt_MainMenu.setTexture(&Tex_MainMenu);
		Bt_Quitter.setTexture(&Tex_Quitter_Selected);
		break;
	default:
		Bt_Continuer.setTexture(&Tex_Continuer);
		Bt_MainMenu.setTexture(&Tex_MainMenu);
		Bt_Quitter.setTexture(&Tex_Quitter);
		break;
	}
}

void MenuPause::draw(RenderTarget& target, RenderStates states) const
{

	target.draw(Overlay);
	target.draw(Bt_Continuer);
	target.draw(Bt_MainMenu);
	target.draw(Bt_Quitter);
}

void MenuPause::loadResource()
{
	Tex_Continuer.loadFromFile("Images/Commun/Continuer.png");
	Tex_Continuer_Selected.loadFromFile("Images/Commun/Continuer_Selected.png");

	Tex_MainMenu.loadFromFile("Images/Pause/MainMenu.png");
	Tex_MainMenu_Selected.loadFromFile("Images/Pause/MainMenu_Selected.png");

	Tex_Quitter.loadFromFile("Images/Commun/Quitter.png");
	Tex_Quitter_Selected.loadFromFile("Images/Commun/Quitter_Selected.png");

	Bt_Continuer.setPosition(Vector2f(288, 75));
	Bt_Continuer.setSize(Vector2f(624, 139));

	Bt_MainMenu.setPosition(Vector2f(288, 100 + 139));
	Bt_MainMenu.setSize(Vector2f(624, 139));

	Bt_Quitter.setPosition(Vector2f(288, 125 + 139 * 2));
	Bt_Quitter.setSize(Vector2f(624, 139));
}
