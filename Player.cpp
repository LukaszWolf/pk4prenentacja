#include "Player.h"
#include "Game.h"
#include <cmath> 

Player::Player(std::string nam, std::string img, int str, int dex, int intel, int con, int lck, CharacterClass ch_cl, int lvl,
    Mount mnt, int tht, int gld, int mush, int hglass, Game&game):
Character(nam, img,str,dex,intel,con,lck,ch_cl,lvl),
mount(mnt), thirst_of_adventure(tht),gold(gld), mushrooms(mush), hourglasses(hglass), game_ref(game) {
    initEquipment();
}

Player::~Player() {}

void Player::upgradeStrength()
{
	this->base_strength++;
	int cost = this->level;
	this->setGold(gold-1);
}

void Player::upgradeDexterity()
{
	this->base_dexterity++;
	int cost = this->level;
	this->setGold(gold - 1);
}
void Player::upgradeIntelligence()
{
	this->base_intelligence++;
	int cost = this->level;
	this->setGold(gold - 1);
}
void Player::upgradeConstitution()
{
	this->base_durability++;
	int cost = this->level;
	this->setGold(gold - 1);
}
void Player::upgradeLuck()
{
	this->base_luck++;
	int cost = this->level;
	this->setGold(gold - 1);
	
}

void Player::attack() {
  
}

int Player::calculateHP() {
	return durability*level;
}

int Player::calculateDamage() {
	return strength*level;
}

int Player::calculateEvasion() {
	return dexterity*level;
}

int Player::calculateResistance() {
	return intelligence*level*0.1;
}

int Player::calculateDamageReduction() {
	return std::floor(intelligence*level/50);
}

double Player::calculateCritChance() {
	return std::max(50,(luck*0,05));
}



void Player::initEquipment()
{
    this->equipment  = {
            {"helmet", nullptr},
            {"shield", nullptr},
            {"trousers", nullptr},
            {"shoes", nullptr},
            {"weapon", nullptr},
            {"necklace", nullptr},
            {"belt", nullptr},
            {"ring", nullptr},
            {"luckyitem", nullptr},
            {"slot1", nullptr},
            {"slot2", nullptr},
            {"slot3", nullptr},
            {"slot4", nullptr},
            {"slot5", nullptr},
            {"slot6", nullptr},
            {"slot7", nullptr},
            {"slot8", nullptr},
			{"shop1", nullptr},
			{"shop2", nullptr},
			{"shop3", nullptr},
			{"shop4", nullptr},
			{"shop5", nullptr},

    };
}
Item* Player::getItem(const std::string& slot_name) const {
    auto it = equipment.find(slot_name);
    if (it != equipment.end()) {
        return it->second;
    }
    return nullptr;
}

void Player::setItem(const std::string& slot_name, Item* item) {
    auto it = equipment.find(slot_name);
    if (it != equipment.end()) {
		it->second = item;
    }
	
	if(!game_ref.getItemChangedFlag())
	this->game_ref.setItemChangedFlag(true);
}


void Player::printEquipment() {
    //std::cout << "Ekwipunek gracza:\n";
    //for (const  auto &pair : equipment) {
    //    if (pair.second) {
    //        std::cout << pair.first << " -> Przedmiot ID: "
				//
    //            //<< "id:" << pair.second->getId()
    //            ////<<"texture: "<<this->match[1]
    //            //<< "name:" << pair.second->getName()
    //            //<< "strenght:" << pair.second->getStrenght()
    //            //<< "dext:" << pair.second->getDexterity()
    //            //<< "inte:" << pair.second->getIntelligence()
    //            //<< "constit:" << pair.second->getConstitution()
    //            //<< "luck:" << pair.second->getLuck() << std::endl;
    //   // }
    //    //else {
    //     //   std::cout << pair.first << " -> brak\n";
    //    }
    //}
}


