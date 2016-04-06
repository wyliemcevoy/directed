#pragma once

#include <memory>

namespace ggraph
{
	class Node;

	class Edge
	{
	public:
		Edge(std::shared_ptr<Node> in, std::shared_ptr<Node> out_);
		~Edge();

		std::shared_ptr<Node> in_;
		std::shared_ptr<Node> out_;
	};
}