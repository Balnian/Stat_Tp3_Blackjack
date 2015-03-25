#pragma once

#include <SFML/Graphics.hpp>
#include "JoueurIA.h"

using namespace sf;

class AiSetUp :public Drawable
{
public:
	enum BtDifState{ MouseHover_Prudent, MouseHover_Moyen, MouseHover_Courageux, MouseHover_Compte, MouseHover_Continuer, None };
	
private:
	bool Compte;
	JoueurIA::TypeAI Choix;
public:
	AiSetUp();
	~AiSetUp();
	void UpdateState(Vector2i Cursor);
	virtual void draw(RenderTarget& target, RenderStates states) const;
	void loadResource();
};

