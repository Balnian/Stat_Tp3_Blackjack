#include "Jeu.h"


Jeu::Jeu()
{
	backgroundImg.loadFromFile("Images/Table.jpg");
	background.setTexture(&backgroundImg);
	background.setPosition(0, 0);
	background.setSize(Vector2f(1200, 700));
	
}

void Jeu::UpdateState(Vector2i Cursor)
{
	Menu.UpdateState(Cursor);
}

void Jeu::draw(RenderTarget& target, RenderStates states) const
{
	// You can draw other high-level objects
	target.draw(background);
	target.draw(Menu);
	
}

Jeu::~Jeu()
{
}
