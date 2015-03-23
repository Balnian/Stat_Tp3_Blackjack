#include "JoueurIA.h"


JoueurIA::JoueurIA(bool comptecarte , TypeAI type)
{
	//Set IA savoir si elle doit compter les carte ou non et de quelle type elle est
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
		CompteCarte();
	else
		ComptePasCarte();
}
void JoueurIA::CompteCarte()
{
	
}
void JoueurIA::ComptePasCarte()
{
	
	int minValue;//valeur minimale pour que le compte depasse 21
	int probability;
	int i = 0;//va me permettre de boucler 3x pour les probabiliter de piger une face

	if ((GetCompte() + 11) <= 21) // Peu importe la carte piger on ne depasse pas 21 donc on pige Sans se pauser de question
		jeu->piger();
	else
	{
		minValue = 22 - GetCompte();

		if (minValue != 1 && minValue != 11) //Si les valeur minimale pour depasser son 1 ou 11 il ne reste que la possibiliter de piger un as
		while ( minValue != 10 && i != 3)
		{			
			if (minValue == 10)
				i++;
			else						
				minValue++;
			
			probability += 4 / 52;
		}
		else //les probabiliter son simplement les 4 as
		   probability = 4 / 52;
       // met les probabiliter en pourcentage avant de verifier si il est  > ou < ou = au pourcentage pour piger
		if ((probability * 100) >= pourcentageForPlay)
			  jeu->piger();
		else
		{
			//Reste a savoir ce quon fait lorsquon ne pige pas
		}
	}
}

