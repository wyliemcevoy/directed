
#include "binary_tree_test.h"

BinaryTreeTest::BinaryTreeTest()
{


}


BinaryTreeTest::~BinaryTreeTest()
{

}

void BinaryTreeTest::SetUp()
{

}

void BinaryTreeTest::TearDown()
{

}

TEST_F(BinaryTreeTest, successful_add_node)
{
	ASSERT_TRUE(tree_.Insert(1));
}

TEST_F(BinaryTreeTest, correct_flatten)
{
	ASSERT_TRUE(tree_.Insert(10));
	ASSERT_TRUE(tree_.Insert(5));
	ASSERT_TRUE(tree_.Insert(15));
	ASSERT_TRUE(tree_.Insert(17));
	ASSERT_TRUE(tree_.Insert(11));
	ASSERT_TRUE(tree_.Insert(8));
	ASSERT_TRUE(tree_.Insert(2));
	tree_.print();
}

TEST_F(BinaryTreeTest, correct_depth)
{
	ASSERT_TRUE(tree_.Insert(10));
	ASSERT_TRUE(tree_.Insert(5));
	ASSERT_TRUE(tree_.Insert(15));
	ASSERT_TRUE(tree_.Insert(17));
	ASSERT_TRUE(tree_.Insert(11));
	ASSERT_TRUE(tree_.Insert(8));
	ASSERT_TRUE(tree_.Insert(2));
	ASSERT_EQ(tree_.GetHeight(), 3);
}