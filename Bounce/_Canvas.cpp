#include "_Canvas.h"
#include"Function.h"
#include<iostream>
using namespace std;
_Canvas::_Canvas(int w, int h)
{
	this->camera_x = 5;
	this->camera_y = 10;
	this->current_canvas = new int*[CAMERA_H];
	for (int i = 0; i < CAMERA_H; i++)
	{
		this->current_canvas[i] = new int[CAMERA_W];
	}
	for (int y = 0; y < CAMERA_H; y++)
	{
		for (int x = 0; x < CAMERA_W; x++)
		{
			this->current_canvas[y][x] = ' ';
			draw_empty( x, y);
		}
	}


}

void _Canvas::draw_char(char c, int x, int y)
{
	if (x >= this->camera_x && y >= this->camera_y &&
		x <= this->camera_x + CAMERA_W && y <= this->camera_y + CAMERA_H) {

		if (x-this->camera_x >= 0 && x - this->camera_x < CAMERA_W &&
			y-this->camera_y >= 0 && y-this->camera_y < CAMERA_H) {

			if (this->current_canvas[y-(int)this->camera_y][x-(int)this->camera_x] != c) {
				this->current_canvas[y-(int)this->camera_y][x-(int)this->camera_x] = c;
				int* elemnet = new int[3]{ c,x-(int)this->camera_x,y-(int)this->camera_y };
				this->draw_c.push_back(elemnet);
			}
		}
	}
	
}

void _Canvas::update(int x, int y, int w,int h)
{
	this->camera_x = x - CAMERA_W / 2;
	this->camera_y = y - CAMERA_H / 2;
	if (this->camera_x < 0) {
		this->camera_x = 0;
	}
	if (this->camera_x > w-CAMERA_W) {
		this->camera_x = w-CAMERA_W;
	}
	if (this->camera_y < 0) {
		this->camera_y = 0;
	}
	if (this->camera_y > h - CAMERA_H ) {
		this->camera_y = h - CAMERA_H ;
	}
}

void _Canvas::draw_string(string s, int x, int y)
{
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		this->draw_char(s[i], x + i, y);
	}
}

void _Canvas::draw_empty(int x, int y)
{
	this->draw_char(EMPTY, x, y);
}

void _Canvas::draw()
{
	int size = this->draw_c.size();
	for (int i = 0; i < size; i++)
	{
		
		goto_c(this->draw_c[i][0], this->draw_c[i][1]+DICH_X, this->draw_c[i][2]+DICH_Y);
		
		
	}
	this->draw_c.clear();
	gotoxy(0, 0);
}

void _Canvas::update()
{
}
