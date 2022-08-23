#pragma once
#include "mylib.h"
#define UP 4
#define DOWN 28
#define LEFT 2
#define RIGHT 89
#define LEN 72
#define XUONG 80
#define TRAI 75
#define PHAI 77
using namespace std;
void XuyenTuong(int& x, int& y) {
	if (y == DOWN + 1) {
		y = UP;
	}
	if (y == UP - 1) {
		y = DOWN;
	}
	if (x == LEFT - 1) {
		x = RIGHT;
	}
	if (x == RIGHT + 1) {
		x = LEFT;
	}
}
void checkDirection(int& x, int& y, int check) {
	if (check == LEN) {
		y--;
	}
	if (check == XUONG) {
		y++;
	}
	if (check == TRAI) {
		x--;
	}
	if (check == PHAI) {
		x++;
	}
}
void randomCandy(int& x, int& y) {
	srand(time(NULL));
	x = (rand() % (RIGHT - LEFT + 1)) + LEFT;
	y = (rand() % (UP - DOWN + 1)) + UP;
	gotoXY(x, y);
	cout << "*";
}
void paintWALL() {
	SetColor(2);
	system("cls");
	for (int i = 1; i <= 90; i++) {
		gotoXY(i, 1);
		cout << char(220);
		gotoXY(i, 3);
		cout << char(220);
		gotoXY(i, 29);
		cout << char(223);
	}
	for (int i = 2; i <= 28; i++) {
		gotoXY(1, i);
		cout << char(219);
		gotoXY(90, i);
		cout << char(219);
	}
	for (int i = 95; i <= 115; i++) {
		gotoXY(i, 1);
		cout << char(220);
		gotoXY(i, 3);
		cout << char(220);
		gotoXY(i, 9);
		cout << char(223);
	}
	for (int i = 2; i <= 8; i++) {
		gotoXY(95, i);
		cout << char(219);
		gotoXY(115, i);
		cout << char(219);
	}
	for (int i = 95; i <= 115; i++) {
		gotoXY(i, 11);
		cout << char(220);
		gotoXY(i, 13);
		cout << char(220);
		gotoXY(i, 29);
		cout << char(223);
	}
	for (int i = 12; i <= 28; i++) {
		gotoXY(95, i);
		cout << char(219);
		gotoXY(115, i);
		cout << char(219);
	}
	gotoXY(6, 2);
	SetColor(9);
	cout << "Point: ";
	gotoXY(35, 2);
	cout << "Challenge: ";
	gotoXY(65, 2);
	cout << "Trang thai: ";
	gotoXY(103, 2);
	cout << "TOP 3";
	gotoXY(101, 12);//101,12
	cout << "HUONG DAN";
}
bool checkGameOver(int a[], int b[], int sl, int point) {
	if (point >= 3) {
		if (a[0] == LEFT - 1 || a[0] == RIGHT + 1 || b[0] == UP - 1 || b[0] == DOWN + 1) {
			return true;
		}
	}
	for (int i = 1; i < sl; i++) {
		if (a[0] == a[i] && b[0] == b[i]) return true;
	}
	return false;
}
void printGameOver() {
	SetColor(14);
	gotoXY(0, 10);
	cout << "\t\t/////////     //\\\\      ||\\\\    //||  ////////     ||||||||  \\\\        // ////////  ||\\\\\\\\\\\\" << endl;
	cout << "\t\t//           //  \\\\     || \\\\  // ||  //           ||    ||   \\\\      //  //        ||    \\\\" << endl;
	cout << "\t\t//  /////   ////\\\\\\\\    ||  \\\\//  ||  ////////     ||    ||    \\\\    //   ////////  ||\\\\\\\\\\\\" << endl;
	cout << "\t\t//    //   //      \\\\   ||        ||  //           ||    ||     \\\\  //    //        ||    \\\\" << endl;
	cout << "\t\t///////   //        \\\\  ||        ||  ////////     ||||||||      \\\\//     ////////  ||     \\\\" << endl;
}
void color() {
	for (int i = 1; i <= 16; i++) {
		SetColor(i);
		cout << i << ".Max dep trai" << endl;
	}
}
void Normal() {
	SetColor(14);
}
void HighLight() {
	SetColor(1);
	SetBGColor(6);
}
void inLogo() {
	SetColor(12);
	SetBGColor(0);
	gotoXY(38, 5);
	cout << "SSSSSS  NN    N      A      K   K   EEEEEE" << endl;
	gotoXY(38, 6);
	cout << "S       N N   N     A A     K  K    E" << endl;
	gotoXY(38, 7);
	cout << "SSSSSS  N  N  N    AAAAA    KKK     EEEEEE" << endl;
	gotoXY(38, 8);
	cout << "     S  N   N N   A     A   K  K    E" << endl;
	gotoXY(38, 9);
	cout << "SSSSSS  N    NN  A       A  K   K   EEEEEE" << endl;
}
int MenuDong(char td[][50], int sum) {
	Normal();
	int dong = 15;
	int cot = 50;
	system("cls");   int chon = 0;
	int i;
	for (i = 0; i < sum; i++)
	{
		gotoXY(cot, dong + i);
		cout << td[i];
	}
	HighLight();
	gotoXY(cot, dong + chon);
	cout << td[chon];
	char kytu;
	while (1) {
		inLogo();
		kytu = _getch();
		if (kytu == 0) kytu = _getch();
		switch (kytu) {
		case LEN:if (chon + 1 > 1)
		{
			Normal();
			gotoXY(cot, dong + chon);
			cout << td[chon];
			chon--;
			HighLight();
			gotoXY(cot, dong + chon);
			cout << td[chon];

		}
				break;
		case XUONG:if (chon + 1 < sum)
		{
			Normal();
			gotoXY(cot, dong + chon);
			cout << td[chon];
			chon++;
			HighLight();
			gotoXY(cot, dong + chon);
			cout << td[chon];

		}
				  break;
		case 13: return chon + 1;
		}  // end switch
	}
}
void loadGame() {
	SetColor(4);
	for (int i = 40; i <= 80; i++) {
		gotoXY(i, 15);
		cout << char(220);
		gotoXY(i, 17);
		cout << char(223);
	}
	gotoXY(40, 16);
	cout << char(219);
	gotoXY(80, 16);
	cout << char(219);
	for (int i = 41; i < 79; i++) {
		gotoXY(i, 16);
		cout << char(16);
		Sleep(50);
	}
}
void random4Candy(int x[], int y[]) {
	srand(time(NULL));
	for (int i = 0; i < 4;) {
		x[i] = (rand() % (RIGHT - LEFT + 1)) + LEFT;
		y[i] = (rand() % (UP - DOWN + 1)) + UP;
		int k = i;
		bool flag = true;
		while (k--) {
			if (x[i] == x[k] && y[i] == y[k]) {
				flag = false;
			}
		}
		if (flag) {
			i++;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (i < 2) {
			SetColor(11);
		}
		else SetColor(13);
		gotoXY(x[i], y[i]);
		cout << "*";
		x[i + 4] = x[i];
		y[i + 4] = y[i];
	}
}
void thaydoiToaDoXYchall3(int check, int& x, int& y) {
	if (check == LEN) {
		y++;
	}
	else if (check == XUONG) {
		y--;
	}
	else if (check == TRAI) {
		x++;
	}
	else if (check == PHAI) {
		x--;
	}
}

