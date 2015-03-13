#include "../QueueUsingStacks/Queue.h"

#include <gtest/gtest.h>

#include <chrono>
#include <iostream>


//==============================================================================================================================================================
class QuickTest : public ::testing::Test
{
	public:
		virtual void SetUp() override
		{
			startTime = std::chrono::system_clock::now();
		}

		virtual void TearDown() override
		{
			auto totalTime = startTime - std::chrono::system_clock::now();

			auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(totalTime);

			EXPECT_LT(duration.count(), 1) << "Test too slow";
		}

	public:
		std::chrono::system_clock::time_point startTime;
};

//==============================================================================================================================================================
class QueueTest : public QuickTest
{
	public:
		virtual void SetUp() override
		{
			QuickTest::SetUp();

			queue.enqueue(0);
			queue.enqueue(1);
			queue.enqueue(2);
		}

		virtual void TearDown() override
		{
			QuickTest::TearDown();
		}

	public:
		Queue queue;
};

//==============================================================================================================================================================
TEST_F(QueueTest, dequeue)
{
	EXPECT_EQ(queue.dequeue(), 0);
	EXPECT_EQ(queue.dequeue(), 1);
	EXPECT_EQ(queue.dequeue(), 2);
}

//==============================================================================================================================================================
TEST_F(QueueTest, isEmpty)
{
	EXPECT_EQ(queue.isEmpty(), false);

	// empty the queue
	EXPECT_EQ(queue.dequeue(), 0);
	EXPECT_EQ(queue.dequeue(), 1);
	EXPECT_EQ(queue.dequeue(), 2);

	EXPECT_EQ(queue.isEmpty(), true);
}

//==============================================================================================================================================================
TEST_F(QueueTest, mustThrow)
{
	auto f = [](Queue queue)
	{
		queue.dequeue();
		queue.dequeue();
		queue.dequeue();
		queue.dequeue();
	};

	EXPECT_THROW(f(queue), std::exception);
}