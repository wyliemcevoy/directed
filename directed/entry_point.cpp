// Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include "graph.h"
#include "node.h"

int main()
{


	ggraph::Graph graph;

	graph.AddNode(1);
	graph.AddNode(2);

	graph.AddEdge(1, 2);
	graph.AddEdge(2, 1);



	std::shared_ptr<ggraph::Node> node_ptr = graph.get_node(1);
	
	std::cout << std::boolalpha << node_ptr->ContainsEdgeInFrom(2) << " has an edge to 2." << std::endl;
	std::cout << std::boolalpha << node_ptr->ContainsEdgeOutTo(2) << " has an edge from 2." << std::endl;

	std::cout << node_ptr->incoming_size() << " ingoing edges." << std::endl;
	std::cout << node_ptr->outgoin_size() << " outgoing edges." << std::endl;

	graph.RemoveEdge(1, 2);

	std::cout << std::boolalpha << node_ptr->ContainsEdgeInFrom(2) << " has an edge to 2." << std::endl;
	std::cout << std::boolalpha << node_ptr->ContainsEdgeOutTo(2) << " has an edge from 2." << std::endl;

	// Wait for input
	std::cout << "Run successful." << std::endl;
	std::cin.get();
    return 0;
}

