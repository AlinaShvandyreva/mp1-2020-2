#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>
#include <omp.h>
#include <Windows.h> //��� �������� ����� 

char* menu[] = { "����:","1 - ���������� ��������� ", "2 - ���������� �������","3 - ���������� ���������", "4 - ���������� ��������", "5 - ���������� �����", "6 - ���������� �����", "7 - ���������� ���������", "8 - �����" };
void showmenu() //����� ����
{
	int menu_size = sizeof(menu) / sizeof(char*);
	int i = 0;
	for (i = 0; i < menu_size; i++)
		printf("%s \n", menu[i]);
}
int menuchoice() //����� �� ���� 
{
	int choice;
	printf("\n������� ����� ������ ��� ���������� ��� ������� 8 ��� ������ �� ���������:   ");
	scanf_s("%d", &choice);
	if (choice < 1 || choice > 8) //�������� ������������ ��������� ������������� ������
	{
		printf("\n�� ����������� ����� ����� ����������, �������, ����������, ��� ���:   ");
		scanf_s("%d", &choice);
	}
	if (choice != 8)
		printf("\n�� ������� <%s>\n\n", menu[choice]);
	return choice;
}
int counter(char path[]) //������� ���������� ������
{
	struct _finddata_t c_file;
	intptr_t hFile;
	int count = 0;
	if ((hFile = _findfirst(path, &c_file)) == -1L)
		printf("������������ ���� � ����������\n");
	else
	{
		do {
			count++;
		} while (_findnext(hFile, &c_file) == 0);
		_findclose(hFile);
	}
	return count; //���-�� ������ 
}
//����������............................//
//case 1: ���������� ��������� 
void Bubble(struct _finddata_t* c_file, int count) //��������� // ��� ������ �� ������� //������ O(n^2) //������� ��������� 
{
	int i, j;
	struct _finddata_t temp;
	for (i = 0; i < count; i++)
	{
		for (j = count - 1; j > i; j--)
		{
			if (c_file[j - 1].size > c_file[j].size) //>
			{
				temp = c_file[j - 1];
				c_file[j - 1] = c_file[j];
				c_file[j] = temp;
			}
		}
	}
}
//case 2: ���������� ������� 
void SelectSort(struct _finddata_t c_file[], int count) //������� 
{
	int i, j, a;
	struct _finddata_t temp; //�����, ����� �������� ������� 
	for (i = 0; i < count; i++)
	{
		a = i;
		temp = c_file[i];
		for (j = i + 1; j < count + 1; j++)
			if (c_file[j].size < temp.size) //<
			{
				a = j;
				temp = c_file[j];
			}
		c_file[a] = c_file[i];
		c_file[i] = temp;
	}
}
//case 3: ���������� ��������� 
void InsertSort(struct _finddata_t* c_file, int count) //��������� //�� ���������� ��� ������ //������ O(n^2)
{
	int i, j;
	struct _finddata_t temp;
	for (i = 1; i < count; i++)
	{
		temp = c_file[i];
		for (j = i - 1; j >= 0 && (c_file[j].size > temp.size); j--) //>
			c_file[j + 1] = c_file[j];
		c_file[j + 1] = temp;
	}
}

void Merge(struct _finddata_t* c_file, int left, int right); //����� MergeSort ������ Merge
//case 4: ���������� �������� 
void MergeSort(struct _finddata_t* c_file, int left, int right) //�������� //��������� ��� ������ 
{
	int mid = (left + right) / 2;
	if (left == right)
		return;
	MergeSort(c_file, left, mid);
	MergeSort(c_file, mid + 1, right);
	Merge(c_file, left, right);
}

