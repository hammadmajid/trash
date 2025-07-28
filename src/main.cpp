#include "raylib.h"

#include "menu.h"

int main() {
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(GetScreenWidth(), GetScreenHeight(), "Trash");

    GameState state = Options;
    Menu menu;

    while (!WindowShouldClose() && state != Exit) {
        if (state == Options) {
            menu.handleInput();

            if (menu.isActionSelected()) {
                state = menu.getSelectedAction();
                menu.resetActionSelected();
            }
        }

        BeginDrawing();
        switch (state) {
            case Options:
                menu.draw();
                break;
            case Play:
                ClearBackground(DARKGRAY);
                break;
            case Scoreboard:
                ClearBackground(DARKGRAY);
                break;
            default:
                continue;
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
