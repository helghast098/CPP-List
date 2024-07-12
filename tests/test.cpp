#include "List.hpp"
#include "gtest/gtest.h"

TEST(ListTest, ListCreation) {
	List<int> l;

	EXPECT_EQ(l.len(), 0);
	EXPECT_EQ(l.cursor_position(), 0);
	EXPECT_EQ(l.front(), std::nullopt);
	EXPECT_EQ(l.back(), std::nullopt);
}

// Encompesses .insert_left .insert_right .cursor_position
TEST(ListTest, ListInsertLeftMoveRight) {
	List<int> l;

	for (int i = 1; i <= 4; ++i)
	{
		l.insert_left(i);
	}

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
