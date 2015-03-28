#include "MenuPrincipal.h"


MenuPrincipal::MenuPrincipal()
{
	state = None;
	
}


MenuPrincipal::~MenuPrincipal()
{
}

void MenuPrincipal::UpdateState(Vector2i Cursor)
{
	if (Bt_JVsJ.getGlobalBounds().contains((Vector2f)Cursor))
	{
		state = MouseHover_JVJ;
	}
	else if (Bt_JVsAi.getGlobalBounds().contains((Vector2f)Cursor))
	{
		state = MouseHover_JVA;
	}
	else if (Bt_AiVsAi.getGlobalBounds().contains((Vector2f)Cursor))
	{
		state = MouseHover_AVA;
	}
	else
	{
		state = None;
	}

	switch (state)
	{
	case MouseHover_JVJ:
		Bt_JVsJ.setTexture(&Tex_JVsJ_Selected);
		Bt_JVsAi.setTexture(&Tex_JVsAi);
		Bt_AiVsAi.setTexture(&Tex_AiVsAi);
		break;
	case MouseHover_JVA:
		Bt_JVsAi.setTexture(&Tex_JVsAi_Selected);
		Bt_AiVsAi.setTexture(&Tex_AiVsAi);
		Bt_JVsJ.setTexture(&Tex_JVsJ);
		break;
	case MouseHover_AVA:
		Bt_JVsAi.setTexture(&Tex_JVsAi);
		Bt_AiVsAi.setTexture(&Tex_AiVsAi_Selected);
		Bt_JVsJ.setTexture(&Tex_JVsJ);
		break;
	default:
		Bt_JVsAi.setTexture(&Tex_JVsAi);
		Bt_AiVsAi.setTexture(&Tex_AiVsAi);
		Bt_JVsJ.setTexture(&Tex_JVsJ);
		break;
	}
}

void MenuPrincipal::draw(RenderTarget& target, RenderStates states) const
{
	
	
	// You can draw other high-level objects
	target.draw(Bt_JVsJ);
	target.draw(Bt_JVsAi);
	target.draw(Bt_AiVsAi);

}

void MenuPrincipal::loadResource()
{
	Tex_JVsJ.loadFromFile("Images/Menu/J_VS_J.png");
	Tex_JVsJ_Selected.loadFromFile("Images/Menu/J_VS_J_Selected.png");
	Tex_JVsAi.loadFromFile("Images/Menu/J_VS_AI.png");
	Tex_JVsAi_Selected.loadFromFile("Images/Menu/J_VS_AI_Selected.png");
	Tex_AiVsAi.loadFromFile("Images/Menu/AI_VS_AI.png");
	Tex_AiVsAi_Selected.loadFromFile("Images/Menu/AI_VS_AI_Selected.png");

	Bt_JVsJ.setPosition(Vector2f(288, 75));
	Bt_JVsJ.setSize(Vector2f(624, 139));

	Bt_JVsAi.setPosition(Vector2f(288, 100 + 139));
	Bt_JVsAi.setSize(Vector2f(624, 139));

	Bt_AiVsAi.setPosition(Vector2f(288, 125 + 139 * 2));
	Bt_AiVsAi.setSize(Vector2f(624, 139));
	
}