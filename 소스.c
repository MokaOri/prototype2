#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
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
int Gold = 10000000;
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
int map[60][19] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1},
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
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1}
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
		crecrt = rand() % 100 + 1;
		Sleep(500);
		if (z == 0) {
			gotoxy(0, 0);
		}
		printf("�÷��̾��� ����!\n\n");
		Sleep(500);
		if (crecrt <= Crt) {
			printf("ġ��Ÿ! ������ %d�� ���ظ� ������.\n\n", Atk * 2);
			mlife -= Atk * 2;
		}
		else {
			printf("������ %d�� ���ظ� ������.\n\n", Atk);
			mlife -= Atk;
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
		printf("�¸�! 100��带 ŉ���ߴ�!\n\n");
		Gold += 100;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void slime() {
	int mlife = 80;
	int matk = 10;
	srand((unsigned int)time(NULL));
	system("cls");
	while (1) {
		crecrt = rand() % 100 + 1;
		Sleep(500);
		printf("�÷��̾��� ����!\n\n");
		Sleep(500);
		if (crecrt <= Crt) {
			printf("ġ��Ÿ! �����ӿ��� %d�� ���ظ� ������.\n\n", Atk * 2);
			mlife -= Atk * 2;
		}
		else {
			printf("�����ӿ��� %d�� ���ظ� ������.\n\n", Atk);
			mlife -= Atk;
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
		printf("�¸�! 200��带 ŉ���ߴ�!\n\n");
		Gold += 200;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void frug() {
	int mlife = 90;
	int matk = 12;
	srand((unsigned int)time(NULL));
	system("cls");
	while (1) {
		crecrt = rand() % 100 + 1;
		Sleep(500);
		printf("�÷��̾��� ����!\n\n");
		Sleep(500);
		if (crecrt <= Crt) {
			printf("ġ��Ÿ! ���������� %d�� ���ظ� ������.\n\n", Atk * 2);
			mlife -= Atk * 2;
		}
		else {
			printf("���������� %d�� ���ظ� ������.\n\n", Atk);
			mlife -= Atk;
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
		printf("�¸�! 300��带 ŉ���ߴ�!\n\n");
		Gold += 300;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void goat() {
	int mlife = 100;
	int matk = 15;
	srand((unsigned int)time(NULL));
	system("cls");
	while (1) {
		crecrt = rand() % 100 + 1;
		Sleep(500);
		printf("�÷��̾��� ����!\n\n");
		Sleep(500);
		if (crecrt <= Crt) {
			printf("ġ��Ÿ! ���ҿ��� %d�� ���ظ� ������.\n\n", Atk * 2);
			mlife -= Atk * 2;
		}
		else {
			printf("���ҿ��� %d�� ���ظ� ������.\n\n", Atk);
			mlife -= Atk;
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
		printf("�¸�! 400��带 ŉ���ߴ�!\n\n");
		Gold += 400;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void bat() {
	int mlife = 200;
	int matk = 20;
	srand((unsigned int)time(NULL));
	system("cls");
	while (1) {
		crecrt = rand() % 100 + 1;
		Sleep(500);
		printf("�÷��̾��� ����!\n\n");
		Sleep(500);
		if (crecrt <= Crt) {
			printf("ġ��Ÿ! ���㿡�� %d�� ���ظ� ������.\n\n", Atk * 2);
			mlife -= Atk * 2;
		}
		else {
			printf("���㿡�� %d�� ���ظ� ������.\n\n", Atk);
			mlife -= Atk;
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
void lizard() {
	int mlife = 300;
	int matk = 40;
	srand((unsigned int)time(NULL));
	system("cls");
	while (1) {
		crecrt = rand() % 100 + 1;
		Sleep(500);
		printf("�÷��̾��� ����!\n\n");
		Sleep(500);
		if (crecrt <= Crt) {
			printf("ġ��Ÿ! �����쿡�� %d�� ���ظ� ������.\n\n", Atk * 2);
			mlife -= Atk * 2;
		}
		else {
			printf("�����쿡�� %d�� ���ظ� ������.\n\n", Atk);
			mlife -= Atk;
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
		printf("�¸�! 700��带 ŉ���ߴ�!\n\n");
		Gold += 700;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void ork() {
	int mlife = 350;
	int matk = 50;
	srand((unsigned int)time(NULL));
	system("cls");
	while (1) {
		crecrt = rand() % 100 + 1;
		Sleep(500);
		printf("�÷��̾��� ����!\n\n");
		Sleep(500);
		if (crecrt <= Crt) {
			printf("ġ��Ÿ! ��ũ���� %d�� ���ظ� ������.\n\n", Atk * 2);
			mlife -= Atk * 2;
		}
		else {
			printf("��ũ���� %d�� ���ظ� ������.\n\n", Atk);
			mlife -= Atk;
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
void imp() {
	int mlife = 500;
	int matk = 80;
	srand((unsigned int)time(NULL));
	system("cls");
	while (1) {
		crecrt = rand() % 100 + 1;
		Sleep(500);
		printf("�÷��̾��� ����!\n\n");
		Sleep(500);
		if (crecrt <= Crt) {
			printf("ġ��Ÿ! �������� %d�� ���ظ� ������.\n\n", Atk * 2);
			mlife -= Atk * 2;
		}
		else {
			printf("�������� %d�� ���ظ� ������.\n\n", Atk);
			mlife -= Atk;
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
		printf("�¸�! 1500��带 ŉ���ߴ�!\n\n");
		Gold += 1500;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void undead() {
	int mlife = 800;
	int matk = 100;
	srand((unsigned int)time(NULL));
	system("cls");
	while (1) {
		crecrt = rand() % 100 + 1;
		Sleep(500);
		printf("�÷��̾��� ����!\n\n");
		Sleep(500);
		if (crecrt <= Crt) {
			printf("ġ��Ÿ! ���񿡰� %d�� ���ظ� ������.\n\n", Atk * 2);
			mlife -= Atk * 2;
		}
		else {
			printf("���񿡰� %d�� ���ظ� ������.\n\n", Atk);
			mlife -= Atk;
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
		printf("�¸�! 2000��带 ŉ���ߴ�!\n\n");
		Gold += 2000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void deathknight() {
	int mlife = 1000;
	int matk = 120;
	srand((unsigned int)time(NULL));
	system("cls");
	while (1) {
		crecrt = rand() % 100 + 1;
		Sleep(500);
		printf("�÷��̾��� ����!\n\n");
		Sleep(500);
		if (crecrt <= Crt) {
			printf("ġ��Ÿ! ������ ��翡�� %d�� ���ظ� ������.\n\n", Atk * 2);
			mlife -= Atk * 2;
		}
		else {
			printf("������ ��翡�� %d�� ���ظ� ������.\n\n", Atk);
			mlife -= Atk;
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
		printf("�¸�! 3000��带 ŉ���ߴ�!\n\n");
		Gold += 3000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void dragonfly() {
	int mlife = 1500;
	int matk = 150;
	srand((unsigned int)time(NULL));
	system("cls");
	while (1) {
		crecrt = rand() % 100 + 1;
		Sleep(500);
		printf("�÷��̾��� ����!\n\n");
		Sleep(500);
		if (crecrt <= Crt) {
			printf("ġ��Ÿ! ���ĸ����� %d�� ���ظ� ������.\n\n", Atk * 2);
			mlife -= Atk * 2;
		}
		else {
			printf("���ĸ����� %d�� ���ظ� ������.\n\n", Atk);
			mlife -= Atk;
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
void dragon() {
	int mlife = 2000;
	int matk = 200;
	srand((unsigned int)time(NULL));
	system("cls");
	while (1) {
		crecrt = rand() % 100 + 1;
		Sleep(500);
		printf("�÷��̾��� ����!\n\n");
		Sleep(500);
		if (crecrt <= Crt) {
			printf("ġ��Ÿ! �巡�￡�� %d�� ���ظ� ������.\n\n", Atk * 2);
			mlife -= Atk * 2;
		}
		else {
			printf("�巡�￡�� %d�� ���ظ� ������.\n\n", Atk);
			mlife -= Atk;
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
		printf("�¸�! 10000��带 ŉ���ߴ�!\n\n");
		Gold += 10000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void satan() {
	int mlife = 2500;
	int matk = 250;
	srand((unsigned int)time(NULL));
	system("cls");
	while (1) {
		crecrt = rand() % 100 + 1;
		Sleep(500);
		printf("�÷��̾��� ����!\n\n");
		Sleep(500);
		if (crecrt <= Crt) {
			printf("ġ��Ÿ! ��ź���� %d�� ���ظ� ������.\n\n", Atk * 2);
			mlife -= Atk * 2;
		}
		else {
			printf("��ź���� %d�� ���ظ� ������.\n\n", Atk);
			mlife -= Atk;
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
		printf("�¸�! 15000��带 ŉ���ߴ�!\n\n");
		Gold += 15000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void demon() {
	int mlife = 3000;
	int matk = 300;
	srand((unsigned int)time(NULL));
	system("cls");
	while (1) {
		crecrt = rand() % 100 + 1;
		Sleep(500);
		printf("�÷��̾��� ����!\n\n");
		Sleep(500);
		if (crecrt <= Crt) {
			printf("ġ��Ÿ! �Ǹ����� %d�� ���ظ� ������.\n\n", Atk * 2);
			mlife -= Atk * 2;
		}
		else {
			printf("�Ǹ����� %d�� ���ظ� ������.\n\n", Atk);
			mlife -= Atk;
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
		printf("�¸�! 20000��带 ŉ���ߴ�!\n\n");
		Gold += 20000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void deathking() {
	int mlife = 5000;
	int matk = 400;
	srand((unsigned int)time(NULL));
	system("cls");
	while (1) {
		crecrt = rand() % 100 + 1;
		Sleep(500);
		printf("�÷��̾��� ����!\n\n");
		Sleep(500);
		if (crecrt <= Crt) {
			printf("ġ��Ÿ! ��տ��� %d�� ���ظ� ������.\n\n", Atk * 2);
			mlife -= Atk * 2;
		}
		else {
			printf("��տ��� %d�� ���ظ� ������.\n\n", Atk);
			mlife -= Atk;
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
		printf("�¸�! 50000��带 ŉ���ߴ�!\n\n");
		Gold += 50000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void GOD() {
	int mlife = 10000;
	int matk = 500;
	srand((unsigned int)time(NULL));
	system("cls");
	while (1) {
		crecrt = rand() % 100 + 1;
		Sleep(500);
		printf("�÷��̾��� ����!\n\n");
		Sleep(500);
		if (crecrt <= Crt) {
			printf("ġ��Ÿ! �ſ��� %d�� ���ظ� ������.\n\n", Atk * 2);
			mlife -= Atk * 2;
		}
		else {
			printf("�ſ��� %d�� ���ظ� ������.\n\n", Atk);
			mlife -= Atk;
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
		printf("�¸�! 100000��带 ŉ���ߴ�!\n\n");
		Gold += 100000;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
		}
	}
}
void lastboss() {
	int mlife = 20000;
	int matk = 800;
	srand((unsigned int)time(NULL));
	system("cls");
	while (1) {
		crecrt = rand() % 100 + 1;
		Sleep(500);
		printf("�÷��̾��� ����!\n\n");
		Sleep(500);
		if (crecrt <= Crt) {
			printf("ġ��Ÿ! ������������ %d�� ���ظ� ������.\n\n", Atk * 2);
			mlife -= Atk * 2;
		}
		else {
			printf("������������ %d�� ���ظ� ������.\n\n", Atk);
			mlife -= Atk;
		}
		if (mlife <= 0) {
			mlife = 0;
			break;
		}
		Sleep(500);
		printf("���������� ����!\n\n");
		Sleep(500);
		if (matk <= Def) {
			printf("�÷��̾ 0�� ���ظ� �Ծ���.\n\n");
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
		printf("�¸�! 100��带 ŉ���ߴ�!\n\n");
		Gold += 100;
		printf("press space to continue");
		while (1) {
			if (GetAsyncKeyState(VK_SPACE)) break;
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
				break;
			}
			else if (z == 71) {
				NHp = NHp / 2;
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
				else if (start[j][i] == 1) printf("��");
				else if (start[j][i] == 2) printf("��");
				else if (start[j][i] == 3) printf("��");
				else if (start[j][i] == 4) printf("��");
				else if (start[j][i] == 5) printf("��");
				else if (start[j][i] == 6) printf("��");
				else if (start[j][i] == 7) printf("��");
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
		system("mode con cols=120 lines=40");
		pos = rand();
		
		if (pos < used / 100000 - bravo) {
			monster = 16;
			serch();
			break;
		}
		else if (pos < used / 70000 - bravo) {
			monster = 15;
			serch();
			break;
		}
		else if (pos < used / 50000 - bravo) {
			monster = 14;
			serch();
			break;
		}
		else if (pos < used / 20000 - bravo) {
			monster = 13;
			serch();
			break;
		}
		else if (pos < used / 10000 - bravo) {
			monster = 12;
			serch();
			break;
		}
		else if (pos < used / 8000 - bravo) {
			monster = 11;
			serch();
			break;
		}
		else if (pos < used / 5000 - bravo) {
			monster = 10;
			serch();
			break;
		}
		else if (pos < used / 2000 - bravo) {
			monster = 9;
			serch();
			break;
		}
		else if (pos < used / 1000 - bravo) {
			monster = 8;
			serch();
			break;
		}
		else if (pos < used / 500 - bravo) {
			monster = 7;
			serch();
			break;
		}
		else if (pos < used / 100 - bravo) {
			monster = 6;
			serch();
			break;
		}
		else if (pos < used / 10 - bravo) {
			monster = 5;
			serch();
			break;
		}
		else if (pos < used - bravo) {
			monster = 4;
			serch();
			break;
		}
		else if (pos < used * 2 - bravo) {
			monster = 3;
			serch();
			break;
		}
		else if (pos < used * 10 - bravo) {
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
					Heal += Heal;
					NHp = Hp;
					used += Heal;
			}
			else if (z == 44) {
				if (Gold >= AtkC) {
					Gold -= AtkC;
					AtkC += AtkC;
					Atk += 10;
					used += AtkC;
				}
			}
			else if (z == 55) {
				if (Gold >= HpC) {
					Gold -= HpC;
					HpC += HpC;
					Hp += 100;
					NHp += 100;
					used += HpC;
				}
			}
			else if (z == 66) {
				if (Gold >= DefC) {
					Gold -= DefC;
					DefC += DefC;
					Def += 2;
					used += DefC;
				}
			}
			else if (z == 77) {
				if (Gold > CrtC && Crt <= 90) {
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
	int z = 38, c = 10;

	while (1) {
		system("mode con cols=120 lines=40");
		system("cls");
		gotoxy(58, 5);
		printf("����");
		gotoxy(40, 10);
		printf("����       ����       �����     ����");
		gotoxy(z, c);
		printf("��");
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
				else if (map[j][i] == 1) printf("��");
				else if (map[j][i] == 2) printf("��");
				else if (map[j][i] == 3) printf("��");

			}
			printf("\n");
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				gotoxy(x + j * 2, y + i);
				if (player[j][i] == 0) printf("  ");
				else if (player[j][i] == 1) printf("��");
				else if (player[j][i] == 2) printf("��");
				else if (player[j][i] == 3) printf("��");
				else if (player[j][i] == 4) printf("��");
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
	CursorView();

	while (1) {
		
		system("mode con cols=120 lines=40");
		if (stop == 0) startm();
		if (stop == 1) return 0;
		maps();








		
	}

	return 0;
}