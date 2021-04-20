#include "Ball.h"
#include"Function.h"
Ball::Ball()
{
	this->x = 15;
	this->y = 0;
	this->v_jump = 0;
	time_check_jump = current_ms();
	this->time_check_move = -1;
}

void Ball::update()
{
	this->_x = this->x;
	this->_y = this->y;
	
	if (this->time_check_move == -1) {
		this->time_check_move = current_ms();
	}
	
	double time_d = (current_ms() - time_check_move) / 1000.0;
	this->time_check_move = current_ms();
	switch (this->state) {
	case S_MOVE_LEFT:
		if (false == this->is_move) {
			this->v_move = this->v_move + ACC_MOVE * time_d;
			if (this->v_move >= 0) {
				this->state = S_IDLE;
			}
		}
		break;
	case S_MOVE_RIGHT:
		if (false == this->is_move) {
			this->v_move = this->v_move - ACC_MOVE * time_d;
			if (this->v_move <= 0) {
				this->state = S_IDLE;
			}
		}
		break;
	case S_IDLE:
		this->v_move = 0;
		break;
	}
	this->x += this->v_move * time_d;
	if (this->x < 0) {
		this->x = 0;
	}
	if (this->x > 19) {
		this->x = 19;
	}
	
	this->is_move = false;


	time_d = (current_ms() - time_check_jump)/1000.0;

	this->v_jump = this->v_jump + G * time_d;
	double __y = this->v_jump * time_d;
	this->y += __y;
	if (this->y > 19) {
		this->y = 19;
	/*	this->v = -this->v*0.7;
		if (__y < 0.5) {
			this->v = 0;
		}*/
		this->v_jump = 0;
	}
	time_check_jump = current_ms();
	gotoxy(22, 2);
	cout << "Speed: " << __y<< "   "<<this->v_jump<<"   ";
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
	if (this->v_jump == 0) {
		this->v_jump = -30;
	}
}

void Ball::move_left()
{
	this->state = S_MOVE_LEFT;
	this->v_move = -MAX_SPEED_MOVE;
	this->is_move = true;
}

void Ball::move_right()
{
	this->state = S_MOVE_RIGHT;
	this->v_move = MAX_SPEED_MOVE;
	this->is_move = true;
}
