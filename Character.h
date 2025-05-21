#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Button.h"

enum class CharacterClass {
    WARRIOR,
    MAGE,
    SCOUT
};

class Character {
protected:
    std::string name;
    std::string img_file_name;
    int hp, damage, evasion, resistance, damage_reduction;
    double crit_chance;
    int level;
    int base_strength, base_dexterity, base_intelligence, base_constitution, base_luck;
    CharacterClass ch_class;

public:


    // Konstruktor (mo�e istnie� w klasie abstrakcyjnej)
    Character(std::string nam, std::string img, int strength, int dexterity, int intelligence, int constitution,
        int luck, CharacterClass ch_cl, int level);
    virtual ~Character() = default; // Abstrakcyjna klasa musi mie� wirtualny destruktor

    // Czyste funkcje wirtualne (klasa abstrakcyjna)
    virtual void attack() = 0;
    virtual int calculateHP() = 0;
    virtual int calculateDamage() = 0;
    virtual int calculateEvasion() = 0;
    virtual int calculateResistance() = 0;
    virtual int calculateDamageReduction() = 0;
    virtual double calculateCritChance() = 0;


    // Gettery dla atrybut�w postaci
    std::string getImgName() const;
    std::string getName() const;
    int getLevel() const;
    virtual int getStrength() = 0;
    virtual int getDexterity() = 0;
    virtual int getIntelligence() = 0;
    virtual int getConstitution() = 0;
    virtual int getLuck() = 0;
    virtual int getArmor() = 0;
    CharacterClass getCharacterClass() const;

};



#endif