#ifndef HEADER_LUA
#define HEADER_LUA

class TLua
{
public:
	lua_State * Lua_S;

private:
	int SetResolution();

};


void SC_Set_Lua_Resolution();

#endif
