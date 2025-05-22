
#include "Game.h"
#include <iostream>
//TODO

// filesystem do sprawdzania czy sa wszystkie tekstury pliki itp i czy zawartosc plikow jest okej np w konstruktorze game,
// wyrzucanie wyjatków jak nie, regexy tez tam
// getline przez wszystkie linijki i regex sprawdzajacy czy sie linijka zgadza albo czy pusta
// gloves dodac w itemach 
// 
//private

void Game::initVariables() { // to chyba bez sensu jesli i tak wszystkie obiekty stron sa tworzone w konstruktorze ,trzeba bedzie potem 
    //wszystko przeniesc do game chyba i dynamicznie tworzyc strony wtedy
    //mozna zrobic wskaznik na page np w Game i go przelaczac i usuwac stare page i podpinac pod ten wskaznik nowe page
    //chyba ze wsm draw dziala tak ze inne sie nie rusyja i handle events tez jest nieaktywne to wsm to wgl nie obciaza
    //awanturniczosc i rzeczy z time musza byc w game
    this->window = nullptr;
    this->player_menu_screen = nullptr;
    this->login_Screen = nullptr;
    this->changePage(GameState::LOGIN_PAGE);
    
}

void Game::initWindow() {
    this->video_mode = sf::VideoMode::getDesktopMode();
    this->window = new sf::RenderWindow(this->video_mode, "Shakes&Fidget 2.0", sf::Style::Fullscreen);
    this->window->setFramerateLimit(60);
}

std::string Game:: formatPlayerLine(Player* p) {
    std::ostringstream oss;
    oss
        << "login: " << p->getName()
        << " pass: " << p->getPassword()
        << " image: " << p->getImgName()
        << " strenght: " << p->getBaseStrenght()
        << " dexterity: " << p->getBaseDexterity()
        << " intelligence: " << p->getBaseIntelligence()
        << " durability: " << p->getBaseConstitution()
        << " luck: " << p->getBaseLuck()
        << " char_class: " << static_cast<int>(p->getCharacterClass())
        << " level: " << p->getLevel()
        << " mount: " << static_cast<int>(p->getMount())
        << " thirst: " << p->getThirst()
        << " gold: " << p->getGold()
        << " mushrooms: " << p->getMushrooms()
        << " hourglasses: " << p->getHourglasses();
    return oss.str();
}

