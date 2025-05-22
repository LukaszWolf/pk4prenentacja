﻿
#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Page.h"
#include "Player.h"

class Game {
private:
    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode video_mode;
    sf::Vector2u windowSize;
    GameState page;
    LoginPage* login_Screen;
    PlayerMenu* player_menu_screen;
    std::vector<Player*> available_accounts; // Tablica wskaŸników do dostepnych kont do szybkiego zalogowania
    Player* loggedInPlayer;
    bool was_account_added;
    bool item_changed_flag;

 

    void initVariables();
    void initWindow();
public:
    Game();
    ~Game();
    sf::Vector2u getWindowSize() const;// u to unsigned int
    bool running() const;
    void changePage(GameState new_page);
    void pollEvents();
    void update();
    void render();
    void LogOut();
    void saveToFileStats();
    void saveToFileEquipment();
    std::vector<Player*>& getAvailableAccounts();
    void setLoggedInPlayer(Player* player);
    Player* getLoggedInPlayer() const;
    bool getItemChangedFlag() const;
    void setItemChangedFlag(bool changed);
    sf::RenderWindow& getWindow();
    
    std::string formatPlayerLine(Player* p);
    std::string formatEquipmentLine(Player* p);

};

#endif // GAME_H
