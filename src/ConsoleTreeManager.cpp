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
	std::cout << "\n(+) inserir (-) remover (=) buscar (q) sair: ";
	std::cin >> input;
	char op = input[0];
	int number = atoi(input.substr(1, input.length()).c_str());
	switch (op) {
	case '+':
		if(tree->insert(number)){
			std::cout << "#" << number << " inserido";
		} else {
			std::cout << "#" << number << " ja existe";
		}
		break;
	case '-':
		if (tree->remove(number))
			std::cout << "#" << number << " removido";
		else
			std::cout << "#" << number << " nao encontrado";
		break;
	case '=':
		if (tree->search(number))
			std::cout << "#" << number << " encontrado";
		else
			std::cout << "#" << number << " nao encontrado";
		break;
	default:
		exit(0);
		break;
	}
}

