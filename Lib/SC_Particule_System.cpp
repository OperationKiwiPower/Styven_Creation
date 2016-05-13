#include "flib.h"
#include "flib_vec2.h"

#include "SC_Particule_System.h"

void TParticule_System::AnimeParticule(const int iTiming)//iTimnig 0 = very speed && 20 = Slow;
{
	m_iCount++;
	if (m_iCount % iTiming == 0)
	{
		m_iTileX++;
		if (m_iTileX >= m_iMaxTileX)
		{
			m_iTileX = m_iTileX % m_iMaxTileX;
			m_iTileY++;
		}
		if (m_iTileY >= m_iMaxTileY)
		{
			m_iTileY = m_iTileY % m_iMaxTileY;
		}
	}
	int iSize = int(m_fSize);
	GfxSpriteSetCutout(m_pSprite, iSize*m_iTileX, iSize*m_iTileY, iSize, iSize);
}

void TParticule_System::CreateSystem(const char * pFileName, const int iTileXMax, const int iTileYMax)
{
	TGfxTexture * pTexture = GfxTextureLoad(pFileName);
	m_pSprite = GfxSpriteCreate(pTexture);

	m_fSize = GfxTextureGetSizeX(pTexture) / (float)iTileXMax;

	m_iMaxTileX = iTileXMax;
	m_iMaxTileY = iTileYMax;

	m_iTileX = 0;
	m_iTileY = 0;

	int iSize = int(m_fSize);
	GfxSpriteSetCutout(m_pSprite, m_iTileX, m_iTileY, iSize, iSize);
	GfxSpriteSetPivot(m_pSprite, (iSize / 2.0f), (iSize / 1.0f));
}
void TParticule_System::SetSystem(TGfxVec2 tPosition,const float fAngle)
{
	m_tPos = tPosition;
	GfxSpriteSetAngle(m_pSprite, GfxMathDegToRad(-fAngle));
	GfxSpriteSetPosition(m_pSprite, m_tPos.x, m_tPos.y);
}
void TParticule_System::RenderSystem()
{
	GfxSpriteRender(m_pSprite);
}
