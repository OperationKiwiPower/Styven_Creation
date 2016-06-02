#ifndef SC_HEADER_Collision

#define SC_HEADER_Collision

#include"flib.h"
#include"flib_vec2.h"

class TBoxCollider
{
public:
	TBoxCollider();
	~TBoxCollider();

	TGfxVec2 m_tSpot_LH;
	TGfxVec2 m_tSpot_RD;
	
	float m_fAngle = 0;
	
	bool IsCollid(TBoxCollider m_bColid);
	bool IsCollid(TGfxVec2 tPoint);
};

class TCercleCollider
{
public:
	TGfxVec2 m_tCenter;
	float m_fRadius;

	bool IsCollid(TBoxCollider m_bColid);
	bool IsCollid(TGfxVec2 m_Point);
	bool IsCollid(TCercleCollider m_bColid);
private:
	TGfxVec2 tAntiForce = TGfxVec2(0.0f,0.0f);
};
#endif
