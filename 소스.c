#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
int monster = 0;
int used = 0;
int Heal = 100;
int AtkC = 100;
int HpC = 100;
int DefC = 100;
int CrtC = 100;
int vil2 = 1;
char key2;
int stop = 0;
int Gold = 10000000;
int Hp = 100;
int NHp = 100;
int Atk = 5;
int Def = 0;
int Crt = 0;
void gotoxy(int x, int y) {

	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}
int map[60][19] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}
};
int player[3][4] = {
	{0,3,0,3,},
	{1,2,2,0,},
	{0,4,0,4,}
};
int start[60][19] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
int encounter = 0;
int pos = 0;
void dog() {
	int z = 38, c = 13;
	int key;
	while (1) {
		system("cls");
		gotoxy(46, 5);
		printf(" 야생의 개를 발견했다.");
		gotoxy(40, 13);
		printf("싸운다                           도망친다");
		gotoxy(z, c);
		printf("☞");
		key = _getch();
		switch (key) {
		case 75:
			if (z <= 50) break;
			z -= 33;
			break;
		case 77:
			if (z >= 50) break;
			z += 33;
			break;
		default:
			break;
		}
		if (GetAsyncKeyState(VK_SPACE)) {

			if (z <= 50) {
			}
			else if (z >= 50) {
				break;
			}
		}
	}
}
void slime() {}
void frug() {}
void goat() {}
void bat() {}
void lizard() {}
void ork() {}
void imp() {}
void undead() {}
void deathknight() {}
void dragonfly() {}
void dragon() {}
void satan() {}
void demon() {}
void deathking() {}
void GOD() {}
void lastboss() {}





