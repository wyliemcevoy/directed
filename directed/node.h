#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include "edge.h"

class Edge;

namespace directed
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
		void RemoveEdgesGoingTo(int id);
		void RemoveEdgesComingFrom(int id);
		void RemoveAllEdges();

		int incoming_size() { return incoming_.size(); }
		int outgoin_size() { return out_going_.size(); }

	private:
		std::vector<std::shared_ptr<Edge>> incoming_;
		std::vector<std::shared_ptr<Edge>> out_going_;
		const int id_;
	};

}
