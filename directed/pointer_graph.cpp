#include "stdafx.h"
#include "pointer_graph.h"

#include <memory>
#include <iostream>


namespace directed {

	PointerGraph::PointerGraph()
	{
	}


	PointerGraph::~PointerGraph()
	{
	}

	bool PointerGraph::AddNode(int id)
	{
		if (ContainsNode(id))
		{
			return false;
		}
		else
		{
			nodes_[id] = std::make_shared<PointerNode>(id);
			return true;
		}
	}

	bool PointerGraph::AddEdge(int out, int in)
	{
		if (ContainsNode(out) && ContainsNode(in))
		{

			// this should probably be references instead of making new shared pointers
			std::shared_ptr<PointerNode> in_ptr = get_node(in);
			std::shared_ptr<PointerNode> out_ptr = get_node(out);

			std::shared_ptr<PointerEdge> edge_ptr = std::make_shared<PointerEdge>(in_ptr, out_ptr);

			in_ptr->AddEdge(edge_ptr);
			out_ptr->AddEdge(edge_ptr);
			
			return true;
		}
		else { return false; }
	}

	bool PointerGraph::RemoveNode(int id)
	{
		if (ContainsNode(id))
		{
			std::shared_ptr<PointerNode> to_be_removed = get_node(id);
			to_be_removed->RemoveAllEdges();
			nodes_.erase(id);

			return true;
		} else {
			return false;
		}
	}

	bool PointerGraph::RemoveEdge(int out, int in)
	{
		if (ContainsNode(out) && ContainsNode(in))
		{
			std::shared_ptr<PointerNode> in_ptr = get_node(in);
			std::shared_ptr<PointerNode> out_ptr = get_node(out);

			in_ptr->RemoveEdgesComingFrom(out);
			out_ptr->RemoveEdgesGoingTo(in);
			
			return true;
		}

		return false;
	}

	bool PointerGraph::ContainsNode(int id)
	{
		return 	nodes_.find(id) != nodes_.end();
	}

	bool PointerGraph::ContainsEdge(int out, int in)
	{
		if (ContainsNode(out) && ContainsNode(in))
		{
			std::shared_ptr<PointerNode> in_ptr = get_node(in);
			std::shared_ptr<PointerNode> out_ptr = get_node(out);
			bool inFromOut = in_ptr->ContainsEdgeInFrom(out);
			bool outFromIn = out_ptr->ContainsEdgeOutTo(in);
			return ( inFromOut && outFromIn );
		}
		else {return false;}
		
	}

	bool PointerGraph::ContainsPath(int from, int to)
	{
		return false;
	}

	std::shared_ptr<PointerNode> PointerGraph::get_node(int id)
	{
		auto search = nodes_.find(id);
		if (search != nodes_.end())
		{
			return search->second;
		}
		else { return nullptr; }
	}

}