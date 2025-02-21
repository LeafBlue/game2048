#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include <conio.h>
#include<utility>
#include<thread>
#include<chrono>


void initdata();
void initflag();
void showpage();
string setelement(int& elem);
void getkeyboard();
void showscore();
void keyfunc(int& inbtn, int** myarr);
string setcolor(int elem);
pair<int, int> getlastIndex(int& indexX, int& indexY, int& keydown);
void insertdata();
bool isdie();

int pc_play();

void re_copy();
int getscore(int** temp);


