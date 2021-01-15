#include "classroom.hpp"

///
Classroom::Classroom()
{

}

// DO NOT MODIFY THIS CODE
// DO NOT MODIFY THIS CODE
// DO NOT MODIFY THIS CODE
Student* Classroom::find_student(unsigned int UID, bool &found)
{
    _classList.ResetIterator();
    while(!_classList.AtEnd())
    {
        Student* s = _classList.IterateItems();
        if(s->GetID() == UID)
        {
            found = true;
            return s;
        }
    }
    found = false;
}

// DO NOT MODIFY THIS CODE
// DO NOT MODIFY THIS CODE
// DO NOT MODIFY THIS CODE
void Classroom::PrintClassroomInformation() const
{
    _classList.ResetIterator();
    while(!_classList.AtEnd())
    {
        std::cout << "****************************************" << std::endl;
        _classList.IterateItems()->PrintData();
        std::cout << std::endl;
    }
}

/// modify code below this line
// ========================================
bool Classroom::AddStudent(const std::string &firstName, const std::string &lastName,unsigned int UID)
{
    bool found = false;
    Student *another = find_student(UID, found);
    if(found)
    {
        return false;
    }

    Student s(firstName, lastName, UID);  


    _classList.AppendItem(s);
    return true;
}

bool Classroom::RemoveStudent(unsigned int UID)
{
    /// removes the student from the list based on UID.
    /// returns true if the student was successfully removed
    bool found = false;
    Student *s = find_student(UID, found);
    if(!found)
    {
        return false;
    }

    return _classList.DeleteItem(*s);
}

void Classroom::AddProjects(const List<Assignment> &projects)
{
    /// adds the projects to the required student's list of projects
    projects.ResetIterator();
    while(!projects.AtEnd())
    {
        bool found = false;
        Assignment* p = projects.IterateItems();
        Student *student = find_student(p->StudentUID, found);
        if(found)
        {
            student->AddProject(p->Grade);
        }
    }
}

void Classroom::AddExams(const List<Assignment> &projects)
{
    /// adds the exams to the required student's list of exams
    projects.ResetIterator();
    while(!projects.AtEnd())
    {
        bool found = false;
        Assignment *p = projects.IterateItems();
        Student *student = find_student(p->StudentUID, found);
        if(found)
        {
            student->AddExam(p->Grade);
        }
    }
}

void Classroom::SetFinalExams(const List<Assignment> &projects)
{
     /// sets the required student's FinalExam score.
    projects.ResetIterator();
    while(!projects.AtEnd())
    {
        bool found = false;
        Assignment *p = projects.IterateItems();
        Student *student = find_student(p->StudentUID, found);
        if(found)
        {
            student->SetFinalExam(p->Grade);
        }
    }
}



