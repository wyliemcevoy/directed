#pragma once


#include "gtest/gtest.h"
#include "linked_list.h"


class LinkedListTest : public ::testing::Test
{
public:
	LinkedListTest();
	~LinkedListTest();
	void SetUp();
	void TearDown();
	void BuildCycleList();
	void BuildRegularList();

	directed::LinkedListNode<int> * list_;

};


