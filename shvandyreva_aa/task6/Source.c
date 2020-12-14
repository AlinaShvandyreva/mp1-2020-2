#define _USE_MATH_DEFINES 
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

char* menu[] = { "����:","1 - ����� 1", "2 - ����� 2" };
char* function[] = {"1 - sin(x)","2 - cos(x)","3 - exp(x)","4 - ch(x)"};

void privetstvie()
{
	printf("����� ���������� � ���������, ����������� ��������� ������ �������� ��� ���������� ������ ������� � �������� ����� � �������� ������������ �� ���� ���������� ���� ������� � ��� �������.");
	printf("\n\n��� ��������� ����� ��� ������ ������.");
	printf("\n\n�� ����������� ������� ��� ������ � ������ 1 ��������� ������� ��������� ����������:\n - ��������� �������� (���������� � �������������� ���������� �������������� ������� ����� ���������������� �),\n - ����������� ������ �������� �������,\n - ������� ����� ������� � ��������� ���������,\n - ���������� ���������, ������� ���� ���������.");
	printf("\n\n�� ����������� ������� ��� ������ � ������ 2 ��������� ������� ��������� ����������:\n - ��������� �������� (���������� � �������������� ���������� �������������� ������� ����� ���������������� �),\n - ������� �� NMax ����� �� ���������� ���������: ��� - �� ���������(�� 1 �� NMax), ����������� ������ �������� �������, ������� ����� ������� � ��������� ���������.");
	printf("\n");
}
void menu_regime() //���� �������
{
	int menu_size = sizeof(menu) / sizeof(char*);
	int i = 0;
	for (i = 0; i < menu_size; i++)
		printf("%s \n", menu[i]);
}
int regime_choice() //����� �� ������ + �������� 
{
	int choice;
	printf("\n����� ������� ������� ���������������?   ");
	scanf_s("%d", &choice);
	if (choice < 1 || choice > 3) //�������� ������������ ��������� ������������� ������
	{
		printf("\n�� ����������� ����� ����� ����, �������, ����������, ��� ���:   ");
		scanf_s("%d", &choice);
	}
		printf("\n�� ������� <%s>\n\n", menu[choice]);
	return choice;
}
void menu_function() //���� �������
{
	int menu_size = sizeof(function) / sizeof(char*);
	int i = 0;
	for (i = 0; i < menu_size; i++)
		printf("%s \n", function[i]);
}
int function_choice() //����� ������� + �������� 
{
	int choice;
	printf("\n�������� �������:   ");
	scanf_s("%d", &choice);
	if (choice < 1 || choice > 4) //�������� ������������ ��������� ������������� ������
	{
		printf("\n������� � ����� ������� ��� � ����, ����������, ������� ����� ��� ���:   ");
		scanf_s("%d", &choice);
	}
		printf("\n�� ������� <%s>\n\n", function[choice-1]);
	return choice;
}
//--------------------------�������-----------------------------//
void sinus(double x, float E, long int count)
{
	int i;
	double etalon = sin(x);
	double function = x;
	double slagaemoe = x;
	for (i = 2; (i <= count) && (fabs(etalon - function) > E); i++)
	{
		slagaemoe = (-1) * slagaemoe * x * x / ((2 * i - 1) * (2 * i - 2));
		function += slagaemoe;
	}
	printf("%16d   %26.6lf   %32.6lf\n", i - 1, function, fabs(etalon - function));
}
void cosinus(double x, float E, long int count)
{
	int i;
	double etalon = cos(x);
	double function = 1;
	double slagaemoe = 1;
	for (i = 2; (i <= count) && (fabs(etalon - function) >= E); i++)
	{
		slagaemoe = (-1) * slagaemoe * x * x / ((2 * i - 2) * (2 * i - 3));
		function += slagaemoe;
	}
	printf("%16d   %26.6lf   %32.6lf\n", i - 1, function, fabs(etalon - function));
}
void exponenta(double x, float E, long int count)
{
	int i;
	double etalon = exp(x);
	double function = 1;
	double slagaemoe = 1;
	for (i = 2; (i <= count) && (fabs(etalon - function) > E); i++)
	{
		slagaemoe *=  x / (i - 1);
		function += slagaemoe;
	}
	printf("%16d   %26.6lf   %32.6lf\n", i - 1, function, fabs(etalon - function));
}
void coshinus(double x, float E, long int count)
{
	int i;
	double etalon = cosh(x);
	double function = 1;
	double slagaemoe = 1;
	for (i = 2; (i <= count) && (fabs(etalon - function) > E); i++)
	{
		slagaemoe *= (x / (i - 1));
		if (i % 2 == 1)
			function += slagaemoe;
	}
	printf("%16d   %26.6lf   %32.6lf\n", i - 1, function, fabs(etalon - function));
}
//-------------------------������-------------------------------//
void regime_one(void(*f)(double, float, int), double x, double etalon)
{
	float E;
	int k;
	printf("\n������� �������� ���������� (>= 0,000001):   ");
	scanf_s("%f", &E);
	printf("\n������� ���������� ��������� �� 1 �� 1000:   ");
	scanf_s("%d", &k);
	printf("\n��������� ��������:   %lf\n", etalon);
	printf("\n���-�� ���������   ����������� ������ �������   ������� ����� ������� � ��������\n");
	f(x, E, k);
	printf("\n�� ��������!\n");
}
void regime_two(void(*f)(double, float, int), double x, double etalon)
{
	int experience, i;
	printf("\n������� ���������� ������������� �� 1 �� 25:   ");
	scanf_s("%d", &experience);
	printf("\n��������� ��������:   %lf\n", etalon);
	printf("\n���-�� ���������   ����������� ������ �������   ������� ����� ������� � ��������\n");
	for (i = 0; i < experience; i++)
		f(x, -2 , i + 1); //������������� ��������, ����� ���������� ��� ��������� 
	printf("\n�� ��������!\n");
}

void main()
{
	setlocale(LC_ALL, "rus");
	int choice_function, regime; //����� ��������� ������� � �����
	double x, exact; //����� � � ��������
	double etalon;

	double (*function[5]) (double, float, long int);
	function[0] = sinus;
	function[1] = cosinus;
	function[2] = exponenta;
	function[3] = coshinus;

	privetstvie();
	menu_regime();
	regime = regime_choice();
	menu_function();
	choice_function = function_choice();
	printf("\n������� x:   ");
	scanf_s("%lf", &x);
	
	switch (choice_function)
	{
	case 1:
		function[0];
		x = x / 180 * M_PI;
		etalon = sin(x);
		break;
	case 2:
		function[1];
		x = x / 180 * M_PI;
		etalon = cos(x);
		break;
	case 3:
		function[2];
		etalon = exp(x);
		break;
	case 4:
		function[3];
		etalon = cosh(x);
		break;
	}
	if (regime == 1)
		regime_one(function[choice_function - 1], x, etalon);
	else
		regime_two(function[choice_function - 1], x, etalon);
	system("pause");
}