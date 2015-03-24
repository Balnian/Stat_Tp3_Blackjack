#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Carte.h"


using namespace std;
using namespace sf;

class JeuDeCarte
{
	vector < Carte > Paquet;
	vector<ValeurCarte> Valeurs;
public:
	JeuDeCarte();
	~JeuDeCarte();

	void loadResource();
	Carte piger();
	void reinitialize();
	int CountNbCardPasPiger();
   int CountNbCarteSorte(int value);
};

