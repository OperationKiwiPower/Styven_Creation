#include "flib.h"
#include "flib_vec2.h"
#include "SC_Drawing.h"

void SC_LineButton(TGfxVec2 tCornerL, TGfxVec2 tCornerR)
{
	TGfxSprite * pSprite;

	GfxLineSpriteJumpTo(pSprite, tCornerL.x, tCornerL.y);
	GfxLineSpriteLineTo(pSprite, tCornerL.x, tCornerL.y);
	GfxLineSpriteLineTo(pSprite, tCornerL.x, tCornerR.y);
	GfxLineSpriteLineTo(pSprite, tCornerR.x, tCornerR.y);
	GfxLineSpriteLineTo(pSprite, tCornerR.x, tCornerL.y);
}

TGfxSprite * SC_SpriteButton(TGfxVec2 tCornerL, TGfxVec2 tCornerR, unsigned int iColor)
{
	TGfxImage * pImage;
	TGfxVec2 Vecteur = tCornerR - tCornerL;
	pImage = GfxImageCreate(Vecteur.x, Vecteur.y);
	TGfxTexture * pTexture = GfxTextureCreate(pImage);
	TGfxSprite * pSprite;
	GfxSpriteSetFilteringEnabled(pSprite, false);
	GfxSpriteSetColor(pSprite, iColor);
	return pSprite;
}