//
//  main.cpp
//  rec05: lab administration model
//
//  Created by Ziqian Zhang on 2022/2/25.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Section{
    
    friend ostream& operator << (ostream& os, const Section& sec);
    
public:
    class TimeSlot{
        friend ostream& operator << (ostream& os, const Section::TimeSlot& timeSlot){
            os << ", Time slot: [Day: " << timeSlot.day
            << ", Start time: ";
            if (timeSlot.time > 12) {
                    os << timeSlot.time - 12 << "pm";
                } else {
                    os << timeSlot.time << "am";
                }
                os << "], Students: ";
            return os;
        }
    public:
        TimeSlot(const string& theDay, int theTime): day(theDay), time(theTime){}
    private:
        string day;
        int time;
    };
    
    class StudentRecord{
        friend ostream& operator << (ostream& os, StudentRecord& record){
            os << "Name: " << record.studentName << ", Grades: ";
            for (int curr_grade: record.grades){
                os << curr_grade << ' ';
            }
            return os;
        }
    public:
        StudentRecord(const string& theName): studentName(theName), grades(14, -1){}
        const string& getStudentName() const { return studentName; }
        void setStudentGrade(int score, int week) {
            grades[week - 1] = score;
        }
    private:
        string studentName;
        vector<int> grades;
    };
    
    Section(const string& secName, const string& day, int time)
    : sectionName(secName), timeSlot(day, time){}
    
    void addStudent(const string& studentName){
        records.push_back(new StudentRecord(studentName));
    }

    void addGrade(const string& studentname, int score, int week){
        for (StudentRecord* curr_stu : records){
            if(curr_stu->getStudentName() == studentname){
                curr_stu->setStudentGrade(score, week);
                return;
            }
        }
    }
    
    // copy constructor
    Section(const Section& other): sectionName(other.sectionName), timeSlot(other.timeSlot){
        for(size_t i = 0; i < other.records.size(); ++i){
            records.push_back(new StudentRecord(*other.records[i]));
        }
    }
    
    // destructor
    ~Section(){
        cout << "Section " << sectionName << " is being deleted" << endl;
        for(StudentRecord* curr_record : records){
            cout << "Deleting " << curr_record->getStudentName() << endl;
            delete curr_record;
        }
    }
private:
    string sectionName;
    TimeSlot timeSlot;
    vector<StudentRecord*> records;
};

ostream& operator << (ostream& os, const Section& sec){
    os << "Section: " << sec.sectionName << sec.timeSlot;
    if (sec.records.size() == 0){
        os << "None" << endl;
    } else {
        os << endl;
        for (Section::StudentRecord* curr_student: sec.records){
            os << *curr_student << endl;
        }
    }
    return os;
}


class LabWorker {
    friend ostream& operator << (ostream& os, const LabWorker& labWorker);
public:
    LabWorker(const string& theName): name(theName), section(nullptr){}
    
    void addSection(Section& sec){ section = &sec; }
    void addGrade(const string& studentname, int score, int week){
        if (section){
            section->addGrade(studentname, score, week);
        }
    }
private:
    string name;
    Section* section;
};

ostream& operator << (ostream& os, const LabWorker& labWorker){
    if (labWorker.section == nullptr){
        os << labWorker.name << " does not have a section" << endl;
    } else {
        os << labWorker.name << " has " << *labWorker.section << endl;
    }
    return os;
}

// Test code
void doNothing(Section sec) { cout << sec << endl; }

int main() {

    cout << "Test 1: Defining a section\n";
    Section secA2("A2", "Tuesday", 16);
    cout << secA2 << endl;

    cout << "\nTest 2: Adding students to a section\n";
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    cout << secA2 << endl;

    cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe( "Moe" );
    cout << moe << endl;

    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection( secA2 );
    cout << moe << endl;

    cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    jane.addSection( secB3 );
    cout << jane << endl;

    cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);
    moe.addGrade("Paul", 19, 1);
    moe.addGrade("George", 16, 1);
    moe.addGrade("Ringo", 7, 1);
    cout << moe << endl;

    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);
    moe.addGrade("Paul", 20, 3);
    moe.addGrade("Ringo", 0, 3);
    moe.addGrade("George", 16, 3);
    cout << moe << endl;

    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
         << "those students (or rather their records?)\n";

    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
         << "then make sure the following call works:\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n";

} // main
