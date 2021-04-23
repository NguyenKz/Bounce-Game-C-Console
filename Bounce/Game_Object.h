#pragma once
//#include"Map.h"
//#include"_Canvas.h"

class Game_Object
{
protected:
	bool _is_soft;
	double x,y;
	double _x,_y;

public:

	/// <summary>
	/// do nothing
	/// </summary>
	Game_Object();
	Game_Object(double x, double y);
	/// <summary>
	/// Init game object with soft type?
	/// </summary>
	/// <param name="is_soft">is soft</param>
	Game_Object(bool is_soft);
	/// <summary>
	/// Init game object with soft type?
	/// x,y is posion
	/// </summary>
	/// <param name="is_soft">is soft</param>
	/// <param name="x">x</param>
	/// <param name="y">y</param>
	Game_Object(bool is_soft,double x,double y);


	///// <summary>
	///// Update game object
	///// </summary>
	///// <param name="map"> map of game</param>
	//virtual void update(Map& map)=0;
	///// <summary>
	///// Draw to canvas
	///// </summary>
	///// <param name="canvas"> canvas</param>
	//virtual void draw(_Canvas& canvas)=0;
	/// <summary>
	/// Check go is collision with this
	/// </summary>
	/// <param name="go">Game object other</param>
	/// <returns>true:is collision</returns>
	bool check_collision(Game_Object* go );
	/// <summary>
	/// Get x pos
	/// </summary>
	/// <returns>x</returns>
	double get_x();
	/// <summary>
	/// Get y pos
	/// </summary>
	/// <returns>y</returns>
	double get_y();
	/// <summary>
	/// Get x old
	/// </summary>
	/// <returns>x old</returns>
	double get__x();
	/// <summary>
	/// Get y old
	/// </summary>
	/// <returns>y</returns>
	double get__y();
	/// <summary>
	/// Get is soft type
	/// </summary>
	/// <returns>is_soft</returns>
	bool is_soft();
	/// <summary>
	/// set x pos
	/// </summary>
	/// <param name="x">x</param>
	void set_x(double x);
	/// <summary>
	/// set y pos
	/// </summary>
	/// <param name="y">y</param>
	void set_y(double y);
	
};

