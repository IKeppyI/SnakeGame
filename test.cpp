#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "pch.h"

using ::testing::AtLeast;
using ::testing::Invoke;

class MockInputHandle : public KEYBOARD {
public:
    MockInputHandle(WINDOW& win, SNAKE& snak) : KEYBOARD(win, &snak) {}

    MOCK_METHOD(void, handleKeyInput, (int key, int scancode, int action, int mods), (override));

    void RealHandleKeyInput(int key, int scancode, int action, int mods) {
        KEYBOARD::handleKeyInput(key, scancode, action, mods);
    }
};

TEST(FoodTest, FoodGeneration) {
    MAP map(100, '1');
    APPLE apple(&map);
    short x, y;
    apple.pos(&x, &y);
    ASSERT_EQ(map.type(x, y), Cell::Food);
}

TEST(FoodTest, PositionGenerationWithinBounds) {
    MAP map(10, 1);

    for (int i = 0; i < 10; ++i) {
        APPLE food(&map);
        short x, y;
        food.pos(&x, &y);
        ASSERT_GE(x, 0);
        ASSERT_LT(x, map.Size());
        ASSERT_GE(y, 0);
        ASSERT_LT(y, map.Size());
    }
}

TEST(FoodTest, FoodDeletion) {
    MAP map(10, 1);
    APPLE food(&map);
    short x, y, x1, y1;
    food.pos(&x1, &y1);
    food.del(&map);
    food.pos(&x, &y);
    ASSERT_EQ(map.type(x1, y1), Cell::Empty);
    ASSERT_EQ(x, -1);
    ASSERT_EQ(y, -1);
}

TEST(SnakeTest, SnakeEatFood) {
    MAP map(100, 1);
    SNAKE snake(&map, 500, 3);
    APPLE apple(&map);
    short foodX, foodY;
    char side;
    bool turn;
    apple.pos(&foodX, &foodY);
    int s, h;
    ASSERT_EQ(map.type(foodX, foodY), Cell::Food);

    WINDOW window(5, 640, 480, "Snake Test");
    MockInputHandle mockKeyboard(window, snake);
    GAMESTATE state(0);
    EXPECT_CALL(mockKeyboard, handleKeyInput(::testing::_, ::testing::_, ::testing::_, ::testing::_))
        .WillRepeatedly(Invoke(&mockKeyboard, &MockInputHandle::RealHandleKeyInput));

    short snakeX, snakeY;
    while (true) {
        snake.Head->pos(&snakeX, &snakeY);

        if (snakeX == foodX && snakeY == foodY) {
            break;
        }

        if (snakeX < foodX) {
            mockKeyboard.handleKeyInput(GLFW_KEY_D, 0, GLFW_PRESS, 0);
            mockKeyboard.handleKeyInput(0, 0, GLFW_RELEASE, 0);
        }
        else if (snakeX > foodX) {
            mockKeyboard.handleKeyInput(GLFW_KEY_A, 0, GLFW_PRESS, 0);
            mockKeyboard.handleKeyInput(0, 0, GLFW_RELEASE, 0);
        }

        while (snakeX != foodX) {
            snake.Move(&state, &apple, nullptr, &map);
            snake.Head->pos(&snakeX, &snakeY);
        }

        if (snakeY < foodY) {
            mockKeyboard.handleKeyInput(GLFW_KEY_W, 0, GLFW_PRESS, 0);
            mockKeyboard.handleKeyInput(0, 0, GLFW_RELEASE, 0);
        }
        else if (snakeY > foodY) {
            mockKeyboard.handleKeyInput(GLFW_KEY_S, 0, GLFW_PRESS, 0);
            mockKeyboard.handleKeyInput(0, 0, GLFW_RELEASE, 0);
        }

        while (snakeY != foodY) {
            snake.Move(&state, &apple, nullptr, &map);
            snake.Head->pos(&snakeX, &snakeY);
        }
    }
    state.Score(&s, &h);
    ASSERT_EQ(s, 100);
    ASSERT_EQ(h, 100);
    ASSERT_EQ(snake.Size(), 4);
    ASSERT_EQ(map.type(foodX, foodY), Cell::Snake);
}

TEST(SnakeTest, CollisionCheck) {
    int moveCallCount = 0;
    MAP map(10, 2);
    SNAKE snake(&map, 500, 3);
    do { moveCallCount++; } while (!snake.Move(nullptr, nullptr, nullptr, &map));
    ASSERT_EQ(moveCallCount, 4);
}

TEST(SnakeTest, SizeChanging) {
    MAP map(100, 1);
    SNAKE snake(&map, 500, 3);
    ASSERT_EQ(snake.Size(), 3);
    for (int i = 0; i < 100; i++) snake.Grow(&map);
    ASSERT_EQ(snake.Size(), 103);
    snake.Decrease(53, &map);
    ASSERT_EQ(snake.Size(), 50);
}

TEST(MapTest, initTest) {
    MAP map(12, 3);
    ASSERT_EQ(map.type(8, 5), Cell::Block);
    ASSERT_EQ(map.type(11, 5), Cell::Block);
}

TEST(MapTest, ChangeCellType) {
    MAP map(10, 1);
    map.change(5, 5, Cell::Bonus);
    ASSERT_EQ(map.type(5, 5), Cell::Bonus);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
