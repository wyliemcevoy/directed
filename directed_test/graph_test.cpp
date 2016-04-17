#include "graph_test.h"

GraphTest::GraphTest()
{
	

}


GraphTest::~GraphTest()
{
	
}

void GraphTest::SetUp()
{
	// Add nodes
	graph.AddNode(1);
	graph.AddNode(2);
	graph.AddNode(3);

	// Add edges
	graph.AddEdge(1, 2);
	graph.AddEdge(2, 1);
}

void GraphTest::TearDown()
{

}

TEST_F(GraphTest, successful_add_node)
{
	ASSERT_TRUE(graph.AddNode(4));
}

TEST_F(GraphTest, return_false_for_existing_node_add)
{
	ASSERT_FALSE(graph.AddNode(1));
}

TEST_F(GraphTest, successful_add_edge)
{
	ASSERT_TRUE(graph.AddEdge(1,2));
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

TEST_F(GraphTest, does_not_contain_nodes_it_should_not)
{
	ASSERT_FALSE(graph.ContainsNode(100)) << "Graph should not contain a node of id 100";
	ASSERT_FALSE(graph.ContainsNode(-10)) << "Graph should not contain a node of id -10";
}

TEST_F(GraphTest, does_not_contain_edges_it_should_not)
{
	ASSERT_FALSE(graph.ContainsEdge(100, 1)) << "Graph should not contain edges to nodes that are not in the graph.";
	ASSERT_FALSE(graph.ContainsEdge(1, 100)) << "Graph should not contain edges to nodes that are not in the graph.";
}

TEST_F(GraphTest, successful_remove_edge)
{
	ASSERT_TRUE(graph.RemoveEdge(1, 2));
	ASSERT_FALSE(graph.ContainsEdge(1, 2));
}