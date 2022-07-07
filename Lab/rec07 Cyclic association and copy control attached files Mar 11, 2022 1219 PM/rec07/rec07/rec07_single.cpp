////
////  rec07.cpp
////  rec07: single version
////
////  Created by Ziqian Zhang on 2022/3/11.
////
//
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//class Student;
//
//class Course {
//    friend ostream& operator<<(ostream& os, const Course& rhs);
//public:
//    // Course methods needed by Registrar
//    Course(const string& courseName);
//    const string& getName() const;
//    bool addStudent(Student* aStudent);
//    void removeStudentsFromCourse();
//
//private:
//    string name;
//    vector<Student*> students;
//};
//
//class Student {
//    friend ostream& operator<<(ostream& os, const Student& rhs);
//public:
//    // Student methods needed by Registrar
//    Student(const string& name);
//    const string& getName() const;
//    bool addCourse(Course* aCourse);
//
//    // Student method needed by Course
//    void removedFromCourse(Course* aCourse);
//
//private:
//    string name;
//    vector<Course*> courses;
//};
//
//class Registrar {
//    friend ostream& operator<<(ostream& os, const Registrar& rhs);
//public:
//    Registrar();
//    bool addCourse(const string& aCourse);
//    bool addStudent(const string& aStudent);
//    bool enrollStudentInCourse(const string& studentName,
//                               const string& courseName);
//    bool cancelCourse(const string& courseName);
//    void purge();
//
//private:
//    size_t findStudent(const string& aStudent) const;
//    size_t findCourse(const string& aCourse) const;
//
//    vector<Course*> courses;
//    vector<Student*> students;
//};
//
//int main() {
//
//    Registrar registrar;
//
//    cout << "No courses or students added yet\n";
//    cout << registrar << endl;
//     
//    cout << "AddCourse CS101.001\n";
//    registrar.addCourse("CS101.001");
//    cout << registrar << endl;
//
//    cout << "AddStudent FritzTheCat\n";
//    registrar.addStudent("FritzTheCat");
//    cout << registrar << endl;
//
//    cout << "AddCourse CS102.001\n";
//    registrar.addCourse("CS102.001");
//    cout << registrar << endl;
//
//    cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
//    registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
//    cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
//    registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
//    cout << registrar << endl;
//
//    cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
//    cout << "Should fail, i.e. do nothing, "
//         << "since Bullwinkle is not a student.\n";
//    registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
//    cout << registrar << endl;
//
//    cout << "CancelCourse CS102.001\n";
//    registrar.cancelCourse("CS102.001");
//    cout << registrar << endl;
//   
//    /*
//    // [OPTIONAL - do later if time]
//    cout << "ChangeStudentName FritzTheCat MightyMouse\n";
//    registrar.changeStudentName("FritzTheCat", "MightyMouse");
//    cout << registrar << endl;
//
//    cout << "DropStudentFromCourse MightyMouse CS101.001\n";
//    registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
//    cout << registrar << endl;
//
//    cout << "RemoveStudent FritzTheCat\n";
//    registrar.removeStudent("FritzTheCat");
//    cout << registrar << endl;
//    */
//
//    cout << "Purge for start of next semester\n";
//    registrar.purge();
//    cout << registrar << endl;
//}
//
//// Course code
//ostream& operator<<(ostream& os, const Course& rhs){
//    os << rhs.name << ": ";
//    if (rhs.students.size() != 0){
//        for (Student* curr : rhs.students){
//            os << curr->getName() << ' ';
//        }
//    }else{
//        os << "No Students";
//    }
//    return os;
//}
//
//const string& Course::getName() const{
//    return name;
//}
//
//bool Course::addStudent(Student* aStudent){
//    for (Student* curr : students){
//        if (curr == aStudent){
//            cout << "This student already enrolled in this course.\n";
//            return false;
//        }
//    }
//    students.push_back(aStudent);
//    aStudent->addCourse(this);
//    return true;
//}
//
//void Course::removeStudentsFromCourse(){
//    for (Student* each:students){
//        each->removedFromCourse(this);
//    }
//    students.clear();
//}
//
//Course::Course(const string& courseName): name(courseName){}
//
//// Student code
//
//ostream& operator<<(ostream& os, const Student& rhs){
//    os << rhs.name << ": " ;
//    if (rhs.courses.size() != 0){
//        for (Course* curr : rhs.courses){
//            os << curr->getName() << ' ';
//        }
//    } else {
//        os << "No Courses" ;
//    }
//    return os;
//}
//
//Student::Student(const string& name) : name(name){}
//
//const string& Student::getName() const{
//    return name;
//}
//bool Student::addCourse(Course* aCourse){
//    for (Course* curr : courses){
//        if (curr == aCourse){
//            cout << "Student already had this course." << endl;
//            return false;
//        }
//    }
//    courses.push_back(aCourse);
//    return true;
//}
//
//void Student::removedFromCourse(Course* aCourse){
//    for (size_t i = 0; i < courses.size(); ++i){
//        if (courses[i] == aCourse){
//            while (i < courses.size()){
//                courses[i] = courses[i + 1];
//                i++;
//            }
//            courses.pop_back();
//            return;
//        }
//    }
//}
//
//// Registrar code
//
//ostream& operator<<(ostream& os, const Registrar& rhs){
//    os << "Registrar's Report" << endl;
//    os << "Courses: " << endl;
//    for (Course* curr : rhs.courses){
//        os << *curr << endl;
//    }
//    os << "Students: " << endl;
//    for (Student* curr : rhs.students){
//        os << *curr << endl;
//    }
//    return os;
//}
//
//Registrar::Registrar(){}
//
//bool Registrar::addCourse(const string& aCourse){
//    for (Course* curr : courses){
//        if (curr->getName() == aCourse){
//            cout << "Course already exist." << endl;
//            return false;
//        }
//    }
//    Course* cptr = new Course(aCourse);
//    courses.push_back(cptr);
//    return true;
//}
//bool Registrar::addStudent(const string& aStudent){
//    for (Student* curr : students){
//        if (curr->getName() == aStudent){
//            cout << "This student already exists." << endl;
//            return false;
//        }
//    }
//    Student* sptr = new Student(aStudent);
//    students.push_back(sptr);
//    return true;
//}
//bool Registrar::enrollStudentInCourse(const string& studentName,
//                                      const string& courseName){
//    size_t studentIdx = findStudent(studentName);
//    size_t courseIdx = findCourse(courseName);
//    if (studentIdx == students.size()){
//        return false;
//    }
//    if (courseIdx == courses.size()){
//        return false;
//    }
//    courses[courseIdx]->addStudent(students[studentIdx]);
//    return true;
//}
//bool Registrar::cancelCourse(const string& courseName){
//    size_t courseIdx = findCourse(courseName);
//    if (courseIdx == courses.size()){
//        return false;
//    }
//    courses[courseIdx]->removeStudentsFromCourse();
//    while (courseIdx < courses.size()){
//        courses[courseIdx] = courses[courseIdx + 1];
//        courseIdx++;
//    }
//    courses.pop_back();
//    return true;
//}
//void Registrar::purge(){
////    for (Course* each : courses){
////        each->removeStudentsFromCourse();
////    }
//    courses.clear();
//    students.clear();
//}
//
//size_t Registrar::findStudent(const string& aStudent) const{
//    for (size_t index = 0; index < students.size(); ++index){
//        if (students[index]->getName() == aStudent){
//            return index;
//        }
//    }
//    return students.size();
//}
//
//size_t Registrar::findCourse(const string& aCourse) const{
//    for (size_t index = 0; index < courses.size(); ++index){
//        if (courses[index]->getName() == aCourse){
//            return index;
//        }
//    }
//    return courses.size() + 1;
//}
//
