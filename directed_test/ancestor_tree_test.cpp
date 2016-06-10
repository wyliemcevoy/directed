#include "ancestor_tree_test.h"



void AncestorTreeTest::SetUp()
{
}

void AncestorTreeTest::TearDown()
{
}

AncestorTreeTest::AncestorTreeTest()
{
}


AncestorTreeTest::~AncestorTreeTest()
{
}


TEST_F(AncestorTreeTest, add_node)
{

	directed::AncestorTree<int> tree;
	directed::AncestorNode<int> * node_1 = tree.BuildNode(1);
	directed::AncestorNode<int> * node_2 = tree.BuildNode(2);

	ASSERT_TRUE(true);
}