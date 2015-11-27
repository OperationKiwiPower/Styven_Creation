#include "flib.h"
#include "flib_vec2.h"
#include <math.h>
#include "SC_CollisionTest.h"
#include "SC_Box.h"

//Construct && Destruct
TBox::TBox(const unsigned int iColor)
{
	CreateBox(iColor);
}
TBox::~TBox()
{

}
//Public 

//----GET
TGfxVec2 TBox::GetCenter()
{
	return tCenter;
}
TBoxCollider TBox::GetCollider()
{
	return m_Collider;
}
bool TBox::GetDrawable()
{
	return bIsDrawable;
}
float TBox::GetAngle()
{
	return fAngle;
}

//----SET
void TBox::CreateBox(unsigned int iColor)
{

	bIsDrawable = true;
	int r = iColor >> 24 & 255;
	int g = iColor >> 16 & 255;
	int b = iColor >> 8 & 255;
	iColor = GfxColor(r, g, b, 150);

	//Line
	pLineSprite = GfxLineSpriteCreate();
		
	//Image
	TGfxImage * pImage = GfxImageCreate(1, 1);
	GfxImageGetData(pImage)[0] = EGfxColor_White;
	TGfxTexture * pTexture = GfxTextureCreate(pImage);
	pSprite = GfxSpriteCreate(pTexture);
	GfxSpriteSetFilteringEnabled(pSprite, false);
	GfxSpriteSetPivot(pSprite, 0.5f, 0.5f);
	SetColor(iColor);
	m_Collider.pDessin = GfxLineSpriteCreate();
}
void TBox::SetBox(TGfxVec2 Position, float W_Ray, float H_Ray, float Angle)
{
	SetCenter(Position);
	SetRayS(W_Ray, H_Ray);
	SetAngle(Angle);
	SetCollider();
}

void TBox::SetDrawable(bool bBool)
{
	bIsDrawable = bBool;
}
void TBox::SetColor(const unsigned int iColor)
{
	GfxSpriteSetColor(pSprite, iColor);
}

//----Show
void TBox::DrawBox()
{
	GfxLineSpriteReset(pLineSprite);
	GfxLineSpriteSetDrawingColor(pLineSprite, EGfxColor_White);
	//Line
	if (pSprite != nullptr)
	{
		GfxSpriteSetPosition(pSprite, tCenter.x, tCenter.y);
		GfxSpriteSetAngle(pSprite, GfxMathDegToRad(-fAngle));
		GfxSpriteSetScale(pSprite, Ray_W*2.0f, Ray_H*2.0f);
	}

	GfxLineSpriteSetDrawingColor(pLineSprite, GfxColor(150, 150, 150, 255));

	TGfxVec2 tAxisX = TGfxVec2(Ray_W, 0).Rotate(GfxMathDegToRad(fAngle));
	TGfxVec2 tAxisY = TGfxVec2(0, Ray_H).Rotate(GfxMathDegToRad(fAngle));

	TGfxVec2 tUR = TGfxVec2(tCenter.x + tAxisX.x + tAxisY.x, tCenter.y + tAxisX.y + tAxisY.y);
	TGfxVec2 tUL = TGfxVec2(tCenter.x - tAxisX.x + tAxisY.x, tCenter.y - tAxisX.y + tAxisY.y);
	TGfxVec2 tDL = TGfxVec2(tCenter.x - tAxisX.x - tAxisY.x, tCenter.y - tAxisX.y - tAxisY.y);
	TGfxVec2 tDR = TGfxVec2(tCenter.x + tAxisX.x - tAxisY.x, tCenter.y + tAxisX.y - tAxisY.y);

	GfxLineSpriteJumpTo(pLineSprite, tUL.x, tUL.y);
	GfxLineSpriteLineTo(pLineSprite, tDL.x, tDL.y);
	GfxLineSpriteLineTo(pLineSprite, tDR.x, tDR.y);
	GfxLineSpriteLineTo(pLineSprite, tUR.x, tUR.y);
	GfxLineSpriteLineTo(pLineSprite, tUL.x, tUL.y);
}
void TBox::RenderBox()
{
	Render_O_Img();
	Render_O_Line();
}
void TBox::Render_O_Line()
{
	if (bIsDrawable)GfxSpriteRender(pLineSprite);
	if (bIsDrawable)GfxSpriteRender(m_Collider.pDessin);
}
void TBox::Render_O_Img()
{
	if (bIsDrawable)GfxSpriteRender(pSprite);
}

//----Box
void TBox::SetRayS(float Width_Ray, float Height_Ray)
{
	Ray_H = Height_Ray;
	Ray_W = Width_Ray;
}
void TBox::SetCenter(TGfxVec2 tPosition)
{
	tCenter = tPosition;
}
//----BoxCollider
void TBox::SetColliderAngle(float fAngle)
{
	m_Collider.fAngle = fAngle;
}
void TBox::SetCollider()
{
	TGfxVec2 tRay(Ray_W, Ray_H);
	m_Collider.tSpot_LH = TGfxVec2(tCenter - tRay);
	m_Collider.tSpot_RD = TGfxVec2(tCenter + tRay);
}
void TBox::SetAngle(float Angle)
{
	fAngle = Angle;
	SetColliderAngle(fAngle);
}

