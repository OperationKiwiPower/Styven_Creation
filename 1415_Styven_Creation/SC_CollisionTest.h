#ifndef SC_HEADER_Collision

#define SC_HEADER_Collision

class BoxCollider
{
public:
	TGfxVec2 tSpot_LH;
	TGfxVec2 tSpot_RD;

	bool IsCollid(BoxCollider m_bColid);

};
class PointCollider
{
public:
	TGfxVec2 tPoint;
	bool IsCollid(BoxCollider m_bColid);
};
class SphereCollider
{
public:
	TGfxVec2 tCenter;
	float m_fRadius;
	bool IsCollid(BoxCollider m_bColid);

};

bool BoxCollider::IsCollid(BoxCollider m_bColid)
{
	if (m_bColid.tSpot_LH.x >= tSpot_LH.x &&
		m_bColid.tSpot_LH.x <= tSpot_RD.x &&
		m_bColid.tSpot_LH.y >= tSpot_LH.y &&
		m_bColid.tSpot_LH.y <= tSpot_RD.y)
	{
		return true;
	}

	return false;
}

bool PointCollider::IsCollid(BoxCollider m_bColid)
{
	if (tPoint.x >= m_bColid.tSpot_LH.x &&
		tPoint.x <= m_bColid.tSpot_RD.x &&
		tPoint.y >= m_bColid.tSpot_LH.y &&
		tPoint.y <= m_bColid.tSpot_RD.y)
	{
		return true;
	}

	return false;
}

bool SphereCollider::IsCollid(BoxCollider m_bColid)
{
	if (m_bColid.tSpot_LH.x >= tCenter.x &&
		m_bColid.tSpot_LH.x <= tCenter.x &&
		m_bColid.tSpot_LH.y >= tCenter.y &&
		m_bColid.tSpot_LH.y <= tCenter.y)
	{
		return true;
	}

	return false;
}

#endif
