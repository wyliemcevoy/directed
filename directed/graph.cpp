#include "stdafx.h"
#include "graph.h"
#include "edge.h"
#include <memory>
#include <iostream>


namespace directed {

	Graph::Graph()
	{
	}


	Graph::~Graph()
	{
	}

	bool Graph::AddNode(int id)
	{
		if (ContainsNode(id))
		{
			return false;
		}
		else
		{
			nodes_[id] = std::make_shared<Node>(id);
			return true;
		}
	}

	bool Graph::AddEdge(int out, int in)
	{
		if (ContainsNode(out) && ContainsNode(in))
		{

			// this should probably be references instead of making new shared pointers
			std::shared_ptr<Node> in_ptr = get_node(in);
			std::shared_ptr<Node> out_ptr = get_node(out);

			std::shared_ptr<Edge> edge_ptr = std::make_shared<Edge>(in_ptr, out_ptr);

			in_ptr->AddEdge(edge_ptr);
			out_ptr->AddEdge(edge_ptr);
			
			return true;
		}
		else { return false; }
	}

	bool Graph::RemoveNode(int id)
	{
		if (ContainsNode(id))
		{
			std::shared_ptr<Node> to_be_removed = get_node(id);
			to_be_removed->RemoveAllEdges();
			nodes_.erase(id);

			return true;
		} else {
			return false;
		}
	}

	bool Graph::RemoveEdge(int out, int in)
	{
		if (ContainsNode(out) && ContainsNode(in))
		{
			std::shared_ptr<Node> in_ptr = get_node(in);
			std::shared_ptr<Node> out_ptr = get_node(out);

			in_ptr->RemoveEdgesComingFrom(out);
			out_ptr->RemoveEdgesGoingTo(in);
			
			return true;
		}

		return false;
	}

	bool Graph::ContainsNode(int id)
	{
		return 	nodes_.find(id) != nodes_.end();
	}

	bool Graph::ContainsEdge(int out, int in)
	{
		if (ContainsNode(out) && ContainsNode(in))
		{
			std::shared_ptr<Node> in_ptr = get_node(in);
			std::shared_ptr<Node> out_ptr = get_node(out);
			bool inFromOut = in_ptr->ContainsEdgeInFrom(out);
			bool outFromIn = out_ptr->ContainsEdgeOutTo(in);
			return ( inFromOut && outFromIn );
		}
		else {return false;}
		
	}

	std::shared_ptr<Node> Graph::get_node(int id)
	{
		auto search = nodes_.find(id);
		if (search != nodes_.end())
		{
			return search->second;
		}
		else { return nullptr; }
	}

}