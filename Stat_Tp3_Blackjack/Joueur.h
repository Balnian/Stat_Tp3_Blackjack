#pragma once
#include "JeuDeCarte.h"
#include "Carte.h"

#include <SFML/Graphics.hpp>
using namespace sf;

class Joueur : public Drawable
{
public:
	Joueur();
	~Joueur();
	void reinitialize();
	int GetCompte();
	void AddCard(Carte card);
	bool Busted();
	virtual void draw(RenderTarget& target, RenderStates states) const;
private:
	JeuDeCarte jeu;
	vector<Carte> cartePiger;
	int Compte;


};

