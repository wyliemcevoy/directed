#include "stdafx.h"
#include "edge.h"
#include "node.h"


namespace ggraph {

	Edge::Edge(std::shared_ptr<Node> in, std::shared_ptr<Node> out) :
		in_(in), out_(out)
	{

	}


	Edge::~Edge()
	{
	}

	int Edge::GetOutId()
	{
		try
		{
			std::shared_ptr<Node> out_p = out_.lock();
			return out_p->get_id();
		}
		catch (std::bad_weak_ptr e)
		{
			// Handle invalid edge.
		}
		return 0;
	}

	int Edge::GetInId()
	{
		try
		{
			std::shared_ptr<Node> in_p = in_.lock();
			return in_p->get_id();
		}
		catch (std::bad_weak_ptr e)
		{
			// Handle invalid edge.
		}
		return 0;
	}

}