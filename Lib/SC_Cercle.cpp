#include "flib.h"
#include "flib_vec2.h"
#include "SC_Cercle.h"

#include <math.h>

TCercle::TCercle(TGfxVec2 tPos, float fRadius)
{
	m_fRadius = fRadius;

	SetPosition(tPos);

	m_pSprite = GfxLineSpriteCreate();
}

void TCercle::SetCollider()
{
	m_tCollid.m_tCenter = m_tPosition;
	m_tCollid.m_fRadius = m_fRadius;
}
void TCercle::SetPosition(TGfxVec2 tPos)
{
	m_tPosition = tPos;
	SetCollider();
}

void TCercle::AddForce(TGfxVec2 tVecDir)
{
	m_tPosition += tVecDir;
}

void TCercle::DrawCercle(int iNumberRay)
{
	GfxLineSpriteReset(m_pSprite);
	GfxLineSpriteSetDrawingColor(m_pSprite, m_iColor);

	int iRay = int(360 / iNumberRay);
	TGfxVec2 tRay;
	tRay = TGfxVec2(m_fRadius, 0.0f);

	GfxLineSpriteJumpTo(m_pSprite, m_tPosition.x + tRay.x, m_tPosition.y + tRay.y);

	for (int i = 0; i < iNumberRay+1; i++)
	{
		float fAngle = float(i * iRay);
		tRay = TGfxVec2(cos(GfxMathDegToRad(fAngle)), sin(GfxMathDegToRad(fAngle)));
		tRay *= m_fRadius;
		GfxLineSpriteLineTo(m_pSprite, m_tPosition.x + tRay.x, m_tPosition.y + tRay.y);
	}
}
