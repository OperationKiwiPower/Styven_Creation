#include "flib.h"
#include "flib_vec2.h"
#include "SC_Drawing.h"
#include <math.h>

void SC_DrawPlayer(TGfxSprite * pSprite, TGfxVec2  & Position, TGfxVec2 Direction, const float fRadius, const int iNumberRay, const float fAngle)
{
	const float fRatioRay = 360.0f / iNumberRay;

	TGfxVec2 Vecteur(Direction - Position);

	if (Vecteur.x != 0 && Vecteur.y != 0)
	{
		Vecteur = Vecteur.Normalize();
		Position.x += Vecteur.x;
		Position.y += Vecteur.y;
	}

	GfxLineSpriteJumpTo(pSprite, Position.x, Position.y);

	for (int i = 0; i < iNumberRay + 1 + fAngle; i++)
	{
		float Cercle_X = Position.x + (cos(GfxMathDegToRad(float(i*fRatioRay + fAngle))) * fRadius);
		float Cercle_Y;

		if (Vecteur.y > 0)Cercle_Y = Position.y + (sin(GfxMathDegToRad(float(i*fRatioRay + fAngle))) * fRadius);
		else Cercle_Y = Position.y - (sin(GfxMathDegToRad(float(i*fRatioRay + fAngle))) * fRadius);

		TGfxVec2 Cercle(Cercle_X, Cercle_Y);

		GfxLineSpriteLineTo(pSprite, Cercle.x, Cercle.y);
	}
}

void SC_DrawCercle(TGfxSprite * pSprite, TGfxVec2  & Position, const float fRadius, const int iNumberRay, unsigned int iColor)
{
	const float fRatioRay = 360.0f / iNumberRay;

	GfxLineSpriteReset(pSprite);
	GfxLineSpriteSetDrawingColor(pSprite, iColor);

	GfxLineSpriteJumpTo(pSprite, Position.x + (cos(GfxMathDegToRad(0)) * fRadius), Position.y + (sin(GfxMathDegToRad(0.0f)) * fRadius));

	for (int i = 0; i < iNumberRay + 1; i++)
	{
		float Cercle_X = Position.x + (cos(GfxMathDegToRad(float(i*fRatioRay))) * fRadius);
		float Cercle_Y = Position.y + (sin(GfxMathDegToRad(float(i*fRatioRay))) * fRadius);
		TGfxVec2 Cercle(Cercle_X, Cercle_Y);

		GfxLineSpriteLineTo(pSprite, Cercle.x, Cercle.y);
	}
}

void SC_DrawCercleTwo(TGfxSprite * pSprite, TGfxVec2 Position_One, TGfxVec2 Position_TWO, const int iNumberRay, unsigned int iColor)
{
	const float fRatioRay = 360.0f / iNumberRay;

	TGfxVec2 TRealCenter(Position_One + (Position_TWO - Position_One) / 2);
	float fRadius = ((Position_TWO - Position_One) / 2).Length();

	GfxLineSpriteReset(pSprite);
	GfxLineSpriteSetDrawingColor(pSprite, iColor);

	GfxLineSpriteJumpTo(pSprite, TRealCenter.x + (cos(GfxMathDegToRad(0)) * fRadius), TRealCenter.y + (sin(GfxMathDegToRad(0.0f)) * fRadius));

	for (int i = 0; i < iNumberRay + 1; i++)
	{
		float Cercle_X = TRealCenter.x + (cos(GfxMathDegToRad(float(i*fRatioRay))) * fRadius);
		float Cercle_Y = TRealCenter.y + (sin(GfxMathDegToRad(float(i*fRatioRay))) * fRadius);
		TGfxVec2 Cercle(Cercle_X, Cercle_Y);

		GfxLineSpriteLineTo(pSprite, Cercle.x, Cercle.y);
	}
}

