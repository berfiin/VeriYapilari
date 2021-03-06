
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stdafx.h"
#include <iostream>
#define STACKLIMIT 7
int stack[STACKLIMIT];
//Stack'in son elemanını (en üstteki) tutan index değeri
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
bool control = isFull();
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

	//Eğer yığın dolu değilse
	if (control == false)
	{
		//top indisini bir artırıyor ve dizinin bu indisine değerimizi atıyoruz
		top = top + 1;
		stack[top] = item;
		std::cout << "Stacke eleman eklendi..";
	}
	//Eğer yığın dolu ise hata mesajı döndürüyoruz
	else
	{
		std::cout << "\n Stack Dolu ...\n";
	}
}

void pop()
{
	bool control = isEmpty();
	//Eğer yığın boş değilse...
	if (control == false)
	{
		//top indisini bir azaltıyoruz.
		top = top - 1;
		std::cout << "Stack den eleman cikarildi";
	}
	else
	{
		std::cout << "\n Stack bos oldugundan herahangi bir elaman cikaramazsiniz...\n";

	}
}



int main()

{
	int hata = 0;
	const char dizi[7] = { '(','a' ,'+' ,'b',')' ,'*' ,'c' };

	for (int i = 0; i < 7; i++)
	{
		if (dizi[i] == '(')
		{
			push(1);
		}

		if (dizi[i] == ')')
		{
			if (isEmpty())
			{
				std::cout << "\n islem hatasi Stack bos oldugundan herahangi bir elaman cikaramazsiniz...\n";
				hata = 1;
				break;
			}

			else
			{
				pop();
			}

		}


	}


	if (hata == 1)
	{
		std::cout << "\nifade yanlis...\n";
	}

	if (isEmpty())
	{
		std::cout << "\nifade dogru...\n";
	}

	else
	{
		std::cout << "\nifade yanlis...\n";
	}
	system("pause");
}

