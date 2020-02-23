#include "BinaryTree.h"
#include "Leaf.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree(Leaf* root) {
	this->root = root;
}

BinaryTree::BinaryTree() :BinaryTree::BinaryTree(nullptr) {
}

void BinaryTree::AddLeaf(int key, int data) {
	Leaf* currLeaf = this->root;
	Leaf* currLeafParent = nullptr;
	while ((currLeaf != nullptr)||(currLeaf->key!=key))
	{
		currLeafParent = currLeaf;
		if (currLeaf->key < key) {
			currLeaf = currLeaf->right;
		}
		else
		{
			currLeaf = currLeaf->left;
		}
	}

	if (currLeaf == nullptr) {
		Leaf* addLeaf = new Leaf(currLeafParent, key, data);
		currLeaf = addLeaf;
	}
	else {
		cout << "���� \'"<<key<<"\' ������ � ������������. �������� �� ������� ����� ��������"<<endl;
		currLeaf->data = data;
	}
}

int BinaryTree::FindLeafDataByKey(int key) {
	Leaf* currLeaf = this->root;

	while ((currLeaf != nullptr) || (currLeaf->key != key)) {
		if (currLeaf->key < key) {
			currLeaf = currLeaf->right;
		}
		else
		{
			currLeaf = currLeaf->left;
		}
	}

	if (currLeaf == nullptr) {
		cout << "����� � ������ \'" << key << "\' �� �������."<<endl;
	}
	else {
		cout << "�������� �� ����� \'" << key << "\' = " << currLeaf->data<<endl;
	}
}

void DeleteTree(Leaf* leaf) {
	if (leaf != nullptr) {
		DeleteTree(leaf->left);
		DeleteTree(leaf->right);
		free(leaf);
	}
}

BinaryTree::~BinaryTree() {
	DeleteTree(this->root);
}

void BinaryTree::DeleteLeafByKey(int key) {
	Leaf* currLeaf = this->root;

	while ((currLeaf != nullptr) || (currLeaf->key != key)) {
		if (currLeaf->key < key) {
			currLeaf = currLeaf->right;
		}
		else
		{
			currLeaf = currLeaf->left;
		}
	}

	if (currLeaf == nullptr) {
		cout << "����� � ������ \'" << key << "\' �� �������." << endl;
	}
	else {
		if (currLeaf->left == nullptr) {
			if (currLeaf->right == nullptr) {//��� ��������
				free(currLeaf);
			}

			else {//���� ������ �������
				if (currLeaf != this->root) {
					if (currLeaf->key > currLeaf->parent->key) {//curr � ������ �����
						currLeaf->parent->right = currLeaf->right;
						free(currLeaf);
					}

					else {//curr � ����� �����
						currLeaf->parent->left = currLeaf->right;
						free(currLeaf);
					}
				}

				else {
					this->root = currLeaf->right;
					free(currLeaf);
				}
			}
		}

		else {
			
			if (currLeaf->right == nullptr) {//���� ����� ������
				if (currLeaf != this->root) {
					if (currLeaf->key > currLeaf->parent->key) {//curr � ������ �����
						currLeaf->parent->right = currLeaf->left;
						free(currLeaf);
					}

					else {//curr � ����� �����
						currLeaf->parent->left = currLeaf->left;
						free(currLeaf);
					}
				}
				
				else {
					this->root = currLeaf->left;
					free(currLeaf);
				}
			}

			else {//���� ��� �������
				Leaf* parentToLeftBranch = currLeaf->right;
				while (parentToLeftBranch!=nullptr)//����� �����, ������ �������� ����� ��������
				{
					parentToLeftBranch = parentToLeftBranch->left;
				}
				parentToLeftBranch = parentToLeftBranch->parent;
				if (currLeaf != this->root) {
					if (currLeaf->key > currLeaf->parent->key) {//curr � ������ �����
						currLeaf->parent->right = currLeaf->right;
						parentToLeftBranch->left = currLeaf->left;
						free(currLeaf);
					}

					else {//curr � ����� �����
						currLeaf->parent->left = currLeaf->right;
						parentToLeftBranch->left = currLeaf->left;
						free(currLeaf);
					}
				}
				else {
					this->root = currLeaf->right;
					parentToLeftBranch->left = currLeaf->left;
					free(currLeaf);
				}
			}
		}
	}
}