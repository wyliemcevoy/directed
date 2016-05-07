
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
	ASSERT_TRUE(tree_.insert(1));
}
