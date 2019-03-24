// StudentClass.h
#ifndef STUDENT_H_ 
#define STUDENT_H_

#include <iostream>
#include <string>
#include <fstream>
#include <typeinfo>

using namespace std;


struct DOB
{
	int month,day,year;
};

class Student{
	
private:
	long id;
	string name,major;
	DOB dob;
	
public:
	Student();
	Student& operator = (const Student& student);
	friend ostream& operator << (ostream& out, const Student& student);
	friend istream& operator >> (istream& in, Student& new_student);
	string get_name();
	void print();
};

#endif
