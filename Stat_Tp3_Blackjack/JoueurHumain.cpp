#include "JoueurHumain.h"
#include <iostream>

JoueurHumain::JoueurHumain()
{
}
JoueurHumain::~JoueurHumain()
{
}

void JoueurHumain::JouerTour(JeuDeCarte* jeuc)
{
	std::cout << "Hum" << endl;
	this->jeu = jeuc;
	AddCard(&jeuc->piger());
}

void JoueurHumain::Piger(Carte* card)
{
	AddCard(card);
}