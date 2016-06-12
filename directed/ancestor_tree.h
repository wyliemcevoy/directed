#pragma once
#include <bitset>
#include <math.h>
#include <unordered_map>
#include <memory>


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
		
		
		friend std::ostream & operator << (std::ostream & os, const AncestorNode & node);
		
		bool HasLeftChild() const { return left_ != nullptr; }
		bool HasRightChild() const { return right_ != nullptr; }

		AncestorNode<T> * GetLeft() const { return left_; }
		AncestorNode<T> * GetRight() const { return right_; }

		// Alternatively you could recursively travel down left and it's children to preprocess for LCA computations.
		// This would be an O(log(n)) opperation on each addition to the tree. As opposed to a O(n) preprocessing once.
		void SetLeft(AncestorNode<T> *left);

		// Alternatively you could recursively travel down right and it's children to preprocess for LCA computations.
		// This would be an O(log(n)) opperation on each addition to the tree. As opposed to a O(n) preprocessing once.
		void SetRight(AncestorNode<T> *right);
		
		// Tight coupling between node and tree to ensure encapsulation of preprocessing data
		friend class AncestorTree<T>;

	private:
		AncestorNode(const T & data_in, AncestorTree<T> & tree) : data(data_in), depth_(0), location_(0), tree_(tree), is_connected_to_root_(false), left_(nullptr), right_(nullptr) {}
		AncestorNode * left_;
		AncestorNode * right_;
		AncestorTree<T> &tree_;

		// 32 bit int with 1 in leftmost position and zeros everwhere else :
		// 1000 0000 0000 0000 0000 0000 0000 0000
		static const unsigned long ONE = 2147483648;
		int depth_;
		int key_;
		unsigned long location_;

		bool is_connected_to_root_;
	};

	template <class T>
	void AncestorNode<T>::SetLeft(AncestorNode<T> * left)
	{
		left_ = left;
		//tree_.InvalidatePreprocessing();
	}

	template <class T>
	void AncestorNode<T>::SetRight(AncestorNode<T> * right)
	{
		right_ = right;
		//tree_.InvalidatePreprocessing();
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


	// supports duplicates
	template<class T>
	class AncestorTree
	{
	public:
		AncestorTree() : preprocessing_valid_(false), root_(nullptr) {}
		~AncestorTree() {}
		void SetRoot(AncestorNode<T> * root) { root_ = root; }
		AncestorNode<T> * BuildNode(const T & data);
		AncestorNode<T> * LeastCommonAncestor(AncestorNode<T> * one, AncestorNode<T> * other); // const;
		void InvalidatePreprocessing() { preprocessing_valid_ = false; }

	private:
		void PreprocessTree();
		void RecursivePreprocessTree(AncestorNode<T> * node, unsigned int current_location, int current_depth);
		int CalculateKey(unsigned long location, int depth);
		AncestorNode<T> * root_;
		mutable bool preprocessing_valid_;

		std::unordered_map<int, AncestorNode<T> *> map_;
		std::vector<std::unique_ptr<AncestorNode<T>>> nodes_;

		// 32 bit int with 1 in leftmost position and zeros everwhere else :
		// 1000 0000 0000 0000 0000 0000 0000 0000
		static const unsigned int ONE = 2147483648;

	};

	template<class T>
	AncestorNode<T> * AncestorTree<T>::BuildNode(const T & data)
	{
		std::unique_ptr<AncestorNode<T>> node_p( new AncestorNode<T>(data, *this));
		nodes_.push_back(std::move(node_p));
		return nodes_[nodes_.size() - 1].get();
	}

	template<class T>
	AncestorNode<T> * AncestorTree<T>::LeastCommonAncestor(AncestorNode<T> * one, AncestorNode<T> * other) // const
	{
		// Handle invalid input (pointers must not be null and nodes must belong to this tree.
		if (one == nullptr || other == nullptr) // || *one->tree_ != *this || *other->tree_ != *this)
		{
			return nullptr;
		}

		if ( ! preprocessing_valid_)
		{
			PreprocessTree();
		}

		// It is  possible that there is no path between these nodes in which case there exists no LCA
		if ( ! (one->is_connected_to_root_ && other->is_connected_to_root_))
		{
			return nullptr;
		}
		/*
		// If the two input pointers point at the same node it is the LCA 
		if (one == other)
		{
			return one;
		}
		*/


		// XOR their locations
		unsigned long lca_bit_depth = one->location_ ^ other->location_;

		// Determine the depth of the LCA if it exists
		// Use hardware speedup to avoid a O(log(n)) search for the leftmost bit
		// for gcc use :
		//		int lca_depth = __builtin_clz(lca_bit_depth);
		
		unsigned long lca_depth = 0;
		unsigned char success = _BitScanReverse(&lca_depth, lca_bit_depth);

		if (success)
		{
			lca_depth = 31 - lca_depth;
			if (lca_bit_depth == 0)
			{
				return root_;
			}

			// Check to see if one is an offspring of other
			if (lca_depth == other->depth_)
			{
				return other;
			}
			// Check to see if other is an offspring of one
			if (lca_depth == one->depth_)
			{
				return one;
			}

			// Consider taking all nodes in the tree at a certain depth and adding them to a list preserving their left-to-right order.
			// The LCA woudld be in that list at index of an integer created by taking the leftmost bits up to lca_depth.
			// But instead of using an array for each depth level of the tree, use a map for the entire tree and use both the depth and
			// the corresponding index at that depth as a unique key.
			// 
			//													 0
			//												 1       2
			//						     	               3   4   5   6
			//
			// Given a depth and an index the key would be generated by a summation of i=0 to (depth-1) 2^i + index
			// Using power series, this simplifies to 2^depth + index - 1

			//int lca_index = one->location_ >> (32 - lca_depth);
			//int key = pow(2, lca_depth) + lca_index - 1;
			int key = CalculateKey(one->location_, lca_depth);

			return map_[key];
		}





		return nullptr;
	}

	template<class T>
	int AncestorTree<T>::CalculateKey(unsigned long location, int depth)
	{
		if (depth == 0)
		{
			return 0;
		}
		return  pow(2.0, depth) + (location >> (32 - depth)) - 1;
	}

	template<class T>
	void AncestorTree<T>::PreprocessTree()
	{
		RecursivePreprocessTree(root_, 0, 0);
		// validate preprocessing flag
		preprocessing_valid_ = true;
	}

	template<class T>
	void AncestorTree<T>::RecursivePreprocessTree(AncestorNode<T> * node, unsigned int current_location, int current_depth)
	{
		if (node != nullptr)
		{
			node->depth_ = current_depth;
			node->location_ = current_location;
			node->key_ = CalculateKey(current_location, current_depth);

			node->is_connected_to_root_ = true;

			map_[node->key_] = node;

			if (node->HasLeftChild())
			{
				// bit at depth is already 0 so no need to set it
                RecursivePreprocessTree(node->GetLeft(), current_location, current_depth + 1);
			}

			if (node->HasRightChild())
			{
				// set bit at depth to 1
				unsigned long right_location = current_location | ONE >> current_depth;
				RecursivePreprocessTree(node->GetRight(), right_location, current_depth + 1);
			}

		}
	}
}