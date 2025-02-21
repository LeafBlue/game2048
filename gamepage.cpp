#include"gamepage.h"


int** arr;
int** _flag;
int** temp;
bool getkey =true;
int score = 0;

void initflag() {
	_flag = new int*[4];
	for (size_t i = 0; i < 4; i++)
	{
		_flag[i] = new int[4];
	}
	_flag[0][0] = 0;	_flag[0][1] = 0;	_flag[0][2] = 0;	_flag[0][3] = 0;
	_flag[1][0] = 0;	_flag[1][1] = 0;	_flag[1][2] = 0;	_flag[1][3] = 0;
	_flag[2][0] = 0;	_flag[2][1] = 0;	_flag[2][2] = 0;	_flag[2][3] = 0;
	_flag[3][0] = 0;	_flag[3][1] = 0;	_flag[3][2] = 0;	_flag[3][3] = 0;
}

//根据数组展示界面
void showpage() {
	system("cls");
	cout << endl;
	cout << "\t" << "|-----|-----|-----|-----|" << endl;
	cout << "\t" << "|"<<setelement(arr[0][0]) << "|" << setelement(arr[0][1]) << "|" << setelement(arr[0][2]) << "|" << setelement(arr[0][3]) << "|" << endl;
	cout << "\t" << "|-----|-----|-----|-----|" << endl;
	cout << "\t" << "|" << setelement(arr[1][0]) << "|" << setelement(arr[1][1]) << "|" << setelement(arr[1][2]) << "|" << setelement(arr[1][3]) << "|" << endl;
	cout << "\t" << "|-----|-----|-----|-----|" << endl;
	cout << "\t" << "|" << setelement(arr[2][0]) << "|" << setelement(arr[2][1]) << "|" << setelement(arr[2][2]) << "|" << setelement(arr[2][3]) << "|" << endl;
	cout << "\t" << "|-----|-----|-----|-----|" << endl;
	cout << "\t" << "|" << setelement(arr[3][0]) << "|" << setelement(arr[3][1]) << "|" << setelement(arr[3][2]) << "|" << setelement(arr[3][3]) << "|" << endl;
	cout << "\t" << "|-----|-----|-----|-----|" << endl;

	showscore();
}

void showscore() {
	cout << "当前得分：" << score << endl;
}

string setelement(int &elem) {
	if (elem == 0) {
		return "     ";
	}
	if (elem >0 && elem < 10) {
		return "  " + setcolor(elem) + to_string(elem) + setcolor(-1) + "  ";
	}
	else if (elem > 9 && elem < 100) {
		return "  " + setcolor(elem) + to_string(elem) + setcolor(-1) + " ";
	}
	else if(elem > 99 && elem < 1000){
		return " " + setcolor(elem) + to_string(elem) + setcolor(-1) + " ";
	}
	else {
		return "" + setcolor(elem) + to_string(elem) + setcolor(-1) + " ";
	}
}

string setcolor(int elem) {
	if (elem == -1) {return "\033[0m";}
	else if (elem == 2) { return "\033[1m\033[33m"; }
	else if (elem == 4) { return "\033[2m\033[33m"; }
	else if (elem == 8) { return "\033[1m\033[32m"; }
	else if (elem == 16) {  return "\033[2m\033[32m";  }
	else if (elem == 32) {  return "\033[1m\033[36m";  }
	else if (elem == 64) {  return "\033[2m\033[36m";  }
	else if (elem == 128) {  return "\033[1m\033[34m";  }
	else if (elem == 256) {  return "\033[2m\033[34m";  }
	else if (elem == 512) {  return "\033[1m\033[32m";  }
	else if (elem == 1024) {  return "\033[2m\033[32m";  }
	else if (elem == 2048) {  return "\033[1m\033[31m";  }
}

//初始化数组
void initdata() {
	arr = new int* [4];
	for (size_t i = 0; i < 4; i++)
	{
		arr[i] = new int[4];
	}
	arr[0][0] = 2;	arr[0][1] = 4;	arr[0][2] = 0;	arr[0][3] = 0;
	arr[1][0] = 0;	arr[1][1] = 0;	arr[1][2] = 0;	arr[1][3] = 0;
	arr[2][0] = 0;	arr[2][1] = 0;	arr[2][2] = 0;	arr[2][3] = 0;
	arr[3][0] = 0;	arr[3][1] = 0;	arr[3][2] = 0;	arr[3][3] = 0;
	showpage();
}

void getkeyboard() {
	
	while (getkey) {
		if (_kbhit()) {
			int ch = _getch();//使用_getch()函数获取按下的键值
			if (ch == 97 || ch == 100 || ch == 115 || ch == 119) {
				keyfunc(ch,arr);
				showpage();
				insertdata();
				if (isdie()) {
					//游戏结束
					getkey = false;
					cout << "游戏失败" << endl;
					return;
				}
			}
			if (ch == 101) {
				int data = pc_play();
				if (data == -1) {
					//游戏结束
					getkey = false;
					cout << "游戏失败" << endl;
					return;
				}
			}
		}
	}
}




