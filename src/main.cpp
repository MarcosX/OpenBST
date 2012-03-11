#include "../test/TestRunner.h"
#include "InOrderVisitor.h"

int main(int argc, char **argv) {
	BinarySearchTree* tree = new BinarySearchTree();

	tree->insert(10);
	tree->insert(1);
	tree->insert(3);
	tree->insert(5);
	tree->insert(20);
	tree->insert(15);
	tree->insert(25);
	InOrderVisitor* visitor = new InOrderVisitor();
	tree->acceptVisitor(visitor);
	std::cout << visitor->getOutput();

	return runAllTests();
}
