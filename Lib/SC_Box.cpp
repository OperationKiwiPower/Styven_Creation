#include "flib.h"
#include "flib_vec2.h"
#include <math.h>
#include <stdio.h>
#include "SC_CollisionTest.h"
#include "SC_Box.h"


TBox::~TBox()
{
	m_pLineSprite = nullptr;
	m_pSprite = nullptr;	
	m_pTextSprite = nullptr;
	//m_pImgSprite = nullptr;
}
//Public 

//----GET
TGfxVec2 TBox::GetCenter()const
{
	return m_tCenter;
}
TGfxVec2 TBox::GetCenterOrigine()const
{
	return m_tCenterOrigine;
}
TBoxCollider TBox::GetCollider()const
{
	return m_Collider;
}
unsigned int TBox::GetColor()const
{
	return m_iColor;
}
bool TBox::GetDrawable() const
{
	return m_bIsDrawable;
}
float TBox::GetAngle() const
{
	return m_fAngle;
}

//----SET
void TBox::CreateBox(unsigned int m_iColor, const bool bText, const bool bSprite, const bool bLine)
{
	if (m_pTextSprite == nullptr && bText)
	{
		m_pTextSprite = GfxTextSpriteCreate();
		GfxSpriteSetFilteringEnabled(m_pTextSprite, true);
	}
	m_bIsDrawable = true;
	if (bLine)
	{
		//Line
		m_pLineSprite = GfxLineSpriteCreate();
	}
	if (bSprite)
	{
		//Image
		TGfxImage * pImage = GfxImageCreate(1, 1);
		GfxImageGetData(pImage)[0] = EGfxColor_White;
		TGfxTexture * pTexture = GfxTextureCreate(pImage);
		m_pSprite = GfxSpriteCreate(pTexture);
		GfxSpriteSetFilteringEnabled(m_pSprite, false);
		GfxSpriteSetPivot(m_pSprite, 0.5f, 0.5f);
		SetColor(m_iColor);
	}
}
void TBox::CreateSpriteBox(TGfxTexture * pTexture, const int iTextureSize, int iTileX, int iTileY)
{
	m_bIsDrawable = true;
	m_pSprite = GfxSpriteCreate(pTexture);
	GfxSpriteSetFilteringEnabled(m_pSprite, false);
	GfxSpriteSetCutout(m_pSprite, iTileX*iTextureSize, iTileY*iTextureSize, iTextureSize, iTextureSize);
	GfxSpriteSetPivot(m_pSprite, iTextureSize / 2.0f, iTextureSize / 2.0f);
	SetBox(TGfxVec2(0.0f, 0.0f), (float)iTextureSize, (float)iTextureSize);
}
void TBox::CreateSpriteBox(TGfxTexture * pTexture)
{
	m_bIsDrawable = true;
	m_pSprite = GfxSpriteCreate(pTexture);
	int iSizeX = GfxSpriteGetSizeX(m_pSprite);
	int iSizeY = GfxSpriteGetSizeY(m_pSprite);
	GfxSpriteSetFilteringEnabled(m_pSprite, false);
	GfxSpriteSetPivot(m_pSprite, iSizeX / 2.0f, iSizeY / 2.0f);
	SetBox(TGfxVec2(0.0f, 0.0f), (float)iSizeX, (float)iSizeY);
}
void TBox::CreateTextBox(const char * pName)
{
	m_bIsDrawable = true;
	m_pSprite = GfxTextSpriteCreate();
	GfxSpriteSetFilteringEnabled(m_pSprite, false);
	GfxTextSpritePrintf(m_pSprite, pName);
	int iSizeX = GfxSpriteGetSizeX(m_pSprite);
	int iSizeY = GfxSpriteGetSizeY(m_pSprite);
	GfxSpriteSetPivot(m_pSprite, iSizeX / 2.0f, iSizeY / 2.0f);
	SetBox(TGfxVec2(0.0f, 0.0f), (float)iSizeX, (float)iSizeY);
}

void TBox::SetTile(const int g_iTextureSize ,const int iTileX, const int iTileY)
{
	GfxSpriteSetCutout(m_pSprite, iTileX*g_iTextureSize, iTileY*g_iTextureSize, g_iTextureSize, g_iTextureSize);
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
	m_bIsDrawable = bBool;
}
void TBox::SetColor(const unsigned int iColor)
{
	m_iColor = iColor;
	if (m_pSprite!=nullptr)
		GfxSpriteSetColor(m_pSprite, m_iColor);
}
void TBox::SetTexte(char * pChar)
{
	GfxTextSpritePrintf(m_pTextSprite, pChar);

	float fSizeX = GfxSpriteGetSizeX(m_pTextSprite)/2.0f;
	float fSizeY = GfxSpriteGetSizeY(m_pTextSprite)/2.0f;
	m_pText = pChar;
	GfxSpriteSetPivot(m_pTextSprite, fSizeX, fSizeY);
	GfxSpriteSetPosition(m_pTextSprite, m_tCenter.x, m_tCenter.y);
}
void TBox::SetTexte(int iValeur)
{
	if (m_pTextSprite == nullptr)
	{
		m_pTextSprite = GfxTextSpriteCreate();
	}
	GfxTextSpritePrintf(m_pTextSprite, "%i\n",iValeur);
	m_iText = iValeur;

	float fSizeX = GfxSpriteGetSizeX(m_pTextSprite) / 2.0f;
	float fSizeY = GfxSpriteGetSizeY(m_pTextSprite) / 2.0f;

	GfxSpriteSetPivot(m_pTextSprite, fSizeX, fSizeY);
	GfxSpriteSetPosition(m_pTextSprite, m_tCenter.x, m_tCenter.y);
}

