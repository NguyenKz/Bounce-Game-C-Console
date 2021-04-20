#pragma once
#include<string>
#include<vector>
using namespace std;
class _Canvas
{
private:
	/// <summary>
	/// width of canvas
	/// </summary>
	int w;
	/// <summary>
	/// height of canvas
	/// </summary>
	int h;
	int**current_canvas;
	vector<int*>draw_c;
public:
	/// <summary>
	/// Init canvas with width and height
	/// </summary>
	/// <param name="w">width</param>
	/// <param name="h">height</param>
	_Canvas(int w, int h);
	/// <summary>
	/// draw a char in x,y of canvas
	/// </summary>
	/// <param name="c"></param>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void draw_char(char c, int x, int y);
	/// <summary>
	/// draw a string in x,y of canvas
	/// </summary>
	/// <param name="s">string to draw</param>
	/// <param name="x">x</param>
	/// <param name="y">y</param>
	void draw_string(string s, int x, int y);
	/// <summary>
	/// Update canvas and draw
	/// </summary>
	void draw();
	/// <summary>
	/// Update canvas
	/// </summary>
	void update();

};

