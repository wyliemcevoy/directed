#pragma once
#include <memory>
#include <iostream>
#include <algorithm>

namespace directed {

	// TODO: Height, LCA, preorder, postorder, Heapify

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
		bool Contains(const T & ref);
		void print();
		int GetHeight();

	private:
		std::unique_ptr<TreeNode> root_;
		int RecursiveHeight(TreeNode * node)
		{
			if (node == nullptr)
			{
				return 0;
			}
			else {
				return 1 + std::max(RecursiveHeight(node->left.get()), RecursiveHeight(node->right.get()));
			}
		}

		bool RecursiveContains(TreeNode * node, const T & target)
		{
			if (node == nullptr)
			{
				return false;
			}
			else {
				if (node->data == target)
				{
					return true;
				}
				else {
					return RecursiveContains(node->left.get(), target) || RecursiveContains(node->right.get(), target);
				}
			}
		}

		void RecursivePrint(std::unique_ptr<TreeNode> & node)
		{
			if (node != nullptr)
			{
				RecursivePrint(node->left);
				std::cout << " " << node->data;
				RecursivePrint(node->right);
			}
		}
	};

	template<class T>
	int BinaryTree<T>::GetHeight()
	{
		return RecursiveHeight(root_.get());
	}

	template<class T>
	bool BinaryTree<T>::Insert(const T & ref)
	{
		// Handle empty tree
		if (root_ == nullptr)
		{
			root_ = std::make_unique<TreeNode>(ref);
		}
		else {
			bool not_finished = true;

			TreeNode * node = root_.get();

			while (not_finished)
			{
				// guarenteed node not null
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
	bool BinaryTree<T>::Contains(const T & target)
	{
		// Empty tree check
		if (root_ == nullptr)
		{
			return false;
		}
		else {
			return RecursiveContains(root_.get(), target);
		}
	}

	template<class T>
	void BinaryTree<T>::print()
	{
		RecursivePrint(root_);
	}
}