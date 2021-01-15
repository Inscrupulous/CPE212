#include "ProcessQueue.hpp"

/// TODO
void ProcessQueue::PushProcess(const std::string & output, Priority p)
{
	Process NewProcess(output, p, _nextPID++);
	for (auto & i : _data)
	{
		if (_data.empty())
		{
			break;
		}

		if (i == NewProcess)
		{
			i.Push(NewProcess);
			return;
		}

	}
	PriorityList NList(NewProcess, p);
	_data.push_back(NList);
	ReheapUpList(_data.size() - 1);
}

/// TODO
void ProcessQueue::ExecuteNextProcess()
{
	Process next = _data.front().Pop();
	next.ExecuteProcess(std::cout);

	if (_data.front().IsEmpty())
	{
		_data.front().SwapList(_data.back());
		_data.pop_back();
		ReheapDownList(0);
	}
}

/// TODO
void ProcessQueue::ReheapUpList(int currentIndex)
{
	if (currentIndex == 0)
	{
		return;
	}

	int parentNode = (currentIndex - 1) / 2;

	/// final case, we are in a correct heap.
	if (_data[parentNode] > _data[currentIndex])
	{
		return;
	}
	_data[parentNode].SwapList(_data[currentIndex]);
	ReheapUpList(parentNode); 
}

/// TODO
void ProcessQueue::ReheapDownList(int currentIndex)
{
	/// Bottom of the list base case.
	int _lastData = _data.size() - 1;
	if (currentIndex > _lastData)
	{
		return;
	}

	int leftChild = (currentIndex * 2) + 1;
	int rightChild = (currentIndex * 2) + 2;

	/// base case: no leaf nodes to go to.  
	if (rightChild > _lastData || leftChild > _lastData)
	{
		return;
	}
	int max = leftChild;
	if (_data[rightChild] > _data[leftChild])
	{
		max = rightChild;
	}

	/// final base case: we are in a correct heap.
	if (_data[max] < _data[currentIndex])
	{
		return;
	}
	_data[max].SwapList(_data[currentIndex]);
	ReheapDownList(max);
}

/// TODO
bool ProcessQueue::IsEmpty() const
{
	return(_data.size() == 0);
}