
#include "linked_list_test.h"


LinkedListTest::LinkedListTest()
{

}

LinkedListTest::~LinkedListTest()
{
}

void LinkedListTest::SetUp()
{
	list_ = nullptr;
}

void LinkedListTest::TearDown()
{
	
}

void LinkedListTest::BuildCycleList()
{
	BuildRegularList();
	// Attach tail to head
	node_handles_[9]->SetNext(list_);
}

void LinkedListTest::BuildRegularList()
{
	for (int i = 0; i < 10; i++)
	{
		node_handles_.push_back(std::make_unique<directed::LinkedListNode<int>>(i));

		if (0 == i)
		{
			list_ = node_handles_[0].get();
		}
		else {
			list_->AddNodeToTail(node_handles_[i].get(),100);
		}
	}
}

TEST_F(LinkedListTest, successful_add_node)
{
	list_ = new directed::LinkedListNode < int>(10);
	list_->SetNext(new directed::LinkedListNode<int>(11));
	ASSERT_TRUE(true);
}

TEST_F(LinkedListTest, does_not_contain_cycle)
{
	BuildRegularList();

	ASSERT_FALSE(list_->ContainsCycle());
}

TEST_F(LinkedListTest, contains_cycle)
{
	BuildCycleList();
	ASSERT_TRUE(list_->ContainsCycle());

	directed::LinkedListNode<int> * current = list_->GetNext();

	while (current->GetData() != 9)
	{
		current = current->GetNext();
	}
	current->SetNext(nullptr);

	directed::LinkedListNode<int> * tiny_list = new directed::LinkedListNode<int>(1);
	tiny_list->SetNext(tiny_list);
	ASSERT_TRUE(tiny_list->ContainsCycle());
	tiny_list->SetNext(nullptr);
	delete(tiny_list);
}


TEST_F(LinkedListTest, reverse_test)
{
	BuildRegularList();

	int regular[10];
	int reversed[10];

	directed::LinkedListNode<int> * cur_reg = list_;

	for (int i = 0; i < 10; i++)
	{
		regular[i] = cur_reg->GetData();
		cur_reg = cur_reg->GetNext();
	}

	directed::LinkedListNode<int> * cur_rev = directed::Reverse(list_);

	for (int i = 0; i < 10; i++)
	{
		reversed[i] = cur_rev->GetData();
		cur_rev = cur_rev->GetNext();
	}

	for (int i = 0; i < 10; i++)
	{
		ASSERT_EQ(regular[i], reversed[9 - i]);
	}

	ASSERT_TRUE(true);
}

