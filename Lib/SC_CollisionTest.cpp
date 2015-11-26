#include"flib.h"
#include"flib_vec2.h"
#include"SC_CollisionTest.h"
#include<math.h>


bool TBoxCollider::IsCollid(TBoxCollider m_bColid)
{
	//LH
	if (m_bColid.tSpot_LH.x >= tSpot_LH.x &&
		m_bColid.tSpot_LH.x <= tSpot_RD.x &&
		m_bColid.tSpot_LH.y >= tSpot_LH.y &&
		m_bColid.tSpot_LH.y <= tSpot_RD.y)
	{
		return true;
	}
	//LD
	if (m_bColid.tSpot_LH.x >= tSpot_LH.x &&
		m_bColid.tSpot_LH.x <= tSpot_RD.x &&
		m_bColid.tSpot_RD.y >= tSpot_LH.y &&
		m_bColid.tSpot_RD.y <= tSpot_RD.y)
	{
		return true;
	}

	//RH
	if (m_bColid.tSpot_RD.x >= tSpot_LH.x &&
		m_bColid.tSpot_RD.x <= tSpot_RD.x &&
		m_bColid.tSpot_LH.y >= tSpot_LH.y &&
		m_bColid.tSpot_LH.y <= tSpot_RD.y)
	{
		return true;
	}
	//RD
	if (m_bColid.tSpot_RD.x >= tSpot_LH.x &&
		m_bColid.tSpot_RD.x <= tSpot_RD.x &&
		m_bColid.tSpot_RD.y >= tSpot_LH.y &&
		m_bColid.tSpot_RD.y <= tSpot_RD.y)
	{
		return true;
	}
	return false;
}
bool TBoxCollider::IsCollid(TPointCollider m_bColid)
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
bool TBoxCollider::IsCollid(TGfxVec2 tPoint)
{
	TGfxVec2 tPosition = tSpot_LH + ((tSpot_RD - tSpot_LH) / 2.0f);
	TGfxVec2 tVec = TGfxVec2(tPoint.x - tPosition.x, tPoint.y - tPosition.y);
	TGfxVec2 tNormX = TGfxVec2(1, 0).Rotate(GfxMathDegToRad(fAngle));
	TGfxVec2 tNormY = TGfxVec2(0, 1).Rotate(GfxMathDegToRad(fAngle));

	TGfxVec2 tDist = TGfxVec2(tVec.DotProduct(tNormX), tVec.DotProduct(tNormY));
	TGfxVec2 tRay = tSpot_RD - tPosition;

	if (abs(tDist.x) <= abs(tRay.x) && abs(tDist.y) <= abs(tRay.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TSphereCollider::IsCollid(TBoxCollider m_bColid , TGfxSprite * pSpriteVec)
{
	TGfxVec2 tPosition = m_bColid.tSpot_LH + ((m_bColid.tSpot_RD - m_bColid.tSpot_LH) / 2.0f);
	TGfxVec2 tVec = TGfxVec2(tCenter.x - tPosition.x, tCenter.y - tPosition.y);
	TGfxVec2 tNormX = TGfxVec2(1, 0).Rotate(GfxMathDegToRad(m_bColid.fAngle));
	TGfxVec2 tNormY = TGfxVec2(0, 1).Rotate(GfxMathDegToRad(m_bColid.fAngle));

	TGfxVec2 tDist = TGfxVec2(tVec.DotProduct(tNormX), tVec.DotProduct(tNormY));
	TGfxVec2 tRay = m_bColid.tSpot_RD - tPosition;
//	if(!GfxInputIsPressed(EGfxInputID_MouseLeft))
	{
		GfxLineSpriteSetDrawingColor(pSpriteVec, EGfxColor_Green);
		GfxLineSpriteJumpTo(pSpriteVec, tPosition.x, tPosition.y);
		GfxLineSpriteLineTo(pSpriteVec, tPosition.x + (tNormX.x * tDist.x), tPosition.y + (tNormX.y * tDist.x));

		GfxLineSpriteSetDrawingColor(pSpriteVec, EGfxColor_Red);
		GfxLineSpriteJumpTo(pSpriteVec, tPosition.x, tPosition.y);
		GfxLineSpriteLineTo(pSpriteVec, tPosition.x + (tNormY.x * tDist.y), tPosition.y + (tNormY.y * tDist.y));
	}


	if (abs(tDist.x) <= abs(tRay.x) && abs(tDist.y) <= abs(tRay.y))
	{
		return true;
	}
	else
	{
		return false;
	}

}
/*
bool SphereCollider::IsCollid(PointCollider m_bColid)
{
return true;

}
bool SphereCollider::IsCollid(SphereCollider m_bColid)
{
return true;
}
*/
