#pragma once
#include "graph.h"

namespace directed {

	class AdjacencyList : public Graph
	{
	public:
		AdjacencyList();
		~AdjacencyList();


		bool AddNode(int id);
		bool AddEdge(int from, int to);
		bool RemoveNode(int id);
		bool RemoveEdge(int out, int in);
		bool ContainsNode(int id);
		bool ContainsEdge(int out, int in);
		bool ContainsPath(int from, int to);
	};
}
