#ifndef HEADER_BOX

#define HEADER_BOX

#include "flib.h"
#include "flib_vec2.h"
#include "SC_CollisionTest.h"


class TBox
{
public:

	TBox() = default;
	TBox(unsigned int iColor);

	//Create && draw
	void CreateBox(unsigned int iColor, const bool bText, const bool bSprite, const bool bLine);
	void CreateSpriteBox(TGfxTexture * pTexture, const unsigned int iColor, const int g_iTextureSize, int iTileX, int iTileY);
	void DrawBox();

	//Get
	TGfxVec2 GetCenter() const;
	TBoxCollider GetCollider() const;

	unsigned int GetColor()const;
	bool GetDrawable()const;
	float GetAngle()const;

	//Set
	void SetAngle(float fAngle);
	void SetTexte(char * pChar);
	void SetTexte(int iValeur);
	void SetTile(const int g_iTextureSize, const int iTileX, const int iTileY);

	void SetCenter(TGfxVec2 tPosition);
	void SetRayS(float Width_Ray, float Height_Ray);
	void SetCollider();
	void SetDrawable(bool bBool);
	void SetColor(const unsigned int m_iColor);
	void SetBox(TGfxVec2 Position, float W_Ray, float H_Ray, float Angle = 0);
	void SetColliderAngle(float fAngle);
	void SetTextColor(unsigned int iColor);
	void SetScale(const float fScale);


	//Render
	void RenderBox();
	void Render_O_Line();
	void Render_O_Img();
	void Render_O_Text();

	char * pText;
	int iText = -1;

private:

	TGfxSprite * pLineSprite = nullptr;	//OutLine
	TGfxSprite * pSprite = nullptr;		//Fill
	TGfxSprite * pTextSprite = nullptr;	//Number on squarre
	TGfxSprite * pImgSprite = nullptr;	//Image in squarre

	bool bIsDrawable = false;	//If you can render it
	TBoxCollider m_Collider;

	unsigned int iColor;

	TGfxVec2 tCenter;
	
	float Ray_H;
	float Ray_W;
	float fAngle = 0;
	float m_fScale = 1.0f;

};


#endif
