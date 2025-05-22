#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <iostream>
#include <vector>
enum class Mount {
	COW,
	HORSE,
	TIGER,
	DRAGON,
	NONE
};

class Game;
class Player : public Character
{
	std:: string password;
	Mount mount;
	int thirst_of_adventure;
	int gold;
	int mushrooms, hourglasses;
	int armor, strength, dexterity, intelligence, durability, luck;
	bool stat_changed;	
	std::map<std::string, Item*> equipment;
	Game& game_ref;
public:
	Player();
	Player(std::string nam, std::string img, int strength, int dexterity, int intelligence, int durability,int luck, CharacterClass ch_cl, int level,
		Mount mount, int thirst, int gold, int mush, int hglass, Game&game); 
	~Player();

	void upgradeStrength();
	void upgradeDexterity();
	void upgradeIntelligence();
	void upgradeConstitution();
	void upgradeLuck();

	void initEquipment();

	void attack() override final ;
	int calculateHP() override final;
	int calculateDamage() override final;
	int calculateEvasion() override final;
	int calculateResistance() override final;
	int calculateDamageReduction() override final;
	double calculateCritChance() override final;

	virtual int getStrength() override final;
	virtual int getDexterity() override final;
	virtual int getIntelligence()override final;
	virtual int getConstitution() override final;
	virtual int getLuck() override final;
	virtual int getArmor() override final;

	void printEquipment();
	void printStats();
	Item* getItem(const std::string& slot_name) const;
	void setItem(const std::string& slot_name, Item* item);
	int getMushrooms() const;
	int getHourglasses() const;
	int getGold() const;
	std::string getPassword() const;
	void setPassword(std::string pass);
	void setGold(int amount);
	int getThirst() const;
	Mount getMount() const;
	void updateEquipment(std::string filename);
};

#endif