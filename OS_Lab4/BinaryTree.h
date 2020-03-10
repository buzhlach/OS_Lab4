#include "Leaf.h"
#include <string>

#pragma once
using namespace std;
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
	void FindLeafDataByKey(int key);//найти значение листа по ключу
	void DeleteLeafByKey(int key);//удалить лист по ключу
	void PrintBinaryTree();//вывести дерево
	void AddRandomLeafs(int n);//случайное дерево длины n с ключами от 0 до 100
	void WriteBinaryTreeToFile();//записать дерево в файл
	void ReadBinaryTreeFromFile();//считать дерево из файла
private:
	void PrintLeaf(Leaf *leaf);
	void PrintBranch(Leaf *leaf);
	void PrintLeafToString(Leaf* leaf, string& strTree);
};

