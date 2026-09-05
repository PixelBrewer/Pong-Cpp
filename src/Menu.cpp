//
// Created by alex on 9/4/26.
//

#include "headers/Menu.hpp"
#include "raylib.h"

Menu::Menu(const std::string &title, const std::string &subtitle) : title(title), subtitle(subtitle) {}

void Menu::Draw() const {
    const int centerX = GetScreenWidth() / 2;
    const int centerY = GetScreenHeight() / 2;

    DrawText(
        title.c_str(),
        centerX - MeasureText(title.c_str(), 48) / 2,
        centerY - 100,
        48,
        DARKGRAY
        );

    DrawText(
        subtitle.c_str(),
        centerX - MeasureText(subtitle.c_str(), 24) / 2,
        centerY - 30,
        24,
        DARKGRAY
        );

    constexpr auto playText = "Press Space to Play";
    constexpr auto quitText = "Press Escape to Quit";

    DrawText(
        playText,
        centerX - MeasureText(playText, 24) / 2,
        centerY + 30,
        24,
        DARKGRAY
        );

    DrawText(
        quitText,
        centerX - MeasureText(quitText, 24) / 2,
        centerY + 70,
        24,
        DARKGRAY
        );
}
