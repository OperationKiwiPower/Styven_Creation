#include "flib.h"
#include "flib_vec2.h"
#include "SC_Cercle.h"

#include <math.h>

TCercle::TCercle(TGfxVec2 tPos, float Radius)
{
	fRadius = Radius;

	SetPosition(tPos);

	pSprite = GfxLineSpriteCreate();
}

TGfxVec2 TCercle::GetPosition()
{
	return tPosition;
}


void TCercle::SetCollider()
{
	m_ShpereCollid.tCenter = tPosition;
	m_ShpereCollid.m_fRadius = fRadius;
}
void TCercle::SetPosition(TGfxVec2 tPos)
{
	tPosition = tPos;
	SetCollider();
}

void TCercle::AddForce(TGfxVec2 tVecDir)
{
	tPosition += tVecDir;
}

void TCercle::DrawCercle(int iNumberRay)
{
	GfxLineSpriteReset(pSprite);
	GfxLineSpriteSetDrawingColor(pSprite, iColor);

	int iRay = int(360 / iNumberRay);
	TGfxVec2 tRay;
	tRay = TGfxVec2(fRadius, 0.0f);

	GfxLineSpriteJumpTo(pSprite, tPosition.x + tRay.x, tPosition.y + tRay.y);

	for (int i = 0; i < iNumberRay+1; i++)
	{
		float fAngle = float(i * iRay);
		tRay = TGfxVec2(cos(GfxMathDegToRad(fAngle)), sin(GfxMathDegToRad(fAngle)));
		tRay *= fRadius;
		GfxLineSpriteLineTo(pSprite, tPosition.x + tRay.x, tPosition.y + tRay.y);
	}
}
