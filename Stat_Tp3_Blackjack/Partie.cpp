#include "Partie.h"


Partie::Partie() :Etat(TourJoueur1)
{
}


Partie::~Partie()
{

}

void Partie::UpdateState(Vector2i Cursor, bool j1, bool j2)
{

	switch (Etat)
	{
	case TourJoueur1:
		GenreJoueur = j1;
		J.setTexture(&Tex_J[TourJoueur1]);
		break;
	case TourJoueur2:
		GenreJoueur = j2;
		J.setTexture(&Tex_J[TourJoueur2]);
		break;
	default:
		break;
	}

	if (Bt_Prendre.getGlobalBounds().contains((Vector2f)Cursor) && !GenreJoueur)
		EtatBt = Prendre;
	else if (Bt_Continuer.getGlobalBounds().contains((Vector2f)Cursor))
		EtatBt = Continuer;
	else
		EtatBt = None;

	switch (EtatBt)
	{
	case Prendre:
		Bt_Prendre.setTexture(&Tex_Prendre_Selected);
		Bt_Continuer.setTexture(&Tex_Continuer);
		break;
	case Continuer:
		Bt_Prendre.setTexture(&Tex_Prendre);
		Bt_Continuer.setTexture(&Tex_Continuer_Selected);
		break;
	default:
		Bt_Prendre.setTexture(&Tex_Prendre);
		Bt_Continuer.setTexture(&Tex_Continuer);
		break;
	}
	

}

void Partie::draw(RenderTarget& target, RenderStates states) const
{
	if (!GenreJoueur)
		target.draw(Bt_Prendre);
	target.draw(Bt_Continuer);
	target.draw(J);
}

Partie::StateInfo Partie::getState()
{
	return StateInfo(Etat, EtatBt);
}

void Partie::loadResource()
{
	Tex_J[0].loadFromFile("Images/AiSetUp/Un.png");
	Tex_J[1].loadFromFile("Images/AiSetUp/Deux.png");

	Tex_Prendre.loadFromFile("Images/Partie/Prendre.png");
	Tex_Prendre_Selected.loadFromFile("Images/Partie/Prendre_Selected.png");

	Tex_Continuer.loadFromFile("Images/Commun/Continuer.png");
	Tex_Continuer_Selected.loadFromFile("Images/Commun/Continuer_Selected.png");

	J.setSize(Vector2f(175, 300));
	J.setPosition(Vector2f(25, (700 - 300) / 2));
	

	Bt_Prendre.setPosition(Vector2f(288, (700-139 * 0.5)/2 ));
	Bt_Prendre.setSize(Vector2f(624, 139));
	Bt_Prendre.setScale(0.5, 0.5);

	Bt_Continuer.setPosition(Vector2f(288 + 624 * 0.5 + 25, (700 - 139 * 0.5)/2));
	Bt_Continuer.setSize(Vector2f(624, 139));
	Bt_Continuer.setScale(0.5, 0.5);

	Paquet.loadResource();
}