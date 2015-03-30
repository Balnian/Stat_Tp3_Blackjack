#pragma once

#include <SFML/Graphics.hpp>
#include "JoueurIA.h"

using namespace sf;

class AiSetUp :public Drawable
{
public:
	enum BtDifState{ MouseHover_Prudent, MouseHover_Moyen, MouseHover_Courageux, MouseHover_Compte, MouseHover_Continuer, None };
	enum NbAI{Zero,Un,Deux};
	BtDifState State[2];
	bool Compte[2];
	JoueurIA::TypeAI Choix[2];
private:
	NbAI Nombre;
	
	Texture Tex_Ai[2];

	Texture Tex_Prudent;
	Texture Tex_Prudent_Selected;

	Texture Tex_Moyen;
	Texture Tex_Moyen_Selected;

	Texture Tex_Courageux;
	Texture Tex_Courageux_Selected;

	Texture Tex_Compte;
	Texture Tex_Compte_Selected;

	Texture Tex_Continuer;
	Texture Tex_Continuer_Selected;

	RectangleShape Ai[2];
	RectangleShape Bt_Prudent[2];
	RectangleShape Bt_Moyen[2];
	RectangleShape Bt_Courageux[2];
	RectangleShape Bt_Compte[2];
	RectangleShape Bt_Continuer;
public:
	AiSetUp();
	~AiSetUp();
	void setNombre(NbAI n);
	NbAI getNombre();
	void UpdateState(Vector2i Cursor);
	JoueurIA getSetUp(NbAI n);
	virtual void draw(RenderTarget& target, RenderStates states) const;
	void loadResource();
};

