#pragma once
#include "flib.h"
#include "flib_vec2.h"
//Static Func
class TLerp
{
public:
	static TGfxVec2 Vector2(TGfxVec2 tOrigine, const TGfxVec2 tDestination, const float fValue);
	static float Float(float fOrigine, float fDestination, float fTime);
};
