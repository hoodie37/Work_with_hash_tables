//#include "stdafx.h" 
#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <cmath>
#include <windows.h>
#include <iostream> 
#include <ctime> 
const int n = 45;
const int t = n * 1.5;
int c = 45;
using namespace std;

//int proverka(int x, int b[t]) {
//	int c = 0;
//	int	k = (x % 10 + x / 10) % t;
//	int k1 = k;
//	int j = 0;
//	while (c != 100) {
//		if (b[k] == x)
//			return b[k];
//		else {
//			k = (k1 + j * j) % t;
//			c++;
//			j++;
//		}
//	}
//	return 0;
//}

bool Delete(int x, int b[t]) {
	int w = 0;
	int	k = (x % 10 + x / 10) % t;
	int k1 = k;
	int j = 0;
	while (w != 100) {
		if (b[k] == x) {
			b[k] = -1;
			return true;
		}
		else {
			k = (k1 + j * j) % t;
			w++;
			j++;
		}
	}
	return false;
}



int dobavlenie(int x, int b[t]) {
	int w = 100;
	int	k = (x % 10 + x / 10) % t;
	int k1 = k;
	int k2 = -1;
	int j = 0;
	int i = 1;
	if (b[k] == x) {
		return 0; // нашлось
	}
	else if (b[k] == 0){
		b[k] = x;
		c++;
		return k;//Добавили 
	}
	else {
		if (b[k] == -1) {
			k2 = k;
		}
		while ((b[k] != x) && (b[k] != 0) && (i < w)) {
			k = (k1 + j * j) % t;
			if (b[k] == -1 && k2 == -1)
				k2 = k;
			j++;
			i++;
		}
		if (b[k] == x) {
			return 0;
		}
		else if (k2 != -1) {
			b[k2] = x;
			c++;
			return k2;
		}
		else if (b[k] == 0) {
			b[k] = x;
			c++;
			return k;
		}
		
	}
}

bool Zamena(int x, int y, int b[t]) {
	if (Delete(x, b)) {
		if (dobavlenie(y, b) != 0) {
			return true;
		}
		else return false;
	}
	else return false;
}
int main()
{
	setlocale(LC_ALL, "Russian");

	int a[n], k;
	int b[t];

	for (int i = 0; i < t; i++) {
		b[i] = 0;
	}
	srand(time(0));
	for (int i = 0; i < n; i++) {
		int flag = 0;
		while (flag == 0) {
			a[i] = 10 + rand() % 90;
			flag = 1;
			for (int j = 0; j < i; j++) {
				if (a[j] == a[i]) {
					flag = 0;
				}
			}

		}

	}
	int k1 = 0;
	for (int i = 0; i < n; ++i) {
		k = (a[i] % 10 + a[i] / 10) % t;
		k1 = k;
		if (b[k] == 0) {
			b[k] = a[i];
		}
		else {
			int j = 1;
			while (b[k] != 0) {
				k = (k1 + j * j) % t;
				j++;
				c++;
			}
			b[k] = a[i];
		}
	}



	//cin >> x;

//cout << "Nachalniy massiv:\n";
//for (int i = 0; i < n; i++)
//	cout << a[i] << " ";
	int stop = 0;
	int x, h = 1;
	int p = 1;
	int p1 = 0;
	while (stop == 0) {
		//system("cls");
		printf("\n");
		cout << "Хэш таблица:\n";
		int c = 1;
		for (int i = 0; i < t; i++) {
			printf("%4s b[%2i] = %3d","", i, b[i]);
			if (c % 10 == 0)
				printf("\n");
			c++;
		}
		
			printf("\n");

		double s = 0;

		for (int i = 0; i < t; ++i) {
			if (b[i] != 0)
				s = s + 1;
		}
		printf("\n");
		//cout << "koef zap: " << s / t << "\n";
		//cout << "sr 4islo prob: " << (double)c / n << "\n";
		if (p == 1) {
			cout << "1.Поиск или добавление элемента\n";
			cout << "2.Удаление элемента\n";
			cout << "3.Замена элемента\n";
			cout << "4.Выход\n";
			cin >> p1;
			if (p1 == 4) {
				stop = 1;
			}
		}
		
		
		
		/////////Наличие\\\\\\\\\
		
		if (p1 == 1) {
			//system("cls");
			cout <<"\n" << "Число для проверки или добавления: ";
			int y = 0;
			cin >> y;
			int g = dobavlenie(y, b);
			if (g == 0) {
				printf("\n");
				//system("cls");
				cout << "Такое число есть в таблице "<< "\n";

			}
			else {
				printf("\n");
				//system("cls");
				cout << "Число добавлено по индексу " << g << "\n";

			}
			
			cout << "1.Назад\n";
			cout << "2.Выход\n";
			cin >> p;
			
			if (p == 2) {
				stop = 1;
			}
		}

		/////////Удаление\\\\\\\\\


		if (p1 == 2) {
			printf("\n"); 
			//system("cls");
			cout << "Число для удаления: ";
			int y = 0;
			cin >> y;
			
			if (Delete(y,b)) {
				printf("\n"); 
				//system("cls");
				cout << "Число удалено успешно\n ";
			}
			else {
				printf("\n"); 
				//system("cls");
				cout << "Число не найдено\n ";
			}
			cout << "1.Назад\n";
			cout << "2.Выход\n";
			cin >> p;

			if (p == 2) {
				stop = 1;
			}
		}

		/////////Замена\\\\\\\\\

		if (p1 == 3) {
			printf("\n"); 
			//system("cls");
			cout << "Число которое хотите заменить: ";
			int y = 0;
			cin >> y;

			cout << "Число на которое хотите заменить: ";
			int x = 0;
			cin >> x;

			if (Zamena(y,x, b)) {
				printf("\n"); 
				//system("cls");
				cout << "Число заменено успешно\n ";
			}
			else {
				printf("\n"); 
				//system("cls");
				cout << "Число не найдено\n ";
			}
			cout << "1.Назад\n";
			cout << "2.Выход\n";
			cin >> p;

			if (p == 2) {
				stop = 1;
			}
		}
	}

	return 0;
}