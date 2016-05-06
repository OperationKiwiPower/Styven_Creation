#include "TButtons.h"


TButtons TButtons::GetAll()
{
	return t_Buttons;
}

void TButtons::SetAll(TButtons mButtons)
{
	t_Buttons = mButtons;
}
void TButtons::DrawAll()
{	
	m_Load.DrawBox();
	m_Undo.DrawBox();
	m_Return.DrawBox();
	for (int i = 0; i < MAX_LAYERS; i++)
	{
		m_Layers[i].DrawBox();
	}
	m_Erase.DrawBox();
}
void TButtons::RenderAll()
{
	t_Buttons = t_Buttons.GetAll();

	m_Load.RenderBox();
	m_Undo.RenderBox();
	m_Return.RenderBox();
	for (int i = 0; i < MAX_LAYERS; i++)
	{
		t_Buttons.m_Layers[i].RenderBox();
	}
	m_Erase.RenderBox();
}
void TButtons::SetColor()
{
	m_Load.SetTile(SIZE_BUTTON, 0, 0);
	m_Undo.SetTile(SIZE_BUTTON, 1, 0);
	m_Return.SetTile(SIZE_BUTTON, 2, 0);
	for (int i = 0; i < MAX_LAYERS; i++)
	{
		t_Buttons.m_Layers[i].SetTile(SIZE_BUTTON, i, 1);
	}
	m_Erase.SetTile(SIZE_BUTTON, 3, 0);
}
TButtons::~TButtons()
{

}
