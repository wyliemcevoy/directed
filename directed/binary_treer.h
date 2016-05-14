#pragma once
#include <memory>
#include <iostream>

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

        bool Insert(const T & ref);
		bool Contains(const T & ref) const;
		void print();

	private:
		std::unique_ptr<TreeNode> root_;
		void print_recursive(std::unique_ptr<TreeNode> & node)
		{
			if (node != nullptr)
			{
				print_recursive(node->left);
				std::cout << " " << node->data;
				print_recursive(node->right);
			}
		}
	};


	template<class T>
	bool BinaryTree<T>::Insert(const T & ref)
	{
		if (root_ == nullptr)
		{
			root_ = std::make_unique<TreeNode>(ref);
		}
		else {
			bool not_finished = true;

			TreeNode * node = root_.get();

			while (not_finished)
			{
				if (node->data < ref)
				{
					if (node->left == nullptr) {
						node->left = std::make_unique<TreeNode>(ref);
						not_finished = false;
					}
					else {
						node = node->left.get();
					}
				}
				else
				{
					if (node->right == nullptr)
					{
						node->right = std::make_unique<TreeNode>(ref);
						not_finished = false;
					}
					else {
						node = node->right.get();
					}
				}
			}
		}
		return true;
	}

	template<class T>
	bool BinaryTree<T>::Contains(const T & ref) const
	{
		if (root == nullptr)
		{
			return false;
		}

		std::unique_ptr<TreeNode<T>> & current_node = root_;
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

	template<class T>
	void BinaryTree<T>::print()
	{
		print_recursive(root_);
	}
}