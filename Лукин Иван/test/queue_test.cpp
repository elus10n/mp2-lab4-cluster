#include "gtest.h"
#include "..\cluster_sim\queue.h"

TEST(Queue, can_create_queue)
{
	ASSERT_NO_THROW(Queue<int> q{});
}

TEST(Queue, can_create_queue_with_positive_size)
{
	ASSERT_NO_THROW(Queue<int> q(1));
}

TEST(Queue, throws_an_exception_when_try_to_create_queue_with_negative_lenght)
{
	ASSERT_ANY_THROW(Queue<int> q(-1));
}

TEST(Queue, can_push_elem)
{
	Queue<int> q{};

	ASSERT_NO_THROW(q.push(1));
}

TEST(Queue, can_pop_elem_correctly)
{
	Queue<int> q{};

	q.push(1);
	q.push(2);

	EXPECT_EQ(1, q.pop());
	EXPECT_EQ(2, q.pop());
}

TEST(Queue, cant_push_elem_in_full_queue)
{
	Queue<int> q(MaxQueuesize);

	for (int i = 1; i <= MaxQueuesize; i++)
		q.push(i);

	ASSERT_ANY_THROW(q.push(101));

	int tmp = q.pop();

	ASSERT_NO_THROW(q.push(102));
}

TEST(Queue, cant_pop_from_empty_queue)
{
	Queue<int> q{};

	ASSERT_ANY_THROW(q.pop());
}

TEST(Queue, get_head_is_working)
{
	Queue<int> q{};

	q.push(1);
	q.push(2);
	q.push(3);

	EXPECT_EQ(1, q.get_head());
}

TEST(Queue, get_head_doesnt_remove_element_from_top)
{
	Queue<int> q{};

	q.push(1);
	q.push(2);
	q.push(3);

	EXPECT_EQ(1, q.get_head());
	EXPECT_EQ(1, q.pop());
}

TEST(Queue, get_head_throws_an_exception_dealing_with_an_empty_queue)
{
	Queue<int> q{};

	ASSERT_ANY_THROW(q.get_head());
}

TEST(Queue, isEmpty_works_correctly)
{
	Queue<int> q{};

	EXPECT_EQ(true, q.isEmpty());

	q.push(1);

	EXPECT_EQ(false, q.isEmpty());
}

TEST(Queue, can_get_size)
{
	const int size = 10;

	Queue<int> q(size);

	EXPECT_EQ(size, q.get_size());
}

TEST(Queue, can_get_tail_pos_correctly)//третий и четвертый pop() нужен, чтобы проверить, правильно ли tail меняется при том, что правый стек успевает опустеть. На всякий случай
{
	Queue<int> q{};//tail == -1

	q.push(0);//tail == 0
	q.push(1);//tail == 1
	q.push(2);//tail == 2

	int tmp = q.pop();//tail == 1
	tmp = q.pop();//tail == 0

	q.push(1);//tail == 1
	q.push(2);//tail == 2
	q.push(3);//tail == 3
	q.push(4);//tail == 4

	tmp = q.pop();//tail == 3
	tmp = q.pop();//tail == 2

	EXPECT_EQ(2, q.get_tail_pos());
}
