#include "JeuDeCarte.h"
#include <iostream>
#include <sstream>

JeuDeCarte::JeuDeCarte()
{

	for (size_t i = 2; i <= 10; i++)
	{
		stringstream ss;
		ss << i;
		string carry;
		ss >> carry;

		Valeurs.emplace_back(carry + "_of_clubs.png", i);
		Valeurs.emplace_back(carry + "_of_diamonds.png", i);
		Valeurs.emplace_back(carry + "_of_hearts.png", i);
		Valeurs.emplace_back(carry + "_of_spades.png", i);
	}
	Valeurs.emplace_back("ace_of_clubs.png", vector < int > {1, 11});
	Valeurs.emplace_back("ace_of_diamonds.png", vector < int > {1, 11});
	Valeurs.emplace_back("ace_of_hearts.png", vector < int > {1, 11});
	Valeurs.emplace_back("ace_of_spades.png", vector < int > {1, 11});

	Valeurs.emplace_back("jack_of_clubs.png", 10);
	Valeurs.emplace_back("jack_of_diamonds.png", 10);
	Valeurs.emplace_back("jack_of_hearts.png", 10);
	Valeurs.emplace_back("jack_of_spades.png", 10);
	
	Valeurs.emplace_back("king_of_clubs.png", 10);
	Valeurs.emplace_back("king_of_diamonds.png", 10);
	Valeurs.emplace_back("king_of_hearts.png", 10);
	Valeurs.emplace_back("king_of_spades.png", 10);
	
	Valeurs.emplace_back("queen_of_clubs.png", 10);
	Valeurs.emplace_back("queen_of_diamonds.png", 10);
	Valeurs.emplace_back("queen_of_hearts.png", 10);
	Valeurs.emplace_back("queen_of_spades.png", 10);
}
JeuDeCarte::~JeuDeCarte()
{
}

void JeuDeCarte::draw(RenderTarget& target, RenderStates states) const
{

}