/* File Name: prosper.assignment3.cpp
   Author: Orlean Prosper
   Email: oprosper2022@fau.edu
   Assignment Number: 3
   Descrition: A program that will calculate the final grade for COP3014 during the summer 2023 semester.
   Last changed: 07/01/2023
*/

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctype.h>
using namespace std;

class COP3014
{
public:
	COP3014(int z, string new_fname, string new_lname, double* new_grades);
	COP3014(int z, string new_fname, double* new_grades);
	COP3014(int z, double* new_grades);
	COP3014(double new_total_grade, char new_letter_grade);
	COP3014();
	void set_student(int z, string new_fname, string new_lname, double* new_grades);
	void set_student(int z, string new_fname, double* new_grades);
	void set_student(int z, double* new_grades);
	void set_grades(double new_total_grade, char new_letter_grade);
	void set_grades(double new_total_grade);
	string get_fname();
	string get_lname();
	char get_letter_grade();
	int get_znumber();
	double* get_grade();
	double get_total_grade();
	void input();
	void calculate_total_grade();
	void calculate_letter_grade();
	void output(ostream& display);

private:
	string fname, lname;
	char letter_grade = 'I';
	int znumber = 0;
	double grades[5] = {0};
	double total_grade = 0.0;
};

class Summer23 : public COP3014
{
public:
	Summer23(int z, string new_fname, string new_lname, double* new_grades, double new_bonus);
	Summer23();
	void input();
	void output(ostream& display);
	void calculate_bonus();
	void set_bonus(double);
	double get_bonus();
private: 
	double bonus;
};

void Greeting();
void check_name(string& name);
void check_znumber(int&);
void check_quiz(double& grade);
void check_exam(double& grade);
void check_bonus(double& bonus);
void check_selection(int&);

int main()
{

	int selection = 0;
	Summer23 student;
	double frank_grades[5] = { 20.0, 20.0, 10, 0.0, 90.0 };
	Summer23 Frank(12345678, "Frank", "Fabulous", frank_grades, 2);
	double gina_grades[5] = { 20.0, 20.0, 20.0, 98.0, 95.0 };
	Summer23 Gina(98765432, "Gina", "Genius", gina_grades, 3);
	Greeting();
	do
	{
		cout << endl << "-----------------------------------" << endl
			<< "(1) Input student information" << endl
			<< "(2) Print student examples to screen" << endl
			<< "(3) Quit" << endl
			<< "Your choice: ";
		cin >> selection;
		check_selection(selection);

		switch (selection)
		{
		case 1:
			student.input();
			student.calculate_total_grade();
			student.calculate_bonus();
			student.calculate_letter_grade();
			student.output(cout);
			break;
		case 2:

			Frank.calculate_total_grade();
			Frank.calculate_bonus();
			Frank.calculate_letter_grade();
			Frank.output(cout);


			Gina.calculate_total_grade();
			Gina.calculate_bonus();
			Gina.calculate_letter_grade();
			Gina.output(cout);
			break;
		default:
			cout << endl << "Please enter a valid menu option: ";
			break;
		}
	} while (selection != 3);

	return 0;
}

COP3014::COP3014()
{
	fname = "N/A";
	lname = "N/A";
	letter_grade = 'I';
	grades[0] = 20;
	grades[1] = 20;
	grades[2] = 20;
	grades[3] = 100;
	grades[4] = 100;
	znumber = 0;
	total_grade = 0.0;
}

COP3014::COP3014(int z, string new_fname, string new_lname, double* new_grades)
{
	for (int i = 0; i < 5; i++)
		grades[i] = new_grades[i];
	znumber = z;
	fname = new_fname;
	lname = new_lname;
}

COP3014::COP3014(int z, string new_fname, double* new_grades)
{
	for (int i = 0; i < 5; i++)
		grades[i] = new_grades[i];
	znumber = z;
	fname = new_fname;
}

COP3014::COP3014(int z, double* new_grades)
{
	for (int i = 0; i < 5; i++)
		grades[i] = new_grades[i];
	znumber = z;
}

COP3014::COP3014(double new_total_grade, char new_letter_grade)
{
	total_grade = new_total_grade;
	letter_grade = new_letter_grade;
}

Summer23::Summer23(int z, string new_fname, string new_lname, double* new_grades, double new_bonus) :COP3014(z, new_fname, new_lname, new_grades)
{
	bonus = new_bonus;
}

