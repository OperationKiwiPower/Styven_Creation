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
	~TBox();

	//Create && draw
	void CreateBox(unsigned int iColor);
	void DrawBox();

	//Get
	TGfxVec2 GetCenter();
	TBoxCollider GetCollider();

	bool GetDrawable();
	float GetAngle();

	//Set
	void SetAngle(float fAngle);
	void SetTexte(char * pChar);
	void SetTexte(int iValeur);

	void SetCenter(TGfxVec2 tPosition);
	void SetRayS(float Width_Ray, float Height_Ray);
	void SetCollider();
	void SetDrawable(bool bBool);
	void SetColor(const unsigned int iColor);
	void SetBox(TGfxVec2 Position, float W_Ray, float H_Ray, float Angle);
	void SetColliderAngle(float fAngle);
	void SetTextColor(unsigned int iColor);


	//Render
	void RenderBox();
	void Render_O_Line();
	void Render_O_Img();
	void TBox::Render_O_Text();

	char * pText;
	int iText = -1;

private:

	TGfxSprite * pLineSprite;	//OutLine
	TGfxSprite * pSprite;		//Fill
	TGfxSprite * pTextSprite;	//Number on squarre

	bool bIsDrawable = false;	//If you can render it
	TBoxCollider m_Collider;

	TGfxVec2 tCenter;

	float Ray_H;
	float Ray_W;
	float fAngle = 0;

};


#endif
