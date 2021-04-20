#include "_Canvas.h"
#include"Function.h"
#include<iostream>
using namespace std;
_Canvas::_Canvas(int w, int h)
{
	this->w = w;
	this->h = h;
	this->current_canvas = new int*[h];
	for (int i = 0; i < h; i++)
	{
		this->current_canvas[i] = new int[w];
	}
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			this->current_canvas[y][x] = ' ';
			draw_char('.', x, y);
		}
	}


}

void _Canvas::draw_char(char c, int x, int y)
{
	if (x >= 0 && x < this->w && y>=0 && y<this->h) {
		if (this->current_canvas[y][x] != c) {
			this->current_canvas[y][x] = c;
			int* elemnet =new int[3]{ c,x,y };
			this->draw_c.push_back(elemnet);
		}
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

void _Canvas::draw()
{
	int size = this->draw_c.size();
	for (int i = 0; i < size; i++)
	{
		goto_c(this->draw_c[i][0], this->draw_c[i][1], this->draw_c[i][2]);
		
	}
	this->draw_c.clear();
	gotoxy(0, 0);
}

void _Canvas::update()
{
}
