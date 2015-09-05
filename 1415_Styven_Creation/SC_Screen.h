#ifndef SC_TSCREEN

class SC_Screen
{
public:

	void Set_SCreen();

	int m_iFull_X;
	int m_iHalf_X;
	int m_iQuart_X;
	int m_iTriQuart_X;

	int m_iFull_Y;
	int m_iHalf_Y;
	int m_iQuart_Y;
	int m_iTriQuart_Y;

};

void SC_Screen::Set_SCreen()
{
	m_iFull_X = GfxGetDisplaySizeX();
	m_iHalf_X = m_iFull_X / 2;
	m_iQuart_X = m_iHalf_X / 2;
	m_iTriQuart_X = m_iQuart_X * 3;
	m_iTriQuart_X = m_iQuart_X * 3;

	m_iFull_Y = GfxGetDisplaySizeY();
	m_iHalf_Y = m_iFull_Y / 2;
	m_iQuart_Y = m_iHalf_Y / 2;
	m_iTriQuart_Y = m_iQuart_Y * 3;
}


#define SC_TSCREEN
#endif // !SC_TSCREEN

