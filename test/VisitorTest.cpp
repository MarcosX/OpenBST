/*
 * VisitorTest.cpp
 *
 *  Created on: Mar 11, 2012
 *      Author: marcos
 */

#include "VisitorTest.h"

VisitorTest::VisitorTest() {
	// TODO Auto-generated constructor stub

}

void VisitorTest::testVerifyOutput() {
	tree->acceptVisitor(visitor);

	std::string expected = "[1][2][3][4][10][11][12][15][16]";
	CPPUNIT_ASSERT_EQUAL(expected, visitor->getOutput());

}

void VisitorTest::setUp() {
	visitor = new InOrderVisitor();
	tree = new BinarySearchTree();

	tree->insert(10);
	tree->insert(1);
	tree->insert(3);
	tree->insert(4);
	tree->insert(2);
	tree->insert(15);
	tree->insert(11);
	tree->insert(12);
	tree->insert(16);
}

void VisitorTest::tearDown() {
	delete visitor;
	delete tree;
}

VisitorTest::~VisitorTest() {
	// TODO Auto-generated destructor stub
}

