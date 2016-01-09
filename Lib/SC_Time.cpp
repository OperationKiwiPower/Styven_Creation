#include <Windows.h>
#include "SC_Time.h"

SYSTEMTIME SC_GetTime()
{
	SYSTEMTIME tTime;
	GetLocalTime(&tTime);
	return tTime;
}
