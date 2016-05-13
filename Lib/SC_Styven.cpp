#include "flib.h"
#include "flib_vec2.h"
//#include "lua.h"
#include "SC_Styven.h"

#include "SC_Box.cpp" ///CODING CONVEN V
#include "SC_Cercle.cpp"
#include "SC_CollisionTest.cpp"
#include "SC_Particule_System.cpp"
#include "SC_Transform.cpp"
#include "SC_Lerp.cpp"
#include "SC_Null.cpp"

//#include "TUIButton.cpp"
//#include "TUIInterface.cpp"
//#include "TUIWidget.cpp"

//#include "SC_Lua.cpp"
//#include "SC_Time.cpp"


void CalculateDebugTime(const char * pChar)
{
	g_iNowTime = GfxTimeGetMilliseconds();
	g_iDebugTime = (g_iNowTime - g_iFirstTime);

	GfxDbgPrintf("%s take %i milisecond\n", pChar, int(g_iDebugTime));
	g_iFirstTime = GfxTimeGetMilliseconds();

}

float SC_GetAngleVector(TGfxVec2  & Position, TGfxVec2 Direction)
{
	TGfxVec2 Vecteur(Direction - Position);

	float hypothenuse = Vecteur.Length();
	float fAngle = GfxMathRadToDeg(acos(Vecteur.x / hypothenuse));

	if (Vecteur.y > 0) return -fAngle;
	return fAngle;
}

