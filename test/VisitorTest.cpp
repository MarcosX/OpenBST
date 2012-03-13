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
	tree->acceptVisitor(inOrderVisitor);
	std::string expected = "[1][2][3][4][10][11][12][15][16]";
	CPPUNIT_ASSERT_EQUAL(expected, inOrderVisitor->getOutput());

	tree->acceptVisitor(preOrderVisitor);
	expected = "[10][1][3][2][4][15][11][12][16]";
	CPPUNIT_ASSERT_EQUAL(expected, preOrderVisitor->getOutput());

	tree->acceptVisitor(postOrderVisitor);
	expected = "[2][4][3][1][12][11][16][15][10]";
	CPPUNIT_ASSERT_EQUAL(expected, postOrderVisitor->getOutput());
}

void VisitorTest::setUp() {
	inOrderVisitor = new InOrderVisitor();
	preOrderVisitor = new PreOrderVisitor();
	postOrderVisitor = new PostOrderVisitor();

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
	delete inOrderVisitor;
	delete tree;
}

VisitorTest::~VisitorTest() {
	// TODO Auto-generated destructor stub
}

