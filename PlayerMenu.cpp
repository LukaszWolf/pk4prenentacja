#include "Page.h"
#include "Game.h"
#include <SFML/Graphics.hpp>



PlayerMenu::PlayerMenu(Game& game) : Page(game) {
    //item_changed_flag = false;
    this->loggedInUser = game_ref.getLoggedInPlayer();
    test_counter = 0;
    this->navBar = new NavBar(400, 1080, game);
    this->player_managment_area = new ContentArea(1520, 1080, game, "player_menu_background2.png", 400, 0);

    this->helmet_slot = new ItemSlot("helmet",{ 439, 47 }, {129,129}, ItemType::HELMET, "test.png", []() {}, nullptr);
    this->armor_slot = new ItemSlot("shield",{ 439, 197 }, {129,129}, ItemType::ARMOR, "test.png", []() {}, nullptr);
    this->gloves_slot = new ItemSlot("trousers",{ 439, 348 }, {129,129}, ItemType::GLOVES, "test.png", []() {}, nullptr);
    this->shoes_slot = new ItemSlot("shoes",{ 439, 499 }, {129,129}, ItemType::SHOES, "test.png", []() {}, nullptr);
    this->weapon_slot = new ItemSlot("weapon",{ 721, 500 }, {129,129}, ItemType::WEAPON, "test.png", []() {}, nullptr);
  //  this->weapon_effect_area = new ItemSlot({ 802,484 }, { 126,126 }, ItemType::HELMET, "test.png", []() {}, nullptr);
    this->necklace_slot = new ItemSlot("necklace",{ 1004, 47 }, {129,129}, ItemType::NECKLACE, "test.png", []() {}, nullptr);
    this->belt_slot = new ItemSlot("belt", {1004, 198}, {129,129}, ItemType::BELT, "test.png", []() {}, nullptr);
    this->ring_slot = new ItemSlot("ring",{ 1004, 339 }, {129,129}, ItemType::RING, "test.png", []() {}, nullptr);
    this->lucky_item_slot = new ItemSlot("luckyitem",{ 1004, 500 }, {129,129}, ItemType::LUCKY_ITEM, "test.png", []() {}, nullptr);

    this->bag_slot1 = new ItemSlot("slot1",{ 1251, 34 }, {129,129}, ItemType::ANY, "test.png", []() {}, nullptr);
    this->bag_slot2 = new ItemSlot("slot2", { 1400,34 }, { 129,129 }, ItemType::ANY, "test.png", []() {}, nullptr);
    this->bag_slot3 = new ItemSlot("slot3", { 1545,34 }, { 129,129 }, ItemType::ANY, "test.png", []() {}, nullptr);
    this->bag_slot4 = new ItemSlot("slot4", { 1693,34 }, { 129,129 }, ItemType::ANY, "test.png", []() {}, nullptr);
    this->bag_slot5= new ItemSlot("slot5", { 1251,177 }, { 129,129 }, ItemType::ANY, "test.png", []() {}, nullptr);
    this->bag_slot6 = new ItemSlot("slot6", { 1400,177 }, { 129,129 }, ItemType::ANY, "test.png", []() {}, nullptr);
    this->bag_slot7 = new ItemSlot("slot7", { 1545,177 }, { 129,129 }, ItemType::ANY, "test.png", []() {}, nullptr);
    this->bag_slot8 = new ItemSlot("slot8", { 1693,177 }, { 129,129 }, ItemType::ANY, "test.png", []() {}, nullptr);

    this->shop_slot1 = new ItemSlot("shop1", { 1192, 570 }, { 129,129 }, ItemType::ANY, "test.png", []() {}, nullptr);
    this->shop_slot2 = new ItemSlot("shop2", { 1192, 700 }, { 129,129 }, ItemType::ANY, "test.png", []() {}, nullptr);
    this->shop_slot3 = new ItemSlot("shop3", { 1373, 700 }, { 129,129 }, ItemType::ANY, "test.png", []() {}, nullptr);
    this->shop_slot4 = new ItemSlot("shop4", { 1533, 700 }, { 129,129 }, ItemType::ANY, "test.png", []() {}, nullptr);
    this->shop_slot5 = new ItemSlot("shop5", { 1533, 570 }, { 129,129 }, ItemType::ANY, "test.png", []() {}, nullptr);

    this->upgrade_strenght_btn = new Button({ 720, 703 }, { 0, 0 }, "upgrade_stat_button.png", []() {});
    this->upgrade_dexterity_btn = new Button({ 720, 796 }, { 0, 0 }, "upgrade_stat_button.png", []() {});
    this->upgrade_intelligence_btn = new Button({ 720, 889 }, { 0, 0 }, "upgrade_stat_button.png", []() {});
    this->upgrade_constitution_btn = new Button({ 1042, 703 }, { 0, 0 }, "upgrade_stat_button.png", []() {});
    this->upgrade_luck_btn = new Button({ 1042, 796 }, { 0, 0 }, "upgrade_stat_button.png", []() {});

    this->textfont.loadFromFile("RodrigoTypo - Tobi Pro ExtraBold.otf");
    strength_text = new sf::Text ("0",textfont,20);
    dexterity_text = new sf::Text("0", textfont, 20);
    intelligence_text = new sf::Text("0", textfont, 20);
    constitution_text = new sf::Text("0", textfont, 20);
    luck_text = new sf::Text("0", textfont, 20);
    armor_text = new sf::Text("0", textfont, 20);

    gold_text = new sf::Text("0", textfont, 20);

    strenght_related_text = new sf::Text("0", textfont, 20);
    dexterity_related_text = new sf::Text("0", textfont, 20);
    intelligence_related_text = new sf::Text("0", textfont, 20);
    constitution_related_text = new sf::Text("0", textfont, 20);
    luck_related_text = new sf::Text("0", textfont, 20);
    armor_related_text = new sf::Text("0", textfont, 20);

    strength_text->setPosition({ 675,710 });
    dexterity_text->setPosition({ 675,803 });
    intelligence_text->setPosition({ 675,896 });
    constitution_text->setPosition({ 995,710 });
    luck_text->setPosition({ 995,803 });
    armor_text->setPosition({ 995,896 });

    gold_text->setPosition({ 1700,400 });

    strenght_related_text->setPosition({ 675,735 });
    dexterity_related_text->setPosition({ 675,828 });
    intelligence_related_text->setPosition({ 675,921 });
    constitution_related_text->setPosition({ 995,735 });
    luck_related_text->setPosition({ 995,828 });
    armor_related_text->setPosition({ 995,921});


    strength_text->setFillColor(sf::Color::White);
    dexterity_text->setFillColor(sf::Color::White);
    intelligence_text->setFillColor(sf::Color::White);
    constitution_text->setFillColor(sf::Color::White);
    luck_text->setFillColor(sf::Color::White);
    armor_text->setFillColor(sf::Color::White);

    gold_text->setFillColor(sf::Color::White);

    strenght_related_text->setFillColor(sf::Color::Cyan);
    dexterity_related_text->setFillColor(sf::Color::Cyan);
    intelligence_related_text->setFillColor(sf::Color::Cyan);
    constitution_related_text->setFillColor(sf::Color::Cyan);
    luck_related_text->setFillColor(sf::Color::Cyan);
    armor_related_text->setFillColor(sf::Color::Cyan);
   


    descriptionBox = new DescriptionBox(textfont, 20);  // dobierz rozmiar czcionki
    descriptionBox->setPosition({ 0,0 });                 // opcjonalnie pozycja domyślna
    descriptionBox->setVisible(false);

    

    ////////dodac sloty z plecaka

    allSlots = {
    helmet_slot,
    armor_slot,
    gloves_slot,
    shoes_slot,
    weapon_slot,
    necklace_slot,
    belt_slot,
    ring_slot,
    lucky_item_slot,
    bag_slot1,
    bag_slot2,
    bag_slot3,
    bag_slot4,
    bag_slot5,
    bag_slot6,
    bag_slot7,
    bag_slot8,
    shop_slot1,
    shop_slot2,
    shop_slot3,
    shop_slot4,
    shop_slot5
    };

    updateSlots();
    updateTextStats();
    itemSwapped = false;
}

