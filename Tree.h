#pragma once
#include "Utensils.h"

struct Tree
{
	Tree* Left;
	Tree* Right;
	KitchenUtensils* item;
	//unsigned long long Data;
	int Height;
};

typedef Tree* PTree;

// �������� ������ � ������������
int height(PTree p);
void newHeight(PTree p);
int sayBalance(PTree p);
void LL(PTree& p);
void RR(PTree& p);
void RL(PTree& p);
void LR(PTree& p);
void Balance(PTree& p);
void Insert(PTree& Root, KitchenUtensils* item, bool& wasInsert);

// �������� ������ � �������������
void deletFromTree(PTree& root, int inventoryNumber, int& countRotation, bool inMin);
PTree delInLeft(PTree& root, int& countRotation);
PTree delInRight(PTree& root, int& countRotation);
void BalanceAfterDel(PTree& p, int& countRotation);

// ������������ ������ ��-��� ������
void DeleteTree(PTree& R);

//// ��������� ������ �� ������ ��� ���������� number - ����� �� �����
//void InfFind(PTree root, unsigned long long& number, unsigned long long& tmp, bool& find);

// ������ ������ �� ���
void PrintTree(PTree R, int level);
