/*
 * TestBST.h
 *
 *  Created on: Mar 7, 2012
 *      Author: marcos
 */

#ifndef TESTBST_H_
#define TESTBST_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../src/BinarySearchTree.h"

class BinarySearchTreeTest: public CppUnit::TestFixture {

CPPUNIT_TEST_SUITE (BinarySearchTreeTest);
		CPPUNIT_TEST(testFindKeys);
		CPPUNIT_TEST(testDeleteKeys);
		CPPUNIT_TEST(testDeleteWithLeftChild);
		CPPUNIT_TEST(testDeleteWithRightChild);
		CPPUNIT_TEST(testDeleteWithBothChild);
	CPPUNIT_TEST_SUITE_END ();

public:

	void setUp();
	void tearDown();

	void testFindKeys();
	void testDeleteKeys();

	void testDeleteWithLeftChild();
	void testDeleteWithRightChild();
	void testDeleteWithBothChild();

	BinarySearchTreeTest();
	virtual ~BinarySearchTreeTest();
private:
	BinarySearchTree* tree;
	int testArray[15];
};

CPPUNIT_TEST_SUITE_REGISTRATION(BinarySearchTreeTest);

#endif /* TESTBST_H_ */
