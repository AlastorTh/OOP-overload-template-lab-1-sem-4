#include <iostream>
#include <vector>
#include <locale>
#include <cmath>
using namespace std;

// =============================== Задание 1 =============================== //

int sroot(int a)
{
	int result;
	result = sqrt(a);
	return result;
}
float sroot(float a)
{
	float result;
	result = sqrt(a);
	return result;
}
double sroot(double a)
{
	double result;
	result = sqrt(a);
	return result;
}

// =============================== Задание 2 =============================== //

char min(char a, char b)
{
	char result;
	result = (a < b) ? a : b;
	return result;
}

int min(int a, int b)
{
	int result;
	result = (a < b) ? a : b;
	return result;
}

double min(double a, double b)
{
	double result;
	result = (a < b) ? a : b;
	return result;
}

// =============================== Задание 3 =============================== //

bool isSquare(int a)
{
	bool result;
	int sqr = 0;
	int cnt = 0;
	for (int i = 1; sqr + 2 <= a; i += 2)
		sqr += i;
	result = (a == sqr || a == 1);
	return result;
}

int foo(int a, int b, int c)
{
	int sqr;
	int cnt;
	int i;

	cnt = 0;
	if (isSquare(a))
		++cnt;
	if (isSquare(b))
		++cnt;
	if (isSquare(c))
		++cnt;
	return cnt;
}

// Доп. аргумент - указатель:
void foo(int *rez, int a, int b, int c)
{
	int sqr;
	int i;

	if (isSquare(a))
		++(*rez);
	if (isSquare(b))
		++(*rez);
	if (isSquare(c))
		++(*rez);
}

// Доп. аргумент - ссылка:
void foo(int &rez, int a, int b, int c)
{
	int sqr;
	int i;

	rez = 0;
	if (isSquare(a))
		++rez;
	if (isSquare(b))
		++rez;
	if (isSquare(c))
		++rez;
}

// =============================== Задание 4 =============================== //

int arrMax(int arr[], int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

char arrMax(char arr[], int size)
{
	char max = arr[0];
	for (int i = 0; i < size; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

// =============================== Задание 5 =============================== //

int sumElements(int arrI[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; ++i)
		sum += arrI[i];
	return sum;
}

double sumElements(double arrD[], int size)
{
	double sum = 0;
	for (int i = 0; i < size; ++i)
		sum += arrD[i];
	return sum;
}

double sumElements(int arrI[], double arrD[], int size)
{
	double sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += arrI[i];
		sum += arrD[i];
	}
	return sum;
}

// ========================================================================= //

void exercise1()
{
	printf("\nЗадание 1:\n");
	int varInteger = 4;
	printf("sroot(%d) = %d\n", varInteger, sroot(varInteger));
	float varFloat = 2.f;
	printf("sroot(%.3f) = %.3f\n", varFloat, sroot(varFloat));
	double varDouble = 2.714;
	printf("sroot(%.3f) = %.3f\n", varDouble, sroot(varDouble));
}

void exercise2()
{
	printf("\nЗадание 2:\n");
	char ch1 = 'a', ch2 = 'z';
	printf("min('%c', '%c') = %c\n", ch1, ch2, min(ch1, ch2));
	int dec1 = 123, dec2 = 321;
	printf("min(%4d, %4d) = %d\n", dec1, dec2, min(dec1, dec2));
	double dbl1 = 3.14, dbl2 = 2.71;
	printf("min(%4.2f, %4.2f) = %.2f\n", dbl1, dbl2, min(dbl1, dbl2));
}

void exercise3()
{
	printf("\nЗадание 3:\n");
	int a = 3;
	int b = 4;
	int c = 4;

	// Возвращающая искомое значение:
	int rez1 = 0;
	rez1 = foo(a, b, c);
	printf("Среди чисел %d, %d и %d - %d из них является квадратом.\n", a, b, c, rez1);

	// Доп. аргумент - указатель:
	int *rez2 = new int(0);
	foo(rez2, a, b, c);
	printf("Среди чисел %d, %d и %d - %d из них является квадратом.\n", a, b, c, *rez2);
	delete rez2;

	// Доп. аргумент - ссылка:
	int rez3 = 0;
	foo(rez3, a, b, c);
	printf("Среди чисел %d, %d и %d - %d из них является квадратом.\n", a, b, c, rez3);
}

void exercise4()
{
	printf("\nЗадание 4:\n");
	char strArr[12] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!'};
	int decArr[10] = {4, 5, 8, 1, 7, 3, 6, 9, 2, 0};
	printf("Максимальный элемент strArr: %c\n", arrMax(strArr, 12));
	printf("Максимальный элемент decArr: %d\n", arrMax(decArr, 10));
}

void exercise5()
{
	printf("\nЗадание 5:\n");
	int arrI[10] = {1, 3, 2, 4, 6, 8, 7, 8, 5, 0};
	double arrD1[4] = {4.12, 1.33, 3.14, 48.5};
	double arrD2[10] = {3.14, 2.71, 6.62, 2.99, 2.69, 1.22, 8.93, 10.5, 6.02, 1.97};
	printf("Сумма элементов arrI[10]: %d\n", sumElements(arrI, 10));
	printf("Сумма элементов arrD1[4]: %.2f\n", sumElements(arrD1, 4));
	printf("Сумма элементов arrI[10] и arrD2[10]: %.2f\n", sumElements(arrI, arrD2, 10));
}

// ========================================================================= //

int main()
{
	setlocale(LC_ALL, "RUS");

	exercise1();
	exercise2();
	exercise3();
	exercise4();
	exercise5();

	return 0;
}
