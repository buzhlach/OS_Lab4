#pragma once
class Leaf
{
public:
	Leaf* parent;//родитель
	Leaf* left;//левый ребёнок
	Leaf* right;//правый ребёнок
	int key;//ключ поиска
	int data;//данные

public:
	Leaf(Leaf* parent, int key, int data);
	Leaf(int key, int data);
	Leaf();
};

