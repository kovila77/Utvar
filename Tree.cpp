#include <iostream>
#include <iomanip>
//#include <fstream>
//#include <string>
#include "Tree.h"
#define max(a,b) (((a) > (b)) ? (a) : (b))
using namespace std;

int height(PTree p)
{
	return p == nullptr ? 0 : p->Height;
}

void newHeight(PTree p)
{
	p->Height = max(height(p->Left), height(p->Right)) + 1;
}

int sayBalance(PTree p)
{
	return height(p->Right) - height(p->Left);
}

void LL(PTree& p)
{
	PTree LeftSon = p->Left;
	p->Left = LeftSon->Right;
	LeftSon->Right = p;
	newHeight(p);
	p = LeftSon;
	newHeight(p);
}

void RR(PTree& p)
{
	PTree RightSon = p->Right;
	p->Right = RightSon->Left;
	RightSon->Left = p;
	newHeight(p);
	p = RightSon;
	newHeight(p);
}

void RL(PTree& p)
{
	LL(p->Right);
	RR(p);
}

void LR(PTree& p)
{
	RR(p->Left);
	LL(p);
}

void Balance(PTree& p)
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

void Insert(PTree& Root, KitchenUtensils* newItem, bool& wasInsert)
{
	if (Root == nullptr)
	{
		Root = new Tree;
		Root->item = newItem;
		Root->Height = 1;
		Root->Right = Root->Left = nullptr;
	}
	else
	{
		if (newItem->inventoryNumber < Root->item->inventoryNumber)
		{
			Insert(Root->Left, newItem, wasInsert);
		}
		else
		{
			if (newItem->inventoryNumber > Root->item->inventoryNumber)
			{
				Insert(Root->Right, newItem, wasInsert);
			}
			else
			{
				wasInsert = false;
				cout << "Утварь с таким инвентарным номером уже существует" << endl;
				cout << Root->item->GetTypeName() << endl;
				Root->item->print();
			}
		}
	}
	if (wasInsert)
	{
		newHeight(Root);
		Balance(Root);
	}
}

void deletFromTree(PTree& root, int inventoryNumber, int& countRotation, bool inMin)
{
	if (root == nullptr)
	{
		return;
	}
	if (inventoryNumber < root->item->inventoryNumber)
	{
		deletFromTree(root->Left, inventoryNumber, countRotation, inMin);
	}
	else
	{
		if (inventoryNumber > root->item->inventoryNumber)
		{
			deletFromTree(root->Right, inventoryNumber, countRotation, inMin);
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
					root->item = ForDel->item;
				}
			}
			delete ForDel->item;
			delete ForDel;
		}
	}
	if (root != nullptr)
	{
		newHeight(root);
		BalanceAfterDel(root, countRotation);
	}
}

PTree delInLeft(PTree& root, int& countRotation)
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

PTree delInRight(PTree& root, int& countRotation)
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

void BalanceAfterDel(PTree& p, int& countRotation)
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

void DeleteTree(PTree& R)
{
	if (R == nullptr) return;
	DeleteTree(R->Left);
	DeleteTree(R->Right);
	delete R;
}

void PrintTree(PTree R, int level)
{
	if (R == nullptr)
		return;
	PrintTree(R->Right, level + 1);
	for (int i = 0; i < level - 1; i++)
	{
		cout << setw(6) << ' ';
	}
	cout << setw(6) << R->item->inventoryNumber << endl;
	PrintTree(R->Left, level + 1);
}

void PrintTreeDirect(PTree R, int level)
{
	if (R == nullptr)
		return;
	cout << R->item->GetTypeName() << endl;
	R->item->print();
	cout << endl;
	PrintTreeDirect(R->Left, level + 1);
	PrintTreeDirect(R->Right, level + 1);
}

void PrintTreeBack(PTree R, int level)
{
	if (R == nullptr)
		return;
	PrintTreeBack(R->Left, level + 1);
	PrintTreeBack(R->Right, level + 1);
	cout << R->item->GetTypeName() << endl;
	R->item->print();
	cout << endl;
}

void PrintTreeSimm(PTree R, int level)
{
	if (R == nullptr)
		return;
	PrintTreeDirect(R->Left, level + 1);
	cout << R->item->GetTypeName() << endl;
	R->item->print();
	cout << endl;
	PrintTreeDirect(R->Right, level + 1);	
}