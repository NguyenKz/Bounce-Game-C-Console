#pragma once
#include"Unit_Block.h"
#include"_Canvas.h"
#include<vector>
using namespace std;
class Block_Map_Object
{
protected:
	char body;
	double x;
	double y;
	bool is_soft;
public:
	/// <summary>
	/// Create a block with size is w*h in x,y and body is body
	/// </summary>
	/// <param name="is_soft">is soft</param>
	/// <param name="w">width</param>
	/// <param name="h">height</param>
	/// <param name="x">x</param>
	/// <param name="y">y</param>
	/// <param name="body">body</param>
	Block_Map_Object(bool is_soft, double x,double y,char body);
	void draw(_Canvas& canvas);
	bool check_collision(int x, int y);
	bool get_is_soft();
};

