#include "graph_test.h"

GraphTest::GraphTest()
{
	directed::Graph graph;

	graph.AddNode(1);
	graph.AddNode(2);

	graph.AddEdge(1, 2);
	graph.AddEdge(2, 1);

}


GraphTest::~GraphTest()
{
	
}


TEST_F(GraphTest, contains_nodes)
{
	ASSERT_TRUE(graph.ContainsNode(1));
	ASSERT_TRUE(graph.ContainsNode(2));
}

TEST_F(GraphTest, contains_edges)
{
	ASSERT_TRUE(graph.ContainsEdge(1,2));
	ASSERT_TRUE(graph.ContainsEdge(2,1));
}