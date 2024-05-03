#include <deepstate/DeepState.hpp>
#include "game.h"

using namespace deepstate;

TEST(Game, BallReset) {
    cBall ball(10, 10);
    ball.reset();
    ASSERT_EQ(ball.getX(), 10);
    ASSERT_EQ(ball.getY(), 10);
    ASSERT_EQ(ball.getDir(), STOP);
}

TEST(Game, BallMove) {
    cBall ball(10, 10);
    ball.changeDirection(RIGHT);
    ball.move();
    ASSERT_EQ(ball.getX(), 11);
    ASSERT_EQ(ball.getY(), 10);
}

TEST(Game, PaddleReset) {
    cPaddle paddle(5, 5);
    paddle.reset();
    ASSERT_EQ(paddle.getX(), 5);
    ASSERT_EQ(paddle.getY(), 5);
}

TEST(Game, PaddleMove) {
    cPaddle paddle(5, 5);
    paddle.changeDirection(UP);
    paddle.move();
    ASSERT_EQ(paddle.getY(), 4);
}

TEST(Game, GameManagerScoreUp) {
    cGameManager gameManager;
    cPaddle paddle1(0, 0);
    gameManager.ScoreUp(&paddle1);
    ASSERT_EQ(gameManager.score1, 1);
}

TEST(Game, GameManagerLogic) {
    cGameManager gameManager;
    gameManager.Logic();
    // Cannot fully test Logic() without specific input, 
    // but checking if it doesn't cause a crash.
}

TEST(Game, GameManagerGame) {
    cGameManager gameManager;
    gameManager.Game();
    // Cannot fully test Game() without user input, 
    // but checking if it doesn't cause a crash.
}

int main(int argc, char *argv[]) {
    DeepState_InitOptions(argc, argv);

    DeepState_Run();
    return 0;
}
