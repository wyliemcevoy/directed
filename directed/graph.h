#pragma once

#include <unordered_map>
#include "node.h"


namespace directed
{
	class Graph
	{
	public:
		Graph();
		~Graph();

		bool AddNode(int id);
		bool AddEdge(int from, int to);
		bool RemoveNode(int id);
		bool RemoveEdge(int out, int in);
		bool ContainsNode(int id);
		bool ContainsEdge(int out, int in);

	//private:
		
		std::shared_ptr<Node> get_node(int id);

		std::unordered_map<int, std::shared_ptr<Node>> nodes_;

	};

}