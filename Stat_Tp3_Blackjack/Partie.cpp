#include "Partie.h"


Partie::Partie() :Etat(TourJoueur1)
{
}


Partie::~Partie()
{

}

void Partie::UpdateState(Vector2i Cursor)
{
	switch (Etat)
	{
	case TourJoueur1:
		break;
	case TourJoueur2:
		break;
	default:

	default:
		break;
	}
}

void Partie::draw(RenderTarget& target, RenderStates states) const
{

	//target.draw(Overlay);
}

Partie::StateInfo Partie::getState()
{
	return StateInfo(Etat, EtatBt);
}

void Partie::loadResource()
{
	Paquet.loadResource();
}