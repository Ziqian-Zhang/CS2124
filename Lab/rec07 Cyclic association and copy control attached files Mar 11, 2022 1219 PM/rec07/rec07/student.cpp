//
//  student.cpp
//  rec07
//
//  Created by Ziqian Zhang on 2022/3/11.
//

#include "student.h"
#include "course.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

ostream& operator<<(ostream& os, const Student& rhs){
    os << rhs.name << ": " ;
    if (rhs.courses.size() != 0){
        for (const Course* curr : rhs.courses){
            os << curr->getName() << ' ';
        }
    } else {
        os << "No Courses" ;
    }
    return os;
}

Student::Student(const string& name) : name(name){}

const string& Student::getName() const{
    return name;
}
bool Student::addCourse(Course* aCourse){
    for (Course* curr : courses){
        if (curr == aCourse){
            cout << "Student already had this course." << endl;
            return false;
        }
    }
    courses.push_back(aCourse);
    return true;
}

void Student::removedFromCourse(Course* aCourse){
    for (size_t i = 0; i < courses.size(); ++i){
        if (courses[i] == aCourse){
            while (i < courses.size()){
                courses[i] = courses[i + 1];
                i++;
            }
            courses.pop_back();
            return;
        }
    }
}
