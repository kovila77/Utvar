#include <iostream>
#include <iomanip>
//#include <fstream>
//#include <string>
#include "Tree.h"
#define max(a,b) (((a) > (b)) ? (a) : (b))
using namespace std;

int Tree::height(PTree p)
{
	return p == nullptr ? 0 : p->Height;
}

void Tree::newHeight(PTree p)
{
	p->Height = max(height(p->Left), height(p->Right)) + 1;
}

int Tree::sayBalance(PTree p)
{
	return height(p->Right) - height(p->Left);
}

void Tree::LL(PTree& p)
{
	PTree LeftSon = p->Left;
	p->Left = LeftSon->Right;
	LeftSon->Right = p;
	newHeight(p);
	p = LeftSon;
	newHeight(p);
}

void Tree::RR(PTree& p)
{
	PTree RightSon = p->Right;
	p->Right = RightSon->Left;
	RightSon->Left = p;
	newHeight(p);
	p = RightSon;
	newHeight(p);
}

void Tree::RL(PTree& p)
{
	LL(p->Right);
	RR(p);
}

void Tree::LR(PTree& p)
{
	RR(p->Left);
	LL(p);
}

void Tree::Balance(PTree& p)
{
	if (sayBalance(p) == 2)
	{
		if (sayBalance(p->Right) >= 0)
		{
			RR(p);
		}
		else
		{
			RL(p);
		}
	}
	else
	{
		if (sayBalance(p) == -2)
		{
			if (sayBalance(p->Left) <= 0)
			{
				LL(p);
			}
			else
			{
				LR(p);
			}
		}
	}
}

void Tree::Insert(PTree& Root, unsigned long long x, bool& wasInsert)
{
	if (Root == nullptr)
	{
		Root = new Tree;
		Root->Data = x;
		Root->Height = 1;
		Root->Right = Root->Left = nullptr;
	}
	else
	{
		if (x < Root->Data)
		{
			Insert(Root->Left, x, wasInsert);
		}
		else
		{
			if (x > Root->Data)
			{
				Insert(Root->Right, x, wasInsert);
			}
			else
			{
				wasInsert = false;
			}
		}
	}
	if (wasInsert)
	{
		newHeight(Root);
		Balance(Root);
	}
}

void Tree::deletFromTree(PTree& root, unsigned long long x, int& countRotation, bool inMin)
{
	if (root == nullptr)
	{
		return;
	}
	if (x < root->Data)
	{
		deletFromTree(root->Left, x, countRotation, inMin);
	}
	else
	{
		if (x > root->Data)
		{
			deletFromTree(root->Right, x, countRotation, inMin);
		}
		else
		{
			PTree ForDel = root;
			if (root->Left == nullptr)
			{
				root = root->Right;
			}
			else
			{
				if (root->Right == nullptr)
				{
					root = root->Left;
				}
				else
				{
					if (inMin)
					{
						if (height(root->Right) < height(root->Left))
						{
							ForDel = delInRight(root->Right, countRotation);
						}
						else
						{
							ForDel = delInLeft(root->Left, countRotation);
						}
					}
					else
					{
						ForDel = delInLeft(root->Left, countRotation);
					}
					root->Data = ForDel->Data;
				}
			}
			delete ForDel;
		}
	}
	if (root != nullptr)
	{
		newHeight(root);
		BalanceAfterDel(root, countRotation);
	}
}

PTree Tree::delInLeft(PTree& root, int& countRotation)
{
	PTree result;
	if (root->Right != nullptr)
	{
		result = delInLeft(root->Right, countRotation);
		if (root != nullptr)
		{
			newHeight(root);
			BalanceAfterDel(root, countRotation);
		}
	}
	else
	{
		result = root;
		root = root->Left;
	}
	return result;
}

PTree Tree::delInRight(PTree& root, int& countRotation)
{
	PTree result;
	if (root->Left != nullptr)
	{
		result = delInLeft(root->Left, countRotation);
		if (root != nullptr)
		{
			newHeight(root);
			BalanceAfterDel(root, countRotation);
		}
	}
	else
	{
		result = root;
		root = root->Right;
	}
	return result;
}

void Tree::BalanceAfterDel(PTree& p, int& countRotation)
{
	if (sayBalance(p) == 2)
	{
		countRotation++;
		if (sayBalance(p->Right) >= 0)
		{
			RR(p);
		}
		else
		{
			RL(p);
		}
	}
	else
	{
		if (sayBalance(p) == -2)
		{
			countRotation++;
			if (sayBalance(p->Left) <= 0)
			{
				LL(p);
			}
			else
			{
				LR(p);
			}
		}
	}
}

void Tree::DeleteTree(PTree& R)
{
	if (R == nullptr) return;
	DeleteTree(R->Left);
	DeleteTree(R->Right);
	delete R;
}

void Tree::InfFind(PTree root, unsigned long long& number, unsigned long long& tmp, bool& find)
{
	if (root == nullptr || find)
	{
		return;
	}
	InfFind(root->Left, number, tmp, find);
	if (number == 0)
	{
		tmp = root->Data;
		find = true;
	}
	else
	{
		number--;
		InfFind(root->Right, number, tmp, find);
	}
}

void Tree::PrintTree(PTree R, int level)
{
	if (R == nullptr)
		return;
	PrintTree(R->Right, level + 1);
	for (int i = 0; i < level - 1; i++)
	{
		cout << setw(6) << ' ';
	}
	cout << setw(6) << R->Data << endl;
	PrintTree(R->Left, level + 1);
}