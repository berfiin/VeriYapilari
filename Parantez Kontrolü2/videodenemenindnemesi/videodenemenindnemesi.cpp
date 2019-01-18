
#include "stdafx.h"
#include <iostream>
#include<stdlib.h>
#include<string>
#include<stdio.h>


using namespace std;

#define STACKLIMIT 7

int stack[STACKLIMIT];
int top = -1;
bool isFull()
{
	if (top == STACKLIMIT - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isEmpty()
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void push(int item)
{
	bool kontrol = isFull();
	if (kontrol == false)
	{
		top = top + 1;
		stack[top] = item;
	}
	else
	{
		cout << "\n stack dolu.....\n" << endl;
	}
}
void pop()
{
	bool kontrol = isEmpty();
	if (kontrol == false)
	{
		top = top - 1;
	}
	else
	{
		cout << "\n stack bos olduğundan herhangi bir eleman çıkarılamaz...\n" << endl;
	}
}
void control(string eleman)
{
	bool con = true;
	for (int i = 0; i < eleman.length(); i++)
	{
		if (eleman[i] == '(')
			push(1);
		else if (eleman[i] == ')')
		{
			if (isEmpty())
			{
				cout << "islem hatası yapildi......." << endl;
				con = false;
				break;
			}
			else
			{
				pop();
			}
		}
		if (con)
		{
			if (isEmpty() == false)
				cout << "islem hatasi yapildi....." << endl;
			else
				cout << "soz dizini dogru...." << endl;
		}
	}
}
int main()
{
	string eleman;
	cout << "mat islemi giriniz" << endl;
	cin >> eleman;
	control(eleman);
	system("pause");
	return 0;
}

