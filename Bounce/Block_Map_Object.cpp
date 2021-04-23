#include "Block_Map_Object.h"

Block_Map_Object::Block_Map_Object(bool is_soft,double x,double y,char body)
{
	this->is_soft = is_soft;
	this->x = x;
	this->y = y;
	this->body = body;
}

void Block_Map_Object::draw(_Canvas& canvas)
{
	canvas.draw_char(this->body, this->x, this->y);
}

bool Block_Map_Object::check_collision(int x, int y)
{
	return x == this->x && y == this->y;
}

bool Block_Map_Object::get_is_soft()
{
	return this->is_soft;
}
