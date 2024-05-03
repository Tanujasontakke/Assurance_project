#pragma once

#include <iostream>
#include <conio.h>
#include <time.h>
#include <Windows.h>

enum eDirection { STOP, RIGHT, UPRIGHT, DOWNRIGHT, LEFT, UPLEFT, DOWNLEFT };
enum eControler { PAUSE, UP, DOWN };

class cBall {
private:
    int x, y;
    int originalX, originalY;
    eDirection dir;

public:
    cBall(int posX, int posY);
    void reset();
    void changeDirection(eDirection direction);
    void randomDirection();
    inline int getX();
    inline int getY();
    inline int getDir();
    void move();
};

class cPaddle {
private:
    int x, y;
    int originalX, originalY;
    eControler joyStick;

public:
    cPaddle(int posX, int posY);
    void reset();
    inline int getX();
    inline int getY();
    void changeDirection(eControler dir);
    void move();
};

class cGameManager {
private:
    int width, height;
    int score1, score2;
    bool quit;
    cBall* ball;
    cPaddle* player1;
    cPaddle* player2;

public:
    cGameManager();
    ~cGameManager();
    void ScoreUp(cPaddle* player);
    void Draw();
    void Input();
    void Logic();
    void Game();
};
