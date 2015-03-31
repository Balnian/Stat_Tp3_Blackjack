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
	State Etat;
	BtState EtatBt;
private:
	bool GenreJoueur;

	Texture Tex_J[2];

	Texture Tex_Prendre;
	Texture Tex_Prendre_Selected;

	Texture Tex_Continuer;
	Texture Tex_Continuer_Selected;

	RectangleShape J;
	RectangleShape Bt_Prendre;
	RectangleShape Bt_Continuer;



	JeuDeCarte Paquet;
	
public:
	Partie();
	~Partie();
	void UpdateState(Vector2i Cursor, bool j1, bool j2);
	virtual void draw(RenderTarget& target, RenderStates states) const;
	void loadResource();
	StateInfo getState();
};

