/*
 * VisitorTest.h
 *
 *  Created on: Mar 11, 2012
 *      Author: marcos
 */

#ifndef VISITORTEST_H_
#define VISITORTEST_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../src/BinarySearchTree.h"
#include "../src/InOrderVisitor.h"
#include "../src/PreOrderVisitor.h"
#include "../src/PostOrderVisitor.h"

class VisitorTest: public CppUnit::TestFixture {

CPPUNIT_TEST_SUITE (VisitorTest);
		CPPUNIT_TEST(testVerifyOutput);
	CPPUNIT_TEST_SUITE_END ();

public:
	VisitorTest();

	void setUp();
	void tearDown();

	void testVerifyOutput();

	virtual ~VisitorTest();
private:
	InOrderVisitor* inOrderVisitor;
	PreOrderVisitor* preOrderVisitor;
	PostOrderVisitor* postOrderVisitor;
	BinarySearchTree* tree;
};

CPPUNIT_TEST_SUITE_REGISTRATION(VisitorTest);

#endif /* VISITORTEST_H_ */
