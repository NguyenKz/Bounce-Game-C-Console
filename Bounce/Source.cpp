#include<conio.h>

#include"_Canvas.h"
#include"Ball.h"
#include <windows.h>
using namespace std;

int main() {
	_Canvas canvas(20, 20);
	Ball ball;
	bool is_running = true;

	int x = 10;
	int y = 10;
	while (is_running) {
		int key = 0;
		if (_kbhit()) {
			key = _getch();
		}
		switch (key)
		{
		case 27://esc
			is_running = false;
			
			break;
		case 'a':case'A':
			canvas.draw_char('.', x, y);
			x--;
			break;
		case 's':case'S':
			canvas.draw_char('.', x, y);
			y++;
			break;
		case 'd':case'D':
			canvas.draw_char('.', x, y);
			x++;
			break;
		case 'w':case'W':
			canvas.draw_char('.', x, y);
			y--;
			break;
		case ' ':
			ball.jump();
			break;
		default:
			break;
		}
		ball.update();
		ball.draw(canvas);
		canvas.draw_char('O', x, y);
		canvas.draw();
		Sleep(10);
	}
	return 0;
}