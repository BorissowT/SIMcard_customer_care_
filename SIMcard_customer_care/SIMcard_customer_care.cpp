#include <iostream>
#include <string>
#include <stdlib.h>
#include<iomanip> 

using namespace std;

struct Tree
{
	string passport;
	//char issueplace[50];
	//char name[50];
	//int birthyear[4];
	//char address[50];

	unsigned char height; //высота поддерева
	Tree* left; //указатели на левое и правое поддерево
	Tree* right;
	int depth; //глубина
	Tree();
};

unsigned char height(Tree* p)
{
	return p ? p->height : 0; //если можно вернуть p(p не пустое значение), то присваиваем ей height, если нет, то p=0
}

int bfactor(Tree* p) //Вычисление коэффициента сбалансированности (2 или-2)
{
	return height(p->right) - height(p->left);
}

Tree::Tree()
{
	this->height = 0;
	this->passport = "0000-00000";
	
}

void fixheight(Tree* p) //вычисление высоты
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

Tree* rotateleft(Tree* q) // левый поворот
{
	Tree* p = q->right;
	q->right = p->left;
	p->left = q; fixheight(q);
	fixheight(p);
	return p;
}

Tree* rotateright(Tree* p) // правый поворот
{
	Tree* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

Tree* balance(Tree* p) // балансировка
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

void addElem(Tree*& h, string newpassport) //добавление элемента в дерево
{
	string convertednewpass, convertedOldpass;
	if (h == NULL) {
		Tree* head = new Tree;

		head->passport = newpassport;
		head->right = NULL;
		head->left = NULL;
		h = head;

		return;
	}
	convertednewpass = newpassport;
	convertednewpass.replace(4, 3, "0");
	convertedOldpass = h->passport;
	convertedOldpass.replace(4, 3, "0");
	if (atoi(convertednewpass.c_str()) < atoi(convertedOldpass.c_str())) //определяется положение вставки 
		addElem(h->left, newpassport);
	if (atoi(convertednewpass.c_str()) > atoi(convertedOldpass.c_str()))
		addElem(h->right, newpassport);
	if (atoi(convertednewpass.c_str()) == atoi(convertedOldpass.c_str()))
		cout << "Такой Киент уже есть" << endl;
	h = balance(h);
}

int main()
{
	setlocale(LC_ALL, "rus");
	Tree* head = new Tree;
	head = NULL;


	string passport;
	cin >> passport;
	addElem(head, passport);
	cin >> passport;
	addElem(head, passport);
	cin >> passport;
	addElem(head, passport);
	cin >> passport;
	addElem(head, passport);
	cin >> passport;
	addElem(head, passport);
	print(head, 0, true);

}

