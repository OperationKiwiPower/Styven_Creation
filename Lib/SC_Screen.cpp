#include "flib.h"
#include "SC_Screen.h"

void SC_SetScreenStruct(TScreen & Screen)
{
	Screen.x.Full = GfxGetDisplaySizeX();
	Screen.x.Half = Screen.x.Full / 2;
	Screen.x.Quart = Screen.x.Half / 2;
	Screen.x.TriQuart = Screen.x.Quart * 3;
	
	Screen.y.Full = GfxGetDisplaySizeY();
	Screen.y.Half = Screen.y.Full / 2;
	Screen.y.Quart = Screen.y.Half / 2;
	Screen.y.TriQuart = Screen.y.Quart * 3;
}
