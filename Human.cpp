#include "Human.h"

// ќпределение метода дл€ установки имени человека
void Human::setFirstName(string firstName)
{
	this->firstName = firstName;
}

// ќпределение метода дл€ установки фамилии человека
void Human::setLastName(string lastName)
{
	this->lastName = lastName;
}

// ќпределение метода дл€ получени€ имени человека
const string Human::getFirstName()
{
	return firstName;
}

// ќпределение метода дл€ получени€ фамилии человека
const string Human::getLastName()
{
	return lastName;
}
