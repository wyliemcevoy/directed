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
	ASSERT_TRUE(graph.ContainsEdge(2, 1)) << "Expected edge 1->2 to be in the graph.";
	ASSERT_TRUE(graph.ContainsEdge(1, 2)) << "Expected edge 2->1 to be in the graph.";
}


TEST_F(GraphTest, doesnt_contain_nodes)
{
	ASSERT_FALSE(graph.ContainsNode(100)) << "Graph should not contain a node of id 100";
	ASSERT_FALSE(graph.ContainsNode(-10)) << "Graph should not contain a node of id -10";
}


TEST_F(GraphTest, doesnt_contain_edges)
{
	ASSERT_FALSE(graph.ContainsEdge(100, 1)) << "Graph should not contain edges to nodes that are not in the graph.";
	ASSERT_FALSE(graph.ContainsEdge(1, 100)) << "Graph should not contain edges to nodes that are not in the graph.";
}