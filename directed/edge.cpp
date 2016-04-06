#include "stdafx.h"
#include "edge.h"


namespace ggraph {

	Edge::Edge(std::shared_ptr<Node> in, std::shared_ptr<Node> out) :
		in_(in), out_(out)
	{

	}


	Edge::~Edge()
	{
	}

}