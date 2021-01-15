#include "item.h"

/**
* Student Section Begin
*/
bool Item::operator==(const Item &otherItem) const
{
    /**
     * Implement this operator using the name and type
     */
	if (this->name == otherItem.name)
	{
		if (this->type == otherItem.type)
		{
			return true;
		}
	}
	return false;
}

bool Item::operator!=(const Item &otherItem) const
{
    /**
     * Implement this operator
     */
	return !(this->type == otherItem.type);
}

bool Item::operator<(const Item & otherItem) const
{
    /**
     * Implement this operator using the name
     */
	return (this->type < otherItem.type);
}

bool Item::operator>(const Item & otherItem) const
{
    /**
     * Implement this operator using the name
     */
	return (this->type > otherItem.type);
}

bool Item::operator<=(const Item & otherItem)  const
{
    /**
     * Implement this operator
     */
	return !(this->type > otherItem.type);
}

bool Item::operator>=(const Item & otherItem)  const
{
    /**
     * Implement this operator using the name
     */
	return !(this->type < otherItem.type);
}
/**
* Student Section End
*/
