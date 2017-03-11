#ifndef LUAPROXYOBJECT_H
#define LUAPROXYOBJECT_H

#include <sol.hpp>

#include <Core/Object.h>

class LuaProxyObject: public Object{
public:
    static void bind(sol::state& lua);

    LuaProxyObject(sol::table& lua_table, const sol::function& fun_delete);
    virtual ~LuaProxyObject();

    virtual void OnUpdate();
    virtual void OnRender();
    virtual void OnClick();
    virtual void OnCollide(Object* obj);

private:
    void BindScriptFunctions(sol::table& lua_table, const sol::function &fun_delete);

    std::unordered_map<std::string, std::string> _props;

    sol::function _fun_init;
    sol::function _fun_update;
    sol::function _fun_render;
    sol::function _fun_collide;
    sol::function _fun_cleanup;
    sol::function _fun_delete_object;

    sol::table _data_storage;
};

#endif // LUAPROXYOBJECT_H
