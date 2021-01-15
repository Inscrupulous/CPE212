/**
 * cleric.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "cleric.hpp"

/**
 * Cleric Class constructor
 * @param characterName The name of the character being created
 * @param characterRace The race of the character being created. This is a enum value.
 * @extends This constructor extends the base Character constructor
 * @attention Follow these instructions:
 *  Cleric starts with 50 health
 *  Assign the starter weapon for the Cleric
 *      Weapon
 *         name : "Simple Wand"
 *         cost : 100
 *         damage : 5
 *  Add the weapon to the Clerics inventory
 *  Assign a value of 10 for the base Cleric characteristic
 */
Cleric::Cleric(string characterName, Race characterRace):Character(characterName, characterRace), Inventory()
{
	Weapon w;
	w.name = "Simple Wand";
	w.damage = 5;
	w.cost = 100;
	SetWeapon (w);
	SetHealth(50);
	SetJob("Cleric");
	Item i;
	i.name = w.name;
	i.value = w.cost;
	i.type = WEAPON;
	Inventory::AddToInventory(i);
	willpower = 10;
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
void Cleric::Attack(Character * enemy)
{
    int damage = this->GetWeapon().damage + (willpower/2);
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
void Cleric::Heal(Character* target)
{
	int heal = 10 + (willpower/2);
	int target_heal = target->GetHealth();
	std::cout << this->GetName() << " heals " << target->GetName()  << " for " << heal << " points\n";
	target_heal += heal;
	target->SetHealth(target_heal);
}
/**
 * Public method Status that prints out the Status of the Cleric
 * @attention You MUST print out the local Cleric variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */

void Cleric::Status()
{
	Character::Status();
	std::cout << "Willpower: " << willpower << std::endl;
}
