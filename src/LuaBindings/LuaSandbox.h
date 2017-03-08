#ifndef LUASANDBOX_H
#define LUASANDBOX_H

#include <vector>

#include <sol.hpp>

#include <LuaBindings/LuaVec2.h>
#include <LuaBindings/LuaSprite.h>
#include <LuaBindings/LuaMouse.h>
#include <LuaBindings/LuaAudio.h>
#include <LuaBindings/LuaKeyboard.h>

class LuaSandbox
{
public:
    LuaSandbox();

    void AddScript(const std::string& origin, const std::string& script_lines);

    void EngineInit();
    void EngineUpdate();
    void EngineRender();
    void EngineCleanUp();

private:
    sol::state _lua;
    sol::function  _fun_init;
    sol::function  _fun_update;
    sol::function  _fun_render;
};

#endif // LUASANDBOX_H
