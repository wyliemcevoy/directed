#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include "pointer_edge.h"

class Edge;

namespace directed
{

	class PointerNode
	{
	public:
		PointerNode(int id);
		~PointerNode();


		bool AddEdge(std::shared_ptr<PointerEdge> edge_ptr);
		void AddIncoming(std::shared_ptr<PointerEdge> edge_ptr);
		void AddOutGoing(std::shared_ptr<PointerEdge> edge_ptr);
		int get_id() { return id_; }
		bool ContainsEdgeOutTo(int id);
		bool ContainsEdgeInFrom(int id);
		bool RemoveEdgesGoingTo(int id);
		bool RemoveEdgesComingFrom(int id);
		void RemoveAllEdges();

		int incoming_size() { return incoming_.size(); }
		int outgoin_size() { return out_going_.size(); }

	private:
		std::vector<std::shared_ptr<PointerEdge>> incoming_;
		std::vector<std::shared_ptr<PointerEdge>> out_going_;
		const int id_;
	};

}
