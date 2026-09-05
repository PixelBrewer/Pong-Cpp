#include <raylib.h>
#include "headers/Game.hpp"
#include "headers/Menu.hpp"

int main()
{
    InitWindow(1920, 1080, "Pong");

    SetTargetFPS(60);

    const Menu menu("Pong!", "A simple game of ping pong");
    Game game;
    bool playing = false;

    while (!WindowShouldClose())
    {
        if (!playing && IsKeyPressed(KEY_SPACE)) {
            playing = true;
        }

        if (playing) {
            game.Update();
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        if (playing) {
            game.Draw();
        }
        else {
            menu.Draw();
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
