#include "stdafx.h"
#include "node.h"


namespace ggraph {

	Node::Node(int id): id_(id)
	{

	}

	Node::~Node()
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
			if (edge_ptr->in_->id_ == id)
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
			if (edge_ptr->out_->id_ = id)
			{
				return true;
			}
		}

		return false;
	}
}