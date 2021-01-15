#include "inventory.hpp"
#include "character.hpp"

/**
 * Inventory Constructor
 * Add the following item to the inventory
 * Item:
 *  name : "Basic Health Potion"
 *  value: 10
 *  type: POTION
 */

Inventory::Inventory()
{
	length = 0;
	Item i;
	i.name = "Basic Health Potion";
	i.value = 10;
	i.type = POTION;
	AddToInventory(i);
}
/**
 * AddToInventory Function
 * Function that adds items to the inventory
 */ 

void Inventory::AddToInventory(Item i)
{
	items[length] = i;
	length++;
}
/**
 * ShowInventory Function
 * Function that shows all items in the inventory
 * @attention Make sure that you format the output string as follows:
 *  Item - <Item Name> Value: <Item Value>
 */ 

void Inventory::ShowInventory()
{
	for (int i = 0; i < length; i++)
	{
		std::cout << "item - " << items[i].name << "Value: " << items[i].value << std::endl;
	}
}
