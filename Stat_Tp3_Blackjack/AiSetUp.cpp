#include "AiSetUp.h"


AiSetUp::AiSetUp() :Nombre(NbAI::Un)
{
	Choix[0] = JoueurIA::TypeAI::prudent;
	Choix[1] = JoueurIA::TypeAI::prudent;
	State[0] = BtDifState::None;
	State[1] = BtDifState::None;
	Compte[0] = false;
	Compte[1] = false;
}


AiSetUp::~AiSetUp()
{
}

void AiSetUp::setNombre(NbAI n)
{
	Nombre = n;
}
AiSetUp::NbAI AiSetUp::getNombre()
{
	return Nombre;
}

void AiSetUp::UpdateState(Vector2i Cursor)
{
	for (size_t i = 0; i < Nombre; i++)
	{
		if (Bt_Compte[i].getGlobalBounds().contains((Vector2f)Cursor))
			State[i] = MouseHover_Compte;
		else if (Bt_Continuer.getGlobalBounds().contains((Vector2f)Cursor))
			State[i] = MouseHover_Continuer;
		else if (Bt_Courageux[i].getGlobalBounds().contains((Vector2f)Cursor))
			State[i] = MouseHover_Courageux;
		else if (Bt_Moyen[i].getGlobalBounds().contains((Vector2f)Cursor))
			State[i] = MouseHover_Moyen;
		else if (Bt_Prudent[i].getGlobalBounds().contains((Vector2f)Cursor))
			State[i] = MouseHover_Prudent;
		else
			State[i] = None;

		if (Compte[i])
			Bt_Compte[i].setTexture(&Tex_Compte_Selected);
		else
			Bt_Compte[i].setTexture(&Tex_Compte);
		
		switch (Choix[i])
		{
		case JoueurIA::TypeAI::moyen:
			Bt_Prudent[i].setTexture(&Tex_Prudent);
			Bt_Moyen[i].setTexture(&Tex_Moyen_Selected);
			Bt_Courageux[i].setTexture(&Tex_Courageux);
			break;
		case JoueurIA::TypeAI::courageux:
			Bt_Prudent[i].setTexture(&Tex_Prudent);
			Bt_Moyen[i].setTexture(&Tex_Moyen);
			Bt_Courageux[i].setTexture(&Tex_Courageux_Selected);
			break;
		default:
			Bt_Prudent[i].setTexture(&Tex_Prudent_Selected);
			Bt_Moyen[i].setTexture(&Tex_Moyen);
			Bt_Courageux[i].setTexture(&Tex_Courageux);
			break;
		}

		switch (State[i])
		{
		case BtDifState::MouseHover_Compte:
			Bt_Compte[i].setTexture(&Tex_Compte_Selected);
			Bt_Continuer.setTexture(&Tex_Continuer);
			break;
		case BtDifState::MouseHover_Continuer:
			Bt_Continuer.setTexture(&Tex_Continuer_Selected);

			break;
		case BtDifState::MouseHover_Courageux:
			Bt_Courageux[i].setTexture(&Tex_Courageux_Selected);
			Bt_Continuer.setTexture(&Tex_Continuer);
			break;
		case BtDifState::MouseHover_Moyen:
			Bt_Moyen[i].setTexture(&Tex_Moyen_Selected);
			Bt_Continuer.setTexture(&Tex_Continuer);
			break;
		case BtDifState::MouseHover_Prudent:
			Bt_Prudent[i].setTexture(&Tex_Prudent_Selected);
			Bt_Continuer.setTexture(&Tex_Continuer);
			break;
		default:
			Bt_Continuer.setTexture(&Tex_Continuer);
			break;
		}
	}
}

JoueurIA AiSetUp::getSetUp(NbAI n)
{
	return JoueurIA(Compte[n], Choix[n]);
}

void AiSetUp::draw(RenderTarget& target, RenderStates states) const
{
	for (size_t i = 0; i < Nombre; i++)
	{
		target.draw(Ai[i]);
		target.draw(Bt_Compte[i]);
		
		target.draw(Bt_Courageux[i]);
		target.draw(Bt_Moyen[i]);
		target.draw(Bt_Prudent[i]);
	}
	target.draw(Bt_Continuer);
}

void AiSetUp::loadResource()
{
	Tex_Ai[0].loadFromFile("Images/AiSetUp/Un.png");
	Tex_Ai[1].loadFromFile("Images/AiSetUp/Deux.png");

	Tex_Prudent.loadFromFile("Images/AiSetUp/Prudent.png");
	Tex_Prudent_Selected.loadFromFile("Images/AiSetUp/Prudent_Selected.png");

	Tex_Moyen.loadFromFile("Images/AiSetUp/Moyen.png");
	Tex_Moyen_Selected.loadFromFile("Images/AiSetUp/Moyen_Selected.png");

	Tex_Courageux.loadFromFile("Images/AiSetUp/Courageux.png");
	Tex_Courageux_Selected.loadFromFile("Images/AiSetUp/Courageux_Selected.png");

	Tex_Compte.loadFromFile("Images/AiSetUp/Compte.png");
	Tex_Compte_Selected.loadFromFile("Images/AiSetUp/Compte_Selected.png");

	Tex_Continuer.loadFromFile("Images/Commun/Continuer.png");
	Tex_Continuer_Selected.loadFromFile("Images/Commun/Continuer_Selected.png");
	for (size_t i = 0; i < 2; i++)
	{
		Ai[i].setSize(Vector2f(175, 300));
		Ai[i].setPosition(Vector2f(25, 25 + (350 * i)));
		Ai[i].setTexture(&Tex_Ai[i]);

		Bt_Prudent[i].setSize(Vector2f(624, 139));
		Bt_Prudent[i].setPosition(Vector2f(288, 25 + (350 * i)));
		Bt_Prudent[i].setScale(0.5, 0.5);

		Bt_Moyen[i].setPosition(Vector2f(288, 25 + 139 * 0.5 + 25 + (350 * i)));
		Bt_Moyen[i].setSize(Vector2f(624, 139));
		Bt_Moyen[i].setScale(0.5, 0.5);

		Bt_Courageux[i].setPosition(Vector2f(288, 25 + (25 + 139 * 0.5) * 2 + (350 * i)));
		Bt_Courageux[i].setSize(Vector2f(624, 139 ));
		Bt_Courageux[i].setScale(0.5, 0.5);

		Bt_Compte[i].setPosition(Vector2f(288 + 624*0.5+25, 25 + 139 * 0.5 + 25 + (350 * i)));
		Bt_Compte[i].setSize(Vector2f(624, 139));
		Bt_Compte[i].setScale(0.5, 0.5);
		
	}
	Bt_Continuer.setPosition(Vector2f(1200 - 625 * 0.5, 700 - 140 * 0.5));
	Bt_Continuer.setSize(Vector2f(624, 139));
	Bt_Continuer.setScale(0.5, 0.5);
	
}