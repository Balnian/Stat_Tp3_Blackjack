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
		if (CompteCarte())
			AddCard(jeu->piger());
	else
		if (ComptePasCarte())
			AddCard(jeu->piger());
}
bool JoueurIA::CompteCarte()
{
	return false;
}
bool JoueurIA::ComptePasCarte()
{
	
	int minValue;//valeur minimale pour que le compte depasse 21
	int probability;
	if ((GetCompte() + 11) <= 21) // Peu importe la carte piger on ne depasse pas 21 donc on pige Sans se pauser de question
		return true;
	else
	{
		minValue = 22 - GetCompte();

		if (minValue != 11) //Si les valeur minimale pour depasser est 11 il ne reste que la possibiliter de piger un as
		while ( minValue != 13)
		{												
			probability += 4;
			minValue++;
		}
		else //les probabiliter son simplement les 4 as
		   probability = 4;
       // met les probabiliter en pourcentage avant de verifier si il est  > ou < ou = au pourcentage pour piger
		if ((100 - ((probability/ 52) * 100)) >= pourcentageForPlay)
			return true;
		
		return false;
	}
}

