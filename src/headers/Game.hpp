//
// Created by alex on 9/4/26.
//

#ifndef PONG_CPP_GAME_HPP
#define PONG_CPP_GAME_HPP
#include "raylib.h"


class Game {
    Rectangle leftPaddle{};
    Rectangle rightPaddle{};
    Vector2 ballPosition{};
    float ballRadius = 10.0f;
    float paddleSpeed = 500.0f;
    Vector2 ballVelocity{};
    float ballSpeed = 475.0f;

    int leftScore = 0;
    int rightScore = 0;
    static constexpr int winningScore = 5;
    bool gameOver = false;

    void ResetMatch();
    void ResetBall();

public:
    Game();
    void Update();
    void Draw() const;
};


#endif //PONG_CPP_GAME_HPP
