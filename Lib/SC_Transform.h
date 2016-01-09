#ifndef HEADER_TRANSFORM
#define HEADER_TRANSFORM

class TTransform_2D
{
public:
	void DrawAxis(const float fRadius, const float fAngleAxis);
	void Render();
	void SetAxis(const TGfxVec2 tPosition);
	void CreateTransform();

private:
	TGfxSprite * pLineSprite;
	TGfxSprite * pTextX;
	TGfxSprite * pTextY;
	TGfxVec2 tPos;
	float fAngle;

	void DrawArrow(const TGfxVec2 tCenter, const TGfxVec2 tDirection, const unsigned int iColor, const float fRadius,TGfxSprite * pSprite);
};



#endif
