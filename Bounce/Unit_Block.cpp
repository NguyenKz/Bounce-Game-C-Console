#include "Unit_Block.h"

Unit_Block::Unit_Block(bool is_soft, double x, double y, char body):Game_Object(is_soft,x,y)
{
	this->body = body;
}


void Unit_Block::draw(_Canvas& canvas)
{
	canvas.draw_char(this->body, this->x, this->y);
}
