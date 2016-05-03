#include "stdafx.h"
#include "pointer_edge.h"
#include "pointer_node.h"


namespace directed {

	PointerEdge::PointerEdge(std::shared_ptr<PointerNode> in, std::shared_ptr<PointerNode> out) :
		in_(in), out_(out)
	{

	}


	PointerEdge::~PointerEdge()
	{
	}

	std::shared_ptr<PointerNode> PointerEdge::GetOut()
	{
		try
		{
			std::shared_ptr<PointerNode> out_p = out_.lock();
			return out_p;
		}
		catch (std::bad_weak_ptr e)
		{
			// Handle invalid edge.
			return nullptr;
		}
	}

	std::shared_ptr<PointerNode> PointerEdge::GetIn()
	{
		try
		{
			std::shared_ptr<PointerNode> in_p = in_.lock();
			return in_p;
		}
		catch (std::bad_weak_ptr e)
		{
			// Handle invalid edge.
			return nullptr;
		}
	}

	int PointerEdge::GetOutId()
	{
		try
		{
			std::shared_ptr<PointerNode> out_p = out_.lock();
			return out_p->get_id();
		}
		catch (std::bad_weak_ptr e)
		{
			// Handle invalid edge.
			return 0;
		}
	}

	int PointerEdge::GetInId()
	{
		try
		{
			std::shared_ptr<PointerNode> in_p = in_.lock();
			return in_p->get_id();
		}
		catch (std::bad_weak_ptr e)
		{
			// Handle invalid edge.
		return 0;
		}
	}
}