/**
 * warrior.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "warrior.hpp"

/**
 * Warrior Class constructor
 * @param characterName The name of the character being created
 * @param characterRace The race of the character being created. This is a enum value.
 * @extends This constructor extends the base Character constructor
 * @attention Follow these instructions:
 *  Warrior starts with 150 health
 *  Assign the starter weapon for the Warrior
 *      Weapon
 *         name : "Starter Longsword"
 *         cost : 100
 *         damage : 10
 *  Add the weapon to the Warriors inventory
 *  Assign a value of 10 for the base Warrior characteristic
 */
Warrior::Warrior(string characterName, Race characterRace):Character(characterName, characterRace), Inventory()
{
	Weapon w;
	w.name = "Starter Longsword";
	w.damage = 10;
	w.cost = 100;
	SetWeapon (w);
	SetHealth(150);
	SetJob("Warrior");
	Item i;
	i.name = w.name;
	i.value = w.cost;
	i.type = WEAPON;
	strength = 10;
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
void Warrior::Attack(Character * target)
{
    int damage = this->GetWeapon().damage + strength/2;
    std::cout << this->GetName() << " attacks " << target->GetName() << " with " << this->GetWeapon().name << " for " << damage << " points\n";
    target->TakeDamage(damage);
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
void Warrior::PowerAttack(Character* target)
{
    int PowerAttk = ((GetHealth())/100)*(this->GetWeapon().damage + strength/2);
    std::cout << this->GetName() << " attacks " << target->GetName() << " with a Power Attack for " << PowerAttk << " points\n";
    target->TakeDamage(PowerAttk);
}

/**
 * Public method Status that prints out the Status of the Cleric
 * @attention You MUST print out the local Cleric variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */

void Warrior::Status()
{
	Character::Status();
	std::cout << "Strength: " << strength << std::endl;
}
