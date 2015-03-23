#include "JeuDeCarte.h"
#include <iostream>
#include <sstream>

JeuDeCarte::JeuDeCarte()
{

	for (int i = 2; i <= 10; i++)
	{
		stringstream ss;
		ss << i;
		string carry;
		ss >> carry;

		Valeurs.emplace_back("Images/Cartes/" + carry + "_of_clubs.png", vector < int > {i});
		Valeurs.emplace_back("Images/Cartes/" + carry + "_of_diamonds.png", vector < int > {i});
		Valeurs.emplace_back("Images/Cartes/" + carry + "_of_hearts.png", vector < int > {i});
		Valeurs.emplace_back("Images/Cartes/" + carry + "_of_spades.png", vector < int > {i});
	}
	vector < int > as{ 1, 11 };
	Valeurs.emplace_back("Images/Cartes/ace_of_clubs.png", as);
	Valeurs.emplace_back("Images/Cartes/ace_of_diamonds.png", as);
	Valeurs.emplace_back("Images/Cartes/ace_of_hearts.png", as);
	Valeurs.emplace_back("Images/Cartes/ace_of_spades.png", as);
						  
	Valeurs.emplace_back("Images/Cartes/jack_of_clubs.png", vector < int > {10});
	Valeurs.emplace_back("Images/Cartes/jack_of_diamonds.png", vector < int > {10});
	Valeurs.emplace_back("Images/Cartes/jack_of_hearts.png", vector < int > {10});
	Valeurs.emplace_back("Images/Cartes/jack_of_spades.png", vector < int > {10});
						  
	Valeurs.emplace_back("Images/Cartes/king_of_clubs.png", vector < int > {10});
	Valeurs.emplace_back("Images/Cartes/king_of_diamonds.png", vector < int > {10});
	Valeurs.emplace_back("Images/Cartes/king_of_hearts.png", vector < int > {10});
	Valeurs.emplace_back("Images/Cartes/king_of_spades.png", vector < int > {10});
						 
	Valeurs.emplace_back("Images/Cartes/queen_of_clubs.png", vector < int > {10});
	Valeurs.emplace_back("Images/Cartes/queen_of_diamonds.png", vector < int > {10});
	Valeurs.emplace_back("Images/Cartes/queen_of_hearts.png", vector < int > {10});
	Valeurs.emplace_back("Images/Cartes/queen_of_spades.png", vector < int > {10});
}
JeuDeCarte::~JeuDeCarte()
{
}

void JeuDeCarte::loadResource()
{
	
	for each (ValeurCarte val in Valeurs)
	{
		Paquet.emplace_back(val.Value);
		Paquet.back().loadFromFile(val.Path);
	}
	random_shuffle(Paquet.begin(), Paquet.end());
}

Carte* JeuDeCarte::piger()
{
	srand(time(NULL));
	int piger;
	while (Paquet.at(piger=(rand() % 52)).piger());
	return &Paquet.at(piger);
}

void JeuDeCarte::reinitialize()
{
	for each (Carte item in Paquet)
	{
		item.
	}
	random_shuffle(Paquet.begin(), Paquet.end());
}