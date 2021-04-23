#pragma once
#include "Game_Object.h"
#include"_Canvas.h"
class Unit_Block :
    public Game_Object
{
private:
    char body;
public:
    Unit_Block(bool is_soft, double x, double y, char body);
    void draw(_Canvas& canvas);

};

