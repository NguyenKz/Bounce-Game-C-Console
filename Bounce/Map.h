#pragma once
#include<string>
#include"_Canvas.h"
#include"Block_Map_Object.h"
#include<vector>
using namespace std;
class Map
{
private:
	vector<string> temp{
		(string)"......................................................",
		(string)".                                                    .",
		(string)".                                                    .",
		(string)".                                                    .",
		(string)".                                                    .",
		(string)".                                                    .",
		(string)".                                                    .",
		(string)".                                                    .",
		(string)".                                                    .",
		(string)".                                                    .",
		(string)".                                                    .",
		(string)".                                                    .",
		(string)".                                                    .",
		(string)".                                                    .",
		(string)".                                                    .",
		(string)".                                                    .",
		(string)".                                                    .",
		(string)".                            ...................     .",
		(string)".                            -------------------     .",
		(string)".                                                    .",
		(string)".   ....................                             .",
		(string)".......                                              .",
		(string)".                                                    .",
		(string)".                           ....................     .",
		(string)".                                                    .",
		(string)".                                                    .",
		(string)"......................................................"
	};
	int w;
	int h;
	vector<Block_Map_Object> map;

public:
	Map();
	/// <summary>
	/// Get width of map
	/// </summary>
	/// <returns>width</returns>
	int get_w();
	/// <summary>
	/// Get height of map
	/// </summary>
	/// <returns>height</returns>
	int get_h();

	Block_Map_Object* get_block(int x, int y);
	void draw(_Canvas& canvas);

};

