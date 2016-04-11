#include "stdafx.h"
#include "edge.h"
#include "node.h"


namespace directed {

	Edge::Edge(std::shared_ptr<Node> in, std::shared_ptr<Node> out) :
		in_(in), out_(out)
	{

	}


	Edge::~Edge()
	{
	}

	std::shared_ptr<Node> Edge::GetOut()
	{
		try
		{
			std::shared_ptr<Node> out_p = out_.lock();
			return out_p;
		}
		catch (std::bad_weak_ptr e)
		{
			// Handle invalid edge.
			return nullptr;
		}
	}

	std::shared_ptr<Node> Edge::GetIn()
	{
		try
		{
			std::shared_ptr<Node> in_p = in_.lock();
			return in_p;
		}
		catch (std::bad_weak_ptr e)
		{
			// Handle invalid edge.
			return nullptr;
		}
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
			return 0;
		}
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
		return 0;
		}
	}
}