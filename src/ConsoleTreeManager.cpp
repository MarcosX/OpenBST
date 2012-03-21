/*
 * ConsoleTreeManager.cpp
 *
 *  Created on: Mar 20, 2012
 *      Author: marcos
 */

#include "ConsoleTreeManager.h"

ConsoleTreeManager::ConsoleTreeManager() {
	tree = new BinarySearchTree();
}

ConsoleTreeManager::~ConsoleTreeManager() {
	// TODO Auto-generated destructor stub
}

void ConsoleTreeManager::interactive(TreeVisitor* _visitor) {
	visitor = _visitor;
	while (true) {
		std::cout << "\n(+) insert (-) remove (=) search (q) quit: ";
		std::cin >> input;
		char op = input[0];
		int number = atoi(input.substr(1, input.length()).c_str());
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
		tree->acceptVisitor(visitor);
		std::cout << visitor->getOutput();
	}
}

