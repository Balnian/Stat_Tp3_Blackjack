#pragma once
#include "Joueur.h"

//constante pour les % de chance de depasser



class JoueurIA: public Joueur
{
public:
	enum TypeAI{courageux,moyen,prudent};
	JoueurIA(bool comptecarte,TypeAI type);
	~JoueurIA();
	void JouerTour();
	bool CompteCarte();
	bool ComptePasCarte();
private:
	bool comptecarte;
	int pourcentageForPlay;	
	const int AI_COURAGEUX = 50;
	const int AI_MOYEN = 65;
	const int AI_PRUDENT = 80;
	const int DEFAULT = 50;
	
    
};

