template<typename Type>
List<Type>::List()
{
	/// initialize the nodes correctly
	_firstNode = NULL;
	_lastNode = NULL;
	_count = 0;
	_iteratorNode = _firstNode;
}

template<typename Type>
List<Type>::~List()
{

		/// delete all data within the list, be sure to account for memory leaks.
		Node<Type> *tempPtr;
		ResetIterator();
		while ( _firstNode != NULL )		// Loops to deallocate all nodes
    		{
    		tempPtr = _firstNode;
    		_firstNode = _firstNode->nextItem;
    		delete tempPtr;
    		}
}

template<typename Type>
void List<Type>::AddItemSorted(const Type &data)
{
    /**
     * Insert the items in the list in ascending order
     */
    Node<Type>* newNode = new Node<Type>(data);
    if(_firstNode == NULL)
    {
        _firstNode = newNode;
        _lastNode = _firstNode;
    }
    else if(Front() > data)
    {
        newNode->nextItem = _firstNode;
        _firstNode = newNode;
    }
    else if(!(Back() > data))
    {
        _lastNode->nextItem = newNode;
        _lastNode = newNode;
    }
    else
    {
        ResetIterator();
        while(!AtEnd())
        {
            if(_iteratorNode->nextItem->localData > data)
            {
                newNode->nextItem = _iteratorNode->nextItem;
                _iteratorNode->nextItem = newNode;
                return;
            }
            else
            {
                IterateItems();
            }
        }
    }
    _count++;
}

template<typename Type>
bool List<Type>::DeleteItem(const Type &data)
{
    /**
     * Deletes a provided item from the list
     */
            if (_firstNode != NULL){
            Node<Type> *tempPtr = _firstNode;

            if (_firstNode->localData == data) //data to be deleted is in head
            {
                _firstNode = _firstNode->nextItem;
                _count--;
                delete tempPtr;
                return true;
            }
            else{
                while (tempPtr->nextItem != NULL && tempPtr->nextItem->localData != data)
                    tempPtr = tempPtr->nextItem;

                if (tempPtr->nextItem == NULL) //item wasnt found
                    
                    return false;

                    else{
                    if (tempPtr->nextItem->localData == data)
                    {
                        Node<Type>* remove = tempPtr->nextItem;
                        tempPtr->nextItem = tempPtr->nextItem->nextItem;
                        _count--;
                        delete remove;
                        return true;
                    }
                }
            }
        }
        else
            return false;
    
}

template<typename Type>
unsigned int List<Type>::Count() const
{
    /**
     * Returns the number of items in the list
     */
	return _count;
}

template<typename Type>
Type& List<Type>::Front()
{
    /**
     * Returns the reference to the item at the front of the list
     */
	return (_firstNode->localData);
}

template<typename Type>
Type List<Type>::Front() const
{
    /**
     * Returns a const copy to the data that is at the front of the list
     */
    Type const data_returned = _firstNode -> localData;
    return data_returned;
}

template<typename Type>
Type& List<Type>::Back()
{
    /**
     * Returns a reference to the item at the back of the list
     */
	return (_lastNode->localData);
}

template<typename Type>
Type List<Type>::Back() const
{
    /**
     * Returns a const copy to the item at the back of the list
     */
    Type const data_returned = _lastNode -> localData;
    return data_returned;
}

template<typename Type>
Type* List<Type>::IterateItems() const
{
	/**
	 * Provides a pointer to the current item at the _iterator pointer.
	 * It moves the iterator pointer to the next item in the list.
	 */
	Type* temp = &(_iteratorNode->localData);
	_iteratorNode = _iteratorNode->nextItem;
	return temp;
}

template<typename Type>
bool List<Type>::AtEnd() const
{
    /**
     * Returns if the iterator pointer is at the end of the list
     */
	if (_iteratorNode == NULL)
	{
		return true;
	}
}

template<typename Type>
void List<Type>::ResetIterator() const
{
    /**
     * Resets the iterator pointer to the beginning of the list
     */
	_iteratorNode = _firstNode;
}

template<typename Type>
Type List<Type>::PopFront()
{
    /**
     * Method that will Pop the first item off of the front of the list.
     * This will remove the item from the list and return its value to the caller.
     */
     ResetIterator();
     Type item = _firstNode->localData;
     DeleteItem(item);
     return item;
}

