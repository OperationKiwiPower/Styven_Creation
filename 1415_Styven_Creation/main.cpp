//-----------------Test Zone-----------------//

#include "flib.h"
#include "SC_Screen.h"
#include "SC_Button.h"

void Initialize()
{
	SC_Screen Display;
	Display.Set_SCreen();
	GfxDbgPrintf("lol");
}
void Update()
{

}
void Render()
{

}

void GfxMain(int, char *[])
{
	GfxCallbacks(Initialize, Update, Render);
}
