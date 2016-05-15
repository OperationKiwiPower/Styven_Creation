#ifndef HEADER_CERCLE
#define HEADER_CERCLE

#include "flib.h"
#include "flib_vec2.h"
#include "SC_CollisionTest.h"

class TCercle
{
public:

	TCercle() = default;
	TCercle(TGfxVec2 tPos,float fRadius,bool bIsFiled = false);

	TGfxVec2 GetPosition(){ return m_tPosition; };
	TCercleCollider GetCollider(){ return m_tCollid; };

	void DrawCercle(int iNumberRay);
	void AddForce(TGfxVec2 tVecDir);

	void SetPosition(TGfxVec2 tPos);
	void SetCollider();

	void Render();

private:
	TGfxVec2 m_tPosition;
	float m_fRadius;
	unsigned int m_iColor = EGfxColor_White;

	bool m_bIsFiled = false;
	TGfxSprite * m_pSprite = nullptr;
	TGfxSprite * m_pLineSprite = nullptr;
	TCercleCollider m_tCollid;

};

#endif
