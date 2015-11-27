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

bool TSphereCollider::IsCollid(TBoxCollider m_bColid)
{
	GfxLineSpriteReset(m_bColid.pDessin);

	TGfxVec2 tPosition = m_bColid.tSpot_LH + ((m_bColid.tSpot_RD - m_bColid.tSpot_LH) / 2.0f);
	TGfxVec2 tVec = TGfxVec2(tCenter.x - tPosition.x, tCenter.y - tPosition.y);
	TGfxVec2 tNormX = TGfxVec2(1, 0).Rotate(GfxMathDegToRad(m_bColid.fAngle));
	TGfxVec2 tNormY = TGfxVec2(0, 1).Rotate(GfxMathDegToRad(m_bColid.fAngle));

	TGfxVec2 tDist = TGfxVec2(tVec.DotProduct(tNormX), tVec.DotProduct(tNormY));
	TGfxVec2 tRay = m_bColid.tSpot_RD - tPosition;

	//cercle
	TGfxVec2 tCloseXCercle;
	TGfxVec2 tCloseYCercle;

	if (tDist.x != 0.0f)
	{
		GfxLineSpriteSetDrawingColor(m_bColid.pDessin, EPantone_Rouge);
		GfxLineSpriteJumpTo(m_bColid.pDessin, tCenter.x, tCenter.y);
		tCloseXCercle = TGfxVec2(tNormX*tDist.x).Normalize()*m_fRadius;
		GfxLineSpriteLineTo(m_bColid.pDessin, tCenter.x - tCloseXCercle.x, tCenter.y - tCloseXCercle.y);
	}

	if (tDist.y != 0.0f)
	{
		GfxLineSpriteSetDrawingColor(m_bColid.pDessin, EPantone_Vert);
		GfxLineSpriteJumpTo(m_bColid.pDessin, tCenter.x, tCenter.y);
		tCloseYCercle = TGfxVec2(tNormY*tDist.y).Normalize()*m_fRadius;
		GfxLineSpriteLineTo(m_bColid.pDessin, tCenter.x - tCloseYCercle.x, tCenter.y - tCloseYCercle.y);
	}
	//box
	GfxLineSpriteSetDrawingColor(m_bColid.pDessin, EPantone_Rouge);
	GfxLineSpriteJumpTo(m_bColid.pDessin, tPosition.x, tPosition.y);
	TGfxVec2 tCloseX = TGfxVec2(tNormX*tDist.x);
	GfxLineSpriteLineTo(m_bColid.pDessin, tPosition.x + tCloseX.x, tPosition.y + tCloseX.y);
	GfxLineSpriteSetDrawingColor(m_bColid.pDessin, EPantone_Vert);
	GfxLineSpriteJumpTo(m_bColid.pDessin, tPosition.x, tPosition.y);
	TGfxVec2 tCloseY = TGfxVec2(tNormY*tDist.y);
	GfxLineSpriteLineTo(m_bColid.pDessin, tPosition.x + tCloseY.x, tPosition.y + tCloseY.y);


	if (abs(tDist.x) <= abs(tRay.x) && abs(tDist.y) <= abs(tRay.y))
	{
		tAntiForce = TGfxVec2(0.0f, 0.0f);
		return true;
	}
	else if (abs(tDist.x - tCloseXCercle.x) <= abs(tRay.x) && abs(tDist.y - tCloseXCercle.y) <= abs(tRay.y))
	{
		if (abs(tDist.x) >= abs(tDist.y))
		{
			tAntiForce = tNormX;
		}
		else
		{
			tAntiForce = tNormY;
		}
		return true;
	}
	else if (abs(tDist.x - tCloseYCercle.x) <= abs(tRay.x) && abs(tDist.y - tCloseYCercle.y) <= abs(tRay.y))
	{
		if (abs(tDist.x) >= abs(tDist.y))
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
