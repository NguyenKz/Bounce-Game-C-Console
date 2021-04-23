
#include "Game_Object.h"

Game_Object::Game_Object()
{
}

Game_Object::Game_Object(bool is_soft)
{
	this->_is_soft = is_soft;
}

Game_Object::Game_Object(bool is_soft, double x, double y)
{
	this->_is_soft = is_soft;
	this->x = x;
	this->y = y;

}

bool Game_Object::check_collision(Game_Object* go)
{
	return 
		this->_is_soft&&
		go->_is_soft&&
		(int)this->x==(int)go->x &&
		(int)this->y==(int)go->y;
}

double Game_Object::get_x()
{

	return this->x;
}

double Game_Object::get_y()
{
	return this->y;
}

double Game_Object::get__x()
{
	return this->_x;
}

double Game_Object::get__y()
{
	return this->_y;
}

bool Game_Object::is_soft()
{
	return this->_is_soft;
}

void Game_Object::set_x(double x)
{
	this->_x = this->x;
	this->x=x;
}

void Game_Object::set_y(double y)
{
	this->_y = this->y;
	this->y = y;
}
