#pragma once
#define G 98
#include<iostream>
#include"_Canvas.h"
using namespace std;
class Ball
{
private:
	double x, y;
	double _x, _y;
    uint64_t last_time;
	float v;
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
};

