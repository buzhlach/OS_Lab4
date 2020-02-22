#include "BinaryTree.h"
#include "Leaf.h"

BinaryTree::BinaryTree(Leaf* root) {
	this->root = root;
}

BinaryTree::BinaryTree() :BinaryTree::BinaryTree(nullptr) {
}