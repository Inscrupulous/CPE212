/**
 * goblin.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "goblin.hpp"

/**
 * Goblin Class constructor
 * @param characterName The name of the character being created
 * @param characterRace The race of the character being created. This is a enum value.
 * @extends This constructor extends the base Character constructor
 * @attention Follow these instructions:
 *  Goblin starts with 30 health
 *  Assign the starter weapon for the Goblin
 *      Weapon
 *         name : "Pointy Stick"
 *         cost : 1
 *         damage : 3
 *  Add the weapon to the Goblins inventory
 *  Assign a value of 2 for the base Goblin characteristic
 */
Goblin::Goblin(string characterName, Race characterRace):Character(characterName, characterRace), Inventory()
{
	Weapon w;
	w.name = "Pointy Stick";
	w.damage = 3;
	w.cost = 1;
	SetWeapon (w);
	SetHealth(30);
	SetJob("Goblin");
	Item i;
	i.name = w.name;
	i.value = w.cost;
	i.type = WEAPON;
	attack = 2;
	Inventory::AddToInventory(i);
}

/**
 * Public method of Mage that attacks an enemy Character
 * @param enemy Pointer to the enemy Character
 * @attention Follow these instructions:
 *  1. The damage for a Mage is calculated by the weapon damage + half the intelligence value
 *  2. The enemy Character must take the damage dealt by the Mage
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Enemy Name> with <Character's Weapon Name> for <damage> points
 */
void Goblin::Attack(Character * enemy)
{
    int damage = this->GetWeapon().damage + (attack/2);
    int enemy_health = enemy->GetHealth();
    std::cout << this->GetName() << " attacks " << enemy->GetName() << " with " << this->GetWeapon().name << " for " << damage << " points\n";
    enemy->TakeDamage(damage);
}
/**
 * Public method of Mage that sends a Fireball at an enemy Character
 * @param enemy Pointer to the enemy Character
 * @attention Follow these instructions:
 *  1. The damage for a Fireball is calculated by the base damage 10 + weapon damage + half the intelligence value
 *  2. The enemy Character must take the damage dealt by the Mage
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Enemy Name> with a Fireball for <damage> points
 */
void Goblin::SneakAttack(Character* enemy)
{
    int SneakAttk = 20 + (attack/2) + this->GetWeapon().damage;
    int enemy_health = enemy->GetHealth();
    std::cout << this->GetName() << " Sneak Attacks " << enemy->GetName() << " for " << SneakAttk << " points\n";
    enemy->TakeDamage(SneakAttk);
}

/**
 * Public method Status that prints out the Status of the Cleric
 * @attention You MUST print out the local Cleric variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */

void Goblin::Status()
{
	Character::Status();
	std::cout << "Attack: " << attack << std::endl;
}
