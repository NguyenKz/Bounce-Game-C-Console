#include "Ball_Object.h"
#include"Function.h"
Ball_Object::Ball_Object(double x, double y):Game_Object(true)
{
	this->set_x(x);
	this->set_y(y);
	this->v_jump = 0;
	this->v_move = 0;
	this->time_check_jump = current_ms();
	this->time_check_move = current_ms();
}

void Ball_Object::update(Map& map)
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
	if (this->v_move > MAX_SPEED_MOVE) {
		this->v_move = 0;
	}
	double __x = this->v_move * time_d;
	
	int _s = 0;
	while (abs(__x) > 0.001) {
		if (__x >= 1) {
			this->x += 1;
			__x -= 1;
		}
		else if (__x <= -1) {
			this->x -= 1;
			__x += 1;
		}
		else {
			this->x += __x;
			__x = 0;
		}

		Block_Map_Object* obj = map.get_block(this->x, this->y);
		if (this->v_move < 0) {
			if (obj != NULL && obj->get_is_soft() == false) {
				this->x += 1;
				_s = 1;
			}
		}


		obj = map.get_block(this->x, this->y);
		if (this->v_move > 0) {
			if (obj != NULL && obj->get_is_soft() == false) {
				this->x -= 1;
				_s = 1;
			}
		}
	

	}
	if (_s == 1) {
		this->v_move = 0;
	}

	this->is_move = false;


	time_d = (current_ms() - time_check_jump) / 1000.0;
	this->v_jump = this->v_jump + G * time_d;
	double __y = this->v_jump * time_d;
	_s = 0;
	while (abs(__y)>0.001) {
		if (__y >= 1) {
			this->y += 1;
			__y -= 1;
		}
		else if (__y <= -1) {
			this->y -= 1;
			__y += 1;
		}
		else {
			this->y += __y;
			__y = 0;
		}

		Block_Map_Object* obj = map.get_block(this->x, this->y);
		if (this->v_jump < 0) {
			if (obj != NULL && obj->get_is_soft() == false) {
				this->y += 1;
				_s = 1;
			}
		}
		

		obj = map.get_block(this->x, this->y);
		if (this->v_jump > 0) {
			if (obj != NULL && obj->get_is_soft() == false) {
				this->y -= 1;
				_s = 1;
			}
		}
		
	}
	if (_s == 1) {
		this->v_jump = 0;
	}

	//if (this->y > map.get_h() - 1) {
	//	this->y = map.get_h() - 1;
	//	/*	this->v = -this->v*0.7;
	//		if (__y < 0.5) {
	//			this->v = 0;
	//		}*/
	//	this->v_jump = 0;
	//}
	time_check_jump = current_ms();
	gotoxy(22, 2);
	cout << "Speed: " << __y << "   " << this->v_jump << "   "<< time_check_jump<<"   ";
	gotoxy(22, 3);
	cout << "Pos: " <<this->x << "   " << this->y << "   ";
}

void Ball_Object::draw(_Canvas& canvas)
{
	canvas.draw_empty(this->_x, this->_y);
	canvas.draw_char('#', this->x, this->y);
	gotoxy(22, 1);
	cout << "Toa do: " << this->x << "  " << this->y << "   ";
}

void Ball_Object::jump()
{
	if (this->v_jump == 0) {
		this->v_jump = -30;
	}
}

void Ball_Object::move_left()
{
	this->state = S_MOVE_LEFT;
	this->v_move = -MAX_SPEED_MOVE;
	this->is_move = true;
}

void Ball_Object::move_right()
{
	this->state = S_MOVE_RIGHT;
	this->v_move = MAX_SPEED_MOVE;
	this->is_move = true;
}
