#pragma once

#include <unordered_map>
#include "node.h"
#include "graph.h"

namespace directed
{
	class PointerGraph : public Graph
	{
	public:
		PointerGraph();
		~PointerGraph();

		bool AddNode(int id) override;
		bool AddEdge(int from, int to) override;
		bool RemoveNode(int id) override;
		bool RemoveEdge(int out, int in) override;
		bool ContainsNode(int id) override;
		bool ContainsEdge(int out, int in) override;
		bool ContainsPath(int from, int to) override;

	private:
		std::shared_ptr<Node> get_node(int id);
		std::unordered_map<int, std::shared_ptr<Node>> nodes_;
	};

}