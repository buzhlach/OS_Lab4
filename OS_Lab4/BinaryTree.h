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
	void AddLeaf(int key, int data);//�������� ����
	int FindLeafDataByKey(int key);//����� �������� ����� �� �����
	void DeleteLeafByKey(int key);//������� ���� �� �����
};

