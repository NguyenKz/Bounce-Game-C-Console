#pragma once
#include<string>
#include<iostream>
using namespace std;
/// <summary>
/// Gotoxy
/// </summary>
/// <param name="x">x</param>
/// <param name="y">y</param>
extern void gotoxy(int, int); 
/// <summary>
/// gotoxy and print char
/// </summary>
/// <param name="c">char to print</param>
/// <param name="x">x</param>
/// <param name="y">y</param>
extern void goto_c(char, int, int);
/// <summary>
/// gotoxy and print string
/// </summary>
/// <param name="s"> string to print</param>
/// <param name="x">x</param>
/// <param name="y">y</param>
extern void goto_s(string,int, int);

/// <summary>
/// get current ms
/// </summary>
extern uint64_t current_ms();