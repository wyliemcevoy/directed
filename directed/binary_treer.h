#pragma once
#include <memory>

namespace directed {

	template <class T>
	class BinaryTree
	{
		struct TreeNode;
		stuct TreeNode{
			T data;
			std::unique_ptr <TreeNode> left;
			std::unique_ptr <TreeNode> right;
			TreeNode(const T& data_in) :data(data_in), left(nullptr), right(nullptr) {};
		};

		void insert(const T & ref);


	public:
		BinaryTree():root_(nullptr)
		{}

		~BinaryTree() {}



	private:
		std::unique_ptr<TreeNode> root_;
	};


	template<class T>
	void BinaryTree<T>::insert(const T & ref)
	{
		std::unique_ptr<TreeNode> node_p(new TreeNode(ref));
		if (root == nullptr)
		{
			root = std::move(node_p);
		}
		else {
			
		}
	}


}