Summer23::Summer23() :COP3014()
{
	bonus = 0;
}


void COP3014::set_student(int z, string new_fname, string new_lname, double* new_grades)
{
	for (int i = 0; i < 5; i++)
		grades[i] = new_grades[i];
	znumber = z;
	fname = new_fname;
	lname = new_lname;
}

void COP3014::set_student(int z, string new_fname, double* new_grades)
{
	for (int i = 0; i < 5; i++)
		grades[i] = new_grades[i];
	znumber = z;
	fname = new_fname;
}

void COP3014::set_student(int z, double* new_grades)
{
	for (int i = 0; i < 5; i++)
		grades[i] = new_grades[i];
	znumber = z;
}

void COP3014::set_grades(double new_total_grade, char new_letter_grade)
{
	total_grade = new_total_grade;
	letter_grade = new_letter_grade;
}

void COP3014::set_grades(double new_total_grade)
{
	total_grade = new_total_grade;
}

string COP3014::get_fname()
{
	return fname;
}
string COP3014::get_lname()
{
	return lname;
}
char COP3014::get_letter_grade()
{
	return letter_grade;
}
int COP3014::get_znumber()
{
	return znumber;
}
double* COP3014::get_grade()
{
	return grades;
}
double COP3014::get_total_grade()
{
	return total_grade;
}

void COP3014::input()
{
	// Ask user for name
	cout << "Please enter your first name: ";
	cin >> fname;
	cout << "Please enter your last name: ";
	cin >> lname;

	// Ask user for znumber: check if it's exactly 8 digits
	cout << "Please enter your Z-number(without the Z): ";
	cin >> znumber;
	check_znumber(znumber);
	// Ask user for grades
	cout << "Enter grade for quiz 1 (in points): ";
	cin >> grades[0];
	check_quiz(grades[0]);
	cout << "Enter grade for quiz 2 (in points): ";
	cin >> grades[1];
	check_quiz(grades[1]);
	cout << "Enter grade for quiz 3 (in points): ";
	cin >> grades[2];
	check_quiz(grades[2]);
	cout << "Enter your midterm grade (in points): ";
	cin >> grades[3];
	check_exam(grades[3]);
	cout << "Enter your finals grade (in points): ";
	cin >> grades[4];
	check_exam(grades[4]);
}

void COP3014::calculate_total_grade()
{
	// use formula to get final letter grade
	total_grade = (grades[0] + grades[1] + grades[2]) / 3.0 + grades[3] * 0.3 + grades[4] * 0.5;

}

void COP3014::calculate_letter_grade()
{
	// use formula to get final letter grade
	if (total_grade < 60 || grades[3] == 0 || grades[4] == 0)
	{
		letter_grade = 'F';
	}
	else if (total_grade < 90 && total_grade >= 80)
	{
		letter_grade = 'B';
	}
	else if (total_grade < 80 && total_grade >= 70)
	{
		letter_grade = 'C';
	}
	else if (total_grade < 70 && total_grade >= 60)
	{
		letter_grade = 'D';
	}
	else if (total_grade >= 90)
	{
		letter_grade = 'A';
	}
	
}

void COP3014::output(ostream& display)
{
	// display information to the screen
	display << endl << "" << fname << " " << lname << " -- Z" << znumber << endl << endl
		<< "\tQuiz 1: " << grades[0] << endl
		<< "\tQuiz 2: " << grades[1] << endl
		<< "\tQuiz 3: " << grades[2] << endl
		<< "\tMidterm: " << grades[3] << endl
		<< "\tFinal: " << grades[4] << endl;
	display.setf(ios::fixed);
	display.setf(ios::showpoint);
	display.precision(2);
	display << "\tTotal grade: " << total_grade << endl
		<< "\tFinal grade: " << letter_grade << endl;
}

void Greeting()
{
	cout << "********************************************************" << endl
		<< "Welcome to the ""Better than Canvas"" grade calculator" << endl
		<< "Select from the menu options below" << endl
		<< "********************************************************" << endl;
}

void check_selection(int& choice)
{
	while (cin.fail())
	{

		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid entry, Please input again: ";
		cin >> choice;

	}
}

void check_znumber(int& znum)
{
	int temp = znum;
	int digits = 0;
	while (temp != 0)
	{
		temp /= 10;
		digits++;
	}
	while (cin.fail() || digits != 8)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Z-number must contain 8 digits only, please re-enter: ";
		cin >> znum;
		temp = znum;
		digits = 0;
		while (temp != 0)
		{
			temp /= 10;
			digits++;
		}
	}

}

