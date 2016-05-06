#pragma once
#include "SC_Styven.h"

const static int MAX_LAYERS = 4;
const static int SIZE_BUTTON = 32;

class TButtons
{
public:

	TBox m_Load;
	TBox m_Return;
	TBox m_Undo;
	TBox m_Layers[MAX_LAYERS];
	TBox m_Erase;

	TButtons GetAll();
	void SetAll(TButtons mButtons);
	void SetColor();

	void DrawAll();
	void RenderAll();
	virtual ~TButtons();
};

static TButtons t_Buttons;
