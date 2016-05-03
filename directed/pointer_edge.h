#pragma once

#include <memory>

namespace directed
{
	class PointerNode;

	class PointerEdge
	{
	public:
		PointerEdge(std::shared_ptr<PointerNode> in, std::shared_ptr<PointerNode> out_);
		~PointerEdge();

		std::shared_ptr<PointerNode> GetOut();
		std::shared_ptr<PointerNode> GetIn();


		int GetOutId();
		int GetInId();

		std::weak_ptr<PointerNode> in_;
		std::weak_ptr<PointerNode> out_;
	};
}