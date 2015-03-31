#pragma once
#include "JeuDeCarte.h"
#include "Carte.h"

#include <SFML/Graphics.hpp>
using namespace sf;

class Joueur : public Drawable
{
public:
	bool isIa();
	bool Joue;
	Joueur();
	~Joueur();
	void reinitialize();
	int GetCompte();
	virtual void JouerTour(JeuDeCarte* jeu);
	void AddCard(Carte* card);
	bool Busted();
	virtual void draw(RenderTarget& target, RenderStates states) const;
protected:
	void setIa();
	void calculateCardPosition();
	JeuDeCarte* jeu;
	vector<Carte*> cartePiger;
	vector<RectangleShape> rect;
	int Compte;
private:
	bool ia;


};

