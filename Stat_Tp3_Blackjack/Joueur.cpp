#include "Joueur.h"


Joueur::Joueur()
{
}

Joueur::~Joueur()
{
}

void Joueur::reinitialize()
{
}

int  Joueur::GetCompte()
{
	int compte=0;
	for each (Carte carte in cartePiger)
	{
		if (carte.getValue(1) + compte > 21)
			compte += carte.getValue(1);
		else
			compte += carte.getValue();
	}
	return compte;
}

void  Joueur::AddCard(Carte card)
{
	cartePiger.push_back(card);
	Compte = GetCompte() + card.getValue();
}
bool Joueur::Busted()
{


}

void Joueur::draw(RenderTarget& target, RenderStates states) const
{

	//target.draw(Overlay);
}
