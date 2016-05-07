#pragma once
#include <memory>

namespace directed {

	template <class T>
	class BinaryTree
	{
		struct TreeNode;
		struct TreeNode{
			T data;
			std::unique_ptr <TreeNode> left;
			std::unique_ptr <TreeNode> right;
			TreeNode(const T& data_in) :data(data_in), left(nullptr), right(nullptr) {};
		};


	public:
		BinaryTree():root_(nullptr)
		{}

		~BinaryTree() {}

        bool insert(const T & ref);
		bool contains(const T & ref);

	private:
		std::unique_ptr<TreeNode> root_;
	};


	template<class T>
	bool BinaryTree<T>::insert(const T & ref)
	{
		std::unique_ptr<TreeNode> node_p(new TreeNode(ref));
		if (root_ == nullptr)
		{
			root_ = std::move(node_p);
		}
		else {
			
		}

		return true;
	}

	template<class T>
	void directed::contains(const T & ref)
	{
		if (root == nullptr)
		{
			return false;
		}

		std::unique_ptr<TreeNode<T>> & current_node = root;
		while (current_node != nullptr)
		{
			if (ref == current_node.data)
			{
				return true;
			}
			else {
				current_node = (current_node.data < ref) ? current_node.left : current_node.right;
			}
		}
		return false;
	}
}