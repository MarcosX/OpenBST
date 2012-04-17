/*
 * ConsoleTreeManager.cpp
 *
 *  Created on: Mar 20, 2012
 *      Author: marcos
 */

#include "ConsoleTreeManager.h"

ConsoleTree::ConsoleTree() {
	tree = new BinarySearchTree();
}

ConsoleTree::~ConsoleTree() {
	// TODO Auto-generated destructor stub
}

void ConsoleTree::interact(BinarySearchTree* tree) {
	this->tree = tree;
	std::cout << "\n(+) insert (-) remove (=) search (q) quit: ";
	std::cin >> input;
	char op = input[0];
	int number = atoi(input.substr(1, input.length()).c_str());
	// Refatorar este código para remover o switch
	switch (op) {
	case '+':
		tree->insert(number);
		break;
	case '-':
		if (tree->remove(number))
			std::cout << "#" << number << " removido\n";
		else
			std::cout << "#" << number << " nao encontrado\n";
		break;
	case '=':
		if (tree->search(number))
			std::cout << "#" << number << " encontrado\n";
		else
			std::cout << "#" << number << " nao encontrado\n";
		break;
	default:
		exit(0);
		break;
	}
}

