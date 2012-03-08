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
		for (int k = i + 1; k < 15; ++k) {
			CPPUNIT_ASSERT(tree->search(testArray[k]));
		}
	}
}

BinarySearchTreeTest::~BinarySearchTreeTest() {
}

