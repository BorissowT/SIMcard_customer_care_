#include "Customer.h"
#include <stdlib.h>
#include<iomanip> 
#include <iostream>

using namespace std;

Tree::Tree()
{
	this->height = 0;
	this->passport = "0000-00000";

}

bool If_digit_passport(string check)
{
	bool error = false;
	for (int i = 0; i < 4; i++)
	{
		if (int(check[i]) < 48 || int(check[i]) > 57)
			error = true;
	}

	for (int i = 5; i < 11; i++)
	{
		if (int(check[i]) < 48 || int(check[i]) > 57)
			error = true;
	}
	return error;

}

unsigned char height(Tree* p)
{
	return p ? p->height : 0; //если можно вернуть p(p не пустое значение), то присваиваем ей height, если нет, то p=0

}

int bfactor(Tree* p)
{
	return height(p->right) - height(p->left);

}

void fixheight(Tree* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;

}

Tree* rotateleft(Tree* q)
{
	Tree* p = q->right;
	q->right = p->left;
	p->left = q; fixheight(q);
	fixheight(p);
	return p;

}

Tree* rotateright(Tree* p)
{
	Tree* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;

}

Tree* balance(Tree* p)
{
	fixheight(p); //вычисление высоты
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p;

}

void print(Tree* h, int i, bool flag)
{
	if (h == NULL)
		return;
	if (flag)
		i += 5;
	print(h->left, i, flag);
	cout << setw(65 - i) << h->passport << endl;//длина вывода
	print(h->right, i, flag);

}

void addElem(Tree*& h, string newpassport, string issueplace, string name, int birthyear, string address)
{
	string convertednewpass, convertedOldpass;
	if (h == NULL) {
		Tree* head = new Tree;

		head->passport = newpassport;
		head->issueplace = issueplace;
		head->name = name;
		head->birthyear = birthyear;
		head->address = address;
		head->right = NULL;
		head->left = NULL;
		h = head;

		return;
	}
	convertednewpass = newpassport;
	convertednewpass.replace(4, 4, "0");
	convertedOldpass = h->passport;
	convertedOldpass.replace(4, 4, "0");
	if (atoi(convertednewpass.c_str()) < atoi(convertedOldpass.c_str())) //определяется положение вставки 
		addElem(h->left, newpassport, issueplace, name, birthyear, address);
	if (atoi(convertednewpass.c_str()) > atoi(convertedOldpass.c_str()))
		addElem(h->right, newpassport, issueplace, name, birthyear, address);
	if (atoi(convertednewpass.c_str()) == atoi(convertedOldpass.c_str()))
		cout << "Такой Киент уже есть" << endl;
	h = balance(h);

}

string InputPassport()
{
	string passport;
	cout << "Введите номер и серию паспорта." << endl;
	cout << "Паспорт должен быть формата  «NNNN-NNNNNN», где N –цифры" << endl;
	cin >> passport;
	while (passport[4] != '-'
		|| passport.length() != 11
		|| If_digit_passport(passport)) {
		cout << "Паспорт должен быть формата  «NNNN-NNNNNN», где N –цифры" << endl;
		cin >> passport;
	}

	return passport;

}

string InputIssueplace()
{
	string issueplace;
	cout << "Введите место выдачи паспорта. Вводимы данные не должны превышать 50 символов." << endl;
	cin >> issueplace;
	while (issueplace.length() > 50) {
		cout << "Вводимы данные не должны превышать 50 символов." << endl;
		cout << "Введите заново." << endl;
		cin >> issueplace;
	}
	return issueplace;

}

string InputName()
{
	string name;
	cout << "Введите ФИО. Вводимы данные не должны превышать 50 символов." << endl;
	cin >> name;
	while (name.length() > 50) {
		cout << "Вводимы данные не должны превышать 50 символов." << endl;
		cout << "Введите заново." << endl;
		cin >> name;
	}
	return name;

}

int InputYear()
{
	int year;
	cout << "Введите год рождения." << endl;
	cin >> year;
	while (year > 2020) {
		cout << "Год выдачи не может быть больше 2020" << endl;
		cout << "Введите заново." << endl;
		cin >> year;
	}
	return year;
}

string InputAddress()
{
	string address;
	cout << "Введите адрес. Вводимы данные не должны превышать 50 символов." << endl;
	cin >> address;
	while (address.length() > 50) {
		cout << "Вводимы данные не должны превышать 50 символов." << endl;
		cout << "Введите заново." << endl;
		cin >> address;
	}
	return address;

}

