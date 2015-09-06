//-----------------Test Zone-----------------//

#include "flib.h"
#include "flib_vec2.h"
#include "SC_Screen.h"
#include "SC_Button.h"
#include "SC_CollisionTest.h"

SC_Screen Display;
Button b_Start;
LineButton b_Exit;

BoxCollider b_StartCollid;
PointCollider b_Mousse;

void Initialize()
{
	Display.Set_SCreen();
	b_StartCollid.tSpot_LH = TGfxVec2(100.0f, 100.0f);
	b_StartCollid.tSpot_RD = TGfxVec2(200.0f, 150.0f);
	b_Start.SC_SpriteButton(b_StartCollid.tSpot_LH, b_StartCollid.tSpot_RD, "Button", EGfxColor_Red);
}
void Update()
{
	float fMousseX = float(GfxGetCurrentMouseX());
	float fMousseY = float(GfxGetCurrentMouseY());
	b_Mousse.tPoint = TGfxVec2(fMousseX, fMousseY);
	if (b_Mousse.IsCollid(b_StartCollid))
	{
		b_Start.SC_GlowIt();
		if (GfxInputIsJustPressed(EGfxInputID_MouseLeft))
		{
			GfxDbgPrintf("Click\n");
		}
	}
	else
	{
		b_Start.SC_NotGlowIt();
	}
}
void Render()
{
	b_Start.SC_RenderButton();
}

void GfxMain(int, char *[])
{
	GfxCallbacks(Initialize, Update, Render);
}
