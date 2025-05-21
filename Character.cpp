#include "Character.h"
#include <sstream>
#include <stdexcept>

Character::Character(std::string nam, std::string img, int str, int dex, int intel, int con,
    int luck, CharacterClass ch_cl, int level): name(nam), img_file_name(img), base_strength(str),
    base_dexterity(dex), base_intelligence(intel), base_constitution(con) {

}



// Implementacje getterów
std::string Character::getImgName() const { return img_file_name; }
std::string Character::getName() const { return name; }
int Character::getLevel() const { return level; }
//int Character::getStrength() const { return base_strength; }
//int Character::getDexterity() const { return base_dexterity; }
//int Character::getIntelligence() const { return base_intelligence; }
//int Character::getConstitution() const { return base_constitution; }
//int Character::getLuck() const { return base_luck; }*/
CharacterClass Character::getCharacterClass() const { return ch_class; }