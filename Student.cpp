#include "Student.h"
#include <string.h>
#include <iostream>
Student::Student()
{
	strcpy_s(this->fullName, 50, "");
	this->groupNumber = 0;
	for (int i = 0; i < 5; i++) {
		this->marks[i] = 0;
	}
}

Student::Student(const char* name, int gr, int*marks)
{
	strcpy_s(this->fullName, 50, name);
	this->groupNumber = gr;
	for (int i = 0; i < 5; i++)
		this->marks[i] = marks[i];

}

Student::~Student()
{
}

void Student::print()
{
	std::cout <<"\n"<< this->fullName << " " << this->groupNumber << "\n";
	for (int i = 0; i < 5; i++)
		std::cout << this->marks[i] << " ";
}

float Student::getAverage()
{
	float sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += this->marks[i];
	}
	return sum / 5.0f;

}

Student& Student::operator=(const Student& s)
{
	if (this != &s) {
		strcpy_s(this->fullName, 50, s.fullName);
		this->groupNumber = s.groupNumber;
		for (int i = 0; i < 5; i++) {
			this->marks[i] = s.marks[i];
		}
	}
	return *this;
}
