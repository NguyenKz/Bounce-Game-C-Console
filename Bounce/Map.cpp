#include "Map.h"
#include"Function.h"
Map::Map()
{
	this->h = this->temp.size();
	this->w = this->temp[0].size();

	for (int _h = 0; _h < this->h; _h++)
	{
		for (int _w = 0; _w < this->w; _w++)
		{
			switch (this->temp[_h][_w]) {
			case '.':
				this->map.push_back(Block_Map_Object(false,  _w, _h, '.'));
				break;
			case '-':
				this->map.push_back(Block_Map_Object(false, _w, _h, '*'));
				break;
			default:
				this->map.push_back(Block_Map_Object(true, _w, _h, ' '));
			}
				
		}
	}
}

int Map::get_w()
{
	return this->w;
}

int Map::get_h()
{
	return this->h;
}

void Map::draw(_Canvas& canvas)
{

	for (int _h = 0; _h < this->h; _h++)
	{
		for (int _w = 0; _w < this->w; _w++)
		{
			this->map[_h*this->w+_w].draw(canvas);
		}
	}
}

Block_Map_Object* Map::get_block(int x, int y)
{

	for (int _h = 0; _h < this->h; _h++)
	{
		for (int _w = 0; _w < this->w; _w++)
		{
			if (this->map[_h * this->w + _w].check_collision(x, y)) {
				return &this->map[_h * this->w + _w];
			}
		}
	}
	return NULL;
}

