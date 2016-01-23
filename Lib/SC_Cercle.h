#ifndef HEADER_CERCLE
#define HEADER_CERCLE

#include "flib.h"
#include "flib_vec2.h"
#include "SC_CollisionTest.h"

class TCercle
{
public:

	TGfxSprite * pSprite;
	TSphereCollider m_ShpereCollid;

	TCercle() = default;
	TCercle(TGfxVec2 tPos,float Radius);

	TGfxVec2 GetPosition();

	void DrawCercle(int iNumberRay);
	void AddForce(TGfxVec2 tVecDir);
	void SetPosition(TGfxVec2 tPos);
	void SetCollider();
	float fRadius;
	unsigned int iColor = EGfxColor_White;

private:
	TGfxVec2 tPosition;

};

#endif
