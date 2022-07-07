//
//  registrar.cpp
//  rec07
//
//  Created by Ziqian Zhang on 2022/3/11.
//

#include "registrar.h"
#include "student.h"
#include "course.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

ostream& operator<<(ostream& os, const Registrar& rhs){
    os << "Registrar's Report" << endl;
    os << "Courses: " << endl;
    for (const Course* curr : rhs.courses){
        os << *curr << endl;
    }
    os << "Students: " << endl;
    for (const Student* curr : rhs.students){
        os << *curr << endl;
    }
    return os;
}

Registrar::Registrar(){}

bool Registrar::addCourse(const string& aCourse){
    for (Course* curr : courses){
        if (curr->getName() == aCourse){
            cout << "Course already exist." << endl;
            return false;
        }
    }
    Course* cptr = new Course(aCourse);
    courses.push_back(cptr);
    return true;
}
bool Registrar::addStudent(const string& aStudent){
    for (Student* curr : students){
        if (curr->getName() == aStudent){
            cout << "This student already exists." << endl;
            return false;
        }
    }
    Student* sptr = new Student(aStudent);
    students.push_back(sptr);
    return true;
}
bool Registrar::enrollStudentInCourse(const string& studentName,
                                      const string& courseName){
    size_t studentIdx = findStudent(studentName);
    size_t courseIdx = findCourse(courseName);
    if (studentIdx == students.size()){
        return false;
    }
    if (courseIdx == courses.size()){
        return false;
    }
    courses[courseIdx]->addStudent(students[studentIdx]);
    return true;
}
bool Registrar::cancelCourse(const string& courseName){
    size_t courseIdx = findCourse(courseName);
    if (courseIdx == courses.size()){
        return false;
    }
    courses[courseIdx]->removeStudentsFromCourse();
    while (courseIdx < courses.size()){
        courses[courseIdx] = courses[courseIdx + 1];
        courseIdx++;
    }
    courses.pop_back();
    return true;
}
void Registrar::purge(){
    for (Course* each : courses){
        delete each;
    }
    for (Student* each : students){
        delete each;
    }
    courses.clear();
    students.clear();
}

size_t Registrar::findStudent(const string& aStudent) const{
    for (size_t index = 0; index < students.size(); ++index){
        if (students[index]->getName() == aStudent){
            return index;
        }
    }
    return students.size();
}

size_t Registrar::findCourse(const string& aCourse) const{
    for (size_t index = 0; index < courses.size(); ++index){
        if (courses[index]->getName() == aCourse){
            return index;
        }
    }
    return courses.size();
}
