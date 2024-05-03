#include "game.h"

using namespace std;

cBall::cBall(int posX, int posY) {
    originalX = posX;
    originalY = posY;
    x = posX;
    y = posY;
    dir = STOP;
}

void cBall::reset() {
    x = originalX;
    y = originalY;
    dir = STOP;
}

void cBall::changeDirection(eDirection direction) {
    dir = direction;
}

void cBall::randomDirection() {
    srand(time(0));
    dir = (eDirection)((rand() % 6) + 1);
}

inline int cBall::getX() {
    return x;
}

inline int cBall::getY() {
    return y;
}

inline int cBall::getDir() {
    return dir;
}

void cBall::move() {
    switch (dir) {
    case STOP:
        break;
    case RIGHT:
        x++;
        break;
    case UPRIGHT:
        x++; y--;
        break;
    case DOWNRIGHT:
        x++; y++;
        break;
    case LEFT:
        x--;
        break;
    case UPLEFT:
        x--; y--;
        break;
    case DOWNLEFT:
        x--; y++;
        break;
    default:
        break;
    }
}

cPaddle::cPaddle(int posX, int posY) {
    originalX = posX;
    originalY = posY;
    x = posX;
    y = posY;
    joyStick = PAUSE;
}

void cPaddle::reset() {
    x = originalX;
    y = originalY;
    joyStick = PAUSE;
}

inline int cPaddle::getX() {
    return x;
}

inline int cPaddle::getY() {
    return y;
}

void cPaddle::changeDirection(eControler dir) {
    joyStick = dir;
}

void cPaddle::move() {
    switch (joyStick) {
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    case PAUSE:
        break;
    default:
        break;
    }
}

cGameManager::cGameManager() {
    quit = false;
    height = 15;
    width = 50;
    score1 = score2 = 0;
    ball = new cBall(width / 2, height / 2);
    player1 = new cPaddle(1, height / 2);
    player2 = new cPaddle(width - 2, height / 2);
}

cGameManager::~cGameManager() {
    delete ball, player1, player2;
}

void cGameManager::ScoreUp(cPaddle* player) {
    if (player == player1)
        score1++;
    else if (player == player2)
        score2++;

    ball->reset();
    player1->reset();
    player2->reset();
}

void cGameManager::Draw() {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

    for (int i = 0; i < width + 2; i++)
        cout << "\xB2";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int ballX = ball->getX();
            int ballY = ball->getY();
            int player1x = player1->getX();
            int player1y = player1->getY();
            int player2x = player2->getX();
            int player2y = player2->getY();

            if (j == 0)
                cout << "\xB1";

            if (ballX == j && ballY == i)
                cout << "o";
            else if (player1x == j && (player1y >= i && player1y < i + 4))
                cout << "\xDB";
            else if (player2x == j && (player2y >= i && player2y < i + 4))
                cout << "\xDB";
            else
                cout << " ";

            if (j == width - 1)
                cout << "\xB1";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "\xB2";
    cout << endl;

    for (int i = 0; i < width / 2 - 3; i++)
        cout << " ";
    cout << score1 << " : " << score2 << endl;
}

void cGameManager::Input() {
    int player1y = player1->getY();
    int player2y = player2->getY();

    if (_kbhit()) {
        if (ball->getDir() == STOP)
            ball->randomDirection();

        switch (_getch()) {
        case 'w':
            if (player1y - 3 > 0)
                player1->changeDirection(UP);
            break;
        case 's':
            if (player1y + 1 < height)
                player1->changeDirection(DOWN);
            break;
        case 'i':
            if (player2y - 3 > 0)
                player2->changeDirection(UP);
            break;
        case 'j':
            if (player2y + 1 < height)
                player2->changeDirection(DOWN);
            break;
        case 'q':
            quit = true;
            break;
        default:
            break;
        }
    }
}

void cGameManager::Logic() {
    ball->move();
    player1->move();
    player2->move();

    int ballX = ball->getX();
    int ballY = ball->getY();
    int player1x = player1->getX();
    int player1y = player1->getY();
    int player2x = player2->getX();
    int player2y = player2->getY();

    if (ballX == player1x + 1) {
        if (ballY == player1y - 3)
            ball->changeDirection(UPRIGHT);
        else if (ballY == player1y - 2 || ballY == player1y - 1)
            ball->changeDirection((eDirection)(rand() % 3 + 1));
        else if (ballY == player1y)
            ball->changeDirection(DOWNRIGHT);
    }
    else if (ballX == player2x - 1) {
        if (ballY == player2y - 3)
            ball->changeDirection(UPLEFT);
        else if (ballY == player2y - 2 || ballY == player2y - 1)
            ball->changeDirection((eDirection)(rand() % 3 + 4));
        else if (ballY == player2y)
            ball->changeDirection(DOWNLEFT);
    }

    if (ballY == height - 1)
        ball->changeDirection(ball->getDir() == DOWNRIGHT ? UPRIGHT : UPLEFT);
    else if (ballY == 0)
        ball->changeDirection(ball->getDir() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
    else if (ballX == width - 1)
        ScoreUp(player1);
    else if (ballX == 0)
        ScoreUp(player2);

    if (player1y - 4 < 0)
        player1->changeDirection(PAUSE);
    else if (player1y + 2 > height)
        player1->changeDirection(PAUSE);

    if (player2y - 4 < 0)
        player2->changeDirection(PAUSE);
    else if (player2y + 2 > height)
        player2->changeDirection(PAUSE);

    if (score1 == 10)
        quit = true;
    else if (score2 == 10)
        quit = true;
}

void cGameManager::Game() {
    string p1, p2;
    cout << "Player1: ";
    cin >> p1;
    cout << "Player2: ";
    cin >> p2;

    while (!quit) {
        Draw();
        Input();
        Logic();
    }

    if (score1 != score2)
        score1 > score2 ? cout << p1 << " Won" : cout << p2 << " Won";
    else
        cout << "Tie";
}
