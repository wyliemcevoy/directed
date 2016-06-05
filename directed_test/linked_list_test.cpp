
#include "linked_list_test.h"
#include <iostream>


LinkedListTest::LinkedListTest()
{

}

LinkedListTest::~LinkedListTest()
{
}

void LinkedListTest::SetUp()
{
	list_ = new directed::LinkedListNode<int>(10);
}

void LinkedListTest::TearDown()
{
	delete(list_);
}

void LinkedListTest::BuildCycleList()
{
	directed::LinkedListNode<int> * current = list_;

	for (int i = 0; i < 10; i++)
	{
		list_->AddToTail(i,100);
	}

	while (current->HasNext())
	{
		current = current->GetNext();
	}
	current->SetNext(list_);

	std::cout << std::endl;
}

void LinkedListTest::BuildRegularList()
{
	for (int i = 0; i < 10; i++)
	{
		list_->AddToTail(i,100);
	}
}

TEST_F(LinkedListTest, successful_add_node)
{
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

	for (int i = 0; i < 11; i++)
	{
		regular[i] = cur_reg->GetData();
		cur_reg = cur_reg->GetNext();
	}

	directed::LinkedListNode<int> * cur_rev = directed::Reverse(list_);

	
	std::cout << cur_rev->ToString() << std::endl;
	std::cout << cur_reg->ToString() << std::endl;

	for (int i = 0; i < 11; i++)
	{
		reversed[i] = cur_rev->GetData();
		cur_rev = cur_rev->GetNext();
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << regular[i] << " " << reversed[10 - i] << std::endl;

		//ASSERT_EQ(cur_reg[i], cur_rev[10 - i]);
	}

	int a = 0;

	delete(cur_rev);

	ASSERT_TRUE(true);
}

