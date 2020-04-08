#include <iostream>
#include <string>
#include <stdlib.h>
#include<iomanip> 
#include "Customer.h"
#include <Windows.h>


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	Tree* head = new Tree;
	head = NULL;
	string passport, issueplace, name, address;
	int year;
	passport = InputPassport();
	issueplace = InputIssueplace();
	name = InputName();
	year = InputYear();
	address = InputAddress();
	addElem(head, passport, issueplace, name, year, address);
	addElem(head, "4444-444444","Барнаул", "Андрей", 1999, "ул. Ленина");
	addElem(head, "2323-444444", "Барнаул", "Андрей", 1999, "ул. Ленина");
	addElem(head, "5635-444444", "Барнаул", "Андрей", 1999, "ул. Ленина");
	addElem(head, "1111-444444", "Барнаул", "Андрей", 1999, "ул. Ленина");
	addElem(head, "9383-444444", "Барнаул", "Андрей", 1999, "ул. Ленина");
	addElem(head, "6379-444444", "Барнаул", "Андрей", 1999, "ул. Ленина");
	print(head, 0, true);

}

