#include<conio.h>
#include"Map.h"
#include"_Canvas.h"
#include"Ball_Object.h"
#include <windows.h>
#include"Function.h"
using namespace std;

int main() {
	Map map;
	_Canvas canvas(map.get_w(), map.get_h());
	Ball_Object ball(20,10);
	
	bool is_running = true;

	int x = 10;
	int y = 10;
	uint64_t last_time = current_ms();
	while (is_running) {
		int key = 0;
		if (GetAsyncKeyState(0x41)) {//a,A
			ball.move_left();
		}if (GetAsyncKeyState(0x53)) {//s,S
			
		}
		if (GetAsyncKeyState(0x44)) {//d,D
			ball.move_right();
		}
		if (GetAsyncKeyState(0x57)) {//w,W
			
		}
		if (GetAsyncKeyState(VK_SPACE)) {
			ball.jump();
		}
		if (current_ms() - last_time > 40) {
			ball.update(map);
			canvas.update(ball.get_x(), ball.get_y(),map.get_w(),map.get_h());
			map.draw(canvas);
			ball.draw(canvas);

			canvas.draw();
			last_time = current_ms();
		}
	}
	return 0;
}