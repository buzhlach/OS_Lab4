#pragma once
class Leaf
{
public:
	Leaf* parent;//��������
	Leaf* left;//����� ������
	Leaf* right;//������ ������
	int key;//���� ������
	int data;//������

public:
	Leaf(Leaf* parent, int key, int data);
	Leaf(int key, int data);
	Leaf();
};

