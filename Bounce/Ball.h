#pragma once

#include<iostream>
#include"_Canvas.h"
using namespace std;
#define SPEED_JUMP 30
#define SPEED_MOVE 30
#define S_MOVE_LEFT 1
#define S_MOVE_RIGHT 2
#define S_IDLE 0
#define G 98
#define ACC_MOVE 25
#define MAX_SPEED_MOVE 10
class Ball
{
private:
	double x, y;
	double _x, _y;
    uint64_t time_check_jump;
	uint64_t time_check_move;
	float v_jump;
	float v_move;
	int state;
	bool is_move;
public:
	Ball();
	/// <summary>
	/// Update ball
	/// </summary>
	void update();
	/// <summary>
	/// Draw ball
	/// </summary>
	/// <param name="canvas">cavnas</param>
	void draw(_Canvas& canvas);
	/// <summary>
	/// Jump
	/// </summary>
	void jump();
	/// <summary>
	/// Move left
	/// </summary>
	void move_left();
	/// <summary>
	/// Move right
	/// </summary>
	void move_right();
};

