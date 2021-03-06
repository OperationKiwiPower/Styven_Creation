#ifndef HEADER_STYVEN_CREATION
#define HEADER_STYVEN_CREATION

#include "SC_CollisionTest.h"
#include "SC_Box.h"
#include "SC_Cercle.h"
#include "SC_Pantone.h"
#include "SC_Particule_System.h"
#include "SC_Lerp.h"

//Box --- BoxCollider --- Cercle --- CercleCollider --- Pantone --- Particul_System --- Lerp

enum EDirection
{
	EDirection_Unknow,
	EDirection_Up,
	EDirection_Down,
	EDirection_Left,
	EDirection_Right,
};

void CalculateDebugTime(const char * pText);

float SC_GetAngleVector(TGfxVec2 Direction);
float SC_GetAngleVector(TGfxVec2  & Position, TGfxVec2 Direction);
EDirection SC_GetDirectionVector(TGfxVec2  & Position, TGfxVec2 Direction);

#endif
