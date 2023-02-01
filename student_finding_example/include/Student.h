//
// Created by Oscar Chaparro on 2/1/23.
//

#ifndef TEST_PROJECT_STUDENT_H
#define TEST_PROJECT_STUDENT_H

#include <string>

using namespace std;

class Student {
public:
    Student(string name, string birthdate);
    string getName();
    string birthdate;
private:
    string name;

};


#endif //TEST_PROJECT_STUDENT_H