//----Show
void TBox::DrawBox()
{
	if (m_pSprite != nullptr)
	{
		GfxSpriteSetPosition(m_pSprite, m_tCenter.x, m_tCenter.y);
		GfxSpriteSetAngle(m_pSprite, GfxMathDegToRad(-m_fAngle));
	}

	//Line
	if (m_pLineSprite != nullptr)
	{
		GfxLineSpriteReset(m_pLineSprite);
		GfxLineSpriteSetDrawingColor(m_pLineSprite, GfxColor(150, 150, 150, 255));
		TGfxVec2 tAxisX = TGfxVec2(m_fRay_W, 0).Rotate(GfxMathDegToRad(m_fAngle))*m_fScale;
		TGfxVec2 tAxisY = TGfxVec2(0, m_fRay_H).Rotate(GfxMathDegToRad(m_fAngle))*m_fScale;

		TGfxVec2 tUR = TGfxVec2(m_tCenter.x + tAxisX.x + tAxisY.x, m_tCenter.y + tAxisX.y + tAxisY.y);
		TGfxVec2 tUL = TGfxVec2(m_tCenter.x - tAxisX.x + tAxisY.x, m_tCenter.y - tAxisX.y + tAxisY.y);
		TGfxVec2 tDL = TGfxVec2(m_tCenter.x - tAxisX.x - tAxisY.x, m_tCenter.y - tAxisX.y - tAxisY.y);
		TGfxVec2 tDR = TGfxVec2(m_tCenter.x + tAxisX.x - tAxisY.x, m_tCenter.y + tAxisX.y - tAxisY.y);

		GfxLineSpriteJumpTo(m_pLineSprite, tUL.x, tUL.y);
		GfxLineSpriteLineTo(m_pLineSprite, tDL.x, tDL.y);
		GfxLineSpriteLineTo(m_pLineSprite, tDR.x, tDR.y);
		GfxLineSpriteLineTo(m_pLineSprite, tUR.x, tUR.y);
		GfxLineSpriteLineTo(m_pLineSprite, tUL.x, tUL.y);
	}
	if (m_pTextSprite != nullptr)
	{
		GfxSpriteSetAngle(m_pTextSprite,GfxMathDegToRad(-m_fAngle));
	}
}
void TBox::RenderBox()
{
	Render_O_Img();
	Render_O_Line();
	Render_O_Text();
}
void TBox::Render_O_Line()
{
	if (m_bIsDrawable&& m_pLineSprite != nullptr)GfxSpriteRender(m_pLineSprite);
}
void TBox::Render_O_Img()
{
	if (m_bIsDrawable&& m_pSprite != nullptr)GfxSpriteRender(m_pSprite);
}
void TBox::Render_O_Text()
{
	if (m_bIsDrawable && m_pTextSprite!=nullptr)GfxSpriteRender(m_pTextSprite);
}

//----Box
void TBox::SetAngle(float Angle)
{
	m_fAngle = Angle;
	SetColliderAngle(m_fAngle);
}
void TBox::SetRayS(float Width_Ray, float Height_Ray)
{
	m_fRay_H = Height_Ray;
	m_fRay_W = Width_Ray;
}
void TBox::SetCenter(TGfxVec2 tPosition)
{
	m_tCenter = tPosition;
	SetCollider();
}
void TBox::SetCenterOrigine(TGfxVec2 tPosition)
{
	m_tCenterOrigine = tPosition;
}
void TBox::SetTextColor(unsigned int iColor)
{
	GfxSpriteSetColor(m_pTextSprite, iColor);
}
void TBox::SetScale(const float fScale)
{
	m_fScale = fScale;
	GfxSpriteSetScale(m_pSprite, m_fScale, m_fScale);
}
void TBox::SetCutOut(const int iIndex)
{
	int iNumberWidth = (GfxSpriteGetTextureSizeX(m_pSprite) / int(m_fRay_W));
	int iNumberHeight = (GfxSpriteGetTextureSizeY(m_pSprite) / int(m_fRay_H));

	int iTileX = iIndex % iNumberWidth;
	int iTileY = iIndex / iNumberHeight;

	GfxSpriteSetCutout(m_pSprite, iTileX * (int)m_fRay_W, iTileY * (int)m_fRay_H, (int)m_fRay_W, (int)m_fRay_H);
}

//----BoxCollider
void TBox::SetColliderAngle(float fAngle)
{
	m_Collider.m_fAngle = fAngle;
}
void TBox::SetCollider()
{
	TGfxVec2 tRay(m_fRay_W / 2.0f, m_fRay_H / 2.0f);
	m_Collider.m_tSpot_LH = TGfxVec2(m_tCenter - tRay);
	m_Collider.m_tSpot_RD = TGfxVec2(m_tCenter + tRay);
}

