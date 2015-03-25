#pragma once

#include <SFML/Graphics.hpp>
#include "JeuDeCarte.h"
using namespace sf;

class Partie : public Drawable
{
public:
	
	enum State{ TourJoueur1, TourJoueur2, VJ1, VJ2, Egal };
	enum BtState{ Prendre, Continuer, None };
	struct StateInfo
	{
		State Etat;
		BtState EtatBt;
		StateInfo(State etat, BtState etatBt)
		{
			Etat = etat;
			EtatBt = etatBt;
		}
	};
private:
	JeuDeCarte Paquet;
	State Etat;
	BtState EtatBt;
public:
	Partie();
	~Partie();
	void UpdateState(Vector2i Cursor);
	virtual void draw(RenderTarget& target, RenderStates states) const;
	void loadResource();
	StateInfo getState();
};

