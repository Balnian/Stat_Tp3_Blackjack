#include "JoueurIA.h"
#include <iostream>

JoueurIA::JoueurIA(bool comptecarte , TypeAI type)
{
	//Initialisation de IA savoir si elle doit compter les carte ou non et de quelle type elle est
	JoueurIA::comptecarte = comptecarte;

	switch (type)
	{
	case courageux:
		pourcentageForPlay = AI_COURAGEUX;
		break;
	case moyen:
		pourcentageForPlay = AI_MOYEN;
		break;
	case prudent:
		pourcentageForPlay = AI_PRUDENT;
		break;
	default:
		pourcentageForPlay = DEFAULT;
		break;
	}
}
JoueurIA::~JoueurIA()
{
}

void JoueurIA::JouerTour()
{
	if (comptecarte)
		if (CompteCarte())
			AddCard(jeu->piger());
	else
		if (ComptePasCarte())
			AddCard(jeu->piger());
}
bool JoueurIA::CompteCarte()
{
   int minValue;//valeur minimale pour que le compte depasse 21
  float probability;

  if ((GetCompte() + 11) <= 21) // Peu importe la carte piger on ne depasse pas 21 donc on pige Sans se pauser de question
  {
	  std::cout << "Jai Un compte de " << GetCompte() << " donc Impossible de depasser" << endl;
	  return true;
  }      
   else
   {
      minValue = 22 - GetCompte();
	  std::cout << "Si je pige une carte de Valeur " << minValue << " Je depasse";

      if (minValue != 11) //Si les valeur minimale pour depasser est 11 il ne reste que la possibiliter de piger un as
      while (minValue != 13)
      {
		  //On compte Toutes les carte quil reste dans le paquet qui on la valeur pour depasser 21 incluant la valeur pour depasser
         if (minValue <= 10)
         probability += jeu->CountNbCarteSorte(minValue); 
         else
          probability += jeu->CountNbCarteSorte(10);

         minValue++;
      }
      else //les probabiliter son simplement les  as quil reste dans le paquet
		  probability = jeu->CountNbCarteSorte(1);;
      // met les probabiliter en pourcentage avant de verifier si il est  > ou < ou = au pourcentage pour piger
	  if ((100 - ((probability / jeu->CountNbCardPasPiger()) * 100)) >= pourcentageForPlay)
	  {
		  std::cout << "Jai " << 100 - ((probability / jeu->CountNbCardPasPiger()) * 100) << "% Chance de ne pas depasser 21 donc Je pige";
		  return true;
	  }

	  std::cout << "Jai " << 100 - ((probability / jeu->CountNbCardPasPiger()) * 100) << "% Chance de ne pas depasser 21 donc Je pige Pas";

      return false;
   }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool JoueurIA::ComptePasCarte()
{	
	int minValue;//valeur minimale pour que le compte depasse 21
	float probability;
	if ((GetCompte() + 11) <= 21) // Peu importe la carte piger on ne depasse pas 21 donc on pige Sans se pauser de question
	{
		std::cout << "Jai Un compte de " << GetCompte() << " donc Impossible de depasser" << endl;
		return true;		
	}
	else
	{
		minValue = 22 - GetCompte();
		std::cout << "Si je pige une carte de Valeur " << minValue << " Je depasse";

		if (minValue != 11) //Si les valeur minimale pour depasser est 11 il ne reste que la possibiliter de piger un as
		while ( minValue != 13)
		{			
			//Aditionne toute les Carte qui son au dessus de la valeur pour depasser 21 incluant la valeur
			probability += 4;
			minValue++;
		}
		else //les probabiliter son simplement les 4 as
		   probability = 4;
       // met les probabiliter en pourcentage avant de verifier si il est  > ou < ou = au pourcentage pour piger
		if ((100 - ((probability / 52) * 100)) >= pourcentageForPlay)
		{
			std::cout << "Jai " << 100 - ((probability / 52) * 100) << "% Chance de ne pas depasser 21 donc Je pige";
			return true;
		}
		std::cout << "Jai " << 100 - ((probability / 52) * 100) << "% Chance de ne pas depasser 21 donc Je pige Pas";
		return false;
	}
}


