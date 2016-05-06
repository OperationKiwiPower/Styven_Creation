#include "flib.h"
#include "flib_vec2.h"
#include <math.h>
#include <stdio.h>
#include "SC_CollisionTest.h"
#include "SC_Box.h"

//Construct && Destruct
TBox::TBox(const unsigned int iColor)
{

}
//Public 

//----GET
TGfxVec2 TBox::GetCenter()const
{
	return tCenter;
}
TBoxCollider TBox::GetCollider()const
{
	return m_Collider;
}
unsigned int TBox::GetColor()const
{
	return iColor;
}
bool TBox::GetDrawable() const
{
	return bIsDrawable;
}
float TBox::GetAngle() const
{
	return fAngle;
}

//----SET
void TBox::CreateBox(unsigned int iColor, const bool bText, const bool bSprite, const bool bLine)
{
	if (pTextSprite == nullptr && bText)
	{
		pTextSprite = GfxTextSpriteCreate();
		GfxSpriteSetFilteringEnabled(pTextSprite, true);
	}
	bIsDrawable = true;
	if (bLine)
	{
		//Line
		pLineSprite = GfxLineSpriteCreate();
	}
	if (bSprite)
	{
		//Image
		TGfxImage * pImage = GfxImageCreate(1, 1);
		GfxImageGetData(pImage)[0] = EGfxColor_White;
		TGfxTexture * pTexture = GfxTextureCreate(pImage);
		pSprite = GfxSpriteCreate(pTexture);
		GfxSpriteSetFilteringEnabled(pSprite, false);
		GfxSpriteSetPivot(pSprite, 0.5f, 0.5f);
		SetColor(iColor);
	}
	m_Collider.pDessin = GfxLineSpriteCreate();
}
void TBox::CreateSpriteBox(TGfxTexture * pTexture,const unsigned int iColor, const int g_iTextureSize, int iTileX, int iTileY)
{
	//if (pTextSprite == nullptr)
	//{
	//	pTextSprite = GfxTextSpriteCreate();
	//	GfxSpriteSetFilteringEnabled(pTextSprite, false);
	//}
	bIsDrawable = true;

	//Line
	//pLineSprite = GfxLineSpriteCreate();

	pLineSprite = nullptr;
	pSprite = nullptr;

	//Image
//	TGfxImage * pImage = GfxImageCreate(1, 1);
//	GfxImageGetData(pImage)[0] = EGfxColor_White;
//	TGfxTexture * m_pTexture = GfxTextureCreate(pImage);
//	pSprite = GfxSpriteCreate(m_pTexture);
//	GfxSpriteSetFilteringEnabled(pSprite, false);
//	GfxSpriteSetPivot(pSprite, 0.5f, 0.5f);
//	SetColor(iColor);

	pImgSprite = GfxSpriteCreate(pTexture);
	GfxSpriteSetFilteringEnabled(pImgSprite, false);
	//GfxSpriteSetFilteringEnabled(pImgSprite, false);
	GfxSpriteSetCutout(pImgSprite, iTileX*g_iTextureSize, iTileY*g_iTextureSize, g_iTextureSize, g_iTextureSize);
	GfxSpriteSetPivot(pImgSprite, g_iTextureSize / 2.0f, g_iTextureSize / 2.0f);

	//m_Collider.pDessin = GfxLineSpriteCreate();
}
void TBox::SetTile(const int g_iTextureSize ,const int iTileX, const int iTileY)
{
	GfxSpriteSetCutout(pImgSprite, iTileX*g_iTextureSize, iTileY*g_iTextureSize, g_iTextureSize, g_iTextureSize);
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
void TBox::SetColor(const unsigned int m_iColor)
{
	iColor = m_iColor;
	if (pSprite!=nullptr)
		GfxSpriteSetColor(pSprite, m_iColor);
}
void TBox::SetTexte(char * pChar)
{
	GfxTextSpritePrintf(pTextSprite, pChar);

	float fSizeX = GfxSpriteGetSizeX(pTextSprite)/2.0f;
	float fSizeY = GfxSpriteGetSizeY(pTextSprite)/2.0f;
	pText = pChar;
	GfxSpriteSetPivot(pTextSprite, fSizeX, fSizeY);
	GfxSpriteSetPosition(pTextSprite, tCenter.x, tCenter.y);
}
void TBox::SetTexte(int iValeur)
{
	if (pTextSprite == nullptr)
	{
		pTextSprite = GfxTextSpriteCreate();
	}
	GfxTextSpritePrintf(pTextSprite, "%i\n",iValeur);
	iText = iValeur;

	float fSizeX = GfxSpriteGetSizeX(pTextSprite) / 2.0f;
	float fSizeY = GfxSpriteGetSizeY(pTextSprite) / 2.0f;

	GfxSpriteSetPivot(pTextSprite, fSizeX, fSizeY);
	GfxSpriteSetPosition(pTextSprite, tCenter.x, tCenter.y);
}

//----Show
void TBox::DrawBox()
{
	if (pSprite != nullptr)
	{
		GfxSpriteSetPosition(pSprite, tCenter.x, tCenter.y);
		GfxSpriteSetAngle(pSprite, GfxMathDegToRad(-fAngle));
		GfxSpriteSetScale(pSprite, Ray_W*2.0f*m_fScale, Ray_H*2.0f*m_fScale);
	}
	if (pImgSprite != nullptr)
	{
		GfxSpriteSetPosition(pImgSprite, tCenter.x, tCenter.y);
		GfxSpriteSetAngle(pImgSprite, GfxMathDegToRad(-fAngle));
		float fTextureSize = float(GfxSpriteGetTextureSizeX(pImgSprite) / 8);
		GfxSpriteSetScale(pImgSprite, Ray_W / fTextureSize, Ray_W / fTextureSize);
	}
	//Line
	if (pLineSprite != nullptr)
	{
		GfxLineSpriteReset(pLineSprite);
		GfxLineSpriteSetDrawingColor(pLineSprite, GfxColor(150, 150, 150, 255));
		TGfxVec2 tAxisX = TGfxVec2(Ray_W, 0).Rotate(GfxMathDegToRad(fAngle))*m_fScale;
		TGfxVec2 tAxisY = TGfxVec2(0, Ray_H).Rotate(GfxMathDegToRad(fAngle))*m_fScale;

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
	if (pTextSprite != nullptr)
	{
		GfxSpriteSetAngle(pTextSprite,GfxMathDegToRad(-fAngle));
	}
}
void TBox::RenderBox()
{
	//GfxDbgPrintf("x = %f  ---------  y = %f\n", m_Collider.tSpot_LH.x, m_Collider.tSpot_LH.y);
	Render_O_Img();
	Render_O_Line();
	Render_O_Text();
}
void TBox::Render_O_Line()
{
	if (bIsDrawable&& pLineSprite != nullptr)GfxSpriteRender(pLineSprite);
	//if (bIsDrawable&& m_Collider.pDessin != nullptr)GfxSpriteRender(m_Collider.pDessin);
}
void TBox::Render_O_Img()
{
	if (bIsDrawable&& pSprite != nullptr)GfxSpriteRender(pSprite);
	if (bIsDrawable&& pImgSprite != nullptr)GfxSpriteRender(pImgSprite);
}
void TBox::Render_O_Text()
{
	if (bIsDrawable && pTextSprite!=nullptr)GfxSpriteRender(pTextSprite);
}

//----Box
void TBox::SetAngle(float Angle)
{
	fAngle = Angle;
	SetColliderAngle(fAngle);
}
void TBox::SetRayS(float Width_Ray, float Height_Ray)
{
	Ray_H = Height_Ray;
	Ray_W = Width_Ray;
}
void TBox::SetCenter(TGfxVec2 tPosition)
{
	tCenter = tPosition;
}
void TBox::SetTextColor(unsigned int iColor)
{
	GfxSpriteSetColor(pTextSprite, iColor);
}
void TBox::SetScale(const float fScale)
{
	m_fScale = fScale;
	GfxSpriteSetScale(pSprite, m_fScale, m_fScale);
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

