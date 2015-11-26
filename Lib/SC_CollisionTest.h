#ifndef SC_HEADER_Collision

#define SC_HEADER_Collision

#include"flib.h"
#include"flib_vec2.h"

class TPointCollider
{
public:
	TGfxVec2 tPoint;
};
class TBoxCollider
{
public:
	TGfxVec2 tSpot_LH;
	TGfxVec2 tSpot_RD;
	float fAngle = 0;

	bool IsCollid(TBoxCollider m_bColid);
	bool IsCollid(TPointCollider m_bColid);
	bool IsCollid(TGfxVec2 tPoint);

};
class TSphereCollider
{
public:
	TGfxVec2 tCenter;
	float m_fRadius;
	float m_fRay;

	bool IsCollid(TBoxCollider m_bColid, TGfxSprite * pSpriteVec);
	bool IsCollid(TPointCollider m_bColid);
	bool IsCollid(TSphereCollider m_bColid);

};
#endif
