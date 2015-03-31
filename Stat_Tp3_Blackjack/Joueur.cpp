#include "Joueur.h"
#include <iostream>

Joueur::Joueur() :ia(false)
{
}

Joueur::~Joueur()
{
}

bool Joueur::isIa()
{
	return ia;
}

void Joueur::setIa()
{
	ia = true;
}

void Joueur::reinitialize()
{
	jeu->reinitialize();
}

void Joueur::JouerTour(JeuDeCarte* jeu)
{
	std::cout << "NOPE!!!"<<std::endl;
}

int  Joueur::GetCompte()
{
	int compte=0;
	for each (Carte* carte in cartePiger)
	{
		if (carte->getValue(1) + compte <= 21)
			compte += carte->getValue(1);
		else
			compte += carte->getValue();
	}
	return compte;
}

void  Joueur::AddCard(Carte* card)
{
	cartePiger.push_back(card);
	Compte = GetCompte() + card->getValue();
	RectangleShape carry(Vector2f(500, 726));
	carry.setScale(0.2, 0.2);
	
	rect.emplace_back(carry);
	
}

void Joueur::calculateCardPosition()
{
	for (size_t i = 0; i < rect.size(); i++)
	{
		rect.at(i).setPosition((1200 - ((500 * 0.2) + 5)*rect.size()) / 2 + ((500 * 0.2) + 5)*rect.size(), (Joue) ? 700 - 727 * 0.2 : 1);
		rect.at(i).setTexture(cartePiger.at(i));
	}
}

bool Joueur::Busted()
{
	return GetCompte() > 21 ? true : false;
}

void Joueur::draw(RenderTarget& target, RenderStates states) const
{
	for (size_t i = 0; i < rect.size(); i++)
	{
		target.draw(rect.at(i));
	}
	//target.draw(Overlay);
}
