#include <vector>
#include <string>

#include "raylib.h"

constexpr int FONT_SIZE = 32;
constexpr int MENU_SPACING = 36;

void drawMenuTitle(const std::string &title, const int screenWidth, const int startYPos) {
    const int titleWidth = MeasureText(title.c_str(), FONT_SIZE);
    const int titlePosX = (screenWidth - titleWidth) / 2;
    DrawText(title.c_str(), titlePosX, startYPos, FONT_SIZE, LIGHTGRAY);

    const int lineWidth = screenWidth / 4;
    const int lineStartX = (screenWidth - lineWidth) / 2;
    DrawLine(lineStartX, startYPos + FONT_SIZE + 4, lineStartX + lineWidth, startYPos + FONT_SIZE + 4, LIGHTGRAY);
}

void drawMenuItems(const std::vector<std::string> &items, const int selectedIndex, const int screenWidth,
                   const int startYPos) {
    for (size_t i = 0; i < items.size(); ++i) {
        const int textWidth = MeasureText(items[i].c_str(), FONT_SIZE);
        const int textPosX = (screenWidth - textWidth) / 2;
        const int textPosY = startYPos + MENU_SPACING * (static_cast<int>(i) + 1);

        const Color color = (static_cast<int>(i) == selectedIndex) ? DARKBLUE : LIGHTGRAY;
        DrawText(items[i].c_str(), textPosX, textPosY, FONT_SIZE, color);
    }
}

void drawMenu(const std::vector<std::string> &menuItems, const int selectedIndex) {
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    const int startYPos = screenHeight / 6;
    const std::string menuTitle = "Trash";

    drawMenuTitle(menuTitle, screenWidth, startYPos);
    drawMenuItems(menuItems, selectedIndex, screenWidth, startYPos);
}

int main() {
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(GetScreenWidth(), GetScreenHeight(), "Trash");

    const std::vector<std::string> menuItems{"Play", "Scoreboard", "Exit"};
    int selectedIndex = 0;

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_DOWN)) {
            selectedIndex = (selectedIndex + 1) % static_cast<int>(menuItems.size());
        }
        if (IsKeyPressed(KEY_UP)) {
            selectedIndex = (selectedIndex - 1 + static_cast<int>(menuItems.size())) % static_cast<int>(menuItems.
                                size());
        }

        BeginDrawing();
        ClearBackground(DARKGRAY);
        drawMenu(menuItems, selectedIndex);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
