#pragma once
#include <memory>

namespace directed {

	template <class T>
	class BinaryNode
	{
		struct TreeNode;
		stuct TreeNode{
			T data;
			std::unique_ptr <TreeNode> left;
			std::unique_ptr <TreeNode> right;
			TreeNode(const T& data_in) :data(data_in), left(nullptr), right(nullptr) {};
		};

	public:
		MultiTreeNode()
		{}

		~MultiTreeNode() {}



	private:

	};

}