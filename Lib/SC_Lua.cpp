
#include "SC_Lua.h"
#include "lua.h"

static TLua m_Lua;

int SetResolution(lua_State * L)
{
	const int w = luaL_checkinteger(L, 1);
	const int h = luaL_checkinteger(L, 2);
	iSize = luaL_checkinteger(L, 3);
	GfxDefaultResolution(w, h);
	return 0;
}
int GetTheSize()
{
	return iSize;
}
void SC_Set_Lua_Resolution()
{
	m_Lua.Lua_S = luaL_newstate();
	TGfxFile * pFile = GfxFileOpenRead("script.lua");
	if (pFile == nullptr)
	{
		GfxDbgAssert(false,"You forgiven again to create the Lua Scripts \nGive (script.lua) in data folder");
	}
	lua_pushcfunction(m_Lua.Lua_S, SetResolution);
	lua_setglobal(m_Lua.Lua_S, "SetResolution");
	LuaDoFile(m_Lua.Lua_S, "script.lua");
}