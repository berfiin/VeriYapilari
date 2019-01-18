// videodeneme.cpp: Konsol uygulamasının giriş noktasını tanımlar.


#include<stdio.h>
#include<stdlib.h>
#include<string>
#include "stdafx.h"
#include <iostream>
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
	else{
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
	//Eğer yığın dolu değilse
	if (kontrol == false)
	{
		//top indisini bir artırıyor ve dizinin bu indisine değerimizi atıyoruz
		top = top + 1;
		stack[top] = item;
	}
	//Eğer yığın dolu ise hata mesajı döndürüyoruz
	else
	{
		printf("\n Stack Dolu ...\n ");
	}
}
void pop()
{
	bool kontrol = isEmpty();
	//Eğer yığın boş değilse...
	if (kontrol == false)
	{
		//top indisini bir azaltıyoruz.
		top = top - 1;
	}
	else
	{
		printf("\n Stack bos oldugundan herahangi bir elaman çıkamazsiniz.......\n ");
	}
}
void control(string eleman) 
{
	bool con = true;
	for (int i = 0; i< eleman.length(); i++)
	{
		if (eleman[i] == '(')

			push(1);

		else if (eleman[i] == ')')
		{
			if (isEmpty())
			{
				cout << "islem hatası yapıldı" << endl;
				con= false;
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
				cout << "islem hatası yapıldı" << endl;
			else
				cout << "söz dizimi dogru" << endl;
		}

	}
}



int main()
{
	
	string eleman;
	cout << "mat islemi gir" << endl;
	cin >> eleman;
	control(eleman);
	system("pause");
    return 0;
}

