/*
����������� ���������, ����������� ���� ����� � �������.

���������� (�������)
+ ������ ��� ������ (������� � ���������).
+ ����� �������� ����� ������������� ����� � n (�� 2 �� 5).
+ ��������� ����������� n-������� ����� � ���������������� �������.
+ ����� ������ ������� �������� ����� � ������ n-������� ����� � ���������������� �������.
+ ��������� ��������, ������� ���� ������� ��� ���������� � �� ��������� � ���������� ����� (�� ���� ���������� �����) �
������� ������� ������ �� ������� � ���������� ����� (�� ���� ���������� �����).
+ ����� ������ �������, ���� �� �������� ��� ������������������ ��� �� �������.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS

void main()
{
	int k, n, p, m, d, l = 0;
	int i = 0;
	setlocale(LC_ALL, "rus");
	int A[5];
	int B[5];
	int seed = 0;
	setlocale(LC_ALL, "rus");
	printf("����� ���������� � ���� <���� � ������>!\n���� �� �������� �������, ������� ����� 0. �����!\n�������� ����� ������������� ����� - n (�� 2 �� 5): ");
	scanf_s("%d", &n);
	srand(time(NULL));
	A[0] = rand() % 9 + 1;
	while (i < n)
	{
		srand(time(NULL));
		k = rand() %( 9 + 1);
		int f;
		for (f = 0; f < i; f++)
		{
			if (k == A[f])
				break;
		}
		if (f == i)
		{
			A[i] = k;
			i++;
		}
	}
	printf("��������� ������� �����: ");
	for (i = 0; i < n; i++)
		printf("%d", A[i]);
	printf("\n���������� ������� �����, ���������� ����������� (���������� n-������� ����� � ���������������� �������)");
	while (n != l)
	{
		printf("\n������� ��� �����: ");
		scanf_s("%d", &p);
		if (p == 0)
		{
			printf("�� �������. �����, ������� ������� ���������: ");
			for (i = 0; i < n; i++)
				printf("%d", A[i]);
			break;
		}
		else
		{
			for (i = n - 1; i >= 0; i--)
			{
				m = p % 10;
				//printf("%d ", m);
				p = p / 10;
				B[i] = m;
			}
			/*for (i = 0; i < n; i++)
				printf("%d", B[i]);*/
			l = 0;
			for (i = 0; i < n; i++)
			{
				if (B[i] == A[i])
					l++;
			}
			printf("\n����� �����: %d", l);
			int f = 0;
			int h = 0;
			for (i = 0; i < n; i++)
			{
				for (f = 0; f < n; f++)
				{
					if (B[i] == A[f])
						h++;
				}
				f++;
			}
			printf("\n����� �����: %d", h);
		}	
	}
	if (n == l)
		printf("\n�����������, �� ������� �����!");
	scanf_s("%d", &d);
}