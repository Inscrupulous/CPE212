/// IMPLEMENT THE FOLLOWING FUNCTIONS

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
		ResetIterator();
	while (!AtEnd())
	{
		Node<Type> *tmpPtr = _iteratorNode;
		IterateItems();
		_firstNode = _iteratorNode;
		delete tmpPtr;
	}

}

template<typename Type>
void List<Type>::AppendItem(const Type &data)
{
	Node<Type> *tmpPtr = new Node<Type>(data);
	/// Append an item correctly into the list
	/// increment _count
	if (_firstNode == NULL)
	{
		_firstNode = tmpPtr;
		_iteratorNode = _firstNode;
		_lastNode = tmpPtr;
	}
	else
	{
		_lastNode->nextItem = tmpPtr;
		_lastNode = tmpPtr;
	}
	_count++;
}

template<typename Type>
bool List<Type>::DeleteItem(const Type &data)
{
	/// remove an item correctly to the list
	/// All items in this project will be equal comparable
	/// return false if the item was not removed
	/// return true if the item was removed.
	/// decrement _count if the item was removed.
	ResetIterator();
	Type NewData;
	Node<Type>* prev;

	if (Front() == data)
	{
		prev = _firstNode;
		_firstNode = prev->nextItem;
		ResetIterator();
		delete prev;
		return true;
	}
	else
	{
		ResetIterator();
		prev = _firstNode;
	while(_iteratorNode != _lastNode)
	{
		NewData = _iteratorNode->nextItem->localData;
	if (NewData == data)
	{
		prev = _iteratorNode->nextItem;
	if (_iteratorNode->nextItem == _lastNode)
	{
		_lastNode = _iteratorNode;
	}
	_iteratorNode->nextItem = _iteratorNode->nextItem->nextItem;
	delete prev;
	_count--;
	return true;
	}
	IterateItems();
	NewData = _iteratorNode->localData;
	}
	return false;
	}
}		

template<typename Type>
unsigned int List<Type>::Count() const
{
	/// returns the size from _count.
	return _count;
}

template<typename Type>
Type& List<Type>::Front()
{
	/// returns a reference to the data in the front of the list
	return _firstNode->localData;
}

template<typename Type>
Type List<Type>::Front() const
{
	/// returns a const copy to the data in the front of the list.
	return _firstNode->localData;
}

template<typename Type>
Type& List<Type>::Back()
{
	/// returns a reference to the data in the back of the list.
	return _lastNode->localData;
}

template<typename Type>
Type List<Type>::Back() const
{
	/// returns a const copy to the data in the back of the list
	return _lastNode->localData;
}

template<typename Type>
Type* List<Type>::IterateItems() const
{
	/// provides a pointer to the current item at the _iterator pointer.
	/// moves the iterator pointer to the next item.
	Type* tmp = &(_iteratorNode->localData);
	_iteratorNode = _iteratorNode->nextItem;
	return tmp;
}

template<typename Type>
bool List<Type>::AtEnd() const
{
	/// returns if your iterator pointer is at the end of the list
	if (_iteratorNode == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename Type>
void List<Type>::ResetIterator() const
{	
	/// resets your iterator pointer to the beginning.
	_iteratorNode = _firstNode;
}


