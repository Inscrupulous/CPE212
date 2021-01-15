/**
 * mage.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "mage.hpp"

/**
 * Mage Class constructor
 * @param characterName The name of the character being created
 * @param characterRace The race of the character being created. This is a enum value.
 * @extends This constructor extends the base Character constructor
 * @attention Follow these instructions:
 *  Mage starts with 50 health
 *  Assign the starter weapon for the Cleric
 *      Weapon
 *         name : "Simple Staff"
 *         cost : 100
 *         damage : 5
 *  Add the weapon to the Mage inventory
 *  Assign a value of 10 for the base Mage characteristic
 */
Mage::Mage(string characterName, Race characterRace):Character(characterName, characterRace), Inventory()
{
	Weapon w;
	w.name = "Simple Staff";
	w.damage = 5;
	w.cost = 100;
	SetWeapon (w);
	SetHealth(50);
	SetJob("Mage");
	Item i;
	i.name = w.name;
	i.value = w.cost;
	i.type = WEAPON;
	intelligence = 10;
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
void Mage::Attack(Character * enemy)
{
    int damage = this->GetWeapon().damage + (intelligence/2);
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
void Mage::Fireball(Character* enemy)
{
    int fireball_damage = 10 + this->GetWeapon().damage + (intelligence/2);
    int enemy_health = enemy->GetHealth();
    std::cout << this->GetName() << " attacks " << enemy->GetName() << " with a Fireball for " << fireball_damage << " points\n";
    enemy->TakeDamage(fireball_damage);
}

/**
 * Public method Status that prints out the Status of the Cleric
 * @attention You MUST print out the local Cleric variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */

void Mage::Status()
{
	Character::Status();
	std::cout << "Intelligence: " << intelligence << std::endl;
}
