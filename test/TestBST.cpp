/*
 * TestBST.cpp
 *
 *  Created on: Mar 7, 2012
 *      Author: marcos
 */

#include "TestBST.h"

BinarySearchTreeTest::BinarySearchTreeTest() {
	// TODO Auto-generated constructor stub

}

void BinarySearchTreeTest::setUp() {
	tree = new BinarySearchTree();
	int set[] = { 10, 5, 3, 8, 2, 4, 6, 9, 15, 12, 18, 11, 13, 16, 20 };
	for (int i = 0; i < 15; ++i) {
		testArray[i] = set[i];
		tree->insert(set[i]);
	}
}

void BinarySearchTreeTest::tearDown() {
	delete tree;
}

void BinarySearchTreeTest::testFindKeys() {
	for (int i = 0; i < 15; ++i) {
		CPPUNIT_ASSERT(tree->search(testArray[i]));
	}
}

void BinarySearchTreeTest::testDeleteKeys() {
	for (int i = 0; i < 15; ++i) {
		CPPUNIT_ASSERT(tree->remove(testArray[i]));
		for (int k = 0; k < 15; ++k) {
			if (k <= i)
				CPPUNIT_ASSERT(!tree->search(testArray[k]));
			else
				CPPUNIT_ASSERT(tree->search(testArray[k]));
		}
	}
}

void BinarySearchTreeTest::testDeleteWithLeftChild() {
	/* Actual Tree
	 *         10
	 *     5           15
	 *   3    8     12     18
	 * 2  4 6   9  11 13 16  20
	 */
	tree->remove(2);
	for (int i = 0; i < 15; ++i) {
		if (testArray[i] == 2)
			CPPUNIT_ASSERT(!tree->search(testArray[i]));
		else
			CPPUNIT_ASSERT(tree->search(testArray[i]));
	}
}

void BinarySearchTreeTest::testDeleteWithRightChild() {
	tree->remove(20);
	for (int i = 0; i < 15; ++i) {
		if (testArray[i] == 20)
			CPPUNIT_ASSERT(!tree->search(testArray[i]));
		else
			CPPUNIT_ASSERT(tree->search(testArray[i]));
	}
}

void BinarySearchTreeTest::testDeleteWithBothChild() {
	tree->remove(5);
	for (int i = 0; i < 15; ++i) {
		if (testArray[i] == 5)
			CPPUNIT_ASSERT(!tree->search(testArray[i]));
		else
			CPPUNIT_ASSERT(tree->search(testArray[i]));
	}
}

BinarySearchTreeTest::~BinarySearchTreeTest() {
}

