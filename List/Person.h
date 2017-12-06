#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
	friend ostream &operator<<(ostream &out,Person &person);
public:
	string name;
	string phone;
	Person &operator=(Person &person);
	bool operator == (Person &person);

};

#endif // !PERSON_H