void Merge(struct _finddata_t* c_file, int left, int right) //������� �������� 
{
	int mid = (left + right) / 2;
	int k, i = left;
	int j = mid + 1;
	struct _finddata_t* add_memory; //��� 
	right += 1;
	add_memory = (struct _finddata_t*)malloc(right * sizeof(struct _finddata_t)); //��� ������
	for (k = left; k < right; k++)
	{
		if ((i <= mid) && (j < right))
		{
			if (c_file[i].size <= c_file[j].size) ///<=
			{
				add_memory[k] = c_file[i];
				i++;
			}
			else
			{
				add_memory[k] = c_file[j];
				j++;
			}
		}
		else
		{
			if (i == mid + 1)
				for (; j < right; j++, k++)
					add_memory[k] = c_file[j];
			else
				for (; i < mid + 1; i++, k++)
					add_memory[k] = c_file[i];
		}
	}
	for (k = left; k < right; k++)
	{
		c_file[k] = add_memory[k];
	}
	free(add_memory); //������������ ��� ������
}
//case 5: ���������� ����� 
void QuickSort(struct _finddata_t* c_file, int count) //������
{
	int i = 0; //����� ������� �������� 
	int j = count - 1; //����� ���������� �������� 
	int mid = count / 2; //����� ������������ ��-�� 
	struct _finddata_t* central;
	central = c_file[mid].size; //����������� ������� 
	struct _finddata_t temp; //���
	do
	{
		while (c_file[i].size < central) //<
			i++;
		while (c_file[j].size > central) //>
			j--;
		if (i <= j)
		{
			temp = c_file[i];
			c_file[i] = c_file[j];
			c_file[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
		QuickSort(c_file, j+1);
	if (count > i)
		QuickSort(c_file + i, count - i);
}
//case 6: ���������� ����� 
int Increment(long inc[], int count); //����� ShellSort ������ Increment  
void ShellSort(struct _finddata_t* c_file, int count)
{
	struct _finddata_t temp; // �������������� ���������� ��� ������������
	long inc, i, j, seq[40];
	int s;
	s = Increment(seq, count); // ���������� ������������������ ����������
	while (s >= 0)
	{
		inc = seq[s--]; //���������� ��������� � ������������ inc[]
		for (i = inc; i < count; i++)
		{
			temp = c_file[i];
			for ((j = i - inc); ((j >= 0) && (c_file[j].size > temp.size)); (j -= inc)) //>
				c_file[j + inc] = c_file[j];
			c_file[j + inc] = temp;
		}
	}
}
int Increment(long inc[], int count)
{
	int p1, p2, p3, s;
	p1 = p2 = p3 = 1;
	s = -1;
	do {
		if (++s % 2) {
			inc[s] = 8 * p1 - 6 * p2 + 1;
		}
		else {
			inc[s] = 9 * p1 - 9 * p3 + 1;
			p2 *= 2;
			p3 *= 2;
		}
		p1 *= 2;
	} while (3 * inc[s] < count);

	return s > 0 ? --s : 0;
}
//case 7: ���������� ��������� 
void CountingSort(struct _finddata_t* c_file, long count) 
{

	int i, j, k = 0;
	int size = 0;
	int max, min, * dop;
	max = min = c_file[0].size;
	struct _finddata_t temp;

	for (i = 0; i < count; i++)
	{
		if (max < c_file[i].size)
			max = c_file[i].size;
		if (min > c_file[i].size)
			min = c_file[i].size;
	}
	size = max - min + 1;
	dop = (int*)malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
		dop[i] = 0;
	for (i = 0; i < count; i++)
		dop[c_file[i].size - min]++;
	for (i = 0; i < size; i++)
	{
		while (dop[i] > 0)
		{
			for (j = 0; j < count; j++)
			{
				if (c_file[j].size == min + i)
				{
					temp = c_file[j];
					c_file[j] = c_file[k];
					c_file[k] = temp;
					k++;
					dop[i]--;
				}
			}
		}
	}
	free(dop);
}


int main()
{
	setlocale(LC_ALL, "rus");
	struct _finddata_t c_file;
	intptr_t hFile;
	char path[200];//����
	int count = 0;
	double t1, t2; //��� ������� ���������� 
	double time_sort;
	int sort; // ����� ������� ���������� 
	int sort_way; // ����� �����������/�������� 
	struct _finddata_t* files; //���������� � ����� 
	SetConsoleCP(1251); //����� � ���� ����� ���� �������� ����� �� ������� �����
	SetConsoleOutputCP(1251); //����� � ���� ����� ���� �������� ����� �� ������� �����
	printf("����� ���������� � ��������� '�������� ��������'\n");
	printf("\n��� ��������� �������, ����� ������ ��� ������������� ����� �� �����������/�������� � ������ ��� �����. \n");
	printf("\n������� ���� �� ����������: \n");
	gets_s(path, 200);
	strcat(path, "\\*");
	printf("\n�� ����� ����: %s\n", path);
	if ((count = counter(path)) != 0)
	{
		files = (struct _finddata_t*)malloc(count * sizeof(struct _finddata_t));
		hFile = _findfirst(path, &c_file);
		printf("\n������ ������ � ��������� ����� (��� ����������): \n\n");
		printf("��� ����� %16c������\n________________________________\n", ' ');
		do
			printf("%-15.12s  %10ld ����\n", c_file.name, c_file.size);
		while (_findnext(hFile, &c_file) == 0);
		printf("\n���������� ������: %d\n\n", count);
		hFile = _findfirst(path, &files[0]);
		for (int i = 1; i < count; i++)
			_findnext(hFile, &files[i]);
		while (1)
		{
			showmenu();
			sort = menuchoice();
			if (sort == 8)
			{
				printf("�� ��������!\n");
				break;
			}
			printf("��� �� ������, ����� ���� �������������� ���� �����:\n1 - �� ����������� �������\n2 - �� �������� �������\n");
			printf("\n�������� ������ ��� �����:");
			scanf_s("%d", &sort_way);
			while ((sort_way < 1) || sort_way > 2) //�������� ������������ ��������� ������������� ������
			{
				printf("�� ����������� ����� ����� �������� ����������, �������, ����������, ��� ��� \n");
				scanf_s("%d", &sort_way);
			}
			switch (sort) //���������� 
			{
			case 1:
				t1 = omp_get_wtime();
				Bubble(files, count);
				t2 = omp_get_wtime();
				break;
			case 2:
				t1 = omp_get_wtime();
				SelectSort(files, count);
				t2 = omp_get_wtime();
				break;
			case 3:
				t1 = omp_get_wtime();
				InsertSort(files, count);
				t2 = omp_get_wtime();
				break;
			case 4:
				t1 = omp_get_wtime();
				MergeSort(files, 0, count - 1);
				t2 = omp_get_wtime();
				break;
			case 5:
				t1 = omp_get_wtime();
				QuickSort(files, count);
				t2 = omp_get_wtime();
				break;
			case 6:
				t1 = omp_get_wtime();
				ShellSort(files, count);
				t2 = omp_get_wtime();
				break;
			case 7:
				t1 = omp_get_wtime();
				CountingSort(files, count);
				t2 = omp_get_wtime();
				break;
			}
			if (sort_way == 1) //������� ����� �� ����������� 
			{
				for (int i = 0; i < count; i++)
					printf("%-12.12s  %10i ����\n", files[i].name, files[i].size);
			}
			if (sort_way == 2) //������� ����� �� �������� 
			{
				for (int i = count - 1; i >= 0; i--)
					printf("%-12.12s  %10ld ����\n", files[i].name, files[i].size);
			}
			time_sort = t2 - t1;
			printf("\n����� �� ���������� ���������:   %f ���.\n", time_sort);
		}
		free(files); //������������ ������������ ������ 
	}
	system("pause");
}