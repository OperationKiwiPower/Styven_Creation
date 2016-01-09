#ifndef HEADER_STYVEN_CREATION
#define HEADER_STYVEN_CREATION

#include "SC_CollisionTest.h"
#include "SC_Box.h"
#include "SC_Cercle.h"
#include "SC_Pantone.h"
#include "SC_Particule_System.h"
#include "SC_Transform.h"
#include "SC_Lerp.h"

#include "SC_Lua.h"
//#include "SC_Time.h"

//Box --- BoxCollider --- Cercle --- CercleCollider --- Pantone

float SC_GetAngleVector(TGfxVec2  & Position, TGfxVec2 Direction);

static TLerp m_Lerp;

class TBox;
class TBoxCollider;

class TCercle;
class TCercleCollider;

#endif
