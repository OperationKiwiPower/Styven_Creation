#pragma once
#include "flib.h"
#include "flib_vec2.h"
//Static Func
class TLerp
{
public:
	TGfxVec2 Vector2(TGfxVec2 tOrigine, const TGfxVec2 tDestination, const float fValue);
	float Float(float fOrigine, float fDestination, float fTime);
};
