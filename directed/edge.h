#pragma once

#include <memory>

namespace directed
{
	class Node;

	class Edge
	{
	public:
		Edge(std::shared_ptr<Node> in, std::shared_ptr<Node> out_);
		~Edge();

		std::shared_ptr<Node> GetOut();
		std::shared_ptr<Node> GetIn();


		int GetOutId();
		int GetInId();

		std::weak_ptr<Node> in_;
		std::weak_ptr<Node> out_;
	};
}