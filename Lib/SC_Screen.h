#ifndef SC_TSCREEN

struct TScreen
{
	struct TSize
	{
		int Full;
		int Half;
		int Quart;
		int TriQuart;
	};
	TSize x;
	TSize y;
};

void SC_SetScreenStruct(TScreen & Screen);

#define SC_TSCREEN
#endif // !SC_TSCREEN