PlayerMenu::~PlayerMenu() {
    delete this->navBar;
    delete this->player_managment_area;
    delete this->player_image;

    delete this->helmet_slot;
    delete this->armor_slot;
    delete this->gloves_slot;
    delete this->shoes_slot;
    delete this->weapon_slot;
    delete this->necklace_slot;
    delete this->belt_slot;
    delete this->ring_slot;
    delete this->lucky_item_slot;

    delete this->bag_slot1;
    delete this->bag_slot2;
    delete this->bag_slot3;
    delete this->bag_slot4;
    delete this->bag_slot5;
    delete this->bag_slot6;
    delete this->bag_slot7;
    delete this->bag_slot8;


    delete this->upgrade_strenght_btn;
    delete this->upgrade_dexterity_btn;
    delete this->upgrade_intelligence_btn;
    delete this->upgrade_constitution_btn;
    delete this->upgrade_luck_btn;

    delete this->strength_text;
    delete this->dexterity_text;
    delete this->intelligence_text;
    delete this->constitution_text;
    delete this->luck_text;
    delete this->armor_text;

    delete this->strenght_related_text;
    delete this->dexterity_related_text;
    delete this->intelligence_related_text;
    delete this->constitution_related_text;
    delete this->luck_related_text;
    delete this->armor_related_text;

    delete this->descriptionBox;
    delete this->gold_text;
}