void serch() {
	int z = 38, c = 13;
	int key;
	while (1) {
		system("cls");
		switch (monster) {
		case 0:
			gotoxy(46, 5);
			printf(" 야생의 개를 발견했다.");
			break;
		case 1:
			gotoxy(46, 5);
			printf(" 야생의 슬라임을 발견했다.");
			break;
		case 2:
			gotoxy(46, 5);
			printf(" 야생의 개구리를 발견했다.");
			break;
		case 3:
			gotoxy(46, 5);
			printf(" 야생의 염소를 발견했다.");
			break;
		case 4:
			gotoxy(46, 5);
			printf(" 야생의 박쥐를 발견했다.");
			break;
		case 5:
			gotoxy(46, 5);
			printf(" 야생의 도마뱀을 발견했다.");
			break;
		case 6:
			gotoxy(46, 5);
			printf(" 야생의 오크를 발견했다.");
			break;
		case 7:
			gotoxy(46, 5);
			printf(" 야생의 임프를 발견했다.");
			break;
		case 8:
			gotoxy(46, 5);
			printf(" 야생의 좀비를 발견했다.");
			break;
		case 9:
			gotoxy(46, 5);
			printf(" 야생의 죽음의 기사를 발견했다.");
			break;
		case 10:
			gotoxy(46, 5);
			printf(" 야생의 용파리를 발견했다.");
			break;
		case 11:
			gotoxy(46, 5);
			printf(" 야생의 드래곤을 발견했다.");
			break;
		case 12:
			gotoxy(46, 5);
			printf(" 야생의 사탄을 발견했다.");
			break;
		case 13:
			gotoxy(46, 5);
			printf(" 야생의 악마를 발견했다.");
			break;
		case 14:
			gotoxy(46, 5);
			printf(" 야생의 사왕을 발견했다.");
			break;
		case 15:
			gotoxy(46, 5);
			printf(" 야생의 신을 발견했다.");
			break;
		case 16:
			gotoxy(46, 5);
			printf(" 야생의 최종보스를 발견했다.");
			break;

		}
		gotoxy(40, 13);
		printf("싸운다                           도망친다");
		gotoxy(z, c);
		printf("☞");
		key = _getch();
		switch (key) {
		case 75:
			if (z <= 50) break;
			z -= 33;
			break;
		case 77:
			if (z >= 50) break;
			z += 33;
			break;
		default:
			break;
		}
		if (GetAsyncKeyState(VK_SPACE)) {

			if (z <= 50) {
			}
			else if (z >= 50) {
				break;
			}
		}
	}
}
void startm() {
	int key;
	int z = 38, c = 10;
	while (1) {
		
		system("mode con cols=120 lines=40");
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 60; j++) {
				if (start[j][i] == 0) printf("  ");
				else if (start[j][i] == 1) printf("■");
				else if (start[j][i] == 2) printf("몬");
				else if (start[j][i] == 3) printf("스");
				else if (start[j][i] == 4) printf("터");
				else if (start[j][i] == 5) printf("헌");
				else if (start[j][i] == 6) printf("터");
				else if (start[j][i] == 7) printf("★");
			}
			printf("\n");		
		}
		gotoxy(40, 10);
		printf("플레이                           종료");
		if (z <= 50) {
			gotoxy(48, 17);
			printf("press space to start");
		}
		else if (z >= 50) {
			gotoxy(49, 17);
			printf("press space to end");
		}
		gotoxy(z, c);
		printf("☞");
		key = _getch();
		
		switch (key) {
		case 75:
			if (z <= 50) break;
			z -= 33;
			break;
		case 77:
			if (z >= 50) break;
			z += 33;
			break;
		default:
			break;
		}
		system("cls");
		if (GetAsyncKeyState(VK_SPACE)) {
			if (z <= 50) {
				stop = 2;
				break;
			}
			else if (z >= 50) {
				stop = 1;
				break;
			}
		}
	}
	

}
void battle() {
	encounter = 0;
	int bravo = 32767;
	srand((unsigned int)time(NULL));
	system("cls");
	while (1) {
		
		pos = rand();
		
		if (pos < used / 125 - bravo) {
			monster = 16;
			serch();
			break;
		}
		else if (pos < used / 62 - bravo) {
			monster = 15;
			serch();
			break;
		}
		else if (pos < used / 31 - bravo) {
			monster = 14;
			serch();
			break;
		}
		else if (pos < used / 15 - bravo) {
			monster = 13;
			serch();
			break;
		}
		else if (pos < used / 7 - bravo) {
			monster = 12;
			serch();
			break;
		}
		else if (pos < used / 2 - bravo) {
			monster = 11;
			serch();
			break;
		}
		else if (pos < used * 2 - bravo) {
			monster = 10;
			serch();
			break;
		}
		else if (pos < used * 7 - bravo) {
			monster = 9;
			serch();
			break;
		}
		else if (pos < used * 15 - bravo) {
			monster = 8;
			serch();
			break;
		}
		else if (pos < used * 31 - bravo) {
			monster = 7;
			serch();
			break;
		}
		else if (pos < used * 62 - bravo) {
			monster = 6;
			serch();
			break;
		}
		else if (pos < used * 125 - bravo) {
			monster = 5;
			serch();
			break;
		}
		else if (pos < used * 250 - bravo) {
			monster = 4;
			serch();
			break;
		}
		else if (pos < used * 500 - bravo) {
			monster = 3;
			serch();
			break;
		}
		else if (pos < used * 1000 - bravo) {
			monster = 2;
			serch();
			break;
		}
		else if (pos < used * 2000 - bravo) {
			monster = 1;
			serch();
			break;
		}
		else if (used == 0) {
			serch();
			break;
		}

	}
}
void shop(){
	int key;
	int z = 33, c = 10;

	while (1) {
		system("mode con cols=120 lines=40");
		system("cls");
		if (z == 33) {
			gotoxy(46, 16);
			printf("가격 : %d. 체력을 전부 회복한다", Heal);
		}
		else if (z == 44) {
			gotoxy(48, 16);
			printf("가격 : %d. 공격력 2 증가", AtkC);
		}
		else if (z == 55) {
			gotoxy(48, 16);
			printf("가격 : %d. 체력 10 증가", HpC);
		}
		else if (z == 66) {
			gotoxy(48, 16);
			printf("가격 : %d. 방어력 1 증가", DefC);
		}
		else if (z == 77) {
			gotoxy(46, 16);
			printf("가격 : %d. 치명타 확률 1% 증가", CrtC);
		}
		else if (z == 88) {
			gotoxy(58, 16);
			printf("나가기");
		}
		gotoxy(58, 5);
		printf("상점\n\n            보유 골드 : %d", Gold);
		gotoxy(35, 10);
		printf("회복       공격력     체력       방어력     치명확률   돌아가기");
		gotoxy(z, c);
		printf("☞");
		key = _getch();

		switch (key) {
		case 75:
			if (z == 33) break;
			z -= 11;
			break;
		case 77:
			if (z == 88) break;
			z += 11;
			break;
		default:
			break;
		}
		if (GetAsyncKeyState(VK_SPACE)) {
			Sleep(100);
			if (z == 33) {
				if (Gold > Heal)
					Gold -= Heal;
					Heal += Heal;
					NHp = Hp;
					used += Heal;
			}
			else if (z == 44) {
				if (Gold > AtkC) {
					Gold -= AtkC;
					AtkC += AtkC;
					Atk += 10;
					used += AtkC;
				}
			}
			else if (z == 55) {
				if (Gold > HpC) {
					Gold -= HpC;
					HpC += HpC;
					Hp += 100;
					NHp += 10;
					used += HpC;
				}
			}
			else if (z == 66) {
				if (Gold > DefC) {
					Gold -= DefC;
					DefC += DefC;
					Def += 5;
					used += DefC;
				}
			}
			else if (z == 77) {
				if (Gold > CrtC) {
					Gold -= CrtC;
					CrtC += CrtC;
					Crt += 10;
					used += CrtC;
				}
			}
			else if (z == 88) break;
		}
		
	}

}
void state(){
	int key;
	while (1) {

		system("mode con cols=120 lines=40");
		
		stop = 2;
		system("cls");
		printf("            Player\n\n\n");
		printf("체력 : %d / %d\n", Hp, NHp);
		printf("공격력 : %d\n", Atk);
		printf("방어력 : %d\n", Def);
		printf("치명타 확률 : %d%\n", Crt);
		printf("보유 골드 : %d%\n", Gold);
		key = _getch();
		switch (key){
		default:
			break;
		}
		if (GetAsyncKeyState(VK_SPACE)) {
			Sleep(100);
			break;
		}
		
	}
}
void vil() {
	int key;
	int z = 38, c = 10;

	while (1) {
		system("mode con cols=120 lines=40");
		system("cls");
		gotoxy(58, 5);
		printf("마을");
		gotoxy(40, 10);
		printf("상점       스탯       사냥터     종료");
		gotoxy(z, c);
		printf("☞");
		key = _getch();

		switch (key) {
		case 75:
			if (z <= 38) break;
			z -= 11;
			break;
		case 77:
			if (z >= 65) break;
			z += 11;
			break;
		default:
			break;
		}
		if (GetAsyncKeyState(VK_SPACE)) {
			Sleep(100);
			if (z <= 38) shop();
			else if (z > 38 && z <= 49) state();
			else if (z > 49 && z < 65) break;
			else if (z >= 65) {
				stop = 1;
				break;
			}
		}
	}
}
void back() {
	int key;
	int z = 38, c = 10;
	
	while (1) {
		system("mode con cols=120 lines=40");
		system("cls");
		gotoxy(46, 5);
		printf("마을로 돌아가시겠습니까?");
		gotoxy(40, 10);
		printf("예                               아니요");
		gotoxy(z, c);
		printf("☞");
		key = _getch();

		switch (key) {
		case 75:
			if (z <= 50) break;
			z -= 33;
			break;
		case 77:
			if (z >= 50) break;
			z += 33;
			break;
		default:
			break;
		}
		if (GetAsyncKeyState(VK_SPACE)) {
			
			if (z <= 50) {
				vil2 = 2;
				vil();
			}
			else if (z >= 50) {
				break;
			}
		}
		if (vil2 == 2) {
			vil2 = 1;
			break;
		}
	}
}
void maps() {
	int key;
	int x = 0, y = 14;
	encounter = 0;
	srand((unsigned int)time(NULL));
	while (1) {
		
		system("mode con cols=120 lines=40");
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 60; j++) {
				if (map[j][i] == 0) printf("  ");
				else if (map[j][i] == 1) printf("■");

			}
			printf("\n");
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				gotoxy(x + j * 2, y + i);
				if (player[j][i] == 0) printf("  ");
				else if (player[j][i] == 1) printf("○");
				else if (player[j][i] == 2) printf("▽");
				else if (player[j][i] == 3) printf("↗");
				else if (player[j][i] == 4) printf("↖");
			}
		}

		key = _getch();
		switch (key) {
		case 75:
			if (x / 2 - 1 == -1) {
				back();
				break;
			}
			x -= 2;
			encounter++;
			break;
		case 77:
			if (x / 2 + 1 == 57) {
				back();
				break;
			}
			x += 2;
			encounter++;
			break;
		default:
			break;
		}
		pos = rand() % 500 + 1;
		if (pos < encounter) battle();
		system("cls");
		if (stop == 1)break;
	}
}



int main() {
	while (1) {
		if (stop == 0) startm();
		if (stop == 1) return 0;
		maps();









		
	}

	return 0;
}