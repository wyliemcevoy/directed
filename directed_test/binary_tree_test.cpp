
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

void BinaryTreeTest::BuildBalancedTree()
{
	tree_.Insert(10);
	tree_.Insert(5);
	tree_.Insert(15);
	tree_.Insert(17);
	tree_.Insert(11);
	tree_.Insert(8);
	tree_.Insert(2);
}

void BinaryTreeTest::BuildSkewedTree()
{
	tree_.Insert(1);
	tree_.Insert(2);
	tree_.Insert(3);
	tree_.Insert(4);
	tree_.Insert(5);
	tree_.Insert(6);
	tree_.Insert(7);
}

TEST_F(BinaryTreeTest, successful_add_node)
{
	ASSERT_TRUE(tree_.Insert(1));
}

TEST_F(BinaryTreeTest, correct_flatten)
{

	tree_.print();
}

TEST_F(BinaryTreeTest, contains)
{
	tree_.Insert(1);
	ASSERT_TRUE(tree_.Contains(1));
}

TEST_F(BinaryTreeTest, correct_balanced_height)
{	
	BuildBalancedTree();
	ASSERT_EQ(tree_.GetHeight(), 3);
}

TEST_F(BinaryTreeTest, correct_skewed_height)
{
	BuildSkewedTree();
	ASSERT_EQ(tree_.GetHeight(), 7);
}


TEST_F(BinaryTreeTest, does_not_contain)
{
	BuildBalancedTree();
	ASSERT_FALSE(tree_.Contains(-100));
}


TEST_F(BinaryTreeTest, corret)
{
	BuildSkewedTree();

	directed::BinaryTree<int> tree;

	{
		int a = 1;
		tree.Insert(a);
	}
	

	ASSERT_TRUE(tree.Contains(1));
}

