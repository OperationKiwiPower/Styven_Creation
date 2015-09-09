#ifndef SC_HEADER_BUTTON

#define SC_HEADER_BUTTON

class Button
{
public:
	TGfxSprite * pTextSprite;
	TGfxSprite * pSprite;
	TGfxSprite * pBevelSprite;
	TGfxVec2 tCenter;
	unsigned int m_iColor;

	void SC_SpriteButton(TGfxVec2 tCornerL, TGfxVec2 tCornerR, const char * pText, const unsigned int iColor);
	void SC_GlowIt();
	void SC_NotGlowIt();
	void SC_RenderButton();
};
//----------Sprite Button
void Button::SC_SpriteButton(TGfxVec2 tCornerL, TGfxVec2 tCornerR, const char * pText, const unsigned int iColor)
{
	TGfxImage * pImage;
	TGfxVec2 Vecteur = tCornerR - tCornerL;
	pImage = GfxImageCreate(int(Vecteur.x), int(Vecteur.y));

	TGfxTexture * pTexture = GfxTextureCreate(pImage);
	pSprite = GfxSpriteCreate(pTexture);
	pTextSprite = GfxTextSpriteCreate();

	GfxSpriteSetFilteringEnabled(pSprite, false);
	GfxSpriteSetFilteringEnabled(pTextSprite, false);
	m_iColor = iColor;
	GfxSpriteSetColor(pSprite, iColor);
	GfxSpriteSetPosition(pSprite, tCornerL.x, tCornerL.y);

	GfxTextSpritePrintf(pTextSprite, pText);
	tCenter = TGfxVec2(tCornerL + (tCornerR - tCornerL) / 2);
	GfxSpriteSetPosition(pTextSprite, tCenter.x, tCenter.y);
}
void Button::SC_RenderButton()
{
	GfxSpriteRender(pSprite);
	GfxTextSpriteRender(pTextSprite, tCenter.x, tCenter.y, EGfxColor_White, 1.0f, true, true);
}
void Button::SC_GlowIt()
{
	GfxSpriteSetColor(pSprite, EGfxColor_White);
}
void Button::SC_NotGlowIt()
{
	GfxSpriteSetColor(pSprite, m_iColor);
}

#endif
