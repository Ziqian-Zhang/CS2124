//
//  course.cpp
//  rec07
//
//  Created by Ziqian Zhang on 2022/3/11.
//

#include "course.h"
#include "student.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

ostream& operator<<(ostream& os, const Course& rhs){
    os << rhs.name << ": ";
    if (rhs.students.size() != 0){
        for (const Student* curr : rhs.students){
            os << curr->getName() << ' ';
        }
    }else{
        os << "No Students";
    }
    return os;
}

const string& Course::getName() const{
    return name;
}

bool Course::addStudent(Student* aStudent){
    for (Student* curr : students){
        if (curr == aStudent){
            cout << "This student already enrolled in this course.\n";
            return false;
        }
    }
    students.push_back(aStudent);
    aStudent->addCourse(this);
    return true;
}

void Course::removeStudentsFromCourse(){
    for (Student* each:students){
        each->removedFromCourse(this);
    }
    students.clear();
}

Course::Course(const string& courseName): name(courseName){}
