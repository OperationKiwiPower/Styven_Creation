#include "SC_Lerp.h"
#include "flib_vec2.h"


TGfxVec2 TLerp::Vector2(TGfxVec2 tOrigine, const TGfxVec2 tDestination, const float fValue)// 0 <-> 1
{
	TGfxVec2 tVec = tDestination - tOrigine;
	tOrigine += tVec*fValue;
	return tOrigine;
}
float TLerp::Float(float fOrigine, float fDestination, float fTime)
{
	float fDecal = fDestination - fOrigine;
	fOrigine += fDecal*fTime;

	return fOrigine;
}