std::string Game::formatEquipmentLine(Player*p) {


    std::ostringstream oss;
    oss << "login: " << p->getName()
        << " helmet: " << (p->getItem("helmet") ? std::to_string(p->getItem("helmet")->getId()) : "000")
        << " shield: " << (p->getItem("shield") ? std::to_string(p->getItem("shield")->getId()) : "000")
        << " trousers: " << (p->getItem("trousers") ? std::to_string(p->getItem("trousers")->getId()) : "000")
        << " shoes: " << (p->getItem("shoes") ? std::to_string(p->getItem("shoes")->getId()) : "000")
        << " weapon: " << (p->getItem("weapon") ? std::to_string(p->getItem("weapon")->getId()) : "000")
        << " necklace: " << (p->getItem("necklace") ? std::to_string(p->getItem("necklace")->getId()) : "000")
        << " belt: " << (p->getItem("belt") ? std::to_string(p->getItem("belt")->getId()) : "000")
        << " ring: " << (p->getItem("ring") ? std::to_string(p->getItem("ring")->getId()) : "000")
        << " luckyitem: " << (p->getItem("luckyitem") ? std::to_string(p->getItem("luckyitem")->getId()) : "000")
        << " slot1: " << (p->getItem("slot1") ? std::to_string(p->getItem("slot1")->getId()) : "000")
        << " slot2: " << (p->getItem("slot2") ? std::to_string(p->getItem("slot2")->getId()) : "000")
        << " slot3: " << (p->getItem("slot3") ? std::to_string(p->getItem("slot3")->getId()) : "000")
        << " slot4: " << (p->getItem("slot4") ? std::to_string(p->getItem("slot4")->getId()) : "000")
        << " slot5: " << (p->getItem("slot5") ? std::to_string(p->getItem("slot5")->getId()) : "000")
        << " slot6: " << (p->getItem("slot6") ? std::to_string(p->getItem("slot6")->getId()) : "000")
        << " slot7: " << (p->getItem("slot7") ? std::to_string(p->getItem("slot7")->getId()) : "000")
        << " slot8: " << (p->getItem("slot8") ? std::to_string(p->getItem("slot8")->getId()) : "000")
        << " shop1: " << (p->getItem("shop1") ? std::to_string(p->getItem("shop1")->getId()) : "000")
        << " shop2: " << (p->getItem("shop2") ? std::to_string(p->getItem("shop2")->getId()) : "000")
        << " shop3: " << (p->getItem("shop3") ? std::to_string(p->getItem("shop3")->getId()) : "000")
        << " shop4: " << (p->getItem("shop4") ? std::to_string(p->getItem("shop4")->getId()) : "000")
        << " shop5: " << (p->getItem("shop5") ? std::to_string(p->getItem("shop5")->getId()) : "000");

    return oss.str();
    //login: player1 helmet: 120 shield: 217 trousers: 328 shoes: 401 weapon: 513 necklace: 000 belt: 000 ring: 
    // 812 luckyitem: 000 slot1: 100 slot2: 0 slot3: 200 slot4: 000 slot5: 600 slot6: 700 slot7: 000 slot8: 900 shop1: 629 shop2: 000 shop3: 729 shop4: 000 shop5: 000
}

void Game::saveToFileStats() {
    const std::string fileName = "accounts.txt";
    std::ifstream in(fileName);
    if (!in.is_open()) {
        // Możesz rzucić wyjątek lub tylko zalogować błąd:
        std::cerr << "Nie można otworzyć pliku do odczytu: " << fileName << "\n";
        return;
    }

    // 1) Wczytaj wszystkie linie do wektora
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(in, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }
    in.close();

    // 2) Przygotuj nową linijkę dla zalogowanego gracza
    std::string newLine = formatPlayerLine(loggedInPlayer);

    // 3) Podmień istniejącą linijkę lub dodaj na końcu
    bool replaced = false;
    std::string prefix = "login: " + loggedInPlayer->getName() + " ";
    for (auto& ln : lines) {
        if (ln.rfind(prefix, 0) == 0) {
            ln = newLine;
            replaced = true;
            break;
        }
    }
    if (!replaced) {
        lines.push_back(newLine);
    }

    // 4) Zapisz wszystkie linie z powrotem, nadpisując plik
    std::ofstream out(fileName, std::ios::trunc);
    if (!out.is_open()) {
        std::cerr << "Nie można otworzyć pliku do zapisu: " << fileName << "\n";
        return;
    }
    for (const auto& ln : lines) {
        out << ln << "\n";
    }
    out.close();

}
void Game::saveToFileEquipment() {
    const std::string fileName = "equipments.txt";

    // 1) Otwórz do odczytu
    std::ifstream in(fileName);
    if (!in.is_open()) {
        std::cerr << "Nie można otworzyć pliku do odczytu: " << fileName << "\n";
        return;
    }

    // 2) Wczytaj wszystkie niepuste linie
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(in, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }
    in.close();

    // 3) Przygotuj nową linijkę dla gracza
    std::string newLine = formatEquipmentLine(loggedInPlayer);

    // 4) Spróbuj podmienić istniejącą, albo dodaj nową
    bool replaced = false;
    const std::string prefix = "login: " + loggedInPlayer->getName() + " ";
    for (auto& ln : lines) {
        if (ln.rfind(prefix, 0) == 0) {
            ln = newLine;
            replaced = true;
            break;
        }
    }
    if (!replaced) {
        lines.push_back(newLine);
    }

    // 5) Zapisz wszystko z powrotem (nadpisując plik)
    std::ofstream out(fileName, std::ios::trunc);
    if (!out.is_open()) {
        std::cerr << "Nie można otworzyć pliku do zapisu: " << fileName << "\n";
        return;
    }
    for (const auto& ln : lines) {
        out << ln << "\n";
    }
    out.close();
}

