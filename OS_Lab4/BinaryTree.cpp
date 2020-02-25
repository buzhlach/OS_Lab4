#include "BinaryTree.h"
#include "Leaf.h"
#include <iostream>
#include <ctime>

using namespace std;

BinaryTree::BinaryTree(Leaf* root) {
	this->root = root;
}

BinaryTree::BinaryTree() :BinaryTree::BinaryTree(nullptr) {
}

void BinaryTree::AddLeaf(int key, int data) {
	Leaf* currLeaf = this->root;
	Leaf* currLeafParent = nullptr;
	int lastMove = 0; //-1 елси left, 1 если right
	while ((currLeaf != nullptr) &&(currLeaf->key!=key))
	{
		currLeafParent = currLeaf;
		if (currLeaf->key < key) {
			currLeaf = currLeaf->right;
			lastMove = 1;
		}
		else
		{
			currLeaf = currLeaf->left;
			lastMove = -1;
		}
	}
	if (currLeaf == this->root) {
		this->root= new Leaf(nullptr, key, data);
	}
	if (currLeaf == nullptr) {
		Leaf* addLeaf = new Leaf(currLeafParent, key, data);
		if (lastMove == -1) {
			currLeafParent->left = addLeaf;
		}
		else if (lastMove == 1) {
			currLeafParent->right = addLeaf;
		}
	}
	else {
		cout << "Key \'"<<key<<"\' exist. Value on this key changed "<<endl;
		currLeaf->data = data;
		cout << endl << "Press any char & Enter to exit." << endl;
		string s;
		cin >> s;
	}
}

void BinaryTree::FindLeafDataByKey(int key) {
	Leaf* currLeaf = this->root;

	while ((currLeaf != nullptr) && (currLeaf->key != key)) {
		if (currLeaf->key < key) {
			currLeaf = currLeaf->right;
		}
		else
		{
			currLeaf = currLeaf->left;
		}
	}

	if (currLeaf == nullptr) {
		cout << "Leaf with key \'" << key << "\' not found."<<endl;
	}
	else {
		cout << "Value by key \'" << key << "\' = " << currLeaf->data<<endl;
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
	this->root = nullptr;
}

void BinaryTree::DeleteLeafByKey(int key) {
	Leaf* currLeaf = this->root;

	while ((currLeaf != nullptr) && (currLeaf->key != key)) {
		if (currLeaf->key < key) {
			currLeaf = currLeaf->right;
		}
		else
		{
			currLeaf = currLeaf->left;
		}
	}

	if (currLeaf == nullptr) {
		cout << "Leaf with key \'" << key << "\' not found." << endl;
	}
	else {
		if (currLeaf->left == nullptr) {
			if (currLeaf->right == nullptr) {//нет потомков
				if (currLeaf->parent->left == currLeaf) {
					currLeaf->parent->left = nullptr;
				}
				currLeaf->parent->right = nullptr;
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
				Leaf* placeToLeftBranch = currLeaf->right->left;
				while (placeToLeftBranch!=nullptr)//выбор места, откуда вставить левую подветвь
				{
					parentToLeftBranch = parentToLeftBranch;
					placeToLeftBranch = placeToLeftBranch->left;
				}
				if (currLeaf != this->root) {
					if (currLeaf->key > currLeaf->parent->key) {//curr в правой ветке
						currLeaf->right->parent = currLeaf->parent;
						currLeaf->parent->right = currLeaf->right;
						currLeaf->parent = parentToLeftBranch;
						parentToLeftBranch->left = currLeaf->left;
						free(currLeaf);
					}

					else {//curr в левой ветке
						currLeaf->right->parent = currLeaf->parent;
						currLeaf->parent->left = currLeaf->right;
						currLeaf->left->parent = parentToLeftBranch;
						parentToLeftBranch->left = currLeaf->left;
						free(currLeaf);
					}
				}
				else {
					currLeaf->right->parent = nullptr;
					this->root = currLeaf->right;
					currLeaf->left->parent = parentToLeftBranch;
					parentToLeftBranch->left = currLeaf->left;
					free(currLeaf);
				}
			}
		}
	}
}

void BinaryTree::PrintBinaryTree() {
	if (root != nullptr) {
		PrintLeaf(root);
		printf("\n");
		PrintBranch(root);
	}
	else
		cout << "Tree is empty." << endl;
}

void BinaryTree::PrintLeaf(Leaf* leaf) {//вывести лист и передать далее
	if (leaf != nullptr) {
		PrintLeaf(leaf->right);
		printf("%8i", leaf->data);
		PrintLeaf(leaf->left);
	}
}

void BinaryTree::PrintBranch(Leaf* leaf) {
	if (leaf != nullptr) {
		PrintBranch(leaf->right);
		if (leaf != root) {
			printf("%3i(%3i)", leaf->key, leaf->parent->key);
		}
		else {
			printf("%3i(%3i)", leaf->key, 0);
		}
		PrintBranch(leaf->left);
	}
}

void BinaryTree::AddRandomLeafs(int n) {
	srand(unsigned(time(0)));
	for (int i = 0; i < n; i++) {
		int data = rand() % 99+1;
		int key = rand() % 99+1;
		this->AddLeaf(key, data);
	}
}