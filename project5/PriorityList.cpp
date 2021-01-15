#include "PriorityList.hpp"

PriorityList::PriorityList(const Process &process, Priority priority) : 
        _priority(priority)
{
    _tasks.push_back(process);
}


/// TODO
void PriorityList::SwapList(PriorityList &otherList)
{
	_tasks.swap(otherList._tasks);
	Priority temp = Prio();
	_priority = otherList._priority;
	otherList._priority = temp;
	
}


/// TODO
Process PriorityList::Pop()
{
	Process temp = _tasks.back();
	_tasks.pop_back();
	return temp;
}


/// TODO
void PriorityList::Push(const Process & process)
{
	_tasks.push_front(process);
}

Priority PriorityList::Prio() const
{
    return _priority;
}

bool PriorityList::IsEmpty() const
{
    return _tasks.size() == 0;
}

bool operator==(const Process &process, const PriorityList &list)
{
    return process.Prio() == list.Prio();
}

bool operator!=(const Process &process, const PriorityList &list)
{
    return process.Prio() != list.Prio();
}

bool operator>(const Process &process, const PriorityList &list)
{
    return process.Prio() > list.Prio();
}

bool operator<(const Process &process, const PriorityList &list)
{
    return process.Prio() < list.Prio();
}

bool operator==(const PriorityList &list, const Process &process)
{
    return list.Prio() == process.Prio();
}

bool operator!=(const PriorityList &list, const Process &process)
{
    return list.Prio() != process.Prio();
}

bool operator>(const PriorityList &list, const Process &process)
{
    return list.Prio() > process.Prio();
}

bool operator<(const PriorityList &list, const Process &process)
{
    return list.Prio() < process.Prio();
}


bool operator==(const PriorityList &lista, const PriorityList &listb)
{
    return lista.Prio() == listb.Prio();
}

bool operator!=(const PriorityList &lista, const PriorityList &listb)
{
    return lista.Prio() != listb.Prio();
}

bool operator>(const PriorityList &lista, const PriorityList &listb)
{
    return lista.Prio() > listb.Prio();
}

bool operator<(const PriorityList &lista, const PriorityList &listb)
{
    return lista.Prio() < listb.Prio();
}



