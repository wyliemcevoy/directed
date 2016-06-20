#pragma once
#include "gtest/gtest.h"
#include "ancestor_tree.h"


class AncestorTreeTest : public ::testing::Test
{
public:
	void SetUp();
	void TearDown();
	AncestorTreeTest();
	~AncestorTreeTest();

	directed::AncestorTree<int> tree_;
};


