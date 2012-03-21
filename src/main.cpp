#include "../test/TestRunner.h"
#include "ConsoleTreeManager.h"

int main(int argc, char **argv) {
//	return runAllTests();
	ConsoleTreeManager *manager = new ConsoleTreeManager();
	manager->interactive(new PreOrderVisitor());
	return 0;
}
