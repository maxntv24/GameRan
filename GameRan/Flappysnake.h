#pragma once
#include<iostream>
#include "mylib.h"
using namespace std;
void paintWALL2() {
	SetColor(2);
	system("cls");
	for (int i = 1; i <= 90; i++) {
		gotoXY(i, 1);
		cout << char(220);
		gotoXY(i, 21);
		cout << char(223);
	}
	for (int i = 2; i <= 20 i++) {
		gotoXY(1, i);
		cout << char(219);
		gotoXY(90, i);
		cout << char(219);
	}
	/*for (int i = 95; i <= 115; i++) {
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
	}*/
	//gotoXY(6, 2);
	//SetColor(9);
	//cout << "Point: ";
	//gotoXY(35, 2);
	//cout << "Challenge: ";
	//gotoXY(65, 2);
	//cout << "Trang thai: ";
	//gotoXY(103, 2);
	//cout << "TOP 3";
	//gotoXY(101, 12);//101,12
	//cout << "HUONG DAN";
}