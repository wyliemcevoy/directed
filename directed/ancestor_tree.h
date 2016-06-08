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
		AncestorNode(const T & data_in) : data(data_in), depth_(0), location_(0) {}
		
		void TickLeft();
		void TickRight();
		T data;
		
		// Reference to the tree it belongs to
		AncestorTree<T> tree_;

		friend std::ostream & operator << (std::ostream & os, const AncestorNode & node);

	private:
		unsigned int ONE = 1;
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
		location_ = location | one << 32 - depth;
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
		AncestorTree() {}
		~AncestorTree() {}
	};

}