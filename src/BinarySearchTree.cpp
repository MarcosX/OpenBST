/*
 * BinarySearchTree.cpp
 *
 *  Created on: Feb 29, 2012
 *      Author: marcos
 */

#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

bool BinarySearchTree::insert(int key) {
	if (root == NULL) {
		root = new Node(key);
		return true;
	}
	Node *newNode = root;
	while (newNode != NULL) {
		if (key < newNode->getKey()) {
			if (newNode->getLeftNode() == NULL) {
				newNode->setLeftNode(new Node(key));
				return true;
			}
			newNode = newNode->getLeftNode();
		} else if (key > newNode->getKey()) {
			if (newNode->getRightNode() == NULL) {
				newNode->setRightNode(new Node(key));
				return true;
			}
			newNode = newNode->getRightNode();
		}
	}
	return false;
}

bool BinarySearchTree::search(int key) {
	Node * search = root;
	while (search != NULL) {
		if (search->getKey() == key)
			return true;
		if (key < search->getKey())
			search = search->getLeftNode();
		else
			search = search->getRightNode();
	}
	return false;
}

bool BinarySearchTree::remove(int key) {
	//Árvore vazia
	if (root == NULL)
		return false;

	//Remover a raiz
	if (root->getKey() == key) {
		Node* toDelete = root;
		if (root->getLeftNode() == NULL)
			root = root->getRightNode();
		else if (root->getRightNode() == NULL)
			root = root->getLeftNode();
		else {
			Node* rightMost = root->getLeftNode();
			Node* previous = NULL;
			while (rightMost->getRightNode() != NULL) {
				previous = rightMost;
				rightMost = rightMost->getRightNode();
			}
			if (previous == NULL)
				toDelete->setLeftNode(rightMost->getLeftNode());
			else
				previous->setRightNode(rightMost->getLeftNode());
			root->setKey(rightMost->getKey());
			toDelete = rightMost;
		}
		delete toDelete;
		return true;
	}

	//Pesquisar na árvore
	Node* search = root;
	Node* previous = NULL;
	while (search != NULL) {
		if (search->getKey() == key) {
			if (previous->getLeftNode() == search)
				removeLeftByCopy(previous);
			else
				removeRightByCopy(previous);
			return true;
		}
		previous = search;
		search =
				key < search->getKey() ?
						search->getLeftNode() : search->getRightNode();
	}
	return false;
}

void BinarySearchTree::removeLeftByCopy(Node *node) {
	Node* toDelete = node->getLeftNode();
	if (toDelete->getLeftNode() == NULL)
		node->setLeftNode(toDelete->getRightNode());
	else if (toDelete->getRightNode() == NULL)
		node->setLeftNode(toDelete->getLeftNode());
	else {
		Node* rightMost = toDelete->getLeftNode();
		Node* previous = NULL;
		while (rightMost->getRightNode() != NULL) {
			previous = rightMost;
			rightMost = rightMost->getRightNode();
		}
		if (previous == NULL)
			toDelete->setLeftNode(rightMost->getLeftNode());
		else
			previous->setRightNode(rightMost->getLeftNode());
		toDelete->setKey(rightMost->getKey());
		toDelete = rightMost;
	}
	delete toDelete;
}

void BinarySearchTree::removeRightByCopy(Node *node) {
	Node* toDelete = node->getRightNode();
	if (toDelete->getLeftNode() == NULL)
		node->setRightNode(toDelete->getRightNode());
	else if (toDelete->getRightNode() == NULL)
		node->setRightNode(toDelete->getLeftNode());
	else {
		Node* rightMost = toDelete->getLeftNode();
		Node* previous = NULL;
		while (rightMost->getRightNode() != NULL) {
			previous = rightMost;
			rightMost = rightMost->getRightNode();
		}
		if (previous == NULL)
			toDelete->setLeftNode(rightMost->getLeftNode());
		else
			previous->setRightNode(rightMost->getLeftNode());
		toDelete->setKey(rightMost->getKey());
		toDelete = rightMost;
	}
	delete toDelete;
}

BinarySearchTree::BinarySearchTree() {
	this->root = NULL;
}

void BinarySearchTree::debugTree() {
	if (root != NULL)
		debugTree(root);
	else
		cout << "Vazio" << endl;
}

void BinarySearchTree::debugTree(Node* node) {
	if (node == NULL)
		return;
	std::cout << "[" << node->getKey() << "]";
	debugTree(node->getLeftNode());
	debugTree(node->getRightNode());
}

void BinarySearchTree::acceptVisitor(TreeVisitor* visitor) {
	visitor->visit(root);
}

BinarySearchTree::~BinarySearchTree() {
}

