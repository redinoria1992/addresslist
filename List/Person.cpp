#include "stdafx.h"
#include "Person.h"

ostream &operator<<(ostream &out, Person &person)
{
	out << person.name << "------" << person.phone;
	return out;
}


Person &Person::operator=(Person &person)
{
	this->name = person.name;
	this->phone = person.phone;
	return *this;
}

bool Person::operator == (Person &person)
{
	if (this->name == person.name && this->phone == person.phone)
	{
		return true;
	}
	return false;
}