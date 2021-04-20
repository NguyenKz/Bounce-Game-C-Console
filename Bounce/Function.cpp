#include "Function.h"
#include <windows.h>
#include<iostream>
#include <chrono>
#include <cstdint>

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x*2, y };
    SetConsoleCursorPosition(h, c);
}

void goto_c(char c, int x, int y )
{
    gotoxy(x, y);
    cout << c;
}

void goto_s(string s, int x, int y )
{
    gotoxy(x, y);
    cout << s;
}

uint64_t current_ms() {
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}