#pragma once
#include "gtest/gtest.h"
#include "binary_treer.h"

class BinaryTreeTest : public ::testing::Test
{
public:
	BinaryTreeTest();
	~BinaryTreeTest();
	void SetUp();
	void TearDown();

	directed::BinaryTree<int> tree_;

};

