//
//  student.hpp
//  rec07
//
//  Created by Ziqian Zhang on 2022/3/11.
//

#ifndef student_hpp
#define student_hpp
#include <iostream>
#include <string>
#include <vector>

class Course;

class Student {
    friend std::ostream& operator<<(std::ostream& os, const Student& rhs);
public:
    // Student methods needed by Registrar
    Student(const std::string& name);
    const std::string& getName() const;
    bool addCourse(Course* aCourse);

    // Student method needed by Course
    void removedFromCourse(Course* aCourse);

private:
    std::string name;
    std::vector<Course*> courses;
};

#endif /* student_hpp */
