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
		cout << "Ключ \'"<<key<<"\' совпал с существующим. Значение по данному ключу изменено"<<endl;
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
		cout << "Листа с ключом \'" << key << "\' не найдено."<<endl;
	}
	else {
		cout << "Значение по ключу \'" << key << "\' = " << currLeaf->data<<endl;
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
		cout << "Листа с ключом \'" << key << "\' не найдено." << endl;
	}
	else {
		if (currLeaf->left == nullptr) {
			if (currLeaf->right == nullptr) {//нет потомков
				free(currLeaf);
			}

			else {//есть правый потомок
				if (currLeaf != this->root) {
					if (currLeaf->key > currLeaf->parent->key) {//curr в правой ветке
						currLeaf->parent->right = currLeaf->right;
						free(currLeaf);
					}

					else {//curr в левой ветке
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
			
			if (currLeaf->right == nullptr) {//есть левый потомк
				if (currLeaf != this->root) {
					if (currLeaf->key > currLeaf->parent->key) {//curr в правой ветке
						currLeaf->parent->right = currLeaf->left;
						free(currLeaf);
					}

					else {//curr в левой ветке
						currLeaf->parent->left = currLeaf->left;
						free(currLeaf);
					}
				}
				
				else {
					this->root = currLeaf->left;
					free(currLeaf);
				}
			}

			else {//есть оба потомка
				Leaf* parentToLeftBranch = currLeaf->right;
				while (parentToLeftBranch!=nullptr)//выбор места, откуда вставить левую подветвь
				{
					parentToLeftBranch = parentToLeftBranch->left;
				}
				parentToLeftBranch = parentToLeftBranch->parent;
				if (currLeaf != this->root) {
					if (currLeaf->key > currLeaf->parent->key) {//curr в правой ветке
						currLeaf->parent->right = currLeaf->right;
						parentToLeftBranch->left = currLeaf->left;
						free(currLeaf);
					}

					else {//curr в левой ветке
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