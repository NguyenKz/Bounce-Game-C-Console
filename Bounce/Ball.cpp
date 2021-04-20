#include "Ball.h"
#include"Function.h"
Ball::Ball()
{
	this->x = 15;
	this->y = 0;
	this->v = 0;
	last_time = current_ms();
}

void Ball::update()
{
	this->_x = this->x;
	this->_y = this->y;
	double time_d = (current_ms() - last_time)/1000.0;

	this->v = this->v + G * time_d;
	double __y = this->v * time_d;
	this->y += __y;
	if (this->y > 19) {
		this->y = 19;
		this->v = -this->v*0.7;
		if (__y < 0.1) {
			this->v = 0;
		}
	}
	last_time = current_ms();
	gotoxy(22, 2);
	cout << "Speed: " << __y<< "   "<<this->v<<"   ";
}

void Ball::draw(_Canvas& canvas)
{
	canvas.draw_char('.', this->_x, this->_y);
	canvas.draw_char('#', this->x, this->y);
	gotoxy(22, 1);
	cout << "Toa do: "<<this->x<<"  "<<this->y<<"   ";
}

void Ball::jump()
{
	this->v = -50;
}