void Player::updateEquipment(std::string filename)
{
	std::ifstream file(filename);
	if (!file) {
		std::cout << "nie udalo sie otworzyc pliku";
		return;
	}
	else {
		std::cout << "otwarto plik " << std::endl;
	}
	std::string line;
	bool found = false;

	std::regex pattern(R"(login:\s*(\w+)\s+helmet:\s*(\d+)\s+shield:\s*(\d+)\s+trousers:\s*(\d+)\s+shoes:\s*(\d+)\s+weapon:\s*(\d+)\s+necklace:\s*(\d+)\s+belt:\s*(\d+)\s+ring:\s*(\d+)\s+luckyitem:\s*(\d+)\s+slot1:\s*(\d+)\s+slot2:\s*(\d+)\s+slot3:\s*(\d+)\s+slot4:\s*(\d+)\s+slot5:\s*(\d+)\s+slot6:\s*(\d+)\s+slot7:\s*(\d+)\s+slot8:\s*(\d+)\s+shop1:\s*(\d+)\s+shop2:\s*(\d+)\s+shop3:\s*(\d+)\s+shop4:\s*(\d+)\s+shop5:\s*(\d+))");

	while (std::getline(file, line) and !found) {
	
		std::smatch match;
		std::cout << std::endl << std::endl << std::endl;
		if (std::regex_match(line, match, pattern)) {
			if ((std::string(match[1]) == this->getName())) {
				found = true;
				Item* helmet = (std::stoi(match[2]) != 0) ? new Item(std::stoi(match[2])) : nullptr;
				Item* shield = (std::stoi(match[3]) != 0) ? new Item(std::stoi(match[3])) : nullptr;
				Item* trousers = (std::stoi(match[4]) != 0) ? new Item(std::stoi(match[4])) : nullptr;
				Item* shoes = (std::stoi(match[5]) != 0) ? new Item(std::stoi(match[5])) : nullptr;
				Item* weapon = (std::stoi(match[6]) != 0) ? new Item(std::stoi(match[6])) : nullptr;
				Item* necklace = (std::stoi(match[7]) != 0) ? new Item(std::stoi(match[7])) : nullptr;
				Item* belt = (std::stoi(match[8]) != 0) ? new Item(std::stoi(match[8])) : nullptr;
				Item* ring = (std::stoi(match[9]) != 0) ? new Item(std::stoi(match[9])) : nullptr;
				Item* luckyitem = (std::stoi(match[10]) != 0) ? new Item(std::stoi(match[10])) : nullptr;

				Item* slot1 = (std::stoi(match[11]) != 0) ? new Item(std::stoi(match[11])) : nullptr;
				Item* slot2 = (std::stoi(match[12]) != 0) ? new Item(std::stoi(match[12])) : nullptr;
				Item* slot3 = (std::stoi(match[13]) != 0) ? new Item(std::stoi(match[13])) : nullptr;
				Item* slot4 = (std::stoi(match[14]) != 0) ? new Item(std::stoi(match[14])) : nullptr;
				Item* slot5 = (std::stoi(match[15]) != 0) ? new Item(std::stoi(match[15])) : nullptr;
				Item* slot6 = (std::stoi(match[16]) != 0) ? new Item(std::stoi(match[16])) : nullptr;
				Item* slot7 = (std::stoi(match[17]) != 0) ? new Item(std::stoi(match[17])) : nullptr;
				Item* slot8 = (std::stoi(match[18]) != 0) ? new Item(std::stoi(match[18])) : nullptr;

				Item* shop1 = (std::stoi(match[19]) != 0) ? new Item(std::stoi(match[19])) : nullptr;
				Item* shop2 = (std::stoi(match[20]) != 0) ? new Item(std::stoi(match[20])) : nullptr;
				Item* shop3 = (std::stoi(match[21]) != 0) ? new Item(std::stoi(match[21])) : nullptr;
				Item* shop4 = (std::stoi(match[22]) != 0) ? new Item(std::stoi(match[22])) : nullptr;
				Item* shop5 = (std::stoi(match[23]) != 0) ? new Item(std::stoi(match[23])) : nullptr;


				this->setItem("helmet", helmet);
				this->setItem("shield", shield);
				this->setItem("trousers", trousers);
				this->setItem("shoes", shoes);
				this->setItem("weapon", weapon);
				this->setItem("necklace", necklace);
				this->setItem("belt", belt);
				this->setItem("ring", ring);
				this->setItem("luckyitem", luckyitem);
				
				this->setItem("slot1", slot1);
				this->setItem("slot2", slot2);
				this->setItem("slot3", slot3);
				this->setItem("slot4", slot4);
				this->setItem("slot5", slot5);
				this->setItem("slot6", slot6);
				this->setItem("slot7", slot7);
				this->setItem("slot8", slot8);

				this->setItem("shop1", shop1);
				this->setItem("shop2", shop2);
				this->setItem("shop3", shop3);
				this->setItem("shop4", shop4);
				this->setItem("shop5", shop5);	
			};

			break; 
		}
		else {
			std::cout << "nie udalo sie wczytac ekwipunku";
		}
	}
}
void Player::printStats()
{
	std::cout << "str: " << getStrength() << ", dex: " << getDexterity() << ", int:" << getIntelligence() << ", con:" << getConstitution() << ", lck:" << getLuck() << std::endl;
}

