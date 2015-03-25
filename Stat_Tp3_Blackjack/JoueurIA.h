#pragma once
#include "Joueur.h"

//constante pour les % de chance de depasser
const int AI_COURAGEUX = 50;
const int AI_MOYEN = 65;
const int AI_PRUDENT = 80;
const int DEFAULT = 50;
enum TypeAI{courageux,moyen,prudent};

class JoueurIA: public Joueur
{
public:
	JoueurIA(bool comptecarte,TypeAI type);
	~JoueurIA();
	void JouerTour();
	bool CompteCarte();
	bool ComptePasCarte();
private:
	bool comptecarte;
	int pourcentageForPlay;	
	
    
};

