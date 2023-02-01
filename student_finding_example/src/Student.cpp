//
// Created by Oscar Chaparro on 2/1/23.
//

#include "Student.h"

Student::Student(string name, string birthdate) {
    this->name = name;
    this->birthdate = birthdate;
}

string Student::getName() {
    return this->name;
}
