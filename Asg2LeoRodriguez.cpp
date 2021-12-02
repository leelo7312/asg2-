// Asg2LeoRodriguez.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vector>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <fstream>



int main()
{
    cout << endl << "Welcome to my GradeBook" << endl;
    string courseName = "Introduction to C++";
    GradeBook gb(courseName);
    gb.loadStudents();
    gb.outputGradeBook();

    gb.inputNewTest();
    gb.outputGradeBook();

    string editName("Mary");
    gb.editStudent(editName);
    gb.outputGradeBook();

    return 0;
}