#pragma once
#include <memory>
#include <iostream>
#include <algorithm>

namespace directed {

	template <class T>
	class BinaryTree
	{
		struct TreeNode {
			T data;
			std::unique_ptr <TreeNode> left;
			std::unique_ptr <TreeNode> right;
			TreeNode(const T& data_in) :data(data_in), left(nullptr), right(nullptr) {};
		};

	public:
		BinaryTree() :root_(nullptr)
		{}

		~BinaryTree() {}

		bool Insert(const T & ref);
		bool Contains(const T & ref);
		std::vector<T> Preorder();
		std::vector<T> Postorder();
		std::vector<T> Inorder();
		int GetHeight();

		// Slow 
		// Uses vectors 
		// Could use arrays, but would require a O(h) pass of the tree to determine height
		T GetLowestCommonAncestor(const T & one, const T & other);

	private:
		std::unique_ptr<TreeNode> root_;
		int RecursiveHeight(TreeNode * node);
		bool RecursiveContains(TreeNode * node, const T & target);
		static void RecursivePreorder(std::vector<T> * build, TreeNode * node);
		static void RecursivePostorder(std::vector<T> * build, TreeNode * node);
		static void RecursiveInorder(std::vector<T> * build, TreeNode * node);
		static void RecursiveGetPath(std::vector<T> * path, TreeNode * current, const T & target);
		std::vector<T> GetPath(const T & target);


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
				if (node->data > ref)
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
	T BinaryTree<T>::GetLowestCommonAncestor(const T & one, const T & other)
	{
		// Handle empty tree scenario
		if (root_ == nullptr)
		{
			return one;
		}

		std::vector<T> one_path = GetPath(one);
		std::vector<T> other_path = GetPath(other);

		// Handle bad input (one or other was not in the tree)
		if (one_path.empty())
		{
			return one;
		}
		if (other_path.empty())
		{
			return other;
		}

		T * current_ancestor = & root_.get()->data;
		int i = 0;

		while ((one_path.size() > i ) && (other_path.size() > i ) && one_path[i] == other_path[i] )
		{
			current_ancestor = & one_path[i];
			i++;
		}

		return * current_ancestor;
	}


	template<class T>
	std::vector<T> directed::BinaryTree<T>::GetPath(const T & target)
	{
		std::vector<T> path;
		RecursiveGetPath(&path, root_.get(), target);

		return path;
	}

	template<class T>
	void directed::BinaryTree<T>::RecursiveGetPath(std::vector<T> * path, TreeNode * current, const T & target)
	{
		if (current != nullptr)
		{
			path->push_back(current->data);

			if (current->data == target)
			{
				// Path found
				return;
			}
			else {
				if (current->data > target)
				{
					// recurse left
					RecursiveGetPath(path, current->left.get(), target);
				}
				else {
					// recurse right
					RecursiveGetPath(path, current->right.get(), target);
				}
			}
		}
		else
		{
			// The target does not exist in this tree, return an empty path for failure.
			path->clear();
		}
	}



	template<class T>
	std::vector<T> BinaryTree<T>::Preorder()
	{
		std::vector<T> build;

		if (root_ != nullptr)
		{
			RecursivePreorder(&build, root_.get());
		}

		return build;
	}

	template<class T>
	std::vector<T> BinaryTree<T>::Inorder()
	{
		std::vector<T> build;

		if (root_ != nullptr)
		{
			RecursiveInorder(&build, root_.get());
		}

		return build;
	}

	template<class T>
	std::vector<T> BinaryTree<T>::Postorder()
	{
		std::vector<T> build;

		if (root_ != nullptr)
		{
			RecursivePostorder(&build, root_.get());
		}

		return build;
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
	int BinaryTree<T>::RecursiveHeight(TreeNode * node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		else {
			return 1 + std::max(RecursiveHeight(node->left.get()), RecursiveHeight(node->right.get()));
		}
	}

	template<class T>
	bool BinaryTree<T>::RecursiveContains(TreeNode * node, const T & target)
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

	template<class T>
	void BinaryTree<T>::RecursivePreorder(std::vector<T> * build, TreeNode * node)
	{
		if (node != nullptr)
		{
			build->push_back(node->data);

			if (node->left != nullptr) {
				RecursivePreorder(build, node->left.get());
			}
			if (node->right != nullptr) {
				RecursivePreorder(build, node->right.get());
			}
		}
	}

	template<class T>
	void BinaryTree<T>::RecursivePostorder(std::vector<T> * build, TreeNode * node)
	{
		if (node != nullptr) {

			if (node->left != nullptr)
			{
				RecursivePostorder(build, node->left.get());
			}
			if (node->right != nullptr) {
				RecursivePostorder(build, node->right.get());
			}
			build->push_back(node->data);

		}
	}

	template<class T>
	void BinaryTree<T>::RecursiveInorder(std::vector<T> * build, TreeNode * node)
	{
		if (node != nullptr) {

			if (node->left != nullptr)
			{
				RecursiveInorder(build, node->left.get());
			}

			build->push_back(node->data);

			if (node->right != nullptr) {
				RecursiveInorder(build, node->right.get());
			}

		}
	}

}