void PlayerMenu::draw(sf::RenderWindow& window) {
    if (navBar != nullptr) {
        navBar->draw(window);
    }

    if (player_managment_area != nullptr) {
        player_managment_area->draw(window);
    }
    for (auto slot : allSlots) {
        if (slot) {
            slot->draw(window);
        }
    }

    this->descriptionBox->draw(window);


    if (upgrade_strenght_btn) {
        upgrade_strenght_btn->draw(window);
    }
    if (upgrade_dexterity_btn) {
        upgrade_dexterity_btn->draw(window);
    }
    if (upgrade_intelligence_btn) {
        upgrade_intelligence_btn->draw(window);
    }
    if (upgrade_constitution_btn) {
        upgrade_constitution_btn->draw(window);
    }
    if (upgrade_luck_btn) {
        upgrade_luck_btn->draw(window);
    }

    if (strength_text) {
        window.draw(*strength_text);
    }
    if (dexterity_text) {
        window.draw(*dexterity_text);
    }
    if (intelligence_text) {
        window.draw(*intelligence_text);
    }
    if (constitution_text) {
        window.draw(*constitution_text);
    }
    if (luck_text) {
        window.draw(*luck_text);
    }
    if (armor_text) {
        window.draw(*armor_text);
    }


    if (strenght_related_text) {
        window.draw(*strenght_related_text);
    }
    if (dexterity_related_text) {
        window.draw(*dexterity_related_text);
    }
    if (intelligence_related_text) {
        window.draw(*intelligence_related_text);
    }
    if (constitution_related_text) {
        window.draw(*constitution_related_text);
    }
    if (luck_related_text) {
        window.draw(*luck_related_text);
    }
    if (armor_related_text) {
        window.draw(*armor_related_text);
    }

    if (gold_text) {
        window.draw(*gold_text);
    }


}


