#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Carte.h"


using namespace std;
using namespace sf;

class JeuDeCarte: public Drawable
{
	vector < Carte > Paquet;
	vector<ValeurCarte> Valeurs;
public:
	JeuDeCarte();
	~JeuDeCarte();
	virtual void draw(RenderTarget& target, RenderStates states) const;
};

