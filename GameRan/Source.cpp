#include <iostream>
#include <fstream>
#include <string>
#include "mylib.h"
#include"gameran.h"
#define UP 4
#define DOWN 28
#define LEFT 2
#define RIGHT 89
#define LEN 72
#define XUONG 80
#define TRAI 75
#define PHAI 77
#define PAUSE 112
#define SPACE 32
using namespace std;
struct Point {
	string ten;
	int diem;
};
int sl = 4, point = 0, challenge = 1, dem = 0;
string tenNguoiChoi, trangthai = "PLAY";
char menu[2][50] = { "1. Bat dau      ",
					 "2. Thoat      " };
void khoi_tao(int toadoX[], int toadoY[]);
void snake(int toadoX[], int toadoY[]);
void xu_li_ran(int toadoX[], int toadoY[], int x, int y);
void them(int a[], int x);
void xoa(int a[], int vt);
void inDS(Point DiemCao[], int& slDiemCao);
void game1(Point DiemCao[]);
void game2();
void update();
void HuongDanGame1();
void HuongDanGame2();
int main() {
	ShowCur(0); // xoa dau nhay
	inLogo();
	Point DiemCao[4];
	int chon, sum = 2;
	while (1) {
		chon = MenuDong(menu, sum);
		system("cls");
		switch (chon) {
		case 1: {
			SetBGColor(0);
			inLogo();
			gotoXY(45, 13);
			SetColor(15);
			cout << "Nhap ten nguoi choi: ";
			cin >> tenNguoiChoi;
			loadGame();
			game1(DiemCao);
			break;
		}
		case 2: {
			return 0;
		}
		}
	}
	_getch();
	return 0;
}
void game1(Point DiemCao[]) {
	int x = 45, y = 15, xcu = -100, ycu = -100;
	int slDiemCao = 0;
	int toadoX[100], toadoY[100];
	int toadoX_candy[8] = { 0 };
	int toadoY_candy[8] = { 0 };
	int check = PHAI;
	paintWALL();
	inDS(DiemCao, slDiemCao);
	update();
	khoi_tao(toadoX, toadoY);	// khởi tạo ra con rắn 
	SetColor(14);				// set màu cho con rắn
	snake(toadoX, toadoY);		// xuất hiện con rắn	
	SetColor(4);				// set màu cho candy
	randomCandy(toadoX_candy[0], toadoY_candy[0]); // sinh ngau nhien candy
	while (true) {
		checkDirection(x, y, check);
		int time;
		if (check == LEN || check == XUONG) {
			time = 150;
		}
		else time = 100;
		Sleep(time);
		if (point < 3) {
			HuongDanGame1();
			XuyenTuong(x, y);
		}
		else {
			challenge = 2;
			update();
			HuongDanGame2();
		}
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				c = _getch();
				switch (c) {
				case LEN: {
					if (check == XUONG) {
						break;
					}
					check = LEN;
					break;
				}
				case XUONG: {
					if (check == LEN) {
						break;
					}
					check = XUONG;
					break;
				}
				case TRAI: {
					if (check == PHAI) {
						break;
					}
					check = TRAI;
					break;
				}
				case PHAI: {
					if (check == TRAI) {
						break;
					}
					check = PHAI;
					break;
				}
				}
			}
			else if (c == PAUSE) {
				trangthai = "PAUSE";
				update();
				_getch();
				trangthai = "PLAY ";
				update();
			}
			else if (c == 32) {
				x = 91;
				y = 10;
				check = PHAI;
			}
		}
		xcu = toadoX[sl - 1];
		ycu = toadoY[sl - 1];
		gotoXY(xcu, ycu);
		cout << " ";
		if (point > 7) {
			xcu = toadoX[sl];
			ycu = toadoY[sl];
			gotoXY(xcu, ycu);
			cout << " ";
		}
		SetColor(14);
		xu_li_ran(toadoX, toadoY, x, y);
		if (point < 7) {
			if (x == toadoX_candy[0] && y == toadoY_candy[0]) {
				sl++;
				point++;
				SetColor(4);
				if (point < 6) {
					randomCandy(toadoX_candy[0], toadoY_candy[0]);
				}
				else if (point == 6) {
					toadoX_candy[0] = 101;
					toadoY_candy[0] = 10;
					gotoXY(toadoX_candy[0], toadoY_candy[0]);
					cout << "*";
				}
				else {
					random4Candy(toadoX_candy, toadoY_candy);
				}
				update();
			}
		}
		else {
			challenge = 3;
			if (x == toadoX_candy[0] && y == toadoY_candy[0]) {
				sl += 2;
				point += 2;
				dem++;
				x = toadoX_candy[5];
				y = toadoY_candy[5];
				thaydoiToaDoXYchall3(check, x, y);
				toadoX_candy[0] = -99;
				toadoY_candy[0] = -99;
				toadoX_candy[1] = -99;
				toadoY_candy[1] = -99;
			}
			else if (x == toadoX_candy[1] && y == toadoY_candy[1]) {
				sl += 2;
				point += 2;
				dem++;
				x = toadoX_candy[4];
				y = toadoY_candy[4];
				thaydoiToaDoXYchall3(check, x, y);
				toadoX_candy[0] = -99;
				toadoY_candy[0] = -99;
				toadoX_candy[1] = -99;
				toadoY_candy[1] = -99;
			}
			else if (x == toadoX_candy[2] && y == toadoY_candy[2]) {
				sl += 2;
				point += 2;
				dem++;
				x = toadoX_candy[7];
				y = toadoY_candy[7];
				thaydoiToaDoXYchall3(check, x, y);
				toadoX_candy[2] = -99;
				toadoY_candy[2] = -99;
				toadoX_candy[3] = -99;
				toadoY_candy[3] = -99;
			}
			else if (x == toadoX_candy[3] && y == toadoY_candy[3]) {
				sl += 2;
				point += 2;
				dem++;
				x = toadoX_candy[6];
				y = toadoY_candy[6];
				thaydoiToaDoXYchall3(check, x, y);
				toadoX_candy[2] = -99;
				toadoY_candy[2] = -99;
				toadoX_candy[3] = -99;
				toadoY_candy[3] = -99;
			}
			update();
			if (dem == 2) {
				random4Candy(toadoX_candy, toadoY_candy);
				dem = 0;
			}
		}
		if (x == 102 && y == 10) {
			x = 45;
			y = 15;
		}
		if (checkGameOver(toadoX, toadoY, sl, point)) {
			system("cls");
			SetColor(8);
			cout << "Diem cua ban: " << point;
			DiemCao[slDiemCao].ten = tenNguoiChoi;
			DiemCao[slDiemCao].diem = point;
			slDiemCao++;
			for (int i = 0; i < slDiemCao - 1; i++) {
				for (int j = i + 1; j < slDiemCao; j++) {
					if (DiemCao[i].diem < DiemCao[j].diem) {
						swap(DiemCao[i], DiemCao[j]);
					}
				}
			}
			slDiemCao--;
			ofstream out("Point.txt", ios_base::out);
			for (int i = 0; i < slDiemCao; i++) {
				out << DiemCao[i].ten << " " << DiemCao[i].diem;
				if (i < slDiemCao - 1) out << endl;
			}
			out.close();
			printGameOver();
			Sleep(1100);
			sl = 4, point = 0, challenge = 1;
			return;
		}
	}
	_getch();
}
void update() {
	SetColor(14);
	gotoXY(13, 2);
	cout << point;
	gotoXY(46, 2);
	cout << challenge;
	gotoXY(77, 2);
	cout << trangthai;
}
void khoi_tao(int toadoX[], int toadoY[]) {
	int x = 45, y = 15;
	for (int i = 0; i < sl; i++) {
		toadoX[i] = x;
		toadoY[i] = y;
		x--;
	}
}
void snake(int toadoX[], int toadoY[]) {
	for (int i = 0; i < sl; i++) {
		gotoXY(toadoX[i], toadoY[i]);
		if (i == 0) {
			cout << "@";
		}
		else cout << "o";
	}
}
void xu_li_ran(int toadoX[], int toadoY[], int x, int y) {
	// them toa do moi vao dau mang
	them(toadoX, x);
	them(toadoY, y);
	xoa(toadoX, sl - 1);
	xoa(toadoY, sl - 1);
	snake(toadoX, toadoY);
}
void them(int a[], int x) {
	for (int i = sl; i > 0; i--) {
		a[i] = a[i - 1];
	}
	a[0] = x;
	sl++;
}
void xoa(int a[], int vt) {
	for (int i = vt; i < sl; i++) {
		a[i] = a[i + 1];
	}
	sl--;
}
void inDS(Point DiemCao[], int& slDiemCao) {
	ifstream in("Point.txt", ios_base::in);
	for (int i = 0; !in.eof(); i++) {
		getline(in, DiemCao[i].ten, ' ');
		in >> DiemCao[i].diem;
		in.ignore();
		slDiemCao++;
	}
	for (int i = 0; i < slDiemCao - 1; i++) {
		for (int j = i + 1; j < slDiemCao; j++) {
			if (DiemCao[i].diem < DiemCao[j].diem) {
				swap(DiemCao[i], DiemCao[j]);
			}
		}
	}
	for (int i = 0; i < slDiemCao; i++) {
		SetColor(9);
		gotoXY(100, i + 5);
		cout << DiemCao[i].ten << ": ";
		SetColor(14);
		cout << DiemCao[i].diem << endl;
	}
	in.close();
}
void HuongDanGame1() {
	SetColor(6);
	gotoXY(97, 14);
	cout << char(30) << " LEN";
	gotoXY(97, 15);
	cout << char(31) << " XUONG";
	gotoXY(97, 16);
	cout << char(17) << " TRAI";
	gotoXY(97, 17);
	cout << char(16) << " PHAI";
	gotoXY(97, 18);
	cout << "P pause";
	gotoXY(97, 19);
	cout << "LUU Y: Co the ";
	gotoXY(97, 20);
	cout << "xuyen tuong.";
}
void HuongDanGame2() {
	SetColor(6);
	gotoXY(97, 14);
	cout << char(30) << " LEN";
	gotoXY(97, 15);
	cout << char(31) << " XUONG";
	gotoXY(97, 16);
	cout << char(17) << " TRAI";
	gotoXY(97, 17);
	cout << char(16) << " PHAI";
	gotoXY(97, 18);
	cout << "P pause";
	gotoXY(97, 19);
	cout << "LUU Y: Khong the ";
	gotoXY(97, 20);
	cout << "xuyen tuong.";
	gotoXY(97, 21);
	cout << "Neu kho khan";
	gotoXY(97, 22);
	cout << "Hay dung""space""";
}