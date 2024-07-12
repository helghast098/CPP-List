#include "List.hpp"
#include "gtest/gtest.h"

TEST(ListTest1, Creation) {
	List<int> l;

	EXPECT_EQ(l.len(), 0);
	EXPECT_EQ(l.cursor_position(), 0);
	EXPECT_EQ(l.front(), std::nullopt);
	EXPECT_EQ(l.back(), std::nullopt);
}

// Encompesses .insert_left .cursor_position .move_right
TEST(ListTest2, InsertLeftMoveRight) {
	List<int> l;

	for (int i = 1; i <= 4; ++i)
	{
		l.insert_left(i);
	}

	EXPECT_EQ(l.front(), std::optional<int>(1));
	EXPECT_EQ(l.back(), std::optional<int>(4));

	EXPECT_EQ(l.len(), 4);
	EXPECT_EQ(l.cursor_position(), 4);
	EXPECT_EQ(l.peek_right(), std::nullopt);
	EXPECT_EQ(l.peek_left(),std::optional<int>(4));

	// moving through list starting at head val: 1
	l.cursor_move_to_head();
	EXPECT_EQ(l.cursor_position(), 0);
	EXPECT_EQ(l.peek_left(), std::nullopt);
	EXPECT_EQ(l.peek_right(), std::optional<int>(1));

	// val: 2
	l.move_right();
	EXPECT_EQ(l.cursor_position(), 1);
	EXPECT_EQ(l.peek_left(), std::optional<int>(1));
	EXPECT_EQ(l.peek_right(), std::optional<int>(2));

	// val:3
	l.move_right();
	EXPECT_EQ(l.cursor_position(), 2);
	EXPECT_EQ(l.peek_left(), std::optional<int>(2));
	EXPECT_EQ(l.peek_right(), std::optional<int>(3));

	// val:4
	l.move_right();
	EXPECT_EQ(l.cursor_position(), 3);
	EXPECT_EQ(l.peek_left(), std::optional<int>(3));
	EXPECT_EQ(l.peek_right(), std::optional<int>(4));

	// val:5
	l.move_right();
	EXPECT_EQ(l.cursor_position(), 4);
	EXPECT_EQ(l.peek_left(), std::optional<int>(4));
	EXPECT_EQ(l.peek_right(), std::nullopt);

	// val:6
	l.move_right();
	EXPECT_EQ(l.cursor_position(), 4);
	EXPECT_EQ(l.peek_left(), std::optional<int>(4));
	EXPECT_EQ(l.peek_right(), std::nullopt);


}

// Encompesses .insert_left .insert_right .cursor_position
TEST(ListTest3, InsertRightMoveLeft) {
	List<int> l;

	for (int i = 1; i <= 4; ++i)
	{
		l.insert_right(i);
	}

	EXPECT_EQ(l.len(), 4);
	EXPECT_EQ(l.cursor_position(), 0);
	EXPECT_EQ(l.peek_right(), std::optional<int>(4));
	EXPECT_EQ(l.peek_left(), std::nullopt);

	// moving through list starting at tail val: 1
	l.cursor_move_to_tail();
	EXPECT_EQ(l.cursor_position(), 4);
	EXPECT_EQ(l.peek_left(), std::optional<int>(1));
	EXPECT_EQ(l.peek_right(), std::nullopt);

	// val: 2
	l.move_left();
	EXPECT_EQ(l.cursor_position(), 3);
	EXPECT_EQ(l.peek_left(), std::optional<int>(2));
	EXPECT_EQ(l.peek_right(), std::optional<int>(1));

	// val:3
	l.move_left();
	EXPECT_EQ(l.cursor_position(), 2);
	EXPECT_EQ(l.peek_left(), std::optional<int>(3));
	EXPECT_EQ(l.peek_right(), std::optional<int>(2));

	// val:4
	l.move_left();
	EXPECT_EQ(l.cursor_position(), 1);
	EXPECT_EQ(l.peek_left(), std::optional<int>(4));
	EXPECT_EQ(l.peek_right(), std::optional<int>(3));

	// val:5

	// val:6
	l.move_left();
	EXPECT_EQ(l.cursor_position(), 0);
	EXPECT_EQ(l.peek_left(), std::nullopt);
	EXPECT_EQ(l.peek_right(), std::optional<int>(4));

}

