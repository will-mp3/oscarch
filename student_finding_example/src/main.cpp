//including other code
#include <iostream>
#include <vector>
#include "Student.h"

//including a namespace
vector<Student> findStudentsSameBirthdate(vector<Student> vector1);


using namespace std;

//the entry point of the program
int main() {

    vector<Student> listOfStudents;

    Student oscar("Oscar Chaparro", "12/17/1987");
    Student jack("Jack", "11/17/1987");
    Student mike("Mike", "12/18/1987");
    //Student oscar2 = Student("bla", "bla");

    listOfStudents.push_back(oscar);
    listOfStudents.push_back(jack);
    listOfStudents.push_back(mike);

    vector<Student> pair = findStudentsSameBirthdate(listOfStudents);

    if(pair.empty()){
        cout<< "All the students have a different birthdate" <<endl;
    }else{
     //print the students
        cout << "Found them: " <<endl;
        cout << pair[0].getName() <<endl;
        cout << pair[1].getName() <<endl;
        string var;
        cin >> var;

    }


    int number = 4;  //100
    int number2 = number >> 2 ; //1
    int number3 = number << 2 ; //10000
    cout << number2 <<endl;
    cout << number3<<endl;

    cout << "Hello " << oscar.getName() <<endl;
    return 0;
}



vector<Student> findStudentsSameBirthdate(vector<Student> students) {
    vector<Student> pair;

    int j = 0;
    for(Student currentStudent: students){

        for(int i = j + 1 ; i < students.size(); i++){
            Student anotherStudent = students[i];

            if (currentStudent.birthdate == anotherStudent.birthdate){
                pair.push_back(currentStudent);
                pair.push_back(anotherStudent);

                break;
            }
        }

        if(!pair.empty())
            break;

        j++;
    }

    return pair;
}