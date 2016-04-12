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


TEST_F(GraphTest, doesxyz)
{
	ASSERT_EQ(1, 1);
}