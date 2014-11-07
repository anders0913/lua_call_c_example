// lua man: http://www.lua.org/manual/5.2/ 

#include <lua.h>
#include <lauxlib.h>
#include <string.h>
#include <stdlib.h>


static int l_add(lua_State *L){
    double d1 = luaL_checknumber(L, 1); // 这个1代表了从左到右lua调用这个函数时传入的第一个参数 lua只有double
	double d2 = luaL_checknumber(L, 2); 

    lua_pushnumber(L, d1 + d2);			// 返回值压入lua栈
    return 1;
}
  
static int l_sub(lua_State *L){
    double d1 = luaL_checknumber(L, 1);   
	double d2 = luaL_checknumber(L, 2); 

    lua_pushnumber(L, d1 - d2);
    return 1;
} 
 
int luaopen_calc(lua_State *L){
	luaL_checkversion(L); // 防止链接多分lua库 参考：http://blog.codingnow.com/2012/01/lua_link_bug.html

	luaL_Reg l[] = {
		{"add", l_add},		
		{"sub", l_sub},
		{NULL, NULL}
	};  
 
	luaL_newlib(L, l); // Creates a new table and registers there the functions in list l. 
    return 1;
}