void PlayerMenu::handleEvents(sf::Event event, sf::RenderWindow& window) {
    sf::Vector2i mousePixel = sf::Mouse::getPosition(window);

    // 1) NavBar
    if (navBar) navBar->handleEvents(event, window);

    // 2) Rozpoczęcie dragowania
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left)
    {
        for (auto slot : allSlots) {
            slot->tryStartDrag(mousePixel, event);
            if (slot->getIsItemDragged()) {
                dragSource = slot;
                break;
            }
        }
    }

    // 3) Zakończenie dragowania
    if (event.type == sf::Event::MouseButtonReleased &&
        event.mouseButton.button == sf::Mouse::Left &&
        dragSource)
    {
        // pomocnicze
        sf::IntRect shopArea(1200, 370, 720, 710);
        ItemSlot* hoverSlot = nullptr;
        for (auto slot : allSlots) {
            if (slot->isHovered(mousePixel)) {
                hoverSlot = slot;
                break;
            }
        }

        // A) Upuszczenie na SLOT sklepu → SPRZEDAŻ lub BLOKADA
        if (hoverSlot && hoverSlot->getNameID().rfind("shop", 0) == 0) {
            // jeśli źródło też slot sklepu → blokada
            if (dragSource->getNameID().rfind("shop", 0) == 0) {
                std::cout << "[BLOKADA] Nie możesz sprzedać itemu, który już jest w sklepie!\\n";
            }
            else {
                // sprzedaż
                Item* it = dragSource->getCurrentItem();
                if (loggedInUser && it) {
                    int price = it->getPrice();
                    loggedInUser->setGold(loggedInUser->getGold() + price);
                    std::cout << "[SPRZEDAŻ] +" << price << " gold\\n";
                    delete it;
                    dragSource->setItem(nullptr);
                    loggedInUser->setItem(dragSource->getNameID(), nullptr);
                }
            }
            // przywrócenie pozycji
            if (dragSource->getCurrentItem())
                dragSource->getCurrentItem()->setPosition(dragSource->getPosition());
            dragSource->cancelDrag();
            dragSource = nullptr;
            return;
        }

        // B) Upuszczenie na SLOT ekwipunku/plecaka
        if (hoverSlot) {
            // jeśli źródło jest sklep → KUPNO (tylko na pusty slot)
            if (dragSource->getNameID().rfind("shop", 0) == 0) {
                if (hoverSlot->getCurrentItem() == nullptr) {
                    // kupno
                    Item* it = dragSource->getCurrentItem();
                    if (loggedInUser && it) {
                        int price = it->getPrice();
                        loggedInUser->setGold(loggedInUser->getGold() - price);
                        std::cout << "[KUPNO] -" << price << " gold\\n";
                        // przenieś przedmiot
                        hoverSlot->setItem(it);
                        dragSource->setItem(nullptr);
                        loggedInUser->setItem(hoverSlot->getNameID(), it);
                        loggedInUser->setItem("shop" + std::to_string(
                            std::stoi(dragSource->getNameID().substr(4))), nullptr);
                    }
                }
                else {
                    // blokada kupna na zajęty slot
                    std::cout << "[BLOKADA] Nie możesz kupić na zajęty slot!\\n";
                    if (dragSource->getCurrentItem())
                        dragSource->getCurrentItem()->setPosition(dragSource->getPosition());
                }
                dragSource->cancelDrag();
                dragSource = nullptr;
                return;
            }
            // jeśli źródło nie jest sklep → zwykły swap/kupno
            bool swapped = hoverSlot->endDrag(mousePixel, event, dragSource, loggedInUser);
            if (swapped) {
                updateSlots();
                dragSource->cancelDrag();
                game_ref.setItemChangedFlag(true);
            }
            else {
                // przywrócenie
                if (dragSource->getCurrentItem())
                    dragSource->getCurrentItem()->setPosition(dragSource->getPosition());
                dragSource->cancelDrag();
            }
            dragSource = nullptr;
            return;
        }

        // C) Upuszczenie poza sloty, ale w OBSZARZE sklepu → SPRZEDAŻ lub BLOKADA
        if (shopArea.contains(mousePixel)) {
            if (dragSource->getNameID().rfind("shop", 0) == 0) {
                std::cout << "[BLOKADA] Nie możesz sprzedać itemu, który już jest w sklepie!\\n";
            }
            else {
                Item* it = dragSource->getCurrentItem();
                if (loggedInUser && it) {
                    int price = it->getPrice();
                    loggedInUser->setGold(loggedInUser->getGold() + price);
                    std::cout << "[SPRZEDAŻ] +" << price << " gold\\n";
                    delete it;
                    dragSource->setItem(nullptr);
                    loggedInUser->setItem(dragSource->getNameID(), nullptr);
                }
            }
            if (dragSource->getCurrentItem())
                dragSource->getCurrentItem()->setPosition(dragSource->getPosition());
            dragSource->cancelDrag();
            dragSource = nullptr;
            return;
        }

        // D) W każdym innym wypadku → zwróć item na swoje miejsce
        if (dragSource->getCurrentItem())
            dragSource->getCurrentItem()->setPosition(dragSource->getPosition());
        dragSource->cancelDrag();
        dragSource = nullptr;
    }

    // 4) Hover/move events dla slotów
    for (auto slot : allSlots) {
        slot->handleEvents(mousePixel, event);
    }

    // 5) Tooltip
    ItemSlot* hovered = nullptr;
    for (auto slot : allSlots)
        if (slot->isHovered(mousePixel))
            hovered = slot;
    if (hovered && hovered->getCurrentItem()) {
        descriptionBox->setItem(hovered->getCurrentItem());
        auto b = hovered->getGlobalBounds();
        descriptionBox->setPosition({ b.left + b.width + 10.f, b.top });
    }
    else {
        descriptionBox->setItem(nullptr);
    }

    // 6) Upgrade Buttons
    if (upgrade_strenght_btn)      upgrade_strenght_btn->handleEvents(mousePixel, event);
    if (upgrade_dexterity_btn)     upgrade_dexterity_btn->handleEvents(mousePixel, event);
    if (upgrade_intelligence_btn)  upgrade_intelligence_btn->handleEvents(mousePixel, event);
    if (upgrade_constitution_btn)  upgrade_constitution_btn->handleEvents(mousePixel, event);
    if (upgrade_luck_btn)          upgrade_luck_btn->handleEvents(mousePixel, event);

    // 7) Sync z danymi
    if (loggedInUser && game_ref.getItemChangedFlag()) {
        updateSlots();
        updateTextStats();
        game_ref.setItemChangedFlag(false);
    }
}


