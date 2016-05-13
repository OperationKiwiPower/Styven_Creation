#pragma once
class TParticule_System
{
public:
	TGfxSprite * m_pSprite;

	void CreateSystem(const char * pFileName, const int iTileXMax, const int iTileYMax);
	void SetSystem(TGfxVec2 tPosition, const float fAngle);
	void RenderSystem();
	void AnimeParticule(const int iTiming);

private:
	TGfxVec2 m_tPos;

	float m_fSize;

	int m_iTileX;
	int m_iTileY;

	int m_iMaxTileX = 4;
	int m_iMaxTileY = 4;
	int m_iCount = 0;
};
