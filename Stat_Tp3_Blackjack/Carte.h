#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

struct ValeurCarte
{
	String Path;
	vector<int> Value;
	ValeurCarte(String path, vector<int> value)
	{
		Path = path;
		Value = value;
	}
	

};

class Carte : public Texture
{
vector<int> Value;
bool Piger;
public:
	
	Carte(vector<int> Value);
	~Carte();
	int getValue(int index=0);
	bool piger();
	void reinitialize();

};

