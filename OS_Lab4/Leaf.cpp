#include "Leaf.h"

Leaf::Leaf(Leaf* parent, int key, int data) {
	this->parent = parent;
	this->left = nullptr;
	this->right = nullptr;
	this->key = key;
	this->data = data;
}

Leaf::Leaf(int key, int data):  Leaf::Leaf(nullptr,key,data){
}

Leaf::Leaf() : Leaf::Leaf(0, 0) {
}


