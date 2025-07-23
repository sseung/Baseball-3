#include "gmock/gmock.h"
#include "baseball.cpp"

TEST(BaseballGame, ThrowExceptionWhenInputhLengthIsUnmatched) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST(BaseballGame, ThrowExceptionWhenInvlidChar) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}