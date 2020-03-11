#pragma once

#include <string>

using namespace std;

struct Tree
{
	string passport;
	string issueplace;
	string name;
	int birthyear;
	string address;

	unsigned char height; //высота поддерева
	Tree* left; //указатели на левое и правое поддерево
	Tree* right;
	int depth; //глубина
	Tree();
};

bool If_digit_passport(string check);

unsigned char height(Tree* p);

int bfactor(Tree* p);

void fixheight(Tree* p);

Tree* rotateleft(Tree* q);

Tree* rotateright(Tree* p);

Tree* balance(Tree* p);

void print(Tree* h, int i, bool flag);

void addElem(Tree*& h, string newpassport, string issueplace, string name, int birthyear, string address);

string InputPassport();

string InputIssueplace();

string InputName();

int InputYear();

string InputAddress();
