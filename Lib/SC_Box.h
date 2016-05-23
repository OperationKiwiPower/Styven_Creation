#ifndef HEADER_BOX

#define HEADER_BOX

#include "flib.h"
#include "flib_vec2.h"
#include "SC_CollisionTest.h"


class TBox
{
public:

	TBox() = default;
	~TBox();

	//Create && draw
	void CreateBox(unsigned int iColor, const bool bText, const bool bSprite, const bool bLine);
	void CreateSpriteBox(TGfxTexture * pTexture, const int iTextureSize, int iTileX, int iTileY);
	void CreateSpriteBox(TGfxTexture * pTexture);
	void CreateTextBox(const char * pName);
	void DrawBox();

	//Get
	TGfxVec2 GetCenter() const;
	TGfxVec2 GetCenterOrigine() const;
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
	void SetCenterOrigine(TGfxVec2 tPosition);
	void SetRayS(float Width_Ray, float Height_Ray);
	void SetCollider();
	void SetDrawable(bool bBool);
	void SetColor(const unsigned int m_iColor);
	void SetBox(TGfxVec2 Position, float W_Ray, float H_Ray, float Angle = 0);
	void SetColliderAngle(float fAngle);
	void SetTextColor(unsigned int iColor);
	void SetScale(const float fScale);
	void SetCutOut(const int iIndex);

	//Render
	void RenderBox();
	void Render_O_Line();
	void Render_O_Img();
	void Render_O_Text();

	char * m_pText;
	int m_iText = -1;

private:

	TGfxSprite * m_pLineSprite = nullptr;	//OutLine
	TGfxSprite * m_pSprite = nullptr;		//Fill
	TGfxSprite * m_pTextSprite = nullptr;	//Number on squarre

	bool m_bIsDrawable = false;	//If you can render it
	TBoxCollider m_Collider;

	unsigned int m_iColor;

	TGfxVec2 m_tCenter;
	TGfxVec2 m_tCenterOrigine;
	
	float m_fRay_H = 0.0f;
	float m_fRay_W = 0.0f;
	float m_fAngle = 0.0f;
	float m_fScale = 1.0f;

};


#endif
