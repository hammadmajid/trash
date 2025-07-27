#include <string>

#include "raylib.h"

void drawMenu() {
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    const int startYPos = screenHeight / 6;
    constexpr int fontSize = 32;

    const auto menuTitle = "Trash";
    const int menuTitleWidth = MeasureText(menuTitle, fontSize);
    const int menuTitlePosX = (screenWidth / 2) - (menuTitleWidth / 2);
    DrawText(menuTitle, menuTitlePosX, startYPos, fontSize, LIGHTGRAY);

    const int lineWidth = screenWidth / 4;
    const int lineStartX = (screenWidth - lineWidth) / 2;
    DrawLine(lineStartX, startYPos + 36, lineStartX + lineWidth, startYPos + 36, LIGHTGRAY);

    const char *menuItems[] = {
        "Play", "Scoreboard", "Exit"
    };
    constexpr int menuLength = std::size(menuItems);

    for (int i = 0; i < menuLength; i++) {
        const int textWidth = MeasureText(menuItems[i], fontSize);
        const int textPosX = (screenWidth / 2) - (textWidth / 2);
        DrawText(menuItems[i], textPosX, startYPos + (36 * (i + 1)), fontSize, LIGHTGRAY);
    }
}


int main() {
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(GetScreenWidth(), GetScreenHeight(), "Trash");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGRAY);

        drawMenu();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
