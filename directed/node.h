#pragma once

#include <vector>
#include <memory>
#include "edge.h"

class Edge;

namespace ggraph
{

	class Node
	{
	public:
		Node(int id);
		~Node();

		void AddIncoming(std::shared_ptr<Edge> edge_ptr);
		void AddOutGoing(std::shared_ptr<Edge> edge_ptr);
		int get_id() { return id_; }
		bool ContainsEdgeOutTo(int id);
		bool ContainsEdgeInFrom(int id);



		int incoming_size() { return incoming_.size(); }
		int outgoin_size() { return out_going_.size(); }

	private:
		std::vector<std::shared_ptr<Edge>> incoming_;
		std::vector<std::shared_ptr<Edge>> out_going_;
		int id_;
	};

}