void keyfunc(int& inbtn, int** myarr) {
	for (int i = 0; i < 3; i++) {
		for (int indexY = 0;indexY < 4;indexY++) {
			for (int indexX = 0;indexX < 4;indexX++) {
				pair<int, int> p = getlastIndex(indexX, indexY, inbtn);
				if (myarr[p.first][p.second] == myarr[indexY][indexX] && myarr[indexY][indexX] != 0) {
					if (p.first != indexY || p.second != indexX) {
						if (_flag[p.first][p.second] == 0 && _flag[indexY][indexX] == 0) {
							int end = (myarr[indexY][indexX]) * 2;
							myarr[p.first][p.second] = end;
							myarr[indexY][indexX] = 0;

							_flag[p.first][p.second] = 1;
							_flag[indexY][indexX] = 1;

							score = score + end;
						}
						
					}
				}
				else if (myarr[p.first][p.second] == 0) {
					myarr[p.first][p.second] = myarr[indexY][indexX];
					myarr[indexY][indexX] = 0;
				}
			}
		}
	}
	initflag();
}



pair<int,int> getlastIndex(int &indexX, int &indexY,int &keydown) {
	pair<int, int> p;
	p.first = indexY;
	p.second = indexX;
	if (keydown == 119) {
		if (indexY>0) {
			p.first = indexY - 1;
		}
	}
	else if (keydown == 115) {
		if (indexY < 3) {
			p.first = indexY + 1;
		}
	}
	else if (keydown == 97) {
		if (indexX > 0) {
			p.second = indexX - 1;
		}
	}
	else if (keydown == 100) {
		if (indexX < 3) {
			p.second = indexX + 1;
		}
	}
	return p;
}


void insertdata() {
	
	int insertdata = 2;
	int randnum = rand() % 100 + 1;
	if (randnum < 14) {
		insertdata = 4;
	}
	vector<pair<int, int>> v;
	for (int y = 0;y < 4;y++) {
		for (int x = 0;x < 4;x++) {
			if (arr[y][x] == 0) {
				pair<int, int> p;
				p.first = y;	p.second = x;
				v.push_back(p);
			}
		}
	}
	if (v.size() > 0) {
		int rand1 = rand() % v.size();
		pair<int, int> p1 = v.at(rand1);
		arr[p1.first][p1.second] = insertdata;
	}
	

	showpage();
}

bool isdie() {
	bool die = true;
	for (int y = 0;y < 4;y++) {
		for (int x = 0; x < 4;x++) {
			int this_data = arr[y][x];
			if (this_data == 0) {
				die = false;
			}
			else {
				if (y > 0 && this_data == arr[y-1][x]) {
					die = false;
				}
				if (y < 3 && this_data == arr[y+1][x]) {
					die = false;
				}
				if (x > 0 && this_data == arr[y][x-1]) {
					die = false;
				}
				if (x < 3 && this_data == arr[y][x+1]) {
					die = false;
				}
			}
		}
	}
	return die;
}



//尝试添加自动玩
//每间隔一秒执行一遍自身
int pc_play() {
	while (true) {
		int score = 0;
		int bigstair = 0;
		int btn_s[4] = { 119,115,97,100 };
		for (size_t i = 0; i < 4; i++)
		{
			//每次循环重新复制棋盘到temp
			re_copy();
			//依次模拟移动
			keyfunc(btn_s[i], temp);
			//计算当前模拟得分
			int tempscore = getscore(temp);
			//重新设置score
			if (tempscore > score) {
				score = tempscore;
				bigstair = btn_s[i];
			}
		}

		//执行移动
		keyfunc(bigstair, arr);
		//展示棋盘并添加新的数字
		showpage();
		insertdata();
		if (isdie()) {
			//游戏结束
			return -1;
		}

		//等待一秒
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}


void re_copy() {
	temp = new int* [4];
	for (size_t i = 0; i < 4; i++)
	{
		temp[i] = new int[4];
		for (size_t j = 0; j < 4; j++)
		{
			temp[i][j] = arr[i][j];
		}
	}
}

int getscore(int** temp) {
	//这两者需要同时兼顾，设置因子给他们分配权重
	//在棋盘空位较多时，注重合并，棋盘空位较少时，注重增加空位
	//空位数量，代表棋盘灵活性
	int zerodata = 0;
	//可合并数量，代表得分潜力
	int adddata = 0;
	//水平和垂直检查
	for (size_t i = 0; i < 4; i++)
	{
		int flag1 = -1;
		int flag2 = -1;
		for (size_t j = 0; j < 4; j++)
		{
			//水平检查
			if (temp[i][j] == 0) {
				zerodata = zerodata + 10;
			}
			else if (temp[i][j] == flag1) {
				flag1 = -1;
				adddata = adddata + 10;
			}
			else {
				flag1 = temp[i][j];
			}
			//垂直检查
			if (temp[j][i] == 0) {
				zerodata = zerodata + 10;
			}
			else if (temp[j][i] == flag2) {
				flag2 = -1;
				adddata = adddata + 10;
			}
			else {
				flag2 = temp[j][i];
			}
		}
	}

	//根据得分设置计算因子
	int zerofactor = 1;
	int addfactor = 2;

	//当空位小于等于5时，注重增加空位
	if (zerodata < 60) {
		zerofactor = 2;
		addfactor = 1;
	}

	int finalscore = zerodata * zerofactor + adddata * addfactor;
	return finalscore;
}