// Encompesses .move_left .move_right
TEST(ListTest4, AlternateMoveRightAndLeft) {
	List<int> l;

	for (int i = 1; i <= 4; ++i)
	{
		l.insert_left(i);
	}

	l.cursor_move_to_head();

	l.move_right();

	l.move_right();

	l.move_left();

	EXPECT_EQ(l.cursor_position(), 1);
	EXPECT_EQ(l.peek_right(), std::optional<int>(2));
	EXPECT_EQ(l.peek_left(), std::optional<int>(1));

	l.move_right();
	l.move_right();
	l.move_right();
	l.move_left();
	l.move_left();

	EXPECT_EQ(l.cursor_position(), 2);
	EXPECT_EQ(l.peek_right(), std::optional<int>(3));
	EXPECT_EQ(l.peek_left(), std::optional<int>(2));
}

// Encompesses .clear
TEST(ListTest5, Clear) {
	List<int> l;

	for (int i = 1; i <= 4; ++i)
	{
		l.insert_left(i);
	}

	l.clear();

	EXPECT_EQ(l.len(), 0);
	EXPECT_EQ(l.cursor_position(), 0);
	EXPECT_EQ(l.front(), std::nullopt);
	EXPECT_EQ(l.back(), std::nullopt);
	EXPECT_EQ(l.peek_right(), std::nullopt);
	EXPECT_EQ(l.peek_left(), std::nullopt);
}

// Encompesses .set_left .set_right
TEST(ListTest6, SetRightAndSetLeft) {
	List<int> l;

	for (int i = 1; i <= 4; ++i)
	{
		l.insert_left(i);
	}

	l.set_left(10);
	l.set_right(20);

	EXPECT_EQ(l.peek_left(), std::optional<int>(10));
	EXPECT_EQ(l.peek_right(), std::nullopt);

	l.move_left();

	l.set_left(100);
	l.set_right(50);
	EXPECT_EQ(l.peek_left(), std::optional<int>(100));
	EXPECT_EQ(l.peek_right(), std::optional<int>(50));
}

TEST(ListTest7, EraseRightEraseLeft) {
	List<int> l;

	// Condition: len = 0 and list empty
	l.erase_left();
	l.erase_right();
	EXPECT_EQ(l.len(), 0);
	EXPECT_EQ(l.cursor_position(), 0);
	EXPECT_EQ(l.peek_left(), std::nullopt);
	EXPECT_EQ(l.peek_right(), std::nullopt);
	EXPECT_EQ(l.front(), std::nullopt);
	EXPECT_EQ(l.back(), std::nullopt);

	// Condition: len = 1
	l.insert_right(1);
	l.erase_left();

	EXPECT_EQ(l.len(), 1);
	EXPECT_EQ(l.cursor_position(), 0);
	EXPECT_EQ(l.peek_left(), std::nullopt);
	EXPECT_EQ(l.peek_right(), std::optional<int>(1));
	EXPECT_EQ(l.front(), std::optional<int>(1));
	EXPECT_EQ(l.back(), std::optional<int>(1));

	l.erase_right();

	EXPECT_EQ(l.len(), 0);
	EXPECT_EQ(l.cursor_position(), 0);
	EXPECT_EQ(l.peek_left(), std::nullopt);
	EXPECT_EQ(l.peek_right(), std::nullopt);
	EXPECT_EQ(l.front(), std::nullopt);
	EXPECT_EQ(l.back(), std::nullopt);

	l.insert_left(1);
	l.erase_right();

	EXPECT_EQ(l.len(), 1);
	EXPECT_EQ(l.cursor_position(), 1);
	EXPECT_EQ(l.peek_left(), std::optional<int>(1));
	EXPECT_EQ(l.peek_right(), std::nullopt);
	EXPECT_EQ(l.front(), std::optional<int>(1));
	EXPECT_EQ(l.back(), std::optional<int>(1));

	l.erase_left();

	EXPECT_EQ(l.len(), 0);
	EXPECT_EQ(l.cursor_position(), 0);
	EXPECT_EQ(l.peek_left(), std::nullopt);
	EXPECT_EQ(l.peek_right(), std::nullopt);
	EXPECT_EQ(l.front(), std::nullopt);
	EXPECT_EQ(l.back(), std::nullopt);

	// Condition: len = 2;


}
