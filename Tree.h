#pragma once

typedef Tree* PTree;

class Tree
{

private:
	Tree* Left;
	Tree* Right;
	unsigned long long Data;
	int Height;

	// Создание дерева и болансировка
	int height(PTree p);
	void newHeight(PTree p);
	int sayBalance(PTree p);
	void LL(PTree& p);
	void RR(PTree& p);
	void RL(PTree& p);
	void LR(PTree& p);
	void Balance(PTree& p);
	void Insert(PTree& Root, unsigned long long x, bool& wasInsert);

	// Удаление вершин с болансировкой
	void deletFromTree(PTree& root, unsigned long long x, int& countRotation, bool inMin);
	PTree delInLeft(PTree& root, int& countRotation);
	PTree delInRight(PTree& root, int& countRotation);
	void BalanceAfterDel(PTree& p, int& countRotation);

	// Освобождение памяти из-под дерева
	void DeleteTree(PTree& R);

	// Инфиксный проход по дереву для нахождения number - числа по счёту
	void InfFind(PTree root, unsigned long long& number, unsigned long long& tmp, bool& find);


	// Печать дерева на бок
	void PrintTree(PTree R, int level);



};