void SC_DrawSquarre(TGfxSprite * pSprite, TGfxVec2  & Position, const float fRatio, unsigned int iColor)
{
	GfxLineSpriteReset(pSprite);
	GfxLineSpriteSetDrawingColor(pSprite, iColor);
	GfxLineSpriteJumpTo(pSprite, Position.x - fRatio, Position.y - fRatio);

	GfxLineSpriteLineTo(pSprite, Position.x + fRatio, Position.y - fRatio);
	GfxLineSpriteLineTo(pSprite, Position.x + fRatio, Position.y + fRatio);
	GfxLineSpriteLineTo(pSprite, Position.x - fRatio, Position.y + fRatio);
	GfxLineSpriteLineTo(pSprite, Position.x - fRatio, Position.y - fRatio);
}

void SC_DrawRect(TGfxSprite * pSprite, TGfxVec2  & Position, const float fWidth, const float fHeight, unsigned int iColor)
{
	GfxLineSpriteReset(pSprite);
	GfxLineSpriteSetDrawingColor(pSprite, iColor);
	GfxLineSpriteJumpTo(pSprite, Position.x - fWidth, Position.y - fHeight);

	GfxLineSpriteLineTo(pSprite, Position.x + fWidth, Position.y - fHeight);
	GfxLineSpriteLineTo(pSprite, Position.x + fWidth, Position.y + fHeight);
	GfxLineSpriteLineTo(pSprite, Position.x - fWidth, Position.y + fHeight);
	GfxLineSpriteLineTo(pSprite, Position.x - fWidth, Position.y - fHeight);
}

void SC_DrawRectTWO(TGfxSprite * pSprite, TGfxVec2 Position_One, TGfxVec2 Position_TWO, unsigned int iColor)
{
	GfxLineSpriteReset(pSprite);
	GfxLineSpriteSetDrawingColor(pSprite, iColor);
	GfxLineSpriteJumpTo(pSprite, Position_One.x, Position_One.y);
	GfxLineSpriteLineTo(pSprite, Position_One.x, Position_TWO.y);
	GfxLineSpriteLineTo(pSprite, Position_TWO.x, Position_TWO.y);
	GfxLineSpriteLineTo(pSprite, Position_TWO.x, Position_One.y);
	GfxLineSpriteLineTo(pSprite, Position_One.x, Position_One.y);
}

float SC_GetAngleVector(TGfxVec2  & Position, TGfxVec2 Direction)
{
	TGfxVec2 Vecteur(Direction - Position);

	float hypothenuse = Vecteur.Length();
	float fAngle = GfxMathRadToDeg(acos(Vecteur.x / hypothenuse));
	return fAngle;
}

void SC_SetImageColor(TGfxSprite * &pSprite, TGfxVec2 Zone1, float fRadius)
{
	TGfxImage * pImage = GfxImageCreate(2,2);

	for (int y = 0; y < GfxImageGetSizeY(pImage); y++)
	{
		for (int x = 0; x < GfxImageGetSizeX(pImage); x++)
		{
			int iIndex = x + (x*y);

			if (float(x) <= Zone1.x + fRadius &&
				float(x) >= Zone1.x - fRadius &&
				float(y) <= Zone1.y + fRadius &&
				float(y) >= Zone1.y - fRadius)
			{
				GfxImageGetData(pImage)[iIndex] = EGfxColor_White;
			}
			//if (float(x) <= Zone2.x + fRadius &&
			//	float(x) >= Zone2.x - fRadius &&
			//	float(y) <= Zone2.y + fRadius &&
			//	float(y) >= Zone2.y - fRadius)
			//{
			//	GfxImageGetData(pImage)[iIndex] = EGfxColor_White;
			//}
			else
			{
				//				GfxImageGetData(pImage)[iIndex] = GfxColor(0,0,0,0);
			}
		}
	}
	TGfxTexture * pTexture = GfxTextureCreate(pImage);

	pSprite = GfxSpriteCreate(pTexture);
	GfxSpriteSetFilteringEnabled(pSprite, false);
}
