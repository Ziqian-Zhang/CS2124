//
//  course.hpp
//  rec07
//
//  Created by Ziqian Zhang on 2022/3/11.
//

#ifndef course_hpp
#define course_hpp
#include <iostream>
#include <string>
#include <vector>

class Student;

class Course {
    friend std::ostream& operator<<(std::ostream& os, const Course& rhs);
public:
    // Course methods needed by Registrar
    Course(const std::string& courseName);
    const std::string& getName() const;
    bool addStudent(Student* aStudent);
    void removeStudentsFromCourse();

private:
    std::string name;
    std::vector<Student*> students;
};

#endif /* course_hpp */
