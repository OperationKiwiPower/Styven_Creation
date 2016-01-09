//-----------------Test Zone-----------------//

#include "flib.h"
#include "flib_vec2.h"
#include "SC_Styven.h"
#include "SC_Transform.h"

TParticule_System m_Fire, m_Smoke, m_Explo;
TTransform_2D m_Trans_Fire, m_Trans_Smoke, m_Trans_Explo;
TGfxVec2 tCenter, tCenterLeft, tCenterRight;
TBox m_Box;
float g_fAngle = 0.0f;
float g_fSpeed = 5.0f;
const float fRadius = 50.0f;

void Initialize()
{
	m_Fire.CreateSystem("T_Fire.tga", 6, 6);
	m_Explo.CreateSystem("T_Explo.tga", 6, 6);
	m_Smoke.CreateSystem("T_Smoke.tga", 8, 8);

	m_Trans_Fire.CreateTransform();
	m_Trans_Explo.CreateTransform();
	m_Trans_Smoke.CreateTransform();

	tCenter = TGfxVec2((float)GfxGetDisplaySizeX() / 2.0f, (float)GfxGetDisplaySizeY() / 1.5f);
	tCenterLeft = TGfxVec2((float)GfxGetDisplaySizeX() / 4.0f, (float)GfxGetDisplaySizeY() / 1.5f);
	tCenterRight = TGfxVec2((float)GfxGetDisplaySizeX() / 4.0f*3.0f, (float)GfxGetDisplaySizeY() / 1.5f);

	m_Trans_Fire.SetAxis(tCenter);
	m_Trans_Explo.SetAxis(tCenterLeft);
	m_Trans_Smoke.SetAxis(tCenterRight);

	m_Fire.SetSystem(tCenter, g_fAngle);
	m_Explo.SetSystem(tCenterLeft, g_fAngle);
	m_Smoke.SetSystem(tCenterRight, g_fAngle);

	GfxSpriteSetColor(m_Fire.pSprite, GfxColor(255, 150, 0, 255));
}
void Update()
{
	m_Fire.AnimeParticule(2);
	m_Explo.AnimeParticule(2);
	m_Smoke.AnimeParticule(2);
	if (GfxInputIsPressed(EGfxInputID_KeyArrowLeft))
		g_fAngle -= g_fSpeed;
	if (GfxInputIsPressed(EGfxInputID_KeyArrowRight))
		g_fAngle += g_fSpeed;
	
	m_Fire.SetSystem(tCenter, g_fAngle);
	m_Explo.SetSystem(tCenterLeft, g_fAngle);
	m_Smoke.SetSystem(tCenterRight, g_fAngle);

	m_Trans_Fire.DrawAxis(fRadius, g_fAngle);
	m_Trans_Explo.DrawAxis(fRadius, g_fAngle);
	m_Trans_Smoke.DrawAxis(fRadius, g_fAngle);
}
void Render()
{
	GfxClear(EGfxColor_Black);
	m_Smoke.RenderSystem();
	m_Fire.RenderSystem();
	m_Explo.RenderSystem();
	if (GfxInputIsPressed(EGfxInputID_KeyNumPad0))
	{
		m_Trans_Fire.Render();
		m_Trans_Explo.Render();
		m_Trans_Smoke.Render();
	}
}

void GfxMain(int, char *[])
{
//	GfxDefaultResolution(1200, 700);
	GfxCallbacks(Initialize, Update, Render);
}
