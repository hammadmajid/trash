#pragma once

#include <vector>
#include <string>

enum GameState {
    Play,
    Scoreboard,
    Exit,
    Options,
};

class Menu {
public:
    Menu();
    
    void draw() const;
    void handleInput();
    [[nodiscard]] GameState getSelectedAction() const;
    [[nodiscard]] bool isActionSelected() const;
    void resetActionSelected();

private:
    std::vector<std::string> menuItems;
    int selectedIndex;
    bool actionSelected;
    
    void drawTitle(const std::string& title, int screenWidth, int startYPos) const;
    void drawItems(int screenWidth, int startYPos) const;
};