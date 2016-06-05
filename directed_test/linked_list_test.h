#pragma once


#include "gtest/gtest.h"
#include "linked_list.h"
#include <memory>


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

private:
	std::vector<std::unique_ptr<directed::LinkedListNode<int>>>  node_handles_;
};


