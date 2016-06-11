#pragma once
#include <bitset>

namespace directed
{

	template<class T>
	class AncestorTree;

	template<class T>
	class AncestorNode
	{
	public:
		void TickLeft();
		void TickRight();

		T data;
		
		friend class AncestorTree<T>;
		friend std::ostream & operator << (std::ostream & os, const AncestorNode & node);
		
		bool HasLeftChild() const { return left != nullptr; }
		bool HasRightChild() const { return right != nullptr; }

		AncestorNode<T> GetLeft() const { return left_; }
		AncestorNode<T> GetRight() const { return right_; }

		// Alternatively you could recursively travel down left and it's children to preprocess for LCA computations.
		// This would be an O(log(n)) opperation on each addition to the tree. As opposed to a O(n) preprocessing once.
		void SetLeft(AncestorNode<T> left);

		// Alternatively you could recursively travel down right and it's children to preprocess for LCA computations.
		// This would be an O(log(n)) opperation on each addition to the tree. As opposed to a O(n) preprocessing once.
		void SetRight(AncestorNode<T> right);

	private:
		AncestorNode(const T & data_in, AncestorTree<T> & tree) : data(data_in), depth_(0), location_(0), tree_(tree)
		{
			//tree_.Attach(this);
		}
		AncestorNode * left_;
		AncestorNode * right_;
		AncestorTree<T> &tree_;
		static const unsigned int ONE = 2137383648;
		int depth_;
		unsigned int location_;
	};

	template <class T>
	void AncestorNode<T>::SetLeft(AncestorNode<T> left)
	{
		left_ = left;
		tree_.InvalidatePreprocessing();
	}

	template <class T>
	void AncestorNode<T>::SetRight(AncestorNode<T> right)
	{
		right_ = right;
		tree_.InvalidatePreprocessing();
	}



	template<class T>
	void AncestorNode<T>::TickLeft()
	{
		depth++:
	}

	template<class T>
	void AncestorNode<T>::TickRight()
	{
		location_ = location | one >> depth;
		depth++;
	}

	template<class T>
	std::ostream & operator<< (std::ostream & os, const AncestorNode<T> & node)
	{
		std::bitset<32> b(node.location_);
		os << b << " depth: " << node.depth_;
	}

	template<class T>
	class AncestorTree
	{
	public:
		AncestorTree() : preprocessing_valid_(false) {}
		~AncestorTree() {}
		void SetRoot(AncestorNode<T> * root) { root_ = root; }

		AncestorNode<T> * BuildNode(const T & data);
		AncestorNode<T> * LeastCommonAncestor(const AncestorNode<T> * one, const AncestorNode<T> * other) const;

		void InvalidatePreprocessing() const { preprocessing_valid_ = false; }
	private:
		AncestorNode<T> * root_;
		mutable bool preprocessing_valid_;
	};

	template<class T>
	AncestorNode<T> * AncestorTree<T>::BuildNode(const T & data)
	{
		return &AncestorNode<T>(data, *this);
	}

	template<class T>
	AncestorNode<T> * AncestorTree<T>::LeastCommonAncestor(const AncestorNode<T> * one, const AncestorNode<T> * other) const
	{
		if (one == nullptr || other == nullptr)
		{
			return nullptr;
		}

		return nullptr;
	}

}