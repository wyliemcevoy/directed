#include "graph_test.h"

GraphTest::GraphTest()
{
	

}


GraphTest::~GraphTest()
{
	
}

void GraphTest::SetUp()
{

	graph.AddNode(1);
	graph.AddNode(2);

	graph.AddEdge(1, 2);
	graph.AddEdge(2, 1);
}

void GraphTest::TearDown()
{

}


TEST_F(GraphTest, contains_nodes)
{
	ASSERT_TRUE(graph.ContainsNode(1));
	ASSERT_TRUE(graph.ContainsNode(2));
}

TEST_F(GraphTest, contains_edges)
{
	ASSERT_TRUE(graph.ContainsEdge(2, 1));
	ASSERT_TRUE(graph.ContainsEdge(1, 2));
}