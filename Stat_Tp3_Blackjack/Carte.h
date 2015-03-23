#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Carte : public Texture
{
int Value;
public:
	
	Carte(int Value);
	~Carte();
	int getValue();

};

