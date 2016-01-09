#include "flib.h"
#include "flib_vec2.h"
#include "SC_Transform.h"

void TTransform_2D::CreateTransform()
{
	pLineSprite = GfxLineSpriteCreate();
	pTextX = GfxTextSpriteCreate();
	pTextY = GfxTextSpriteCreate();

	GfxTextSpritePrintf(pTextX, "X");
	GfxTextSpritePrintf(pTextY, "Y");

	GfxSpriteSetPivot(pTextX, GfxSpriteGetSizeX(pTextX) / 2.0f, GfxSpriteGetSizeY(pTextX) / 2.0f);
	GfxSpriteSetPivot(pTextY, GfxSpriteGetSizeX(pTextY) / 2.0f, GfxSpriteGetSizeY(pTextY) / 2.0f);
}
void TTransform_2D::SetAxis(const TGfxVec2 tPosition)
{
	tPos = tPosition;
}
void TTransform_2D::DrawArrow(const TGfxVec2 tCenter, const TGfxVec2 tDirection, const unsigned int iColor, const float fRadius, TGfxSprite * pTexSprite)
{
	GfxLineSpriteSetDrawingColor(pLineSprite, iColor);
	TGfxVec2 tSideArrow(tDirection - tCenter);
	//tSideArrow = tSideArrow.Normalize();
	tSideArrow = tSideArrow.Rotate(GfxMathDegToRad(fAngle));

	float fArrowAngle = GfxMathDegToRad(135.0f);
	TGfxVec2 tSideArrowLeft = tSideArrow.Normalize().Rotate(fArrowAngle) * (fRadius / 10.0f);
	TGfxVec2 tSideArrowRight = tSideArrow.Normalize().Rotate(-fArrowAngle) * (fRadius / 10.0f);

	GfxLineSpriteJumpTo(pLineSprite, tCenter.x, tCenter.y);
	GfxLineSpriteLineTo(pLineSprite, tCenter.x + tSideArrow.x, tCenter.y + tSideArrow.y);
	//left 
	GfxLineSpriteJumpTo(pLineSprite, tCenter.x + tSideArrow.x, tCenter.y + tSideArrow.y);
	GfxLineSpriteLineTo(pLineSprite, tCenter.x + tSideArrow.x + tSideArrowLeft.x, tCenter.y + tSideArrow.y + tSideArrowLeft.y);
	//rigt
	GfxLineSpriteJumpTo(pLineSprite, tCenter.x + tSideArrow.x, tCenter.y + tSideArrow.y);
	GfxLineSpriteLineTo(pLineSprite, tCenter.x + tSideArrow.x + tSideArrowRight.x, tCenter.y + tSideArrow.y + tSideArrowRight.y);

	GfxSpriteSetPosition(pTexSprite, tCenter.x + tSideArrow.x, tCenter.y + tSideArrow.y);
}
void TTransform_2D::DrawAxis(const float fRadius, const float fAngleAxis)
{
	GfxLineSpriteReset(pLineSprite);
	fAngle = fAngleAxis;
	TGfxVec2 tAxX = TGfxVec2(tPos.x + fRadius, tPos.y);
	TGfxVec2 tAxY = TGfxVec2(tPos.x, tPos.y - fRadius);
	DrawArrow(tPos, tAxX, EGfxColor_Red, fRadius,pTextX);
	DrawArrow(tPos, tAxY, EGfxColor_Green, fRadius, pTextY);
}
void TTransform_2D::Render()
{
	GfxSpriteRender(pLineSprite);
	GfxSpriteRender(pTextX);
	GfxSpriteRender(pTextY);
}