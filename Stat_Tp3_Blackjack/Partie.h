#pragma once

#include <SFML/Graphics.hpp>
#include "JeuDeCarte.h"
using namespace sf;

class Partie : public Drawable
{
	JeuDeCarte Paquet;
public:
	Partie();
	~Partie();
	virtual void draw(RenderTarget& target, RenderStates states) const;
	void loadResource();
};