//public
Game::Game() {
    this->initVariables();
    this->initWindow();
    this->login_Screen = new LoginPage(*this);
    this->player_menu_screen = new PlayerMenu(*this);
    was_account_added = false;
    item_changed_flag = false;
}

Game::~Game() {
    if (loggedInPlayer) {
        saveToFileStats();
        saveToFileEquipment();
    }
    if (login_Screen != nullptr) {
        delete login_Screen;
    }
    if (player_menu_screen != nullptr) {
        delete player_menu_screen;
    }
    delete this->window;
}

sf::Vector2u Game::getWindowSize() const {
    return this->window->getSize();
}

bool Game::running() const {
    return this->window->isOpen();
}

void Game::changePage(GameState new_page) {
    this->page = new_page;
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->event)) {
        if (this->event.type == sf::Event::KeyPressed) {
            if (this->event.key.code == sf::Keyboard::Escape) {
                // Akcja po naciœniêciu klawisza Escape
                this->window->close();  // Na przyk³ad zamkniêcie gry
            }
        }
        

        switch (this->page) { // to cbyba bez sensu
        case GameState::LOGIN_PAGE:
            this->login_Screen->handleEvents(this->event, *this->window);
            break;
        case GameState::PLAYER_MENU:

            //this->tavern_screen->handleEvents(this->event, *this->window);
            this->player_menu_screen->handleEvents(this->event, *this->window); ///to do przeniesienia w inne miejsce potem
            break;
        default:
            break;
        }
    }
}

void Game::update() {
    this->pollEvents();
}

void Game::render() {
    this->window->clear(sf::Color(25, 162, 210, 255));
    switch (this->page) {
    case GameState::LOGIN_PAGE:
        this->login_Screen->draw(*this->window);
        break;
    case GameState::PLAYER_MENU:
        this->player_menu_screen->draw(*this->window);
    default:
        break;
    }

    this->window->display();
}

std::vector<Player*>& Game::getAvailableAccounts(){
    return available_accounts;
}


sf::RenderWindow& Game::getWindow(){
    return *window;
}

void Game::LogOut(){

    if (loggedInPlayer == nullptr) {
        std::cout << "Nie ma zalogowanego gracza!" << std::endl;
        
    }
    else {
        saveToFileStats();
        saveToFileEquipment();
        std::vector<std::string> equipmentSlots = {
            "helmet", "shield", "trousers", "shoes", "weapon", "necklace", "belt", "ring", "luckyitem",
            "slot1", "slot2", "slot3", "slot4", "slot5", "slot6", "slot7", "slot8"
        };

        for (const std::string& slot : equipmentSlots) {

            Item* item = loggedInPlayer->getItem(slot); 
            if (item != nullptr) {

                delete item;
                std::cout << "Usuniêto przedmiot z slotu: " << slot << std::endl;
            }

            // Ustawienie slotu na nullptr
            loggedInPlayer->setItem(slot, nullptr);
        }
    }
    
    setLoggedInPlayer(nullptr);
    changePage(GameState::LOGIN_PAGE);
}

void Game::setLoggedInPlayer(Player* player){
    this->loggedInPlayer = player;
    player_menu_screen->setLoggedInUser(player);


}

Player* Game::getLoggedInPlayer() const{
    return loggedInPlayer;
}

bool Game::getItemChangedFlag()const{
    return item_changed_flag;
}
void Game::setItemChangedFlag(bool changed) {
    item_changed_flag = changed;
}
