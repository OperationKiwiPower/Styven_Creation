#include "flib.h"
#include "flib_vec2.h"
#include "SC_Button.h"

void SC_LineButton(LineButton &m_button, TGfxVec2 tCornerL, TGfxVec2 tCornerR, const char * pText)
{
	GfxLineSpriteJumpTo(m_button.pLineSprite, tCornerL.x, tCornerL.y);
	GfxLineSpriteLineTo(m_button.pLineSprite, tCornerL.x, tCornerR.y);
	GfxLineSpriteLineTo(m_button.pLineSprite, tCornerR.x, tCornerR.y);
	GfxLineSpriteLineTo(m_button.pLineSprite, tCornerR.x, tCornerL.y);
	GfxLineSpriteLineTo(m_button.pLineSprite, tCornerL.x, tCornerL.y);
	GfxTextSpritePrintf(m_button.pTextSprite, pText);

}

void SC_SpriteButton(Button &m_button, TGfxVec2 tCornerL, TGfxVec2 tCornerR, unsigned int iColor)
{
	TGfxImage * pImage;
	TGfxVec2 Vecteur = tCornerR - tCornerL;
	pImage = GfxImageCreate(int(Vecteur.x), int(Vecteur.y));
//	TGfxTexture * pTexture = GfxTextureCreate(pImage);
	GfxSpriteSetFilteringEnabled(m_button.pSprite, false);
	GfxSpriteSetColor(m_button.pSprite, iColor);
}
