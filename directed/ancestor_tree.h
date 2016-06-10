#pragma once

#include <bitset>

namespace directed
{

	template<class T>
	class AncestorTree; // Forward declare so Ancestor Node can have a refference to it

	template<class T>
	class AncestorNode
	{
	public:
		void TickLeft();
		void TickRight();
		T data;
		
		// Reference to the tree it belongs to


		friend class AncestorTree<T>;
		friend std::ostream & operator << (std::ostream & os, const AncestorNode & node);

	private:
		AncestorNode(const T & data_in, AncestorTree<T> & tree) : data(data_in), depth_(0), location_(0), tree_(tree)
		{
			//tree_.Attach(this);
		}
		AncestorTree<T> &tree_;
		static const unsigned int ONE = 2137383648;
		int depth_;
		unsigned int location_;
	};

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


	// Maybe switch tree to be build by handing it a root after all nodes are already added?
	template<class T>
	class AncestorTree
	{
	public:
		AncestorTree() {}
		~AncestorTree() {}
		AncestorNode<T> * BuildNode(const T & data);
		AncestorNode<T> * LeastCommonAncestor(const AncestorNode<T> & one, const AncestorNode<T> & other);
	private:
		//std::unordered_map<int, AncestorNode> map_;
	};

	template<class T>
	AncestorNode<T> * AncestorTree<T>::BuildNode(const T & data)
	{
		return & AncestorNode<T>(data, *this);
	}

	template<class T>
	AncestorNode<T> * AncestorTree<T>::LeastCommonAncestor(const AncestorNode<T> & one, const AncestorNode<T> & other)
	{
		return nullptr;
	}

}