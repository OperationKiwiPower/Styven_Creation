#ifndef SC_HEADER_BUTTON

#define SC_HEADER_BUTTON

class LineButton
{
public:
	TGfxSprite * pTextSprite;
	TGfxSprite * pLineSprite;

	void SC_LineButton(TGfxVec2 tCornerL, TGfxVec2 tCornerR, const char * pText);
};
class Button
{
public:
	TGfxSprite * pTextSprite;
	TGfxSprite * pSprite;

	void SC_RenderButton();
	void SC_SpriteButton(TGfxVec2 tCornerL, TGfxVec2 tCornerR, const char * pText, const unsigned int iColor);
};

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
	GfxSpriteSetColor(pSprite, iColor);
	GfxSpriteSetPosition(pSprite, tCornerL.x, tCornerL.y);

	GfxTextSpritePrintf(pTextSprite, pText);
	TGfxVec2 tDecal(float(GfxSpriteGetSizeX(pTextSprite)), float(GfxSpriteGetSizeY(pTextSprite)));
	TGfxVec2 tCenter(tCornerL + (tCornerR - tCornerL) / 2 - (tDecal/2));
	GfxSpriteSetPosition(pTextSprite, tCenter.x, tCenter.y);
}
void Button::SC_RenderButton()
{
	GfxSpriteRender(pSprite);
	GfxSpriteRender(pTextSprite);
}

void LineButton::SC_LineButton(TGfxVec2 tCornerL, TGfxVec2 tCornerR, const char * pText)
{
	pTextSprite = GfxTextSpriteCreate();
	pLineSprite = GfxLineSpriteCreate();
	GfxLineSpriteJumpTo(pLineSprite, tCornerL.x, tCornerL.y);
	GfxLineSpriteLineTo(pLineSprite, tCornerL.x, tCornerR.y);
	GfxLineSpriteLineTo(pLineSprite, tCornerR.x, tCornerR.y);
	GfxLineSpriteLineTo(pLineSprite, tCornerR.x, tCornerL.y);
	GfxLineSpriteLineTo(pLineSprite, tCornerL.x, tCornerL.y);
	GfxTextSpritePrintf(pTextSprite, pText);

}

#endif
