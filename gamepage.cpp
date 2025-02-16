#include"gamepage.h"


int arr[4][4];
int _flag[4][4];
bool getkey =true;


void initflag() {
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
			keyfunc(ch);
		}
	}
}




void keyfunc(int& inbtn) {
	for (int i = 0; i < 3; i++) {
		for (int indexY = 0;indexY < 4;indexY++) {
			for (int indexX = 0;indexX < 4;indexX++) {
				pair<int, int> p = getlastIndex(indexX, indexY, inbtn);
				if (arr[p.first][p.second] == arr[indexY][indexX] && arr[indexY][indexX] != 0) {
					if (p.first != indexY || p.second != indexX) {
						if (_flag[p.first][p.second] == 0 && _flag[indexY][indexX] == 0) {

							arr[p.first][p.second] = (arr[indexY][indexX]) * 2;
							arr[indexY][indexX] = 0;

							_flag[p.first][p.second] = 1;
							_flag[indexY][indexX] = 1;
						}
						
					}
				}
				else if (arr[p.first][p.second] == 0) {
					arr[p.first][p.second] = arr[indexY][indexX];
					arr[indexY][indexX] = 0;
				}
			}
		}
	}
	if (isdie()) {
		//游戏结束
		getkey = false;
		cout << "游戏失败" << endl;
		return;
	}
	initflag();
	showpage();
	insertdata();
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