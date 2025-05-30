﻿#include "Page.h"
#include "Game.h"
#include <regex>
#include <iostream>

LoginPage::LoginPage(Game& game) : Page(game) {

    this->content_box = new ContentArea(1920, 1080, game, "wybor_postaci.png", 0, 0);
    this->username_text_box = new TextBox(1370, 320, 354, 90, "Enter nickname");
    this->password_text_box = new TextBox(1370, 450, 354, 90, "Enter password");
    this->login_button = new Button("LOGIN", { 1390, 580 }, { 314, 80 }, "login_button.png");
}

LoginPage::~LoginPage() {
    delete this->content_box;
    delete this->username_text_box;
    delete this->password_text_box;
    delete this->login_button;

    for (auto btn : account_btns) {
        if (btn != nullptr) delete btn;
    }
    
}

void LoginPage::draw(sf::RenderWindow& window) {
    if (this->content_box != nullptr)
        this->content_box->draw(window);

    if (this->username_text_box != nullptr)
        this->username_text_box->draw(window);

    if (this->password_text_box != nullptr)
        this->password_text_box->draw(window);

    if (this->login_button != nullptr)
        this->login_button->draw(window);

    for (const auto& player : insertion_order) {
        userToButtonMap[player]->draw(window);
    }
}

void LoginPage::handleEvents(sf::Event event, sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    if (this->content_box != nullptr)
        this->content_box->handleEvents(event, window);

    for (const auto& pair : userToButtonMap) {
        pair.second->handleEvents(mousePos, event);
        if (pair.second->isClicked(mousePos, event)) {
            LogIn(pair.first);
            std::cout << pair.first->getName();
            break;
        }
    }

    if (this->login_button->isClicked(mousePos, event)) {
        std::string login = this->username_text_box->getText();
        std::string pass = this->password_text_box->getText();
        std::string line = userExistLine(login, "accounts.txt");

        if (isValidLogin(login) and isPasswordMatched(pass, line)) {
            addAccountToAvailable(line, pass);
            username_text_box->clearText();
            password_text_box->clearText();
        }

    }

    if (this->username_text_box != nullptr)
        this->username_text_box->handleEvent(event);
    if (this->password_text_box != nullptr)
        this->password_text_box->handleEvent(event);

    login_button->handleEvents(mousePos, event);

}

std::string LoginPage::userExistLine(std::string nam, std::string file_name) {
    std::ifstream file(file_name);
    if (!file) {
        std::cout << "Nie mozna otworzyc pliku: " << file_name << std::endl;
        return "";
    }
    std::string line;
    std::string to_find = "login: " + nam;
    while (std::getline(file, line)) {
        if (line.find(to_find) != std::string::npos) {
            return line;
        }
    }
    return "";
}

bool LoginPage::isValidLogin(std::string login) {
    if (login.empty()) return false;
    for (char c : login) {
        if (!isalnum(c)) return false;
    }
    return true;
}

bool LoginPage::isValidPassword(std::string password) {
    return true;
}

bool LoginPage::isPasswordMatched(std::string password, std::string line) {
    std::string to_find = "pass: " + password;
    bool matched= isValidPassword(password) && line.find(to_find) != std::string::npos;
    if (matched) {
      
        return true;
    }
      return false;

}

void LoginPage::addAccountToAvailable(std::string stats, std::string password) {
    std::regex pattern(R"(login:\s*(\w+)\s+pass:\s*(\w+)\s+image:\s*(\S+)\s+strenght:\s*(\d+)\s+dexterity:\s*(\d+)\s+intelligence:\s*(\d+)\s+durability:\s*(\d+)\s+luck:\s*(\d+)\s+char_class:\s*(\d+)\s+level:\s*(\d+)\s+mount:\s*(\d+)\s+thirst:\s*(\d+)\s+gold:\s*(\d+)\s+mushrooms:\s*(\d+)\s+hourglasses:\s*(\d+))");
    std::smatch matches;

    if (!std::regex_search(stats, matches, pattern)) return;

    std::string login = matches[1];
    std::string image = matches[3];
    int str = std::stoi(matches[4]);
    int dex = std::stoi(matches[5]);
    int intel = std::stoi(matches[6]);
    int con = std::stoi(matches[7]);
    int luck = std::stoi(matches[8]);
    CharacterClass char_class = static_cast<CharacterClass>(std::stoi(matches[9]));
    int level = std::stoi(matches[10]);
    Mount mount = static_cast<Mount>(std::stoi(matches[11]));
    int thirst = std::stoi(matches[12]);
    int gold = std::stoi(matches[13]);
    int mushrooms = std::stoi(matches[14]);
    int hourglasses = std::stoi(matches[15]);

    Player* new_player = new Player(login, image, str, dex, intel, con, luck, char_class,
        level, mount, thirst, gold, mushrooms, hourglasses,game_ref);
    new_player->setPassword(password);
    insertion_order.push_front(new_player);

    
    if (insertion_order.size() > MAX_PLAYERS) {
        // znajdź ostatniego
        auto it = insertion_order.end();
        --it;
        Player* oldest = *it;
        // usuń go z listy
        insertion_order.erase(it);
        // usuń przycisk
        userToButtonMap.erase(oldest);
        // zwolnij pamięć po Playerze, jeśli to konieczne
        delete oldest;
    }

    // teraz ustaw pozycje przycisków dla do 6 graczy:
    float basePosX = 250;
    float spacingX = 270;
    float basePosY = 280;
    float spacingY = 250;
    int i = 0;
    for (const auto& player : insertion_order) {
        int y = i / 3;
        int x = i % 3;
        sf::Vector2f pos{ basePosX + x * spacingX, basePosY + y * spacingY };

        if (userToButtonMap.find(player) == userToButtonMap.end()) {
            // tworzymy nowy przycisk
            userToButtonMap[player] = std::make_unique<Button>(login, pos, sf::Vector2f{ 160,160 }, image);
        }
        else {
            // tylko przesunięcie istniejącego
            userToButtonMap[player]->setPosition(pos);
        }
        ++i;
    }
}

void LoginPage::updateEquipment(std::string filename, Player* player) {
    player->updateEquipment(filename);
}

void LoginPage::LogIn(Player* player) {
    game_ref.setLoggedInPlayer(player);

    game_ref.changePage(GameState::PLAYER_MENU);
   
    player->updateEquipment("equipments.txt");
}
