#include "flib.h"
#include "flib_vec2.h"

#include "SC_Particule_System.h"

void TParticule_System::AnimeParticule(const int iTiming)//iTimnig 0 = very speed && 20 = Slow;
{
	iCount++;
	if (iCount % iTiming == 0)
	{
		iTileX++;
		if (iTileX >= iMaxTileX)
		{
			iTileX = iTileX % iMaxTileX;
			iTileY++;
		}
		if (iTileY >= iMaxTileY)
		{
			iTileY = iTileY % iMaxTileY;
		}
	}
	int iSize = int(fSize);
	GfxSpriteSetCutout(pSprite, iSize*iTileX, iSize*iTileY, iSize, iSize);
}

void TParticule_System::CreateSystem(const char * pName, const int iTileXMax, const int iTileYMax)
{
	TGfxTexture * pTexture = GfxTextureLoad(pName);
	pSprite = GfxSpriteCreate(pTexture);

	fSize = GfxTextureGetSizeX(pTexture) / (float)iTileXMax;
//	float fY = GfxTextureGetSizeY(pTexture) / (float)iTileYMax;

//	if (fSize != fY)
//		GfxDbgAssert(true, "T'as merdé tes mesures gros");
//	if (GfxTextureGetSizeX(pTexture) % iTileXMax != 0 && GfxTextureGetSizeY(pTexture) % iTileYMax != 0)
//		GfxDbgAssert(true, "C'est pas divisible");

	iMaxTileX = iTileXMax;
	iMaxTileY = iTileYMax;

	iTileX = 0;
	iTileY = 0;

	int iSize = int(fSize);
	GfxSpriteSetCutout(pSprite, iTileX, iTileY, iSize, iSize);
	GfxSpriteSetPivot(pSprite, (iSize / 2.0f), (iSize / 1.0f));
}
void TParticule_System::SetSystem(TGfxVec2 tPosition,const float fAngle)
{
	tPos = tPosition;
	GfxSpriteSetAngle(pSprite, GfxMathDegToRad(-fAngle));
	GfxSpriteSetPosition(pSprite, tPos.x, tPos.y);
}
void TParticule_System::RenderSystem()
{
	GfxSpriteRender(pSprite);
}
