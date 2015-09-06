//-----------------Test Zone-----------------//

#include "flib.h"
#include "flib_vec2.h"
#include "SC_Screen.h"
#include "SC_Button.h"

SC_Screen Display;
Button b_Start;
LineButton b_Exit;

void Initialize()
{

	Display.Set_SCreen();
	TGfxVec2 tCorner1(100.0f, 100.0f);
	TGfxVec2 tCorner2(200.0f, 150.0f);
	b_Start.SC_SpriteButton(tCorner1,tCorner2,"Button",EGfxColor_Red);

	GfxDbgPrintf("Breakpoint");
}
void Update()
{

}
void Render()
{
	b_Start.SC_RenderButton();
}

void GfxMain(int, char *[])
{
	GfxCallbacks(Initialize, Update, Render);
}
