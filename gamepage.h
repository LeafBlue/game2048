#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include <conio.h>
#include<utility>


void initdata();
void initflag();
void showpage();
string setelement(int& elem);
void getkeyboard();
void keyfunc(int& inbtn);
string setcolor(int elem);
pair<int, int> getlastIndex(int& indexX, int& indexY, int& keydown);
void insertdata();
bool isdie();
