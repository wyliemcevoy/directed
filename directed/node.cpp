#include "stdafx.h"
#include "node.h"


namespace ggraph {

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
			try
			{
				auto in_ptr = edge_ptr->in_.lock();
				if (in_ptr->id_ = id)
				{
					return true;
				}

			}
			catch (std::bad_weak_ptr e)
			{
				// Handle removing this edge.
			}
		}

		return false;
	}

	bool Node::ContainsEdgeInFrom(int id)
	{
		for (auto edge_ptr : incoming_)
		{
			try
			{
				auto out_ptr = edge_ptr->out_.lock();
				if (out_ptr->id_ = id)
				{
					return true;
				}

			}
			catch (std::bad_weak_ptr e)
			{
				 // Handle removing this edge.
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

	Node::~Node()
	{

	}
}