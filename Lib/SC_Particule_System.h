#ifndef HEADER_PARTICULE_SYSTEM
#define HEADER_PARTICULE_SYSTEM

class TParticule_System
{
public:
	TGfxSprite * pSprite;

	void CreateSystem(const char * pName, const int iTileXMax, const int iTileYMax);
	void SetSystem(TGfxVec2 tPosition, const float fAngle);
	void RenderSystem();
	void AnimeParticule(const int iTiming);

private:
	TGfxVec2 tPos;

	float fSize;

	int iTileX;
	int iTileY;

	int iMaxTileX = 4;
	int iMaxTileY = 4;
	int iCount = 0;
};

#endif //HEADER_PARTICULE_SYSTEM
