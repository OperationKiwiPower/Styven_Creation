#include"flib.h"
#include"flib_vec2.h"
#include"SC_CollisionTest.h"

bool TBoxCollider::IsCollid(TBoxCollider m_bColid)
{
	//LH
	if (m_bColid.m_tSpot_LH.x >= m_tSpot_LH.x &&
		m_bColid.m_tSpot_LH.x <= m_tSpot_RD.x &&
		m_bColid.m_tSpot_LH.y >= m_tSpot_LH.y &&
		m_bColid.m_tSpot_LH.y <= m_tSpot_RD.y)
	{
		return true;
	}
	//LD
	if (m_bColid.m_tSpot_LH.x >= m_tSpot_LH.x &&
		m_bColid.m_tSpot_LH.x <= m_tSpot_RD.x &&
		m_bColid.m_tSpot_RD.y >= m_tSpot_LH.y &&
		m_bColid.m_tSpot_RD.y <= m_tSpot_RD.y)
	{
		return true;
	}

	//RH
	if (m_bColid.m_tSpot_RD.x >= m_tSpot_LH.x &&
		m_bColid.m_tSpot_RD.x <= m_tSpot_RD.x &&
		m_bColid.m_tSpot_LH.y >= m_tSpot_LH.y &&
		m_bColid.m_tSpot_LH.y <= m_tSpot_RD.y)
	{
		return true;
	}
	//RD
	if (m_bColid.m_tSpot_RD.x >= m_tSpot_LH.x &&
		m_bColid.m_tSpot_RD.x <= m_tSpot_RD.x &&
		m_bColid.m_tSpot_RD.y >= m_tSpot_LH.y &&
		m_bColid.m_tSpot_RD.y <= m_tSpot_RD.y)
	{
		return true;
	}
	return false;
}
bool TBoxCollider::IsCollid(TGfxVec2 tPoint)
{
	m_tSpot_LH += TGfxVec2(1.0f, 1.0f);
	m_tSpot_RD -= TGfxVec2(1.0f, 1.0f);

	TGfxVec2 tPosition = m_tSpot_LH + ((m_tSpot_RD - m_tSpot_LH) / 2.0f);
	TGfxVec2 tVec = TGfxVec2(tPoint.x - tPosition.x, tPoint.y - tPosition.y);
	TGfxVec2 tNormX = TGfxVec2(1, 0).Rotate(GfxMathDegToRad(m_fAngle));
	TGfxVec2 tNormY = TGfxVec2(0, 1).Rotate(GfxMathDegToRad(m_fAngle));

	m_tSpot_LH -= TGfxVec2(1.0f, 1.0f);
	m_tSpot_RD += TGfxVec2(1.0f, 1.0f);

	TGfxVec2 tDist = TGfxVec2(tVec.DotProduct(tNormX), tVec.DotProduct(tNormY));
	TGfxVec2 tRay = m_tSpot_RD - tPosition;

	if (fabs(tDist.x) <= fabs(tRay.x) && fabs(tDist.y) <= fabs(tRay.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TCercleCollider::IsCollid(TBoxCollider m_bColid)
{
	TGfxVec2 tPosition = m_bColid.m_tSpot_LH + ((m_bColid.m_tSpot_RD - m_bColid.m_tSpot_LH) / 2.0f);
	TGfxVec2 tVec = TGfxVec2(m_tCenter.x - tPosition.x, m_tCenter.y - tPosition.y);
	TGfxVec2 tNormX = TGfxVec2(1, 0).Rotate(GfxMathDegToRad(m_bColid.m_fAngle));
	TGfxVec2 tNormY = TGfxVec2(0, 1).Rotate(GfxMathDegToRad(m_bColid.m_fAngle));

	TGfxVec2 tDist = TGfxVec2(tVec.DotProduct(tNormX), tVec.DotProduct(tNormY));
	TGfxVec2 tRay = m_bColid.m_tSpot_RD - tPosition;

	//cercle
	TGfxVec2 tCloseXCercle;
	TGfxVec2 tCloseYCercle;

	if (tDist.x != 0.0f)
	{
		tCloseXCercle = TGfxVec2(tNormX*tDist.x).Normalize()*m_fRadius;
	}

	if (tDist.y != 0.0f)
	{
		tCloseYCercle = TGfxVec2(tNormY*tDist.y).Normalize()*m_fRadius;
	}
	
	if (fabs(tDist.x) <= fabs(tRay.x) && fabs(tDist.y) <= fabs(tRay.y))
	{
		tAntiForce = TGfxVec2(0.0f, 0.0f);
		return true;
	}
	else if (fabs(tDist.x - tCloseXCercle.x) <= fabs(tRay.x) && fabs(tDist.y - tCloseXCercle.y) <= fabs(tRay.y))
	{
		if (fabs(tDist.x) >= fabs(tDist.y))
		{
			tAntiForce = tNormX;
		}
		else
		{
			tAntiForce = tNormY;
		}
		return true;
	}
	else if (fabs(tDist.x - tCloseYCercle.x) <= fabs(tRay.x) && fabs(tDist.y - tCloseYCercle.y) <= fabs(tRay.y))
	{
		if (fabs(tDist.x) >= fabs(tDist.y))
		{
			tAntiForce = tNormX;
		}
		else
		{
			tAntiForce = tNormY;
		}
		return true;
	}
	else
	{
		return false;
	}

}
bool TCercleCollider::IsCollid(TGfxVec2 m_Point)
{
	TGfxVec2 tVec = m_Point - m_tCenter;
	float fLenght = tVec.Length();
	if (fLenght < m_fRadius)
		return true;
	else
		return false;
}
