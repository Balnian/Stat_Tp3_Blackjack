#include "MainMenu.h"


MainMenu::MainMenu()
{
	state = None;
	Tex_JVsAi.loadFromFile("Images/Menu/J_VS_AI.png");
	Tex_JVsAi_Selected.loadFromFile("Images/Menu/J_VS_AI_Selected.png");
	Tex_AiVsAi.loadFromFile("Images/Menu/AI_VS_AI.png");
	Tex_AiVsAi_Selected.loadFromFile("Images/Menu/AI_VS_AI_Selected.png");

	Bt_JVsAi.setPosition(Vector2f(288,100));
	Bt_JVsAi.setSize(Vector2f(624, 139));
	Bt_AiVsAi.setPosition(Vector2f(288, 150+139));
	Bt_AiVsAi.setSize(Vector2f(624, 139));
}


MainMenu::~MainMenu()
{
}

void MainMenu::UpdateState(Vector2i Cursor)
{
	if (Bt_JVsAi.getGlobalBounds().contains((Vector2f)Cursor))
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
	case MouseHover_JVA:
		Bt_JVsAi.setTexture(&Tex_JVsAi_Selected);
		Bt_AiVsAi.setTexture(&Tex_AiVsAi);
		break;
	case MouseHover_AVA:
		Bt_JVsAi.setTexture(&Tex_JVsAi);
		Bt_AiVsAi.setTexture(&Tex_AiVsAi_Selected);
		break;
	default:
		Bt_JVsAi.setTexture(&Tex_JVsAi);
		Bt_AiVsAi.setTexture(&Tex_AiVsAi);
		break;
	}
}

void MainMenu::draw(RenderTarget& target, RenderStates states) const
{
	
	
	// You can draw other high-level objects
	target.draw(Bt_JVsAi);
	target.draw(Bt_AiVsAi);

}
