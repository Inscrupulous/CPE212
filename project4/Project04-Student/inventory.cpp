#include "inventory.hpp"

void Inventory::Add(const Item &i)
{
    /**
     * Add the item to the inventory
     */
	contents.AddItemSorted(i);
	length++;
}

bool Inventory::Remove(const Item &i)
{
    /**
     * Delete the item from the inventory
     */
	contents.DeleteItem(i);
	length--;
}

bool Inventory::isEmpty() const
{
    /**
     * Return if the inventory is empty
     */
	if (contents.Count() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Inventory::isFull() const
{
    /**
     * Return if the inventory is full
     */
	if (contents.AtEnd())
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Inventory::ShowInventory() const
{
    PrintHeader();  // Leave this here
	contents.ResetIterator();
	while (!contents.AtEnd())
	{
		PrintItem(contents.IterateItems());
	}

    PrintFooter();  // Leave this here
}

Item Inventory::PopFront() {
    /**
     * Pop the first item off of the inventory and return it back to the caller
     */
	return (contents.PopFront());
}

/**
 * DO NOT MODIFY
 * @param i {Item*}
 */
void Inventory::PrintItem(Item *i) const
{
    if(i == nullptr)
    {
        std::cout << "ITEM IS NULL" << std::endl;
        return;
    }
    // Formatting the output into a table
    std::cout << std::left
              << std::setw(10)
              << i->GetType();
    std::cout
              << std::setw(35)
              << i->GetName();
    std::cout
              << std::setw(7)
              << i->GetValue()
              << std::endl;
}
