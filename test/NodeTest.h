/*
 * NodeTest.h
 *
 *  Created on: Mar 2, 2012
 *      Author: marcos
 */

#ifndef NODETEST_H_
#define NODETEST_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../src/Node.h"

using namespace std;

class NodeTest: public CPPUNIT_NS::TestFixture {

CPPUNIT_TEST_SUITE (NodeTest);
		CPPUNIT_TEST(testConstructedNode);
		CPPUNIT_TEST(testAssignLeftNode);
		CPPUNIT_TEST(testAssignRightNode);
		CPPUNIT_TEST(testSetKey);
	CPPUNIT_TEST_SUITE_END ();
public:
	NodeTest();
	void setUp();
	void tearDown();
	void testConstructedNode();
	void testAssignLeftNode();
	void testAssignRightNode();
	void testSetKey();

	virtual ~NodeTest();
private:
	Node *n;
};

CPPUNIT_TEST_SUITE_REGISTRATION(NodeTest);
#endif /* NODETEST_H_ */
