#include "stdafx.h"
#include "pointer_node.h"
#include <iostream>


namespace directed {

	PointerNode::PointerNode(int id): id_(id)
	{

	}

	bool PointerNode::AddEdge(std::shared_ptr<PointerEdge> edge_ptr)
	{
		// If the edge does not label this node's id as either its incoming or outgoing,
		// then this is an invalid edge and we should bail and return failure.
		if (!((edge_ptr->GetInId() == id_) || (edge_ptr->GetOutId() == id_)))
		{
			return false;
		}

		if (edge_ptr->GetInId() == id_)
		{
			incoming_.push_back(edge_ptr);
		}
		
		// supports an edge connecting a node to itself, so not an elseif condition
		if (edge_ptr->GetOutId() == id_)
		{
			out_going_.push_back(edge_ptr);
		}

		return true;
	}

	void PointerNode::AddIncoming(std::shared_ptr<PointerEdge> edge_ptr)
	{
		incoming_.push_back(edge_ptr);
	}

	void PointerNode::AddOutGoing(std::shared_ptr<PointerEdge> edge_ptr)
	{
		out_going_.push_back(edge_ptr);
	}

	bool PointerNode::ContainsEdgeOutTo(int id)
	{
		for (auto edge_ptr : out_going_)
		{
			if (edge_ptr->GetInId() == id)
			{
				return true;
			}
		}

		return false;
	}

	bool PointerNode::ContainsEdgeInFrom(int id)
	{
		for (auto edge_ptr : incoming_)
		{
			if (edge_ptr->GetOutId() == id)
			{
				return true;
			}
		}

		return false;
	}

	bool PointerNode::RemoveEdgesGoingTo(int id)
	{
		auto search = std::remove_if(out_going_.begin(), out_going_.end(), [id](std::shared_ptr<PointerEdge> edge_ptr) { return edge_ptr->GetInId() == id; });
		bool edges_found = search != out_going_.end();
		
		out_going_.erase(search, out_going_.end());	

		return edges_found;
	}

	bool PointerNode::RemoveEdgesComingFrom(int id)
	{
		auto search = std::remove_if(incoming_.begin(), incoming_.end(), [id](std::shared_ptr<PointerEdge> edge_ptr) {return edge_ptr->GetOutId() == id; });
		bool edges_found = search != incoming_.end();
		
		incoming_.erase(search, incoming_.end());

		return edges_found;
	}

	void PointerNode::RemoveAllEdges()
	{
		std::shared_ptr<PointerNode> node_p;

		// Handle removing out going edges and neighbor nodes copies of those edges 
		for (std::shared_ptr<PointerEdge> edge_p : out_going_)
		{
			node_p = edge_p->GetIn();
			if (node_p != nullptr)
			{
				node_p->RemoveEdgesComingFrom(id_);
			}
		}

		// Handle removing incoming edges and neighbor nodes copies of those edges 
		for (std::shared_ptr<PointerEdge> edge_p : incoming_)
		{
			node_p = edge_p->GetOut();
			if (node_p != nullptr)
			{
				node_p->RemoveEdgesGoingTo(id_);
			}
		}
	}


	PointerNode::~PointerNode()
	{

	}
}