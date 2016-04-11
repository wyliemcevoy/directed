#include "stdafx.h"
#include "node.h"
#include <iostream>


namespace directed {

	Node::Node(int id): id_(id)
	{

	}

	void Node::AddIncoming(std::shared_ptr<Edge> edge_ptr)
	{
		incoming_.push_back(edge_ptr);
	}

	void Node::AddOutGoing(std::shared_ptr<Edge> edge_ptr)
	{
		out_going_.push_back(edge_ptr);
	}

	bool Node::ContainsEdgeOutTo(int id)
	{
		for (auto edge_ptr : out_going_)
		{
			std::cout << "comparing "<< edge_ptr->GetInId() << " to " << id << std::endl;

			if (edge_ptr->GetInId() == id)
			{
				return true;
			}
		}

		return false;
	}

	bool Node::ContainsEdgeInFrom(int id)
	{
		for (auto edge_ptr : incoming_)
		{
			std::cout << "comparing " << edge_ptr->GetOutId() << " to " << id << std::endl;

			if (edge_ptr->GetOutId() == id)
			{
				return true;
			}
		}

		return false;
	}

	void Node::RemoveEdgesGoingTo(int id)
	{
		auto search = std::remove_if(out_going_.begin(), out_going_.end(), [id](std::shared_ptr<Edge> edge_ptr) {return edge_ptr->GetOutId() == id; });
		out_going_.erase(search, out_going_.end());
	}

	void Node::RemoveEdgesComingFrom(int id)
	{
		auto search = std::remove_if(incoming_.begin(), incoming_.end(), [id](std::shared_ptr<Edge> edge_ptr) {return edge_ptr->GetInId() == id; });		
		incoming_.erase(search, incoming_.end());
	}

	void Node::RemoveAllEdges()
	{
		std::shared_ptr<Node> node_p;

		// Handle removing out going edges and neighbor nodes copies of those edges 
		for (std::shared_ptr<Edge> edge_p : out_going_)
		{
			node_p = edge_p->GetIn();
			if (node_p != nullptr)
			{
				node_p->RemoveEdgesComingFrom(id_);
			}
		}

		// Handle removing incoming edges and neighbor nodes copies of those edges 
		for (std::shared_ptr<Edge> edge_p : incoming_)
		{
			node_p = edge_p->GetOut();
			if (node_p != nullptr)
			{
				node_p->RemoveEdgesGoingTo(id_);
			}
		}
	}


	Node::~Node()
	{

	}
}