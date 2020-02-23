#include "Leaf.h"

#pragma once
//> right
//< left
class BinaryTree
{
public:
	Leaf* root;

public:
	BinaryTree(Leaf* root);
	BinaryTree();
	~BinaryTree();
	void AddLeaf(int key, int data);//добавить лист
	int FindLeafDataByKey(int key);//найти значение листа по ключу
	void DeleteLeafByKey(int key);//удалить лист по ключу
};