void Player::setGold(int amount)
{
	std::cout << "[setGold] previous gold: " << this->gold << ", new: " << amount << std::endl;
	this->gold = amount;
	std::cout << "gold: " << gold<<std::endl;
}

int Player::getStrength()
{
	int total = base_strength;
	std::vector<std::string> slots = { "helmet","shield","trousers","shoes","weapon","necklace","belt","ring","luckyitem" };
	for (const auto& slot : slots) {
		auto it = equipment.find(slot);
		if (it != equipment.end() and it->second)
			total += it->second->getStrenght();
	}
	return total;
}

int Player::getDexterity()
{
	int total = base_dexterity;
	std::vector<std::string> slots = { "helmet","shield","trousers","shoes","weapon","necklace","belt","ring","luckyitem" };
	for (const auto& slot : slots) {
		auto it = equipment.find(slot);
		if (it != equipment.end() and it->second)
			total += it->second->getDexterity();
	}
	return total;
}

int Player::getIntelligence()
{
	int total = base_intelligence;
	std::vector<std::string> slots = { "helmet","shield","trousers","shoes","weapon","necklace","belt","ring","luckyitem" };
	for (const auto& slot : slots) {
		auto it = equipment.find(slot);
		if (it != equipment.end() and it->second)
			total += it->second->getIntelligence();
	}
	return total;
}

int Player::getConstitution()
{
	int total = base_durability;
	std::vector<std::string> slots = { "helmet","shield","trousers","shoes","weapon","necklace","belt","ring","luckyitem" };
	for (const auto& slot : slots) {
		auto it = equipment.find(slot);
		if (it != equipment.end() and it->second)
			total += it->second->getConstitution();
	}
	return total;
}

int Player::getLuck()
{
	int total = base_luck;
	std::vector<std::string> slots = { "helmet","shield","trousers","shoes","weapon","necklace","belt","ring","luckyitem" };
	for (const auto& slot : slots) {
		auto it = equipment.find(slot);
		if (it != equipment.end() and it->second)
			total += it->second->getLuck();
	}
	return total;
}

int Player::getArmor() { 
	int total = 0;
	std::vector<std::string> slots = { "helmet","shield","trousers","shoes","weapon","necklace","belt","ring","luckyitem" };
	for (const auto& slot : slots) {
		auto it = equipment.find(slot);
		if (it != equipment.end() and it->second)
			total += it->second->getArmor();
	}
	return total;
}

int Player::getMushrooms()const {
	return mushrooms; 
}
int Player::getHourglasses() const{
	return hourglasses; 
}
int Player::getGold() const{
	return gold;
}
std::string Player::getPassword() const{
	return password;
}
void Player::setPassword(std::string pass){
	password = pass;
}
int Player::getThirst() const{
	return thirst_of_adventure;
}
Mount Player::getMount() const{
	return mount; 
}