void check_quiz(double& grade)
{
	//Checks to make sure the input is a positive number and not a character
	
	while (grade < 0 || cin.fail() || grade > 20)
	{
		if (grade > 20)
		{
			cout << "Please do not add bonus points, 20 points max, re-enter grade: ";
			cin >> grade;
		}
		else {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid entry. Please input again: ";
			cin >> grade;
		}
	}
	
}

void check_exam(double& grade)
{
	//Checks to make sure the input is a positive number and not a character

	while (grade < 0 || cin.fail() || grade > 100)
	{
		if (grade > 100)
		{
			cout << "Please do not add bonus points, 100 points max, re-enter grade: ";
			cin >> grade;
		}
		else {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid entry. Please input again: ";
			cin >> grade;
		}
	}

}

void check_bonus(double& bonus)
{
	//Checks to make sure the input is a positive number and not a character

	while (bonus < 0 || cin.fail() || bonus > 3)
	{
		
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid entry. Bonus is only 0-3%. Please input again: ";
		cin >> bonus;
	
	}

}

void check_name(string& name)
{
	int digit = 0;

	for (int i = 0; i < name.length(); i++)
	{
		if (isdigit(name[i]))
		{
			digit++;
		}
	}
	while (digit != 0)
	{
		digit = 0;
		cin.clear();
		cout << "Please only enter characters for your name: ";
		cin >> name;
		for (int i = 0; i < name.length(); i++)
		{
			if (isdigit(name[i]))
			{
				digit++;
			}
		}
	}
}


void Summer23::input()
{
	string first_name, last_name;
	double student_grades[5] = {0};
	int student_znumber = 0;
	// Ask user for name
	cout << "Please enter your first name: ";
	cin >> first_name;
	check_name(first_name);
	cout << "Please enter your last name: ";
	cin >> last_name;
	check_name(last_name);

	// Ask user for znumber: check if it's exactly 8 digits
	cout << "Please enter your Z-number(without the Z): ";
	cin >> student_znumber;
	check_znumber(student_znumber);
	// Ask user for grades
	cout << "Enter grade for quiz 1 (in points): ";
	cin >> student_grades[0];
	check_quiz(student_grades[0]);
	cout << "Enter grade for quiz 2 (in points): ";
	cin >> student_grades[1];
	check_quiz(student_grades[1]);
	cout << "Enter grade for quiz 3 (in points): ";
	cin >> student_grades[2];
	check_quiz(student_grades[2]);
	cout << "Enter your midterm grade (in points): ";
	cin >> student_grades[3];
	check_exam(student_grades[3]);
	cout << "Enter your finals grade (in points): ";
	cin >> student_grades[4];
	check_exam(student_grades[4]);
	cout << "Enter bonus amount (up to 3%): ";
	cin >> bonus;
	check_bonus(bonus);

	set_student(student_znumber, first_name, last_name,student_grades);
}

void Summer23::output(ostream& display)
{
	string first_name = get_fname();
	string last_name = get_lname();
	int student_znumber = get_znumber();
	double* student_grades = get_grade();
	double total_percent = get_total_grade();
	char student_letter_grade = get_letter_grade();
	// display information to the screen
	display << endl << "" << first_name << " " << last_name << " -- Z" << student_znumber << endl << endl
		<< "\tQuiz 1: " << student_grades[0] << endl
		<< "\tQuiz 2: " << student_grades[1] << endl
		<< "\tQuiz 3: " << student_grades[2] << endl
		<< "\tMidterm: " << student_grades[3] << endl
		<< "\tFinal: " << student_grades[4] << endl;
	display.setf(ios::fixed);
	display.setf(ios::showpoint);
	display.precision(2);
	display << "\tTotal grade: " << total_percent / (1 + (bonus * 0.01)) << endl
		<< "\tBonus: " << bonus << "%" << endl;
	display << "\tTotal grade with bonus: " << total_percent << endl
		<< "\tFinal grade: " << student_letter_grade << endl;
}

void Summer23::calculate_bonus()
{
	double percent = bonus * 0.01;
	double bonus_grade = get_total_grade();
	bonus_grade = bonus_grade * (1 + percent);
	set_grades(bonus_grade);
}

void Summer23::set_bonus(double new_bonus)
{
	bonus = new_bonus;
}

double Summer23::get_bonus()
{
	return bonus;
}