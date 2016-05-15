#include "flib.h"
#include "flib_vec2.h"
#include "SC_Cercle.h"

#include <math.h>

TGfxSprite * CreateCercleFiled(const int iRay)
{
	const int iDiam = iRay * 2;
	TGfxImage * pImage = GfxImageCreate(iDiam, iDiam);
	unsigned int * pData = GfxImageGetData(pImage);
	for (int y = 0; y < iDiam; y++)
	{
		for (int x = 0; x < iDiam; x++)
		{
			const int iIndex = y*iDiam + x;
			TGfxVec2 tVec = (TGfxVec2(float(x), float(y)) - TGfxVec2(float(iRay), float(iRay)));
			if (tVec.Length() < iRay)
				pData[iIndex] = GfxColor(255, 255, 255, 255-(tVec.Length() / float(iRay) * 255));
			else
				pData[iIndex] = EPantone_Alpha;
		}
	}
	TGfxSprite * pSprite = GfxSpriteCreate(GfxTextureCreate(pImage));
	GfxSpriteSetPivot(pSprite, float(iRay), float(iRay));
	return pSprite;
}

TCercle::TCercle(TGfxVec2 tPos, float fRadius, bool bIsFiled)
{
	m_fRadius = fRadius;
	m_bIsFiled = bIsFiled;

	SetPosition(tPos);
	if (m_bIsFiled)
		m_pSprite = CreateCercleFiled(int(fRadius));

	m_pLineSprite = GfxLineSpriteCreate();
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
void TCercle::Render()
{
	if (m_pSprite != nullptr && m_bIsFiled)
    		GfxSpriteRender(m_pSprite);
	if (m_pLineSprite != nullptr && !m_bIsFiled)
		GfxSpriteRender(m_pLineSprite);
}
void TCercle::AddForce(TGfxVec2 tVecDir)
{
	m_tPosition += tVecDir;
}

void TCercle::DrawCercle(int iNumberRay)
{
	GfxLineSpriteReset(m_pLineSprite);
	GfxLineSpriteSetDrawingColor(m_pLineSprite, m_iColor);
	GfxSpriteSetPosition(m_pSprite, m_tPosition.x, m_tPosition.y);

	int iRay = int(360 / iNumberRay);
	TGfxVec2 tRay;
	tRay = TGfxVec2(m_fRadius, 0.0f);

	GfxLineSpriteJumpTo(m_pLineSprite, m_tPosition.x + tRay.x, m_tPosition.y + tRay.y);

	for (int i = 0; i < iNumberRay+1; i++)
	{
		float fAngle = float(i * iRay);
		tRay = TGfxVec2(cos(GfxMathDegToRad(fAngle)), sin(GfxMathDegToRad(fAngle)));
		tRay *= m_fRadius;
		GfxLineSpriteLineTo(m_pLineSprite, m_tPosition.x + tRay.x, m_tPosition.y + tRay.y);
	}
}
