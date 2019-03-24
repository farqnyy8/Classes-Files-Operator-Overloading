
#include "Student.h"

Student::Student()
{
	id = 0; 
	name = " ";
	major = " ";
	dob.day = 1;
	dob.month = 1;
	dob.year = 1980;
}

void Student::print()
{
	cout << "Student Name: " << name << endl;
	cout << "Student Major: " << major << endl;
	cout << "Student ID: " << id << endl;
	cout << "Student DOB: " <<dob.day << "-" << dob.month << "-" << dob.year  << endl;
	cout << "*********************************************" << endl << endl;
}
ostream& operator << (ostream& out, const Student& student)
{
	out << "Student Name: " << student.name << endl;
	out << "Student Major: " << student.major << endl;
	out << "Student ID: " << student.id << endl;
	out << "Student DOB: " << student.dob.day << "-" << student.dob.month << "-" << student.dob.year  << endl;
	out << "*********************************************" << endl << endl;
	
	return out;
}

istream& operator >> (istream& in, Student& new_student)
{
	cin.ignore();
	cout << "Enter Student Name: ";
	getline(in, new_student.name);
	
	cout << "Enter Student Major: ";
	getline(in, new_student.major);
	
	cout << "Enter Student ID: ";
	in >> new_student.id;
	
	cout << "Enter Student DOB: " << endl;
	cout << "	Month: ";
	in >> new_student.dob.month;
	
	cout << "	Day: ";
	in >> new_student.dob.day;
	
	cout << "	Year: ";
	in >> new_student.dob.year;
	
	return in;
}

Student& Student::operator = (const Student& student)
{
	name = student.name;
	major = student.major;
	dob.day = student.dob.day;
	dob.month = student.dob.month;
	dob.year = student.dob.year;
	id = student.id;
}

string Student::get_name() 
{
	return name;
}
