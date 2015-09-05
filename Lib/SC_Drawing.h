#ifndef SC_DRAWING

void SC_DrawPlayer(TGfxSprite * pSprite, TGfxVec2  & Position, TGfxVec2 Direction, const float fRadius, const int iNumberRay, const float fAngle);

void SC_DrawSquarre(TGfxSprite * pSprite, TGfxVec2  & Position, const float fRatio,unsigned int iColor);

void SC_DrawRect(TGfxSprite * pSprite, TGfxVec2  & Position, const float fWidth, const float fHeight, unsigned int iColor);

void SC_DrawRectTWO(TGfxSprite * pSprite, TGfxVec2 Position_One, TGfxVec2 Position_TWO, unsigned int iColor);

void SC_DrawCercle(TGfxSprite * pSprite, TGfxVec2  & Position, const float fRadius, const int iNumberRay, unsigned int iColor);

void SC_DrawCercleTwo(TGfxSprite * pSprite, TGfxVec2 Position_One, TGfxVec2 Position_TWO, const int iNumberRay, unsigned int iColor);

float SC_GetAngleVector(TGfxVec2  & Position, TGfxVec2 Direction);

void SC_SetImageColor(TGfxSprite * &pSprite, TGfxVec2 Zone1, float fRadius);

#define SC_DRAWING

#endif
