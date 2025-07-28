#include "menu.h"

#include "raylib.h"

constexpr int FONT_SIZE = 32;
constexpr int MENU_SPACING = 36;

Menu::Menu() : selectedIndex(0), actionSelected(false) {
    menuItems = {"Play", "Scoreboard", "Exit"};
}

void Menu::draw() const {
    ClearBackground(DARKGRAY);

    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    const int startYPos = screenHeight / 6;
    const std::string menuTitle = "Trash";

    drawTitle(menuTitle, screenWidth, startYPos);
    drawItems(screenWidth, startYPos);
}

void Menu::handleInput() {
    if (IsKeyPressed(KEY_ENTER)) {
        actionSelected = true;
        return;
    }

    if (IsKeyPressed(KEY_DOWN)) {
        selectedIndex = (selectedIndex + 1) % static_cast<int>(menuItems.size());
    }

    if (IsKeyPressed(KEY_UP)) {
        selectedIndex = (selectedIndex - 1 + static_cast<int>(menuItems.size())) % static_cast<int>(menuItems.size());
    }
}

GameState Menu::getSelectedAction() const {
    switch (selectedIndex) {
        case 0: return Play;
        case 1: return Scoreboard;
        case 2: return Exit;
        default: return GameState::Options;
    }
}

bool Menu::isActionSelected() const {
    return actionSelected;
}

void Menu::resetActionSelected() {
    actionSelected = false;
}

void Menu::drawTitle(const std::string &title, int screenWidth, int startYPos) const {
    const int titleWidth = MeasureText(title.c_str(), FONT_SIZE);
    const int titlePosX = (screenWidth - titleWidth) / 2;
    DrawText(title.c_str(), titlePosX, startYPos, FONT_SIZE, LIGHTGRAY);

    const int lineWidth = screenWidth / 4;
    const int lineStartX = (screenWidth - lineWidth) / 2;
    DrawLine(lineStartX, startYPos + FONT_SIZE + 4, lineStartX + lineWidth, startYPos + FONT_SIZE + 4, LIGHTGRAY);
}

void Menu::drawItems(int screenWidth, int startYPos) const {
    for (size_t i = 0; i < menuItems.size(); ++i) {
        const int textWidth = MeasureText(menuItems[i].c_str(), FONT_SIZE);
        const int textPosX = (screenWidth - textWidth) / 2;
        const int textPosY = startYPos + MENU_SPACING * (static_cast<int>(i) + 1);

        const Color color = (static_cast<int>(i) == selectedIndex) ? DARKBLUE : LIGHTGRAY;
        DrawText(menuItems[i].c_str(), textPosX, textPosY, FONT_SIZE, color);
    }
}
