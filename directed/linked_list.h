#pragma once

#include <string>

namespace directed
{
	// Raw pointer implementation of a linked list
	template <class T>
	class LinkedListNode {
	public:
		LinkedListNode(const T & data) : next_(nullptr), data_(data) {}
		~LinkedListNode() {
		}

		LinkedListNode * GetNext() const { return next_; }
		void SetNext(LinkedListNode * next) { next_ = next; }
		void SetValue(const T & data) { data_ = data; }
		bool HasNext() { return next_ != nullptr; }
		T GetData() { return data_; }


		// To prevent this function runing indefinitely if there is a cycle, it will
		// terminate after reaching a max depth (and not add the node)
		bool AddToTail(const T & data, int max_depth)
		{
			LinkedListNode * current = this;
			int count = 0;
			while (current->HasNext() && count < max_depth)
			{
				count++;
				current = current->GetNext();
			}

			if (count < max_depth)
			{
				current->SetNext(new LinkedListNode<T>(data));
				return true;
			}
			else
			{
				return false;
			}
		}

		bool AddNodeToTail(LinkedListNode * node, int max_depth)
		{
			LinkedListNode * current = this;
			int count = 0;
			while (current->HasNext() && count < max_depth)
			{
				count++;
				current = current->GetNext();
			}

			if (count < max_depth)
			{
				current->SetNext(node);
				return true;
			}
			else
			{
				return false;
			}
		}

		bool ContainsCycle()
		{
			LinkedListNode * single_jump = this;
			LinkedListNode * double_jump = this;

			while (double_jump != nullptr && double_jump->HasNext() && double_jump->GetNext()->HasNext())
			{
				single_jump = single_jump->GetNext();
				double_jump = double_jump->GetNext()->GetNext();

				if (double_jump == single_jump || double_jump->GetNext() == single_jump)
				{
					return true;
				}
			}
			return false;
		}

		std::string ToString()
		{
			int count = 0;
			int max_depth = 100;
			LinkedListNode<T> * current = this;
			std::stringstream ss;
			while (count < max_depth && current != nullptr)
			{
				ss << current->GetData();
				if (current->HasNext())
				{
					ss << ",";
				}

				count++;
				current = current->GetNext();
			}

			return ss.str();
		}

	private:
		LinkedListNode * next_;
		T data_;
	};

	template <class T>
	LinkedListNode<T>* Reverse(LinkedListNode<T>* head)
	{
		LinkedListNode<T> * previous = nullptr;
		LinkedListNode<T> * current = head;
		LinkedListNode<T> * next = nullptr;

		while (current != nullptr)
		{
			next = current->GetNext();
			current->SetNext(previous);
			previous = current;
			current = next;
		}

		return previous;
	}

}