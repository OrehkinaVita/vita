#pragma once
#include <fstream>
using namespace std;
class Student
{
public:

	char fullName[50];
	int groupNumber;
	int marks[5];

	Student();
	Student(const char*, int, int*);
	~Student();
	void print();
	float getAverage();
	Student& operator= (const Student& s);
	bool compStudent( Student b) {
		return this->getAverage() > b.getAverage();

	}
	bool operator > (Student b) {
		return this->getAverage() > b.getAverage();

	}
	friend istream& operator>>(istream& is, Student& s) {
		is >> s.fullName>>s.groupNumber;
		for (int i = 0; i < 5; i++)
			is>>s.marks[i];
		return is;
	}
	friend ostream& operator<<(ostream& is, Student& s) {
		is << s.fullName <<" "<< s.groupNumber<<" ";
		for (int i = 0; i < 5; i++)
			is << s.marks[i]<<" ";
		is << "\n";
		return is;
	}
	static int  compStudentByGroup(const void* a, const void* b) {
		Student* pa = (Student*)a;
		Student* pb = (Student*)b;
		return pa->groupNumber - pb->groupNumber;
	}
	
};

