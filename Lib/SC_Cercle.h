#ifndef HEADER_CERCLE
#define HEADER_CERCLE

#include "flib.h"
#include "flib_vec2.h"
#include "SC_CollisionTest.h"

class TCercle
{
public:

	TGfxSprite * m_pSprite;
	TCercleCollider m_tCollid;

	TCercle() = default;
	TCercle(TGfxVec2 tPos,float fRadius);

	TGfxVec2 GetPosition(){ return m_tPosition; };
	TCercleCollider GetCollider(){ return m_tCollid; };

	void DrawCercle(int iNumberRay);
	void AddForce(TGfxVec2 tVecDir);

	void SetPosition(TGfxVec2 tPos);
	void SetCollider();


private:
	TGfxVec2 m_tPosition;
	float m_fRadius;
	unsigned int m_iColor = EGfxColor_White;

};

#endif
