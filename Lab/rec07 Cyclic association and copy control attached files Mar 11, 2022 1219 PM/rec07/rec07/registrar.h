//
//  registrar.hpp
//  rec07
//
//  Created by Ziqian Zhang on 2022/3/11.
//

#ifndef registrar_hpp
#define registrar_hpp

#include <iostream>
#include <string>
#include <vector>

class Course;
class Student;

class Registrar {
    friend std::ostream& operator<<(std::ostream& os, const Registrar& rhs);
public:
    Registrar();
    bool addCourse(const std::string& aCourse);
    bool addStudent(const std::string& aStudent);
    bool enrollStudentInCourse(const std::string& studentName,
                               const std::string& courseName);
    bool cancelCourse(const std::string& courseName);
    void purge();

private:
    size_t findStudent(const std::string& aStudent) const;
    size_t findCourse(const std::string& aCourse) const;

    std::vector<Course*> courses;
    std::vector<Student*> students;
};

#endif /* registrar_hpp */
