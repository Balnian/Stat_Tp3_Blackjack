#include "Carte.h"


Carte::Carte(int Value) :Value(Value),Piger(false)
{
}


Carte::~Carte()
{
}

//int Carte::getValue()
//{
//	return Value;
//}

// retourne si la carte � d�j� �t� piger ou non et si elle n'a pas �t� piger on la met � l'�tat piger
bool Carte::piger()
{
	return Piger ? Piger : !(Piger = true);
}