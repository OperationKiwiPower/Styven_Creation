#ifndef SC_HEADER_Collision

#define SC_HEADER_Collision

class PointCollider
{
public:
	TGfxVec2 tPoint;
};
class BoxCollider
{
public:
	TGfxVec2 tSpot_LH;
	TGfxVec2 tSpot_RD;

	bool IsCollid(BoxCollider m_bColid);
	bool IsCollid(PointCollider m_bColid);
	bool IsCollid(SphereCollider m_bColid);

};
class SphereCollider
{
public:
	TGfxVec2 tCenter;
	float m_fRadius;
	float m_fRay;

	bool IsCollid(BoxCollider m_bColid);
	bool IsCollid(PointCollider m_bColid);
	bool IsCollid(SphereCollider m_bColid);

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
bool BoxCollider::IsCollid(PointCollider m_bColid)
{
	if (m_bColid.tPoint.x >= tSpot_LH.x &&
		m_bColid.tPoint.x <= tSpot_RD.x &&
		m_bColid.tPoint.y >= tSpot_LH.y &&
		m_bColid.tPoint.y <= tSpot_RD.y)
	{
		return true;
	}

	return false;
}

bool SphereCollider::IsCollid(BoxCollider m_bColid)
{
	return true;

}
bool SphereCollider::IsCollid(PointCollider m_bColid)
{
	return true;

}
bool SphereCollider::IsCollid(SphereCollider m_bColid)
{
	return true;
}

#endif
