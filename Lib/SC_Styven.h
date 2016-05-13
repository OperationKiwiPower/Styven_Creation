#ifndef HEADER_STYVEN_CREATION
#define HEADER_STYVEN_CREATION

#include "SC_CollisionTest.h"	///CODING CONVEN V
#include "SC_Box.h"	///CODING CONVEN V
#include "SC_Cercle.h"	///CODING CONVEN V
#include "SC_Pantone.h"	///CODING CONVEN V
#include "SC_Particule_System.h"	///CODING CONVEN V
#include "SC_Lerp.h"	///CODING CONVEN V

//Box --- BoxCollider --- Cercle --- CercleCollider --- Pantone --- Particul_System --- Lerp


void CalculateDebugTime(const char * pText);
float SC_GetAngleVector(TGfxVec2  & Position, TGfxVec2 Direction);

#endif
