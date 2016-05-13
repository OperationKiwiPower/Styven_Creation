#include "flib.h"
#include "flib_vec2.h"
#include "SC_Styven.h"

#include "SC_Box.cpp"
#include "SC_Cercle.cpp"
#include "SC_CollisionTest.cpp"
#include "SC_Particule_System.cpp"
#include "SC_Lerp.cpp"

int g_iDebugTime = 0;
int g_iFirstTime = 0;
int g_iNowTime = 0;

void CalculateDebugTime(const char * pText)
{
	g_iNowTime = GfxTimeGetMilliseconds();
	g_iDebugTime = (g_iNowTime - g_iFirstTime);

	GfxDbgPrintf("%s take %i milisecond\n", pText, int(g_iDebugTime));
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

