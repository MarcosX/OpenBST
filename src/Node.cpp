/*
 * Node.cpp
 *
 *  Created on: Feb 29, 2012
 *      Author: marcos
 */

#include "Node.h"

Node::Node(int key) {
	this->key = key;
	this->rigthNode = NULL;
	this->leftNode = NULL;
}

int Node::getKey() {
	return this->key;
}

Node *Node::getRightNode() {
	return this->rigthNode;
}

Node *Node::getLeftNode() {
	return this->leftNode;
}

void Node::setRightNode(Node *node) {
	this->rigthNode = node;
}

void Node::setLeftNode(Node *node) {
	this->leftNode = node;
}

void Node::setKey(int key) {
	this->key = key;
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

