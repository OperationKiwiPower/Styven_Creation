#ifndef HEADER_CERCLE
#define HEADER_CERCLE

#include "flib.h"
#include "flib_vec2.h"
#include "SC_CollisionTest.h"

class TCercle
{
public:

	TGfxSprite * pSprite;

	TCercle() = default;
	TCercle(TGfxVec2 tPos,float Radius);

	TGfxVec2 GetPosition();
	TSphereCollider m_ShpereCollid;
	void DrawCercle(int iNumberRay);
	void AddForce(TGfxVec2 tVecDir);
	void SetPosition(TGfxVec2 tPos);
	void SetCollider();

private:
	TGfxVec2 tPosition;
	float fRadius;

};

#endif
