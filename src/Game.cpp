//
// Created by alex on 9/4/26.
//

#include "headers/Game.hpp"
#include<algorithm>
#include <cmath>

Game::Game() {
    const auto width = static_cast<float>(GetScreenWidth());
    const auto height = static_cast<float>(GetScreenHeight());

    leftPaddle = {.x = 40.0f, .y = height / 2.0f - 50.0f, .width = 20.0f, .height = 100.0f};
    rightPaddle = {.x = width - 60.0f, .y = height / 2.0f - 50.0f, .width = 20.0f, .height = 100.0f};

    ResetBall();
}

void Game::Update() {

    if (gameOver) {
        if (IsKeyPressed(KEY_R)) {
            ResetMatch();
        }
        return;
    }

    const auto deltaTime = GetFrameTime();
    const auto movement = paddleSpeed * deltaTime;

    if (IsKeyDown(KEY_W)) {
        leftPaddle.y -= movement;
    }
    if (IsKeyDown(KEY_S)) {
        leftPaddle.y += movement;
    }

    if (IsKeyDown(KEY_UP)) {
        rightPaddle.y -= movement;
    }
    if (IsKeyDown(KEY_DOWN)) {
        rightPaddle.y += movement;
    }

    const auto screenHeight = static_cast<float>(GetScreenHeight());

    leftPaddle.y = std::clamp(leftPaddle.y, 0.0f, screenHeight - leftPaddle.height);
    rightPaddle.y = std::clamp(rightPaddle.y, 0.0f, screenHeight - rightPaddle.height);

    ballPosition.x += ballVelocity.x * deltaTime;
    ballPosition.y += ballVelocity.y * deltaTime;

    if (ballPosition.y - ballRadius <= 0.0f && ballVelocity.y < 0.0f) {
        ballPosition.y = ballRadius;
        ballVelocity.y = -ballVelocity.y;
    }

    if (ballPosition.y + ballRadius >= screenHeight && ballVelocity.y > 0.0f) {
        ballPosition.y = screenHeight - ballRadius;
        ballVelocity.y = -ballVelocity.y;
    }

    if (ballVelocity.x < 0.0f && CheckCollisionCircleRec(ballPosition, ballRadius, leftPaddle)) {
        ballPosition.x = leftPaddle.x + leftPaddle.width + ballRadius;
        ballVelocity.x = -ballVelocity.x;
    }

    if (ballVelocity.x > 0.0f && CheckCollisionCircleRec(ballPosition, ballRadius, rightPaddle)) {
        ballPosition.x = rightPaddle.x - ballRadius;
        ballVelocity.x = -ballVelocity.x;
    }

    const float screenWidth = static_cast<float>(GetScreenWidth());

    if (ballPosition.x + ballRadius < 0.0f) {
        ++rightScore;
    }
    else if (ballPosition.x - ballRadius > screenWidth) {
        ++leftScore;
    }
    else {
        return; // No point scored this frame.
    }

    gameOver = leftScore >= winningScore || rightScore >= winningScore;

    if (!gameOver) {
        ResetBall();
    }
}

void Game::Draw() const {
    DrawRectangleRec(leftPaddle, DARKGRAY);
    DrawRectangleRec(rightPaddle, DARKGRAY);

    if (!gameOver) {
        DrawCircleV(ballPosition, ballRadius, RED);
    }

    const auto screenWidth = GetScreenWidth();
    const auto screenHeight = GetScreenHeight();

    const int centerX = screenWidth / 2.0f;
    const int centerY = screenHeight / 2.0f;

    const char* scoreText = TextFormat("%d     %d", leftScore, rightScore);

    DrawText(
    scoreText,
    centerX - MeasureText(scoreText, 48) / 2,
    30,
    48,
    DARKGRAY
);

    if (gameOver) {
        const char* winnerText = leftScore >= winningScore
            ? "Left player wins!"
            : "Right player wins!";

        constexpr auto restartText = "Press R to play again";

        DrawText(
            winnerText,
            centerX - MeasureText(winnerText, 40) / 2,
            centerY - 40,
            40,
            DARKGRAY
        );

        DrawText(
            restartText,
            centerX - MeasureText(restartText, 24) / 2,
            centerY + 20,
            24,
            DARKGRAY
        );
    }
}

void Game::ResetBall() {
    ballPosition = {
        .x = static_cast<float>(GetScreenWidth()) / 2.0f,
        .y = static_cast<float>(GetScreenHeight()) / 2.0f,
    };
    const auto angle = static_cast<float>(GetRandomValue(20, 50)) * DEG2RAD;

    const auto directionX = GetRandomValue(0,1) == 0 ? -1.0f : 1.0f;
    const auto directionY = GetRandomValue(0,1) == 0 ? -1.0f : 1.0f;
    ballVelocity = {
        .x = std::cos(angle) * ballSpeed * directionX,
        .y = std::sin(angle) * ballSpeed * directionY,
    };
}

void Game::ResetMatch() {
    leftScore = 0;
    rightScore = 0;
    gameOver = false;

    const auto screenHeight = static_cast<float>(GetScreenHeight());

    leftPaddle.y = (screenHeight - leftPaddle.height) / 2.0f;
    rightPaddle.y = (screenHeight - rightPaddle.height) / 2.0f;

    ResetBall();
}
