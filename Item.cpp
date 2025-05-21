#include "Item.h"

Item::Item(int item_id) : id(0), strength(0), dexterity(0), intelligence(0), constitution(0), luck(0), armor(0),price(100)
, type(ItemType::ANY) {



   
    std::ifstream file("items.txt");
    if (!file.is_open()) {
        std::cerr << "Nie mozna otworzyc pliku items.txt" << std::endl;
        return;
    }

    std::string line;
    // zaktualizowany regex: dodany "type:" po name:
    std::regex pattern(
        "id:\\s*" + std::to_string(item_id) +
        R"(.*?img:\s*([^\s]+)\s+)"           // [1] œcie¿ka obrazka
        R"(name:\s*([^\s]+)\s+)"            // [2] nazwa
        R"(type:\s*([^\s]+)\s+)"            // [3] typ
        R"(strength:\s*(\d+)\s+)"           // [4] strength
        R"(dexterity:\s*(\d+)\s+)"          // [5] dexterity
        R"(intelligence:\s*(\d+)\s+)"       // [6] intelligence
        R"(constitution:\s*(\d+)\s+)"       // [7] constitution
        R"(luck:\s*(\d+)\s+)"               // [8] luck
        R"(armor:\s*(\d+))"                 // [9] armor na koñcu
    );

    std::smatch match;
    bool found = false;

    while (std::getline(file, line)) {
        if (std::regex_search(line, match, pattern)) {
            this->id = item_id;

            // wczytanie tekstury
            std::string imagePath = match[1];
            if (!this->texture.loadFromFile(imagePath)) {
                std::cerr << "Nie udalo sie wczytac textury: " << imagePath << std::endl;
            }
            else {
                this->sprite.setTexture(this->texture);
            }

            // wczytanie nazwy i przypisanie typu
            this->name = match[2];
            std::string typeStr = match[3];
            if (typeStr == "WEAPON")     this->type = ItemType::WEAPON;
            else if (typeStr == "ARMOR")      this->type = ItemType::ARMOR;
            else if (typeStr == "HELMET")     this->type = ItemType::HELMET;
            else if (typeStr == "GLOVES")     this->type = ItemType::GLOVES;
            else if (typeStr == "SHOES")      this->type = ItemType::SHOES;
            else if (typeStr == "RING")       this->type = ItemType::RING;
            else if (typeStr == "NECKLACE")   this->type = ItemType::NECKLACE;
            else if (typeStr == "BELT")       this->type = ItemType::BELT;
            else if (typeStr == "LUCKY_ITEM") this->type = ItemType::LUCKY_ITEM;
            else                                 this->type = ItemType::ANY;

            // wczytanie statystyk
            this->strength = std::stoi(match[4]);
            this->dexterity = std::stoi(match[5]);
            this->intelligence = std::stoi(match[6]);
            this->constitution = std::stoi(match[7]);
            this->luck = std::stoi(match[8]);
            this->armor = std::stoi(match[9]);


            found = true;
            break;
        }
    }
    file.close();

    


    if (!found) {
        std::cerr << "Nie znaleziono itemu o id: " << item_id << std::endl;
    }
}
    /*
    if (!texture.loadFromFile(texturePath)) {
        std::cout << "nie udalo sie wczytac tekstury" << texturePath << std::endl;
    }
    else {
        sprite.setTexture(texture);
    }
    */


/*
Item::Item(int item_id) {
    this->id = item_id;
    std::cout << "stworzono item id: " << item_id << std::endl;
    //tu sie powinien otworzyc plik z itemami i sie powinny statystyki wczytac itp;
    //statystyki mozna jako mnozniki zrobic ze mnoza basic staty ale chyba bez sensu wsm
}
*/

void Item::setPosition(sf::Vector2f pos) {
    sprite.setPosition(pos);
}

sf::FloatRect Item::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}


int Item::getId() const
{
    return this->id;
}

//
ItemType Item::getType() const {
    return type;
}
sf::Texture& Item::getTexture()  //referencje zeby nie operowac na kopii, brak const bo jest to obiekt edytowalny
{
    return texture;
}
int Item::getStrenght() const
{
    return strength;
}
int Item::getDexterity() const
{
    return dexterity;
}
int Item::getIntelligence() const
{
    return intelligence;
}
int Item::getConstitution() const
{
    return constitution;
}
int Item::getLuck() const
{
    return luck;
}
int Item::getArmor() const {
    return armor;
}
std::string Item::getName() const
{
    return name;
}
sf::Sprite& Item::getSprite() 
{
    return sprite;
}

std::vector < std::string>Item::getDescriptionStrings() {
    std::vector < std::string> v;
    if (this->getStrenght() != 0) {
        v.push_back("Strenght: " + std::to_string(this->getStrenght()));
    }
    if (this->getDexterity() != 0) {
        v.push_back("Dexterity: " + std::to_string(this->getDexterity()));
    }
    if (this->getIntelligence() != 0) {
        v.push_back("Intelligence: " + std::to_string(this->getIntelligence()));
    }
    if (this->getConstitution() != 0) {
        v.push_back("Constitution: " + std::to_string(this->getConstitution()));
    }
    if (this->getLuck() != 0) {
        v.push_back("Luck: " + std::to_string(this->getLuck()));
    }
    if (this->getArmor() != 0) {
        v.push_back("Armor: " + std::to_string(this->getArmor()));
    }
    return v;
}

int Item::getPrice()
{
    return price;
}
