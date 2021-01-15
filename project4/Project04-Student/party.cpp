#include "party.hpp"

Party::Party(const std::string & n) 
{
    name = n;
}

Party::Party()
{
    name = "Lazy Party";
}

std::string Party::GetName() const
{
    /**
     * Returns the parties name
     */
	return name;
}

void Party::AddMember(Character *c)
{
    /**
     * Add a member to this party. Make sure it is in order
     */
	members.AddItemSorted(c);
	size++;
}

bool Party::RemoveMember(Character *c)
{
    /**
     * Remove a character from the party
     */
	members.DeleteItem(c);
	size--;
}


void Party::ShowParty() const
{
    PrintHeader(); // Leave this here
	members.ResetIterator();
	while (!members.AtEnd())
	{
		PrintMemberData(*members.IterateItems());
	}
    PrintFooter(); // Leave this here
}

Character* Party::FindMember(int id)
{
    /**
     * Return the Character in the party that has the id that is being passed into this function.
     * Return NULL if one isn't found
     */
    members.ResetIterator();
    while (!members.AtEnd())
    {
        Character *FindCharacter = *members.IterateItems();
        int pointerID = FindCharacter -> GetUid();
        if (id == pointerID)
        {
            return FindCharacter;
        }
    }
    return NULL;
}


void Party::Attack(Party* targetGroup, int attackerUID, int targetUID)
{
    /**
     * Given the party, attackerUID and targetUID the attacker will attack the target. Make sure you handle the case
     *  where the target dies, you don't want to forget to get your loot.
     */
     Character *attacker = FindMember(attackerUID);
    if (attacker == NULL)
    {
        std::cout<<"Attacker does not exist"<< endl;
        return;
    }
    Character *target = targetGroup -> FindMember(targetUID);
    attacker -> Attack(target);
    int targetHP = target -> GetHealth();
    if (targetHP <= 0)
    {
        attacker -> LootTarget(target);
	targetGroup->RemoveMember(target);
    }
}


int Party::GetSize() const
{
    /**
     * Returns the party size
     */
	return size;
}

/**
 * DO NOT MODIFY
 * @param m {Character*}
 */
void Party::PrintMemberData(Character *m) const
{
    // Formatting the output into a table
    std::cout << std::left
              << std::setw(5)
              << m->GetUid()
              << std::setw(20)
              << m->GetName()
              << std::setw(7)
              << m->GetLevel()
              << std::setw(8)
              << m->GetHealth()
              << std::setw(8)
              << m->GetRace()
              << std::setw(4)
              << m->GetJob()
              << std::endl;
}
