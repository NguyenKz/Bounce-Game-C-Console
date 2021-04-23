#pragma once
#include "Game_Object.h"
#include"Map.h"
#define SPEED_JUMP 30
#define SPEED_MOVE 30
#define S_MOVE_LEFT 1
#define S_MOVE_RIGHT 2
#define S_IDLE 0
#define G 98
#define ACC_MOVE 35
#define MAX_SPEED_MOVE 15


class Ball_Object :
    public Game_Object
{
private:
	uint64_t time_check_jump;
	uint64_t time_check_move;
	float v_jump;
	float v_move;
	int state;
	bool is_move;
public:
	Ball_Object(double x,double y);
	/// <summary>
	/// Update ball
	/// </summary>
	void update(Map& map);
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

