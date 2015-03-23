#include "Carte.h"


Carte::Carte(vector<int>  Value) :Value(Value), Piger(false)
{
}


Carte::~Carte()
{
}

int Carte::getValue(int index)
{
	if (index>=Value.size())
	{
		return Value.back();
	}
	else if (index<=0)
	{
		return Value.front();
	}
	else
	{
		return Value.at(index);
	}
	
}

// retourne si la carte à déjà été piger ou non et si elle n'a pas été piger on la met à l'état piger
bool Carte::piger()
{
	return Piger ? Piger : !(Piger = true);
}

void Carte::reinitialize()
{
	Piger = false;
}