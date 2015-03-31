#pragma once
#include "Joueur.h"
class JoueurHumain: public Joueur
{
public:
	JoueurHumain();
	~JoueurHumain();
	virtual void JouerTour(JeuDeCarte* jeuc);
	void Piger(Carte* card);
};