void PlayerMenu::updateSlots() {
    if (loggedInUser) {
        // synchronizujemy każdy ItemSlot z przedmiotem w ekwipunku gracza
        helmet_slot->setItem(loggedInUser->getItem("helmet"));
        armor_slot->setItem(loggedInUser->getItem("shield"));
        gloves_slot->setItem(loggedInUser->getItem("trousers"));
        shoes_slot->setItem(loggedInUser->getItem("shoes"));
        weapon_slot->setItem(loggedInUser->getItem("weapon"));
        necklace_slot->setItem(loggedInUser->getItem("necklace"));
        belt_slot->setItem(loggedInUser->getItem("belt"));
        ring_slot->setItem(loggedInUser->getItem("ring"));
        lucky_item_slot->setItem(loggedInUser->getItem("luckyitem"));


        // sloty na przedmioty w plecaku
        bag_slot1->setItem(loggedInUser->getItem("slot1"));
        bag_slot2->setItem(loggedInUser->getItem("slot2"));
        bag_slot3->setItem(loggedInUser->getItem("slot3"));
        bag_slot4->setItem(loggedInUser->getItem("slot4"));
        bag_slot5->setItem(loggedInUser->getItem("slot5"));
        bag_slot6->setItem(loggedInUser->getItem("slot6"));
        bag_slot7->setItem(loggedInUser->getItem("slot7"));
        bag_slot8->setItem(loggedInUser->getItem("slot8"));

        shop_slot1->setItem(loggedInUser->getItem("shop1"));
        shop_slot2->setItem(loggedInUser->getItem("shop2"));
        shop_slot3->setItem(loggedInUser->getItem("shop3"));
        shop_slot4->setItem(loggedInUser->getItem("shop4"));
        shop_slot5->setItem(loggedInUser->getItem("shop5"));
    }

    else {
        // jeżeli nie ma zalogowanego gracza, czyścimy wszystkie sloty
        for (auto slot : allSlots) {
            slot->setItem(nullptr);
        }
    }
}

void PlayerMenu::updateTextStats()
{
    if (loggedInUser) {
        gold_text->setString(std::to_string(loggedInUser->getGold()));

    strength_text->setString(std::to_string(loggedInUser->getStrength()));
    dexterity_text->setString(std::to_string(loggedInUser->getDexterity()));
    intelligence_text->setString(std::to_string(loggedInUser->getIntelligence()));
    constitution_text->setString(std::to_string(loggedInUser->getConstitution()));
    luck_text->setString(std::to_string(loggedInUser->getLuck()));
    armor_text->setString(std::to_string(loggedInUser->getArmor()));

    strenght_related_text->setString(std::to_string(loggedInUser->calculateDamage()));
    dexterity_related_text->setString(std::to_string(loggedInUser->calculateEvasion()));
    intelligence_related_text->setString(std::to_string(loggedInUser->calculateDamageReduction()));
    constitution_related_text->setString(std::to_string(loggedInUser->calculateHP()));
    double crit = loggedInUser->calculateCritChance();  // np. 0.123456
    std::ostringstream oss;
    oss << std::fixed        // stała notacja dziesiętna
        << std::setprecision(2)  // 2 cyfry po przecinku
        << crit
        <<"%";
    luck_related_text->setString(oss.str());  // "0.12"
    armor_related_text->setString(std::to_string(loggedInUser->calculateResistance()));
    }



}

void PlayerMenu::setLoggedInUser(Player* player) {
    this->loggedInUser = player;
    updateSlots();
    updateTextStats();
}
