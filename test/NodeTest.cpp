/*
 * NodeTest.cpp
 *
 *  Created on: Mar 2, 2012
 *      Author: marcos
 */

#include "NodeTest.h"

NodeTest::NodeTest() {

}

void NodeTest::setUp() {
	n = new Node(10);
}

void NodeTest::testConstructedNode() {
	CPPUNIT_ASSERT_EQUAL(10, n->getKey());
	CPPUNIT_ASSERT(n->getLeftNode() == NULL);
	CPPUNIT_ASSERT(n->getRightNode() == NULL);
}

void NodeTest::testAssignLeftNode() {
	Node* n2 = new Node(6);
	n->setLeftNode(n2);
	CPPUNIT_ASSERT_EQUAL(6, n->getLeftNode()->getKey());
	CPPUNIT_ASSERT_EQUAL(n2, n->getLeftNode());
}

void NodeTest::testAssignRightNode() {
	Node* n2 = new Node(15);
	n->setRightNode(n2);
	CPPUNIT_ASSERT_EQUAL(15, n->getRightNode()->getKey());
	CPPUNIT_ASSERT_EQUAL(n2, n->getRightNode());
}

void NodeTest::testSetKey() {
	n->setKey(100);
	CPPUNIT_ASSERT_EQUAL(n->getKey(), 100);
}

void NodeTest::tearDown() {
	delete n;
}

NodeTest::~NodeTest() {
}

