#ifndef SC_HEADER_Collision

#define SC_HEADER_Collision

#include"flib.h"
#include"flib_vec2.h"

class TBoxCollider
{
public:
	TGfxSprite * pDessin;
	TGfxVec2 tSpot_LH;
	TGfxVec2 tSpot_RD;
	float fAngle = 0;

	bool IsCollid(TBoxCollider m_bColid);
	bool IsCollid(TGfxVec2 tPoint);

};
class TSphereCollider
{
public:
	TGfxVec2 tCenter;
	float m_fRadius;
	bool IsCollid(TBoxCollider m_bColid);
	bool IsCollid(TSphereCollider m_bColid);
	TGfxVec2 tAntiForce = TGfxVec2(0.0f,0.0f);
private:

};
#endif
