#pragma comment(lib, "user32")
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <windef.h>
int speed = 0;
int boss = 0;
int up = 0;
int skillon = 0;
int skillrand = 0;
int skill1 = 0;
int skill2 = 0;
int skill3 = 0;
int skill4 = 0;
int skill5 = 0;
int effcet = 0;
int bar = 0;
int z = 0;
int crecrt = 0;
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
int Gold = 0;
int Hp = 100;
int NHp = 100;
int Atk = 5;
int Def = 0;
int Crt = 0;
void CursorView() {
	HANDLE consolHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = 0;
	SetConsoleCursorInfo(consolHandle , &cursorInfo);
}
void gotoxy(int x, int y) {

	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

int map[60][2] = {
	{2,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{0,1},
	{3,1}
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
void Load_Text(const char* text) 
{
	FILE* file = fopen(text, "r");
	char buffer[10000] = { 0, };
	fread(buffer, 1, 10000, file); 
	printf("%s", buffer);
	fclose(file);
}
void LASTBOSSBATTLE() {
	int core[400];
	int x = 0, y = 24;
	int i = 0, a = 0;
	int sx[400];
	int sy[400];
	encounter = 0;
	srand((unsigned int)time(NULL));
	system("cls");
	for (int j = 0; j < 400; j++) {
		core[j] = 1;
	}
	
	while (1) {
		
		Sleep(50 - speed);
		
		for (i = a; i < a + 5; i++) {
			sx[i] = rand() % 60 + 1;
			sy[i] = 0;
		}
		a = i;
		if (a == 400) break;
		
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				if (j == 0) {
					gotoxy(x - 2, y + i);
					printf("  ");
				}
				else if (j == 2) {
					gotoxy(x + j * 2 + 2, y + i);
					printf("  ");
				}
				gotoxy(x + j * 2, y + i);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				if (player[j][i] == 0) printf("  ");
				else if (player[j][i] == 1) printf("��");
				else if (player[j][i] == 2) printf("��");
				else if (player[j][i] == 3) printf("��");
				else if (player[j][i] == 4) printf("��");
			}
		}
		for (int j = 0; j < a; j++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			if (core[j] == 1) {
				gotoxy(sx[j] * 2, sy[j] - 1);
				printf("  ");
				gotoxy(sx[j] * 2, sy[j]);
				printf("��");
				sy[j]++;
			}
			if (sy[j] > 29) {
				gotoxy(sx[j] * 2, sy[j]);
				printf("  ");
				core[j] = 0;
			}
		}
		for (int l = 0; l < 2; l++) {
			for (int j = 0; j < 60; j++) {
				gotoxy(j * 2, 27 + l);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				if (map[j][l] == 1) printf("��");

			}
			printf("\n");
		}
		gotoxy(100, 30);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("HP: %d / %d", Hp, NHp);
		if (GetAsyncKeyState(VK_LEFT)) {
			if (x / 2 - 1 == -1) {
				x += 2;
			}
			x -= 2;
			Sleep(5);
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			if (x / 2 + 1 == 57) {
				x -= 2;
			}
			x += 2;
			Sleep(5);
		}
		for (int j = 0; j < a; j++) {
			if (sx[j] == x / 2 + 1 && sy[j] == y) NHp -= Hp / 5 - Def;
		}
		if (NHp <= 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			system("cls");
			break;
		}
	}
}

void dog() {
	int mlife = 20;
	int matk = 5;
	srand((unsigned int)time(NULL));
	system("cls");
	FILE* read = fopen("wow.txt", "r");
	char buffer[10000] = { 0, };
	fread(buffer, 1, 10000, read); 
	printf("%s", buffer);
	fclose(read);
	while (1) {
		skillrand = rand() % 100 + 1;
		crecrt = rand() % 100 + 1;
		Sleep(500);
		if (z == 0) {
			gotoxy(0, 0);
		}
		printf("�÷��̾��� ����!\n\n");
		Sleep(500);
		if (skillon == 0) {
			if (crecrt <= Crt) {
				printf("ġ��Ÿ! ������ %d�� ���ظ� ������.\n\n", Atk * 2);
				mlife -= Atk * 2;
			}
			else {
				printf("������ %d�� ���ظ� ������.\n\n", Atk);
				mlife -= Atk;
			}
		}
		else if (skillon == 1) {
			if (skill1 == 1 && skillrand <= 10) {
				printf("���̾�� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ������ %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
				else {
					printf("������ %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
			}
			else if (skill2 == 1 && skillrand > 10 && skillrand <= 15) {
				printf("�踮� �ߵ�!\n\n");
				bar = 1;
			}
			else if (skill3 == 1 && skillrand > 15 && skillrand <= 25) {
				printf("������ �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ������ %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("������ %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
			}
			else if (skill4 == 1 && skillrand > 25 && skillrand <= 35) {
				printf("�������� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ������ %d�� ���ظ� ������.\n\n", Atk * 8);
					mlife -= Atk * 8;
				}
				else {
					printf("������ %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
			}
			else if (skill5 == 1 && skillrand > 35 && skillrand <= 40) {
				printf("����Ʈ���� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ������ %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("������ %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
				effcet = 1;
			}
			else {
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ������ %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
				else {
					printf("������ %d�� ���ظ� ������.\n\n", Atk);
					mlife -= Atk;
				}
			}
		}
		if (mlife <= 0) {
			mlife = 0;
			break;
		}
		Sleep(500);
		printf("���� ����!\n\n");
		Sleep(500);
		if (matk <= Def) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
		}
		else if (bar == 1) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
			bar = 0;
		}
		else if (effcet == 1) {
			printf("���� ������ �����ߴ�\n\n");
			effcet = 0;
		}
		else {
			printf("�÷��̾ %d�� ���ظ� �Ծ���.\n\n", matk - Def);
			NHp -= matk - Def;
		}
		z = 1;
		if (NHp <= 0) {
			printf("�÷��̾��� ���� ���Ͽ� ��������\n\nGame Over\n");
			printf("press space to end");
			stop = 1;
			while (1) {
				if (GetAsyncKeyState(VK_SPACE)) break;
			}
			break;
		}

	}
	z = 0;
	if (mlife == 0) {
		printf("�¸�! 200��带 ŉ���ߴ�!\n\n");
		Gold += 200;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void slime() {
	z = 0;
	int mlife = 60;
	int matk = 10;
	srand((unsigned int)time(NULL));
	system("cls");
	FILE* read = fopen("slime.txt", "r");
	char buffer[10000] = { 0, };
	fread(buffer, 1, 10000, read);
	printf("%s", buffer);
	fclose(read);
	while (1) {
		skillrand = rand() % 100 + 1;
		crecrt = rand() % 100 + 1;
		Sleep(500);
		if (z == 0) {
			gotoxy(0, 0);
		}
		printf("�÷��̾��� ����!\n\n");
		z = 1;
		Sleep(500);
		if (skillon == 0) {
			if (crecrt <= Crt) {
				printf("ġ��Ÿ! �����ӿ��� %d�� ���ظ� ������.\n\n", Atk * 2);
				mlife -= Atk * 2;
			}
			else {
				printf("�����ӿ��� %d�� ���ظ� ������.\n\n", Atk);
				mlife -= Atk;
			}
		}
		else if (skillon == 1) {
			if (skill1 == 1 && skillrand <= 10) {
				printf("���̾�� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �����ӿ��� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
				else {
					printf("�����ӿ��� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
			}
			else if (skill2 == 1 && skillrand > 10 && skillrand <= 15) {
				printf("�踮� �ߵ�!\n\n");
				bar = 1;
			}
			else if (skill3 == 1 && skillrand > 15 && skillrand <= 25) {
				printf("������ �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �����ӿ��� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("�����ӿ��� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
			}
			else if (skill4 == 1 && skillrand > 25 && skillrand <= 35) {
				printf("�������� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �����ӿ��� %d�� ���ظ� ������.\n\n", Atk * 8);
					mlife -= Atk * 8;
				}
				else {
					printf("�����ӿ��� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
			}
			else if (skill5 == 1 && skillrand > 35 && skillrand <= 40) {
				printf("����Ʈ���� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �����ӿ��� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("�����ӿ��� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
				effcet = 1;
			}
			else {
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �����ӿ��� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
				else {
					printf("�����ӿ��� %d�� ���ظ� ������.\n\n", Atk);
					mlife -= Atk;
				}
			}
		}
		if (mlife <= 0) {
			mlife = 0;
			break;
		}
		Sleep(500);
		printf("�������� ����!\n\n");
		Sleep(500);
		if (matk <= Def) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
		}
		else if (bar == 1) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
			bar = 0;
		}
		else if (effcet == 1) {
			printf("�������� ������ �����ߴ�\n\n");
			effcet = 0;
		}
		else {
			printf("�÷��̾ %d�� ���ظ� �Ծ���.\n\n", matk - Def);
			NHp -= matk - Def;
		}
		if (NHp <= 0) {
			printf("�÷��̾��� ���� ���Ͽ� ��������\n\nGame Over\n");
			printf("press space to end");
			stop = 1;
			while (1) {
				if (GetAsyncKeyState(VK_SPACE)) break;
			}
			break;
		}

	}
	if (mlife == 0) {
		printf("�¸�! 500��带 ŉ���ߴ�!\n\n");
		Gold += 500;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void frug() {
	z = 0;
	int mlife = 150;
	int matk = 50;
	srand((unsigned int)time(NULL));
	system("cls");
	FILE* read = fopen("frug.txt", "r");
	char buffer[10000] = { 0, };
	fread(buffer, 1, 10000, read);
	printf("%s", buffer);
	fclose(read);
	while (1) {
		skillrand = rand() % 100 + 1;
		crecrt = rand() % 100 + 1;
		Sleep(500);
		if (z == 0) {
			gotoxy(0, 0);
		}
		printf("�÷��̾��� ����!\n\n");
		z = 1;
		Sleep(500);
		if (skillon == 0) {
			if (crecrt <= Crt) {
				printf("ġ��Ÿ! ���������� %d�� ���ظ� ������.\n\n", Atk * 2);
				mlife -= Atk * 2;
			}
			else {
				printf("���������� %d�� ���ظ� ������.\n\n", Atk);
				mlife -= Atk;
			}
		}
		else if (skillon == 1) {
			if (skill1 == 1 && skillrand <= 10) {
				printf("���̾�� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���������� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
				else {
					printf("���������� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
			}
			else if (skill2 == 1 && skillrand > 10 && skillrand <= 15) {
				printf("�踮� �ߵ�!\n\n");
				bar = 1;
			}
			else if (skill3 == 1 && skillrand > 15 && skillrand <= 25) {
				printf("������ �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���������� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("���������� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
			}
			else if (skill4 == 1 && skillrand > 25 && skillrand <= 35) {
				printf("�������� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���������� %d�� ���ظ� ������.\n\n", Atk * 8);
					mlife -= Atk * 8;
				}
				else {
					printf("���������� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
			}
			else if (skill5 == 1 && skillrand > 35 && skillrand <= 40) {
				printf("����Ʈ���� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���������� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("���������� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
				effcet = 1;
			}
			else {
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���������� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
				else {
					printf("���������� %d�� ���ظ� ������.\n\n", Atk);
					mlife -= Atk;
				}
			}
		}
		if (mlife <= 0) {
			mlife = 0;
			break;
		}
		Sleep(500);
		printf("�������� ����!\n\n");
		Sleep(500);
		if (matk <= Def) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
		}
		else if (bar == 1) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
			bar = 0;
		}
		else if (effcet == 1) {
			printf("�������� ������ �����ߴ�\n\n");
			effcet = 0;
		}
		else {
			printf("�÷��̾ %d�� ���ظ� �Ծ���.\n\n", matk - Def);
			NHp -= matk - Def;
		}
		if (NHp <= 0) {
			printf("�÷��̾��� ���� ���Ͽ� ��������\n\nGame Over\n");
			printf("press space to end");
			stop = 1;
			while (1) {
				if (GetAsyncKeyState(VK_SPACE)) break;
			}
			break;
		}

	}
	if (mlife == 0) {
		printf("�¸�! 1000��带 ŉ���ߴ�!\n\n");
		Gold += 1000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void goat() {
	z = 0;
	int mlife = 250;
	int matk = 60;
	srand((unsigned int)time(NULL));
	system("cls");
	FILE* read = fopen("goat.txt", "r");
	char buffer[10000] = { 0, };
	fread(buffer, 1, 10000, read);
	printf("%s", buffer);
	fclose(read);
	while (1) {
		skillrand = rand() % 100 + 1;
		crecrt = rand() % 100 + 1;
		Sleep(500);
		if (z == 0) {
			gotoxy(0, 0);
		}
		printf("�÷��̾��� ����!\n\n");
		z = 1;
		Sleep(500);
		if (skillon == 0) {
			if (crecrt <= Crt) {
				printf("ġ��Ÿ! ���ҿ��� %d�� ���ظ� ������.\n\n", Atk * 2);
				mlife -= Atk * 2;
			}
			else {
				printf("���ҿ��� %d�� ���ظ� ������.\n\n", Atk);
				mlife -= Atk;
			}
		}
		else if (skillon == 1) {
			if (skill1 == 1 && skillrand <= 10) {
				printf("���̾�� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���ҿ��� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
				else {
					printf("���ҿ��� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
			}
			else if (skill2 == 1 && skillrand > 10 && skillrand <= 15) {
				printf("�踮� �ߵ�!\n\n");
				bar = 1;
			}
			else if (skill3 == 1 && skillrand > 15 && skillrand <= 25) {
				printf("������ �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���ҿ��� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("���ҿ��� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
			}
			else if (skill4 == 1 && skillrand > 25 && skillrand <= 35) {
				printf("�������� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���ҿ��� %d�� ���ظ� ������.\n\n", Atk * 8);
					mlife -= Atk * 8;
				}
				else {
					printf("���ҿ��� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
			}
			else if (skill5 == 1 && skillrand > 35 && skillrand <= 40) {
				printf("����Ʈ���� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���ҿ��� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("���ҿ��� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
				effcet = 1;
			}
			else {
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���ҿ��� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
				else {
					printf("���ҿ��� %d�� ���ظ� ������.\n\n", Atk);
					mlife -= Atk;
				}
			}
		}
		if (mlife <= 0) {
			mlife = 0;
			break;
		}
		Sleep(500);
		printf("������ ����!\n\n");
		Sleep(500);
		if (matk <= Def) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
		}
		else if (bar == 1) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
			bar = 0;
		}
		else if (effcet == 1) {
			printf("������ ������ �����ߴ�\n\n");
			effcet = 0;
		}
		else {
			printf("�÷��̾ %d�� ���ظ� �Ծ���.\n\n", matk - Def);
			NHp -= matk - Def;
		}
		if (NHp <= 0) {
			printf("�÷��̾��� ���� ���Ͽ� ��������\n\nGame Over\n");
			printf("press space to end");
			stop = 1;
			while (1) {
				if (GetAsyncKeyState(VK_SPACE)) break;
			}
			break;
		}

	}
	if (mlife == 0) {
		printf("�¸�! 4000��带 ŉ���ߴ�!\n\n");
		Gold += 4000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void bat() {
	z = 0;
	int mlife = 400;
	int matk = 70;
	srand((unsigned int)time(NULL));
	system("cls");
	FILE* read = fopen("bat.txt", "r");
	char buffer[10000] = { 0, };
	fread(buffer, 1, 10000, read);
	printf("%s", buffer);
	fclose(read);
	while (1) {
		skillrand = rand() % 100 + 1;
		crecrt = rand() % 100 + 1;
		Sleep(500);
		if (z == 0) {
			gotoxy(0, 0);
		}
		printf("�÷��̾��� ����!\n\n");
		z = 1;
		Sleep(500);
		if (skillon == 0) {
			if (crecrt <= Crt) {
				printf("ġ��Ÿ! ���㿡�� %d�� ���ظ� ������.\n\n", Atk * 2);
				mlife -= Atk * 2;
			}
			else {
				printf("���㿡�� %d�� ���ظ� ������.\n\n", Atk);
				mlife -= Atk;
			}
		}
		else if (skillon == 1) {
			if (skill1 == 1 && skillrand <= 10) {
				printf("���̾�� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���㿡�� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
				else {
					printf("���㿡�� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
			}
			else if (skill2 == 1 && skillrand > 10 && skillrand <= 15) {
				printf("�踮� �ߵ�!\n\n");
				bar = 1;
			}
			else if (skill3 == 1 && skillrand > 15 && skillrand <= 25) {
				printf("������ �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���㿡�� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("���㿡�� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
			}
			else if (skill4 == 1 && skillrand > 25 && skillrand <= 35) {
				printf("�������� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���㿡�� %d�� ���ظ� ������.\n\n", Atk * 8);
					mlife -= Atk * 8;
				}
				else {
					printf("���㿡�� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
			}
			else if (skill5 == 1 && skillrand > 35 && skillrand <= 40) {
				printf("����Ʈ���� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���㿡�� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("���㿡�� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
				effcet = 1;
			}
			else {
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���㿡�� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
				else {
					printf("���㿡�� %d�� ���ظ� ������.\n\n", Atk);
					mlife -= Atk;
				}
			}
		}
		if (mlife <= 0) {
			mlife = 0;
			break;
		}
		Sleep(500);
		printf("������ ����!\n\n");
		Sleep(500);
		if (matk <= Def) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
		}
		else if (bar == 1) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
			bar = 0;
		}
		else if (effcet == 1) {
			printf("������ ������ �����ߴ�\n\n");
			effcet = 0;
		}
		else {
			printf("�÷��̾ %d�� ���ظ� �Ծ���.\n\n", matk - Def);
			NHp -= matk - Def;
		}
		if (NHp <= 0) {
			printf("�÷��̾��� ���� ���Ͽ� ��������\n\nGame Over\n");
			printf("press space to end");
			stop = 1;
			while (1) {
				if (GetAsyncKeyState(VK_SPACE)) break;
			}
			break;
		}

	}
	if (mlife == 0) {
		printf("�¸�! 8000��带 ŉ���ߴ�!\n\n");
		Gold += 8000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void lizard() {
	z = 0;
	int mlife = 505;
	int matk = 110;
	srand((unsigned int)time(NULL));
	system("cls");
	FILE* read = fopen("lizard.txt", "r");
	char buffer[10000] = { 0, };
	fread(buffer, 1, 10000, read);
	printf("%s", buffer);
	fclose(read);
	while (1) {
		skillrand = rand() % 100 + 1;
		crecrt = rand() % 100 + 1;
		Sleep(500);
		if (z == 0) {
			gotoxy(0, 0);
		}
		printf("�÷��̾��� ����!\n\n");
		z = 1;
		Sleep(500);
		if (skillon == 0) {
			if (crecrt <= Crt) {
				printf("ġ��Ÿ! �����쿡�� %d�� ���ظ� ������.\n\n", Atk * 2);
				mlife -= Atk * 2;
			}
			else {
				printf("�����쿡�� %d�� ���ظ� ������.\n\n", Atk);
				mlife -= Atk;
			}
		}
		else if (skillon == 1) {
			if (skill1 == 1 && skillrand <= 10) {
				printf("���̾�� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �����쿡�� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
				else {
					printf("�����쿡�� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
			}
			else if (skill2 == 1 && skillrand > 10 && skillrand <= 15) {
				printf("�踮� �ߵ�!\n\n");
				bar = 1;
			}
			else if (skill3 == 1 && skillrand > 15 && skillrand <= 25) {
				printf("������ �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �����쿡�� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("�����쿡�� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
			}
			else if (skill4 == 1 && skillrand > 25 && skillrand <= 35) {
				printf("�������� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �����쿡�� %d�� ���ظ� ������.\n\n", Atk * 8);
					mlife -= Atk * 8;
				}
				else {
					printf("�����쿡�� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
			}
			else if (skill5 == 1 && skillrand > 35 && skillrand <= 40) {
				printf("����Ʈ���� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �����쿡�� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("�����쿡�� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
				effcet = 1;
			}
			else {
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �����쿡�� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
				else {
					printf("�����쿡�� %d�� ���ظ� ������.\n\n", Atk);
					mlife -= Atk;
				}
			}
		}
		if (mlife <= 0) {
			mlife = 0;
			break;
		}
		Sleep(500);
		printf("�������� ����!\n\n");
		Sleep(500);
		if (matk <= Def) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
		}
		else if (bar == 1) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
			bar = 0;
		}
		else if (effcet == 1) {
			printf("�������� ������ �����ߴ�\n\n");
			effcet = 0;
		}
		else {
			printf("�÷��̾ %d�� ���ظ� �Ծ���.\n\n", matk - Def);
			NHp -= matk - Def;
		}
		if (NHp <= 0) {
			printf("�÷��̾��� ���� ���Ͽ� ��������\n\nGame Over\n");
			printf("press space to end");
			stop = 1;
			while (1) {
				if (GetAsyncKeyState(VK_SPACE)) break;
			}
			break;
		}

	}
	if (mlife == 0) {
		printf("�¸�! 32000��带 ŉ���ߴ�!\n\n");
		Gold += 32000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void ork() {
	z = 0;
	int mlife = 950;
	int matk = 120;
	srand((unsigned int)time(NULL));
	system("cls");
	FILE* read = fopen("ork.txt", "r");
	char buffer[10000] = { 0, };
	fread(buffer, 1, 10000, read);
	printf("%s", buffer);
	fclose(read);
	while (1) {
		skillrand = rand() % 100 + 1;
		crecrt = rand() % 100 + 1;
		Sleep(500);
		if (z == 0) {
			gotoxy(0, 0);
		}
		printf("�÷��̾��� ����!\n\n");
		z = 1;
		Sleep(500);
		if (skillon == 0) {
			if (crecrt <= Crt) {
				printf("ġ��Ÿ! ��ũ���� %d�� ���ظ� ������.\n\n", Atk * 2);
				mlife -= Atk * 2;
			}
			else {
				printf("��ũ���� %d�� ���ظ� ������.\n\n", Atk);
				mlife -= Atk;
			}
		}
		else if (skillon == 1) {
			if (skill1 == 1 && skillrand <= 10) {
				printf("���̾�� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ��ũ���� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
				else {
					printf("��ũ���� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
			}
			else if (skill2 == 1 && skillrand > 10 && skillrand <= 15) {
				printf("�踮� �ߵ�!\n\n");
				bar = 1;
			}
			else if (skill3 == 1 && skillrand > 15 && skillrand <= 25) {
				printf("������ �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ��ũ���� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("��ũ���� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
			}
			else if (skill4 == 1 && skillrand > 25 && skillrand <= 35) {
				printf("�������� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ��ũ���� %d�� ���ظ� ������.\n\n", Atk * 8);
					mlife -= Atk * 8;
				}
				else {
					printf("��ũ���� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
			}
			else if (skill5 == 1 && skillrand > 35 && skillrand <= 40) {
				printf("����Ʈ���� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ��ũ���� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("��ũ���� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
				effcet = 1;
			}
			else {
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ��ũ���� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
				else {
					printf("��ũ���� %d�� ���ظ� ������.\n\n", Atk);
					mlife -= Atk;
				}
			}
		}
		if (mlife <= 0) {
			mlife = 0;
			break;
		}
		Sleep(500);
		printf("��ũ�� ����!\n\n");
		Sleep(500);
		if (matk <= Def) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
		}
		else if (bar == 1) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
			bar = 0;
		}
		else if (effcet == 1) {
			printf("��ũ�� ������ �����ߴ�\n\n");
			effcet = 0;
		}
		else {
			printf("�÷��̾ %d�� ���ظ� �Ծ���.\n\n", matk - Def);
			NHp -= matk - Def;
		}
		if (NHp <= 0) {
			printf("�÷��̾��� ���� ���Ͽ� ��������\n\nGame Over\n");
			printf("press space to end");
			stop = 1;
			while (1) {
				if (GetAsyncKeyState(VK_SPACE)) break;
			}
			break;
		}

	}
	if (mlife == 0) {
		printf("�¸�! 64000��带 ŉ���ߴ�!\n\n");
		Gold += 64000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void imp() {
	z = 0;
	int mlife = 1500;
	int matk = 140;
	srand((unsigned int)time(NULL));
	system("cls");
	FILE* read = fopen("imp.txt", "r");
	char buffer[10000] = { 0, };
	fread(buffer, 1, 10000, read);
	printf("%s", buffer);
	fclose(read);
	while (1) {
		skillrand = rand() % 100 + 1;
		crecrt = rand() % 100 + 1;
		Sleep(500);
		if (z == 0) {
			gotoxy(0, 0);
		}
		printf("�÷��̾��� ����!\n\n");
		z = 1;
		Sleep(500);
		if (skillon == 0) {
			if (crecrt <= Crt) {
				printf("ġ��Ÿ! �������� %d�� ���ظ� ������.\n\n", Atk * 2);
				mlife -= Atk * 2;
			}
			else {
				printf("�������� %d�� ���ظ� ������.\n\n", Atk);
				mlife -= Atk;
			}
		}
		else if (skillon == 1) {
			if (skill1 == 1 && skillrand <= 10) {
				printf("���̾�� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �������� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
				else {
					printf("�������� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
			}
			else if (skill2 == 1 && skillrand > 10 && skillrand <= 15) {
				printf("�踮� �ߵ�!\n\n");
				bar = 1;
			}
			else if (skill3 == 1 && skillrand > 15 && skillrand <= 25) {
				printf("������ �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �������� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("�������� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
			}
			else if (skill4 == 1 && skillrand > 25 && skillrand <= 35) {
				printf("�������� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �������� %d�� ���ظ� ������.\n\n", Atk * 8);
					mlife -= Atk * 8;
				}
				else {
					printf("�������� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
			}
			else if (skill5 == 1 && skillrand > 35 && skillrand <= 40) {
				printf("����Ʈ���� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �������� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("�������� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
				effcet = 1;
			}
			else {
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �������� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
				else {
					printf("�������� %d�� ���ظ� ������.\n\n", Atk);
					mlife -= Atk;
				}
			}
		}
		if (mlife <= 0) {
			mlife = 0;
			break;
		}
		Sleep(500);
		printf("������ ����!\n\n");
		Sleep(500);
		if (matk <= Def) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
		}
		else if (bar == 1) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
			bar = 0;
		}
		else if (effcet == 1) {
			printf("������ ������ �����ߴ�\n\n");
			effcet = 0;
		}
		else {
			printf("�÷��̾ %d�� ���ظ� �Ծ���.\n\n", matk - Def);
			NHp -= matk - Def;
		}
		if (NHp <= 0) {
			printf("�÷��̾��� ���� ���Ͽ� ��������\n\nGame Over\n");
			printf("press space to end");
			stop = 1;
			while (1) {
				if (GetAsyncKeyState(VK_SPACE)) break;
			}
			break;
		}

	}
	if (mlife == 0) {
		printf("�¸�! 256000��带 ŉ���ߴ�!\n\n");
		Gold += 256000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void undead() {
	z = 0;
	int mlife = 1250;
	int matk = 150;
	srand((unsigned int)time(NULL));
	system("cls");
	FILE* read = fopen("undead.txt", "r");
	char buffer[10000] = { 0, };
	fread(buffer, 1, 10000, read);
	printf("%s", buffer);
	fclose(read);
	while (1) {
		skillrand = rand() % 100 + 1;
		crecrt = rand() % 100 + 1;
		Sleep(500);
		if (z == 0) {
			gotoxy(0, 0);
		}
		printf("�÷��̾��� ����!\n\n");
		z = 1;
		Sleep(500);
		if (skillon == 0) {
			if (crecrt <= Crt) {
				printf("ġ��Ÿ! ���񿡰� %d�� ���ظ� ������.\n\n", Atk * 2);
				mlife -= Atk * 2;
			}
			else {
				printf("���񿡰� %d�� ���ظ� ������.\n\n", Atk);
				mlife -= Atk;
			}
		}
		else if (skillon == 1) {
			if (skill1 == 1 && skillrand <= 10) {
				printf("���̾�� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���񿡰� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
				else {
					printf("���񿡰� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
			}
			else if (skill2 == 1 && skillrand > 10 && skillrand <= 15) {
				printf("�踮� �ߵ�!\n\n");
				bar = 1;
			}
			else if (skill3 == 1 && skillrand > 15 && skillrand <= 25) {
				printf("������ �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���񿡰� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("���񿡰� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
			}
			else if (skill4 == 1 && skillrand > 25 && skillrand <= 35) {
				printf("�������� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���񿡰� %d�� ���ظ� ������.\n\n", Atk * 8);
					mlife -= Atk * 8;
				}
				else {
					printf("���񿡰� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
			}
			else if (skill5 == 1 && skillrand > 35 && skillrand <= 40) {
				printf("����Ʈ���� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���񿡰� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("���񿡰� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
				effcet = 1;
			}
			else {
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���񿡰� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
				else {
					printf("���񿡰� %d�� ���ظ� ������.\n\n", Atk);
					mlife -= Atk;
				}
			}
		}
		if (mlife <= 0) {
			mlife = 0;
			break;
		}
		Sleep(500);
		printf("������ ����!\n\n");
		Sleep(500);
		if (matk <= Def) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
		}
		else if (bar == 1) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
			bar = 0;
		}
		else if (effcet == 1) {
			printf("������ ������ �����ߴ�\n\n");
			effcet = 0;
		}
		else {
			printf("�÷��̾ %d�� ���ظ� �Ծ���.\n\n", matk - Def);
			NHp -= matk - Def;
		}
		if (NHp <= 0) {
			printf("�÷��̾��� ���� ���Ͽ� ��������\n\nGame Over\n");
			printf("press space to end");
			stop = 1;
			while (1) {
				if (GetAsyncKeyState(VK_SPACE)) break;
			}
			break;
		}

	}
	if (mlife == 0) {
		printf("�¸�! 512000��带 ŉ���ߴ�!\n\n");
		Gold += 512000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void deathknight() {
	z = 0;
	int mlife = 2000;
	int matk = 200;
	srand((unsigned int)time(NULL));
	system("cls");
	FILE* read = fopen("deathknight.txt", "r");
	char buffer[10000] = { 0, };
	fread(buffer, 1, 10000, read);
	printf("%s", buffer);
	fclose(read);
	while (1) {
		skillrand = rand() % 100 + 1;
		crecrt = rand() % 100 + 1;
		Sleep(500);
		if (z == 0) {
			gotoxy(0, 0);
		}
		printf("�÷��̾��� ����!\n\n");
		z = 1;
		Sleep(500);
		if (skillon == 0) {
			if (crecrt <= Crt) {
				printf("ġ��Ÿ! ������ ��翡�� %d�� ���ظ� ������.\n\n", Atk * 2);
				mlife -= Atk * 2;
			}
			else {
				printf("������ ��翡�� %d�� ���ظ� ������.\n\n", Atk);
				mlife -= Atk;
			}
		}
		else if (skillon == 1) {
			if (skill1 == 1 && skillrand <= 10) {
				printf("���̾�� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ������ ��翡�� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
				else {
					printf("������ ��翡�� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
			}
			else if (skill2 == 1 && skillrand > 10 && skillrand <= 15) {
				printf("�踮� �ߵ�!\n\n");
				bar = 1;
			}
			else if (skill3 == 1 && skillrand > 15 && skillrand <= 25) {
				printf("������ �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ������ ��翡�� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("������ ��翡�� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
			}
			else if (skill4 == 1 && skillrand > 25 && skillrand <= 35) {
				printf("�������� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ������ ��翡�� %d�� ���ظ� ������.\n\n", Atk * 8);
					mlife -= Atk * 8;
				}
				else {
					printf("������ ��翡�� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
			}
			else if (skill5 == 1 && skillrand > 35 && skillrand <= 40) {
				printf("����Ʈ���� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ������ ��翡�� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("������ ��翡�� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
				effcet = 1;
			}
			else {
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ������ ��翡�� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
				else {
					printf("������ ��翡�� %d�� ���ظ� ������.\n\n", Atk);
					mlife -= Atk;
				}
			}
		}
		if (mlife <= 0) {
			mlife = 0;
			break;
		}
		Sleep(500);
		printf("������ ����� ����!\n\n");
		Sleep(500);
		if (matk <= Def) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
		}
		else if (bar == 1) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
			bar = 0;
		}
		else if (effcet == 1) {
			printf("������ ����� ������ �����ߴ�\n\n");
			effcet = 0;
		}
		else {
			printf("�÷��̾ %d�� ���ظ� �Ծ���.\n\n", matk - Def);
			NHp -= matk - Def;
		}
		if (NHp <= 0) {
			printf("�÷��̾��� ���� ���Ͽ� ��������\n\nGame Over\n");
			printf("press space to end");
			stop = 1;
			while (1) {
				if (GetAsyncKeyState(VK_SPACE)) break;
			}
			break;
		}

	}
	if (mlife == 0) {
		printf("�¸�! 2048000��带 ŉ���ߴ�!\n\n");
		Gold += 2048000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void dragonfly() {
	z = 0;
	int mlife = 2200;
	int matk = 210;
	srand((unsigned int)time(NULL));
	system("cls");
	FILE* read = fopen("dragonfly.txt", "r");
	char buffer[10000] = { 0, };
	fread(buffer, 1, 10000, read);
	printf("%s", buffer);
	fclose(read);
	while (1) {
		skillrand = rand() % 100 + 1;
		crecrt = rand() % 100 + 1;
		Sleep(500);
		if (z == 0) {
			gotoxy(0, 0);
		}
		printf("�÷��̾��� ����!\n\n");
		z = 1;
		Sleep(500);
		if (skillon == 0) {
			if (crecrt <= Crt) {
				printf("ġ��Ÿ! ���ĸ����� %d�� ���ظ� ������.\n\n", Atk * 2);
				mlife -= Atk * 2;
			}
			else {
				printf("���ĸ����� %d�� ���ظ� ������.\n\n", Atk);
				mlife -= Atk;
			}
		}
		else if (skillon == 1) {
			if (skill1 == 1 && skillrand <= 10) {
				printf("���̾�� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���ĸ����� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
				else {
					printf("���ĸ����� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
			}
			else if (skill2 == 1 && skillrand > 10 && skillrand <= 15) {
				printf("�踮� �ߵ�!\n\n");
				bar = 1;
			}
			else if (skill3 == 1 && skillrand > 15 && skillrand <= 25) {
				printf("������ �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���ĸ����� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("���ĸ����� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
			}
			else if (skill4 == 1 && skillrand > 25 && skillrand <= 35) {
				printf("�������� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���ĸ����� %d�� ���ظ� ������.\n\n", Atk * 8);
					mlife -= Atk * 8;
				}
				else {
					printf("���ĸ����� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
			}
			else if (skill5 == 1 && skillrand > 35 && skillrand <= 40) {
				printf("����Ʈ���� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���ĸ����� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("���ĸ����� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
				effcet = 1;
			}
			else {
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ���ĸ����� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
				else {
					printf("���ĸ����� %d�� ���ظ� ������.\n\n", Atk);
					mlife -= Atk;
				}
			}
		}
		if (mlife <= 0) {
			mlife = 0;
			break;
		}
		Sleep(500);
		printf("���ĸ��� ����!\n\n");
		Sleep(500);
		if (matk <= Def) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
		}
		else if (bar == 1) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
			bar = 0;
		}
		else if (effcet == 1) {
			printf("���ĸ��� ������ �����ߴ�\n\n");
			effcet = 0;
		}
		else {
			printf("�÷��̾ %d�� ���ظ� �Ծ���.\n\n", matk - Def);
			NHp -= matk - Def;
		}
		if (NHp <= 0) {
			printf("�÷��̾��� ���� ���Ͽ� ��������\n\nGame Over\n");
			printf("press space to end");
			stop = 1;
			while (1) {
				if (GetAsyncKeyState(VK_SPACE)) break;
			}
			break;
		}

	}
	if (mlife == 0) {
		printf("�¸�! 4096000��带 ŉ���ߴ�!\n\n");
		Gold += 4096000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void dragon() {
	z = 0;
	int mlife = 2500;
	int matk = 230;
	srand((unsigned int)time(NULL));
	system("cls");
	FILE* read = fopen("dragon.txt", "r");
	char buffer[10000] = { 0, };
	fread(buffer, 1, 10000, read);
	printf("%s", buffer);
	fclose(read);
	while (1) {
		skillrand = rand() % 100 + 1;
		crecrt = rand() % 100 + 1;
		Sleep(500);
		if (z == 0) {
			gotoxy(0, 0);
		}
		printf("�÷��̾��� ����!\n\n");
		z = 1;
		Sleep(500);
		if (skillon == 0) {
			if (crecrt <= Crt) {
				printf("ġ��Ÿ! �巡�￡�� %d�� ���ظ� ������.\n\n", Atk * 2);
				mlife -= Atk * 2;
			}
			else {
				printf("�巡�￡�� %d�� ���ظ� ������.\n\n", Atk);
				mlife -= Atk;
			}
		}
		else if (skillon == 1) {
			if (skill1 == 1 && skillrand <= 10) {
				printf("���̾�� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �巡�￡�� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
				else {
					printf("�巡�￡�� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
			}
			else if (skill2 == 1 && skillrand > 10 && skillrand <= 15) {
				printf("�踮� �ߵ�!\n\n");
				bar = 1;
			}
			else if (skill3 == 1 && skillrand > 15 && skillrand <= 25) {
				printf("������ �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �巡�￡�� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("�巡�￡�� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
			}
			else if (skill4 == 1 && skillrand > 25 && skillrand <= 35) {
				printf("�������� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �巡�￡�� %d�� ���ظ� ������.\n\n", Atk * 8);
					mlife -= Atk * 8;
				}
				else {
					printf("�巡�￡�� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
			}
			else if (skill5 == 1 && skillrand > 35 && skillrand <= 40) {
				printf("����Ʈ���� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �巡�￡�� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("�巡�￡�� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
				effcet = 1;
			}
			else {
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �巡�￡�� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
				else {
					printf("�巡�￡�� %d�� ���ظ� ������.\n\n", Atk);
					mlife -= Atk;
				}
			}
		}
		if (mlife <= 0) {
			mlife = 0;
			break;
		}
		Sleep(500);
		printf("�巡���� ����!\n\n");
		Sleep(500);
		if (matk <= Def) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
		}
		else if (bar == 1) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
			bar = 0;
		}
		else if (effcet == 1) {
			printf("�巡���� ������ �����ߴ�\n\n");
			effcet = 0;
		}
		else {
			printf("�÷��̾ %d�� ���ظ� �Ծ���.\n\n", matk - Def);
			NHp -= matk - Def;
		}
		if (NHp <= 0) {
			printf("�÷��̾��� ���� ���Ͽ� ��������\n\nGame Over\n");
			printf("press space to end");
			stop = 1;
			while (1) {
				if (GetAsyncKeyState(VK_SPACE)) break;
			}
			break;
		}

	}
	if (mlife == 0) {
		printf("�¸�! 16384000��带 ŉ���ߴ�!\n\n");
		Gold += 16384000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void satan() {
	z = 0;
	int mlife = 2700;
	int matk = 250;
	srand((unsigned int)time(NULL));
	system("cls");
	FILE* read = fopen("satan.txt", "r");
	char buffer[10000] = { 0, };
	fread(buffer, 1, 10000, read);
	printf("%s", buffer);
	fclose(read);
	while (1) {
		skillrand = rand() % 100 + 1;
		crecrt = rand() % 100 + 1;
		Sleep(500);
		if (z == 0) {
			gotoxy(0, 0);
		}
		printf("�÷��̾��� ����!\n\n");
		z = 1;
		Sleep(500);
		if (skillon == 0) {
			if (crecrt <= Crt) {
				printf("ġ��Ÿ! ��ź���� %d�� ���ظ� ������.\n\n", Atk * 2);
				mlife -= Atk * 2;
			}
			else {
				printf("��ź���� %d�� ���ظ� ������.\n\n", Atk);
				mlife -= Atk;
			}
		}
		else if (skillon == 1) {
			if (skill1 == 1 && skillrand <= 10) {
				printf("���̾�� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ��ź���� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
				else {
					printf("��ź���� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
			}
			else if (skill2 == 1 && skillrand > 10 && skillrand <= 15) {
				printf("�踮� �ߵ�!\n\n");
				bar = 1;
			}
			else if (skill3 == 1 && skillrand > 15 && skillrand <= 25) {
				printf("������ �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ��ź���� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("��ź���� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
			}
			else if (skill4 == 1 && skillrand > 25 && skillrand <= 35) {
				printf("�������� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ��ź���� %d�� ���ظ� ������.\n\n", Atk * 8);
					mlife -= Atk * 8;
				}
				else {
					printf("��ź���� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
			}
			else if (skill5 == 1 && skillrand > 35 && skillrand <= 40) {
				printf("����Ʈ���� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ��ź���� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("��ź���� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
				effcet = 1;
			}
			else {
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ��ź���� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
				else {
					printf("��ź���� %d�� ���ظ� ������.\n\n", Atk);
					mlife -= Atk;
				}
			}
		}
		if (mlife <= 0) {
			mlife = 0;
			break;
		}
		Sleep(500);
		printf("��ź�� ����!\n\n");
		Sleep(500);
		if (matk <= Def) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
		}
		else if (bar == 1) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
			bar = 0;
		}
		else if (effcet == 1) {
			printf("��ź�� ������ �����ߴ�\n\n");
			effcet = 0;
		}
		else {
			printf("�÷��̾ %d�� ���ظ� �Ծ���.\n\n", matk - Def);
			NHp -= matk - Def;
		}
		if (NHp <= 0) {
			printf("�÷��̾��� ���� ���Ͽ� ��������\n\nGame Over\n");
			printf("press space to end");
			stop = 1;
			while (1) {
				if (GetAsyncKeyState(VK_SPACE)) break;
			}
			break;
		}

	}
	if (mlife == 0) {
		printf("�¸�! 32768000��带 ŉ���ߴ�!\n\n");
		Gold += 32768000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void demon() {
	z = 0;
	int mlife = 3000;
	int matk = 270;
	srand((unsigned int)time(NULL));
	system("cls");
	FILE* read = fopen("demon.txt", "r");
	char buffer[10000] = { 0, };
	fread(buffer, 1, 10000, read);
	printf("%s", buffer);
	fclose(read);
	while (1) {
		skillrand = rand() % 100 + 1;
		crecrt = rand() % 100 + 1;
		Sleep(500);
		if (z == 0) {
			gotoxy(0, 0);
		}
		printf("�÷��̾��� ����!\n\n");
		z = 1;
		Sleep(500);
		if (skillon == 0) {
			if (crecrt <= Crt) {
				printf("ġ��Ÿ! �Ǹ����� %d�� ���ظ� ������.\n\n", Atk * 2);
				mlife -= Atk * 2;
			}
			else {
				printf("�Ǹ����� %d�� ���ظ� ������.\n\n", Atk);
				mlife -= Atk;
			}
		}
		else if (skillon == 1) {
			if (skill1 == 1 && skillrand <= 10) {
				printf("���̾�� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �Ǹ����� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
				else {
					printf("�Ǹ����� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
			}
			else if (skill2 == 1 && skillrand > 10 && skillrand <= 15) {
				printf("�踮� �ߵ�!\n\n");
				bar = 1;
			}
			else if (skill3 == 1 && skillrand > 15 && skillrand <= 25) {
				printf("������ �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �Ǹ����� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("�Ǹ����� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
			}
			else if (skill4 == 1 && skillrand > 25 && skillrand <= 35) {
				printf("�������� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �Ǹ����� %d�� ���ظ� ������.\n\n", Atk * 8);
					mlife -= Atk * 8;
				}
				else {
					printf("�Ǹ����� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
			}
			else if (skill5 == 1 && skillrand > 35 && skillrand <= 40) {
				printf("����Ʈ���� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �Ǹ����� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("�Ǹ����� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
				effcet = 1;
			}
			else {
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �Ǹ����� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
				else {
					printf("�Ǹ����� %d�� ���ظ� ������.\n\n", Atk);
					mlife -= Atk;
				}
			}
		}
		if (mlife <= 0) {
			mlife = 0;
			break;
		}
		Sleep(500);
		printf("�Ǹ��� ����!\n\n");
		Sleep(500);
		if (matk <= Def) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
		}
		else if (bar == 1) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
			bar = 0;
		}
		else if (effcet == 1) {
			printf("�Ǹ��� ������ �����ߴ�\n\n");
			effcet = 0;
		}
		else {
			printf("�÷��̾ %d�� ���ظ� �Ծ���.\n\n", matk - Def);
			NHp -= matk - Def;
		}
		if (NHp <= 0) {
			printf("�÷��̾��� ���� ���Ͽ� ��������\n\nGame Over\n");
			printf("press space to end");
			stop = 1;
			while (1) {
				if (GetAsyncKeyState(VK_SPACE)) break;
			}
			break;
		}

	}
	if (mlife == 0) {
		printf("�¸�! 131072000��带 ŉ���ߴ�!\n\n");
		Gold += 131072000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void deathking() {
	z = 0;
	int mlife = 3300;
	int matk = 300;
	srand((unsigned int)time(NULL));
	system("cls");
	FILE* read = fopen("deathking.txt", "r");
	char buffer[10000] = { 0, };
	fread(buffer, 1, 10000, read);
	printf("%s", buffer);
	fclose(read);
	while (1) {
		skillrand = rand() % 100 + 1;
		crecrt = rand() % 100 + 1;
		Sleep(500);
		if (z == 0) {
			gotoxy(0, 0);
		}
		printf("�÷��̾��� ����!\n\n");
		z = 1;
		Sleep(500);
		if (skillon == 0) {
			if (crecrt <= Crt) {
				printf("ġ��Ÿ! ��տ��� %d�� ���ظ� ������.\n\n", Atk * 2);
				mlife -= Atk * 2;
			}
			else {
				printf("��տ��� %d�� ���ظ� ������.\n\n", Atk);
				mlife -= Atk;
			}
		}
		else if (skillon == 1) {
			if (skill1 == 1 && skillrand <= 10) {
				printf("���̾�� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ��տ��� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
				else {
					printf("��տ��� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
			}
			else if (skill2 == 1 && skillrand > 10 && skillrand <= 15) {
				printf("�踮� �ߵ�!\n\n");
				bar = 1;
			}
			else if (skill3 == 1 && skillrand > 15 && skillrand <= 25) {
				printf("������ �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ��տ��� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("��տ��� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
			}
			else if (skill4 == 1 && skillrand > 25 && skillrand <= 35) {
				printf("�������� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ��տ��� %d�� ���ظ� ������.\n\n", Atk * 8);
					mlife -= Atk * 8;
				}
				else {
					printf("��տ��� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
			}
			else if (skill5 == 1 && skillrand > 35 && skillrand <= 40) {
				printf("����Ʈ���� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ��տ��� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("��տ��� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
				effcet = 1;
			}
			else {
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ��տ��� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
				else {
					printf("��տ��� %d�� ���ظ� ������.\n\n", Atk);
					mlife -= Atk;
				}
			}
		}
		if (mlife <= 0) {
			mlife = 0;
			break;
		}
		Sleep(500);
		printf("����� ����!\n\n");
		Sleep(500);
		if (matk <= Def) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
		}
		else if (bar == 1) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
			bar = 0;
		}
		else if (effcet == 1) {
			printf("����� ������ �����ߴ�\n\n");
			effcet = 0;
		}
		else {
			printf("�÷��̾ %d�� ���ظ� �Ծ���.\n\n", matk - Def);
			NHp -= matk - Def;
		}
		if (NHp <= 0) {
			printf("�÷��̾��� ���� ���Ͽ� ��������\n\nGame Over\n");
			printf("press space to end");
			stop = 1;
			while (1) {
				if (GetAsyncKeyState(VK_SPACE)) break;
			}
			break;
		}

	}
	if (mlife == 0) {
		printf("�¸�! 262144000��带 ŉ���ߴ�!\n\n");
		Gold += 262144000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void GOD() {
	z = 0;
	int mlife = 3500;
	int matk = 330;
	srand((unsigned int)time(NULL));
	system("cls");
	FILE* read = fopen("GOD.txt", "r");
	char buffer[10000] = { 0, };
	fread(buffer, 1, 10000, read);
	printf("%s", buffer);
	fclose(read);
	while (1) {
		skillrand = rand() % 100 + 1;
		crecrt = rand() % 100 + 1;
		Sleep(500);
		if (z == 0) {
			gotoxy(0, 0);
		}
		printf("�÷��̾��� ����!\n\n");
		z = 1;
		Sleep(500);
		if (skillon == 0) {
			if (crecrt <= Crt) {
				printf("ġ��Ÿ! �ſ��� %d�� ���ظ� ������.\n\n", Atk * 2);
				mlife -= Atk * 2;
			}
			else {
				printf("�ſ��� %d�� ���ظ� ������.\n\n", Atk);
				mlife -= Atk;
			}
		}
		else if (skillon == 1) {
			if (skill1 == 1 && skillrand <= 10) {
				printf("���̾�� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �ſ��� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
				else {
					printf("�ſ��� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
			}
			else if (skill2 == 1 && skillrand > 10 && skillrand <= 15) {
				printf("�踮� �ߵ�!\n\n");
				bar = 1;
			}
			else if (skill3 == 1 && skillrand > 15 && skillrand <= 25) {
				printf("������ �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �ſ��� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("�ſ��� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
			}
			else if (skill4 == 1 && skillrand > 25 && skillrand <= 35) {
				printf("�������� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �ſ��� %d�� ���ظ� ������.\n\n", Atk * 8);
					mlife -= Atk * 8;
				}
				else {
					printf("�ſ��� %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
			}
			else if (skill5 == 1 && skillrand > 35 && skillrand <= 40) {
				printf("����Ʈ���� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �ſ��� %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("�ſ��� %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
				effcet = 1;
			}
			else {
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! �ſ��� %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
				else {
					printf("�ſ��� %d�� ���ظ� ������.\n\n", Atk);
					mlife -= Atk;
				}
			}
		}
		if (mlife <= 0) {
			mlife = 0;
			break;
		}
		Sleep(500);
		printf("���� ����!\n\n");
		Sleep(500);
		if (matk <= Def) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
		}
		else if (bar == 1) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
			bar = 0;
		}
		else if (effcet == 1) {
			printf("���� ������ �����ߴ�\n\n");
			effcet = 0;
		}
		else {
			printf("�÷��̾ %d�� ���ظ� �Ծ���.\n\n", matk - Def);
			NHp -= matk - Def;
		}
		if (NHp <= 0) {
			printf("�÷��̾��� ���� ���Ͽ� ��������\n\nGame Over\n");
			printf("press space to end");
			stop = 1;
			while (1) {
				if (GetAsyncKeyState(VK_SPACE)) break;
			}
			break;
		}

	}
	if (mlife == 0) {
		printf("�¸�! 1048576000��带 ŉ���ߴ�!\n\n");
		Gold += 1548576000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void lastboss() {
	z = 0;
	int mlife = 20000;
	int matk = 800;
	srand((unsigned int)time(NULL));
	system("cls");
	
	while (1) {
		if(speed < 22) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		FILE* read = fopen("lastboss.txt", "r");
		char buffer[10000] = { 0, };
		fread(buffer, 1, 10000, read);
		printf("%s", buffer);
		fclose(read);
		skillrand = rand() % 100 + 1;
		crecrt = rand() % 100 + 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		Sleep(500);
		if (z == 0) {
			gotoxy(0, 0);
		}
		printf("�÷��̾��� ����!\n\n");
		z = 1;
		Sleep(500);
		if (skillon == 0) {
			if (crecrt <= Crt) {
				printf("ġ��Ÿ! ������������ %d�� ���ظ� ������.\n\n", Atk * 2);
				mlife -= Atk * 2;
			}
			else {
				printf("������������ %d�� ���ظ� ������.\n\n", Atk);
				mlife -= Atk;
			}
		}
		else if (skillon == 1) {
			if (skill1 == 1 && skillrand <= 10) {
				printf("���̾�� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ������������ %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
				else {
					printf("������������ %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
			}
			else if (skill2 == 1 && skillrand > 10 && skillrand <= 15) {
				printf("�踮� �ߵ�!\n\n");
				bar = 1;
			}
			else if (skill3 == 1 && skillrand > 15 && skillrand <= 25) {
				printf("������ �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ������������ %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("������������ %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
			}
			else if (skill4 == 1 && skillrand > 25 && skillrand <= 35) {
				printf("�������� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ������������ %d�� ���ظ� ������.\n\n", Atk * 8);
					mlife -= Atk * 8;
				}
				else {
					printf("������������ %d�� ���ظ� ������.\n\n", Atk * 4);
					mlife -= Atk * 4;
				}
			}
			else if (skill5 == 1 && skillrand > 35 && skillrand <= 40) {
				printf("����Ʈ���� �ߵ�!\n\n");
				Sleep(500);
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ������������ %d�� ���ظ� ������.\n\n", Atk * 6);
					mlife -= Atk * 6;
				}
				else {
					printf("������������ %d�� ���ظ� ������.\n\n", Atk * 3);
					mlife -= Atk * 3;
				}
				effcet = 1;
			}
			else {
				if (crecrt <= Crt) {
					printf("ġ��Ÿ! ������������ %d�� ���ظ� ������.\n\n", Atk * 2);
					mlife -= Atk * 2;
				}
				else {
					printf("������������ %d�� ���ظ� ������.\n\n", Atk);
					mlife -= Atk;
				}
			}
		}
		if (mlife <= 0) {
			mlife = 0;
			break;
		}
		Sleep(500);
		printf("���������� ����!\n\n");
		Sleep(500);
		if (matk <= Def) {
			system("cls");
			while (1) {
				gotoxy(48, 0);
				printf("press space to Defence");
				if (GetAsyncKeyState(VK_SPACE)) break;
				Sleep(50);
			}
			LASTBOSSBATTLE();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		else if (bar == 1) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
			bar = 0;
		}
		else if (effcet == 1) {
			printf("���������� ������ �����ߴ�\n\n");
			effcet = 0;
		}
		else {
			system("cls");
			while (1) {
				gotoxy(48, 0);
				printf("press space to Defence");
				if (GetAsyncKeyState(VK_SPACE)) break;
				Sleep(50);
			}
			LASTBOSSBATTLE();
		}
		if (NHp <= 0) {
			printf("�÷��̾��� ���� ���Ͽ� ��������\n\nGame Over\n");
			printf("press space to end");
			stop = 1;
			while (1) {
				if (GetAsyncKeyState(VK_SPACE)) break;
			}
			break;
		}
		speed += 2;
		if (speed == 50) speed -= 2;

	}
	if (mlife == 0) {
		int color;
		while (1) {
			color = rand() % 15 + 1;
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
			FILE* read = fopen("VicTory.txt", "r");
			char buffer[10000] = { 0, };
			fread(buffer, 1, 10000, read);
			printf("%s", buffer);
			fclose(read);
			stop = 1;
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}

void loading() {
	srand((unsigned int)time(NULL));
	gotoxy(41, 15);
	printf("loading");
	for (int i = 0; i < 10; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), rand() % 10 + 1);
		gotoxy(49 + 2 * i, 15);
		printf("[]");
		Sleep(250);
	}
}
void skillshop() {
	int key;
	int z = 33, c = 10;

	while (1) {
		system("mode con cols=120 lines=40");
		system("cls");
		if (z == 33) {
			gotoxy(30, 16);
			printf("���� : 10000. 10�� Ȯ���� ���. ���ݷ��� �ι��� ���ظ� ������");
		}
		else if (z == 44) {
			gotoxy(30, 16);
			printf("���� : 15000. 5�� Ȯ���� ���. �̹��� ����� ������ ����Ѵ�");
		}
		else if (z == 55) {
			gotoxy(30, 16);
			printf("���� : 20000. 10�� Ȯ���� ���. ���ݷ��� ������ ���ظ� ������");
		}
		else if (z == 66) {
			gotoxy(30, 16);
			printf("���� : 40000. 10�� Ȯ���� ���. ���ݷ��� �׹��� ���ظ� ������");
		}
		else if (z == 77) {
			gotoxy(20, 16);
			printf("���� : 100000. 5�� Ȯ���� ���. ���ݷ��� ������ ���ظ� ������ ���� �����ൿ�� �����Ѵ�.");
		}
		else if (z == 88) {
			gotoxy(58, 16);
			printf("������");
		}
		gotoxy(58, 5);
		printf("����\n\n            ���� ��� : %d", Gold);
		gotoxy(35, 10);
		printf("���̾   �踮��     ����       ������     ����Ʈ��   ���ư���");
		gotoxy(z, c);
		printf("��");
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
				if (Gold >= 10000 && skill1 == 0) {
					skill1 = 1;
					Gold -= 10000;
					skillon = 1;
				}
			}
			else if (z == 44) {
				if (Gold >= 15000 && skill2 == 0) {
					skill2 = 1;
					Gold -= 15000;
					skillon = 1;
				}
			}
			else if (z == 55) {
				if (Gold >= 20000 && skill3 == 0) {
					skill3 = 1;
					Gold -= 20000;
					skillon = 1;
				}
			}
			else if (z == 66) {
				if (Gold >= 40000 && skill4 == 0) {
					skill4 = 1;
					Gold -= 40000;
					skillon = 1;
				}
			}
			else if (z == 77) {
				if (Gold >= 100000 && skill5 == 0) {
					skill5 = 1;
					Gold -= 100000;
					skillon = 1;
				}
			}
			else if (z == 88) break;
		}
	}
}	
void serch() {
	int z = 38, c = 13;
	int key;
	while (1) {
		system("cls");
		switch (monster) {
		case 0:
			gotoxy(46, 5);
			printf(" �߻��� ���� �߰��ߴ�.");
			break;
		case 1:
			gotoxy(46, 5);
			printf(" �߻��� �������� �߰��ߴ�.");
			break;
		case 2:
			gotoxy(46, 5);
			printf(" �߻��� �������� �߰��ߴ�.");
			break;
		case 3:
			gotoxy(46, 5);
			printf(" �߻��� ���Ҹ� �߰��ߴ�.");
			break;
		case 4:
			gotoxy(46, 5);
			printf(" �߻��� ���㸦 �߰��ߴ�.");
			break;
		case 5:
			gotoxy(46, 5);
			printf(" �߻��� �������� �߰��ߴ�.");
			break;
		case 6:
			gotoxy(46, 5);
			printf(" �߻��� ��ũ�� �߰��ߴ�.");
			break;
		case 7:
			gotoxy(46, 5);
			printf(" �߻��� ������ �߰��ߴ�.");
			break;
		case 8:
			gotoxy(46, 5);
			printf(" �߻��� ���� �߰��ߴ�.");
			break;
		case 9:
			gotoxy(46, 5);
			printf(" �߻��� ������ ��縦 �߰��ߴ�.");
			break;
		case 10:
			gotoxy(46, 5);
			printf(" �߻��� ���ĸ��� �߰��ߴ�.");
			break;
		case 11:
			gotoxy(46, 5);
			printf(" �߻��� �巡���� �߰��ߴ�.");
			break;
		case 12:
			gotoxy(46, 5);
			printf(" �߻��� ��ź�� �߰��ߴ�.");
			break;
		case 13:
			gotoxy(46, 5);
			printf(" �߻��� �Ǹ��� �߰��ߴ�.");
			break;
		case 14:
			gotoxy(46, 5);
			printf(" �߻��� ����� �߰��ߴ�.");
			break;
		case 15:
			gotoxy(46, 5);
			printf(" �߻��� ���� �߰��ߴ�.");
			break;
		case 16:
			gotoxy(46, 5);
			printf(" �߻��� ���������� �߰��ߴ�.");
			break;

		}
		gotoxy(40, 13);
		printf("�ο��                           ����ģ��");
		if (z >= 50) {
			gotoxy(49, 17);
			printf("ü�� %d �Ҹ�", NHp / 2);
		}
		gotoxy(z, c);
		printf("��");
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
			Sleep(100);
			if (z == 38) {
				if (monster == 0) dog();
				else if (monster == 1) slime();
				else if (monster == 2) frug();
				else if (monster == 3) goat();
				else if (monster == 4) bat();
				else if (monster == 5) lizard();
				else if (monster == 6) ork();
				else if (monster == 7) imp();
				else if (monster == 8) undead();
				else if (monster == 9) deathknight();
				else if (monster == 10) dragonfly();
				else if (monster == 11) dragon();
				else if (monster == 12) satan();
				else if (monster == 13) demon();
				else if (monster == 14) deathking();
				else if (monster == 15) GOD();
				else if (monster == 16) lastboss();
				system("mode con cols=120 lines=40");
				break;
			}
			else if (z == 71) {
				NHp = NHp / 2;
				system("mode con cols=120 lines=40");
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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		FILE* read = fopen("title.txt", "r");
		char buffer[10000] = { 0, };
		fread(buffer, 1, 10000, read);
		printf("%s", buffer);
		fclose(read);
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 60; j++) {
				gotoxy(2 * j, i);
				if (start[j][i] == 0) printf("  ");
				else if (start[j][i] == 1) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
					printf("��");
				}
				else if (start[j][i] == 2) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					printf("��");
				}
				else if (start[j][i] == 3) printf("��");
				else if (start[j][i] == 4) printf("��");
				else if (start[j][i] == 5) printf("��");
				else if (start[j][i] == 6) printf("��");
				else if (start[j][i] == 7) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					printf("��");
				}
			}
			printf("\n");		
		}
		
		gotoxy(40, 10);
		printf("�÷���                           ����");
		if (z <= 50) {
			gotoxy(48, 17);
			printf("press space to start");
		}
		else if (z >= 50) {
			gotoxy(49, 17);
			printf("press space to end");
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		gotoxy(z, c);
		printf("��");
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
			Sleep(100);
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
	srand((unsigned int)time(NULL));
	system("cls");
	while (1) {
		
		if (boss == 1) {
			monster = 16;
			serch();
			break;
		}
		else if (used > 2097152000) {
			monster = 15 + up;
			if (monster > 16) monster = 16;
			serch();
			break;
		}
		else if (used > 524288000) {
			monster = 14 + up;
			if (monster > 16) monster = 16;
			serch();
			break;
		}
		else if (used > 262144000) {
			monster = 13 + up;
			if (monster > 16) monster = 16;
			serch();
			break;
		}
		else if (used > 65536000) {
			monster = 12 + up;
			if (monster > 16) monster = 16;
			serch();
			break;
		}
		else if (used > 32768000) {
			monster = 11 + up;
			if (monster > 16) monster = 16;
			serch();
			break;
		}
		else if (used > 8192000) {
			monster = 10 + up;
			if (monster > 16) monster = 16;
			serch();
			break;
		}
		else if (used > 4096000) {
			monster = 9 + up;
			if (monster > 16) monster = 16;
			serch();
			break; 
		}
		else if (used > 1024000) {
			monster = 8 + up;
			if (monster > 16) monster = 16;
			serch();
			break;
		}
		else if (used > 512000) {
			monster = 7 + up;
			if (monster > 16) monster = 16;
			serch();
			break;
		}
		else if (used > 128000) {
			monster = 6 + up;
			if (monster > 16) monster = 16;
			serch();
			break;
		}
		else if (used > 64000) {
			monster = 5 + up;
			if (monster > 16) monster = 16;
			serch();
			break;
		}
		else if (used > 32000) {
			monster = 4 + up;
			if (monster > 16) monster = 16;
			serch();
			break;
		}
		else if (used > 8000) {
			monster = 3 + up;
			if (monster > 16) monster = 16;
			serch();
			break;
		}
		else if (used > 2000) {
			monster = 2 + up;
			if (monster > 16) monster = 16;
			serch();
			break;
		}
		else if (used > 0) {
			monster = 1 + up;
			if (monster > 16) monster = 16;
			serch();
			break;
		}
		else if (used == 0) {
			monster = 0 + up;
			if (monster > 16) monster = 16;
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
			printf("���� : %d. ü���� ���� ȸ���Ѵ�", Heal);
		}
		else if (z == 44) {
			gotoxy(48, 16);
			printf("���� : %d. ���ݷ� 10 ����", AtkC);
		}
		else if (z == 55) {
			gotoxy(48, 16);
			printf("���� : %d. ü�� 100 ����", HpC);
		}
		else if (z == 66) {
			gotoxy(48, 16);
			printf("���� : %d. ���� 2 ����", DefC);
		}
		else if (z == 77) {
			gotoxy(46, 16);
			printf("���� : %d. ġ��Ÿ Ȯ�� 10% ����", CrtC);
		}
		else if (z == 88) {
			gotoxy(58, 16);
			printf("������");
		}
		gotoxy(58, 5);
		printf("����\n\n            ���� ��� : %d", Gold);
		gotoxy(35, 10);
		printf("ȸ��       ���ݷ�     ü��       ����     ġ��Ȯ��   ���ư���");
		gotoxy(z, c);
		printf("��");
		gotoxy(0, 0);
		printf("%d", used);
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
				if (Gold >= Heal)
					Gold -= Heal;
					used += Heal;
					Heal += Heal;
					NHp = Hp;
					
			}
			else if (z == 44) {
				if (Gold >= AtkC) {
					Gold -= AtkC;
					used += AtkC;
					AtkC += AtkC;
					Atk += 10;
					
				}
			}
			else if (z == 55) {
				if (Gold >= HpC) {
					Gold -= HpC;
					used += HpC;
					HpC += HpC;
					Hp += 100;
					NHp += 100;
					
				}
			}
			else if (z == 66) {
				if (Gold >= DefC) {
					Gold -= DefC;
					used += DefC;
					DefC += DefC;
					Def += 2;
					
				}
			}
			else if (z == 77) {
				if (Gold > CrtC && Crt <= 90) {
					Gold -= CrtC;
					used += CrtC;
					CrtC += CrtC;
					Crt += 10;
					
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
		printf("ü�� : %d / %d\n", Hp, NHp);
		printf("���ݷ� : %d\n", Atk);
		printf("���� : %d\n", Def);
		printf("ġ��Ÿ Ȯ�� : %d%\n", Crt);
		printf("���� ��� : %d%\n", Gold);
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
	int z = 33, c = 10;

	while (1) {
		system("mode con cols=120 lines=40");
		system("cls");
		gotoxy(58, 5);
		printf("����");
		gotoxy(35, 10);
		printf("����       ��ų����   ����       �����     ����");
		gotoxy(z, c);
		printf("��");
		key = _getch();

		switch (key) {
		case 75:
			if (z <= 38) break;
			z -= 11;
			break;
		case 77:
			if (z >= 70) break;
			z += 11;
			break;
		default:
			break;
		}
		if (GetAsyncKeyState(VK_SPACE)) {
			Sleep(100);
			if (z == 33) shop();
			else if (z == 44) skillshop();
			else if (z == 55) state();
			else if (z == 66) break;
			else if (z == 77) {
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
		printf("������ ���ư��ðڽ��ϱ�?");
		gotoxy(40, 10);
		printf("��                               �ƴϿ�");
		gotoxy(z, c);
		printf("��");
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
			Sleep(100);
			if (z <= 50) {
				vil2 = 2;
				vil();
			}
			else if (z >= 50) {
				system("mode con cols=120 lines=40");
				break;
			}
		}
		if (vil2 == 2) {
			vil2 = 1;
			system("mode con cols=120 lines=40");
			break;
		}
	}
}
void maps() {
	int key;
	int x = 0, y = 24;
	encounter = 0;
	srand((unsigned int)time(NULL));
	system("cls");
	while (1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 60; j++) {
				gotoxy(j * 2, 27 + i);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				if (map[j][i] == 0) printf("  ");
				else if (map[j][i] == 1) printf("��");
				else if (map[j][i] == 2) printf("��");
				else if (map[j][i] == 3) printf("��");

			}
			printf("\n");
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				if (j == 0) {
					gotoxy(x - 2, y + i);
					printf("  ");
				}
				else if (j == 2) {
					gotoxy(x + j * 2 + 2, y + i);
					printf("  ");
				}
				gotoxy(x + j * 2, y + i);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				if (player[j][i] == 0) printf("  ");
				else if (player[j][i] == 1) printf("��");
				else if (player[j][i] == 2) printf("��");
				else if (player[j][i] == 3) printf("��");
				else if (player[j][i] == 4) printf("��");
			}
		}
		gotoxy(100, 0);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("HP: %d / %d", Hp, NHp);
		gotoxy(100, 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		printf("Gold : %d", Gold);
		gotoxy(0, 0);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		printf("EnCounter : ");
		for (int i = 0; i <= encounter; i++) {
			gotoxy(12 + 2 * i, 0);
			printf("��");
		}
		gotoxy(0, 1);
		printf("%d", monster + up);
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
		
		if (GetAsyncKeyState(VK_F1)) { 
			Sleep(100);
			up++; 
		}
		if (GetAsyncKeyState(VK_F2)) {
			Sleep(100);
			Gold += 1000000000;
		}
		pos = rand() % 500 + 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		if (pos < encounter) battle();
		if (stop == 1)break;
	}
}



int main() {
	CursorView();
	int key;
	int z = 38, c = 10;
	while (1) {
		
		system("mode con cols=120 lines=40");
		if (stop == 0) startm();
		if (stop == 2) loading();
		if (stop == 1) return 0;
		maps();
		Sleep(100);
		if(NHp <= 0){
			while (1) {
				system("mode con cols=120 lines=40");
				system("cls");
				gotoxy(46, 5);
				printf("��Ȱ�Ͻðڽ��ϱ�? (1ȸ ����)");
				gotoxy(40, 10);
				printf("��                               �ƴϿ�");
				gotoxy(z, c);
				printf("��");
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
					Sleep(100);
					if (z <= 50) {
						NHp = Hp;
						stop = 2;
						maps();
						break;
					}
					else if (z >= 50) {
						break;
					}
				}
			}
		}

	}

	return 0;
}