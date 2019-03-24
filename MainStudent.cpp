
#include <vector>
#include <fstream>
#include "Student.h"

//global variables
const int SIZE = 20;

//function declaration
int get_input();
void display_all(const Student students[SIZE], int& num);
void delete_student(Student students[SIZE], long& id);
void read_all_data(); 
void save_all_data(Student students[SIZE]);

//main funtion
int main()
{
	Student students[SIZE];	
	
	read_all_data();
	
	int input, add = 0;
	
	do
	{
		input = get_input();
		Student new_s;
		
		switch(input)
		{
			case 1: cin >> students[add];
					add++; 		
			break;
			
			case 2: cout << "Enter the ID of student to be deleted: ";  
				
			break;
			
			case 3: display_all(students, add); 
			
			break;
			
			case 4: cout << "Exit Program: enter 4 to confirm program exit or 6 to continue: "; 
				cin >> input; 
			break;
			
			default: cout << "Command not recognized: input again." << endl;
		}
		
		system("pause");
		system("cls");
		
	}while(input != 4);
	
	save_all_data(students);
	
	return 0;
}


int get_input()
{
	cout << "Enter action to be performed: " << endl;
	cout << "1. Add student." << endl;
	cout << "2. Remove student. "  << endl;
	cout << "3. View all students Info." << endl;
	cout << "4. Exit program." << endl;
	
	int input;
	cout << "Input: ";
	cin >> input;
	
	return input;
}


void delete_student(Student students[SIZE], long& id)
{
	cout << "deleted" << endl;
}

void display_all(const Student students[SIZE], int& num)
{
	
	for (int i = 0; i < num; i++)
		cout << students[i];
}


void read_all_data()
{
	
	ifstream in;
	
	in.open("Student.txt", ios::binary);
	
	if(in.fail())
		cout << "FILE NOT OPENED" << endl;
	
	Student* student;
	
	in.read(reinterpret_cast<char*> (&student), sizeof(Student));
	
	int num = 1;
	while(!in.eof())
	{
		student->print();
		in.read(reinterpret_cast<char*> (&student), sizeof(Student));
		
	}
	
	in.close();
	
	cout << "ALL DATA READ" << endl;
}


void save_all_data(Student students[SIZE])
{	
		
	ofstream out;
	
	out.open("Student.txt", ios::binary);
	
	if(out.fail())
		cout << "FILE NOT OPENED" << endl;
	
	for (int i = 0; i < SIZE; i++)
		out.write(reinterpret_cast<char*> (&students[i]), sizeof(Student));
	
	out.close();
	
	cout << "ALL DATA SAVED" << endl;
}
