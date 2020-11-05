﻿#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<locale.h>
#define SIZE 100
#define _CRT_SECURE_NO_WARNINGS
int tov[4];

void PrintTovar(int* tov, int* C, int* b, char* D, int *a) //информация о отсканированном продукте //сколько раз отсканирован один продукт 
{
	int k = 0;
	for (int i = 0; i < 4; i++)
		if (C[i] == tov[i])
			k++;
	if (k == 4)
	{
		*b+=1;
		printf("%s %3d шт. скидка на товар:%d%%\n", D, *b, a);
	}
	return;
}
void chek1(int b, int l, int h, char* D, int* prise_itog, int* prise_itog_sale) //чек
{
	if (b != 0)
	{
		int prise= b * l;
		int prise_sale = b *(l- l * h / 100);
		printf("%50s %10d*%d=%1dруб\n                      скидка: %d руб(%d%%)\n", D, b, (l - l * h / 100), prise_sale, (prise-prise_sale), h);
		*prise_itog += prise;
		*prise_itog_sale+= prise_sale;
		return;
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	int notebook96[4] = { 2,3,8,9 }; //120 рублей 
	int notebook9 = 120;
	int blok9 = 0;
	char Arr1[SIZE] = "2389 Тетрадка 96 листов 120 руб./шт.";
	int sale1 = 5;

	int notebook48[4] = { 1,8,5,0 }; //100 рублей 
	int notebook4 = 100;
	int blok4 = 0;
	char Arr2[SIZE] = "1850 Тетрадка 48 листов 100 руб./шт.";
	int sale2 = 10;

	int penblue[4] = { 3,2,5,1 }; //80 рублей
	int penb = 80;
	int rychkab = 0;
	char Arr3[SIZE] = "3251 Синяя ручка 80 руб./шт.";
	int sale3 = 15;

	int penblack[4] = { 6,7,1,4 }; //90 рублей 
	int pen = 90;
	int rychka = 0;
	char Arr4[SIZE] = "6751 Чёрная ручка 90 руб./шт.";
	int sale4 = 5;

	int pencils[4] = { 9,6,6,2 }; //150 рублей
	int pencl = 150;
	int pencil = 0;
	char Arr5[SIZE] = "9662 Набор карандашей 150 руб./шт.";
	int sale5 = 20;

	int eraser[4] = { 5,7,3,9 }; //20 рублей 
	int eras = 20;
	int er = 0;
	char Arr6[SIZE] = "5739 Ластик 20 руб./шт.";
	int sale6 = 0;

	int penscolor[4] = { 1,6,1,7 }; //160 рублей 
	int pencol = 160;
	int penc = 0;
	char Arr7[SIZE] = "1617 Набор цветных ручек 160 руб./шт.";
	int sale7 = 20;

	int stickers[4] = { 2,8,6,4 }; //100 рублей
	int sticker = 100;
	int stick = 0;
	char Arr8[SIZE] = "2864 Набор стикеров 100 руб./шт.";
	int sale8 = 15;

	int line15[4] = { 5,8,2,4 }; //40 рублей 
	int line1 = 40;
	int line = 0;
	char Arr9[SIZE] = "5824 Линейка 15 см. 40 руб./шт.";
	int sale9 = 0;

	int line20[4] = { 8,7,0,3 }; //50 рублей 
	int line2 = 50;
	int lin = 0;
	char Arr10[SIZE] = "8703 Линейка 20 см. 50 руб./шт.";
	int sale10 = 5;

	int prise_itog=0;
	int prise_itog_sale=0;
	int tovar = 0;
	printf("Введите штрихкод товара ");
	scanf_s("%d", &tovar);
	while (tovar != 0) //сканируем товары
	{
		system("cls");
		for (int i = 4 - 1; i >= 0; i--) //переводит штрихкод в массив 
		{
			int m = tovar % 10;
			tovar = tovar / 10;
			tov[i] = m;
		}
		PrintTovar(tov, notebook96, &blok9, Arr1, sale1);
		PrintTovar(tov, notebook48, &blok4, Arr2, sale2);
		PrintTovar(tov, penblue, &rychkab, Arr3, sale3);
		PrintTovar(tov, penblack, &rychka, Arr4, sale4);
		PrintTovar(tov, pencils, &pencil, Arr5, sale5);
		PrintTovar(tov, eraser, &er, Arr6, sale6);
		PrintTovar(tov, penscolor, &penc, Arr7, sale7);
		PrintTovar(tov, stickers, &stick, Arr8, sale8);
		PrintTovar(tov, line15, &line, Arr9, sale9);
		PrintTovar(tov, line20, &lin, Arr10, sale10);

		printf("Введите штрихкод товара ");
		scanf_s("%d", &tovar);
	}
	system("cls");
	if (tovar == 0)
	{
		printf("                      ЧЕК\n");
		chek1(blok9, notebook9, sale1, Arr1, &prise_itog, &prise_itog_sale); 
		chek1(blok4, notebook4, sale2, Arr2, &prise_itog, &prise_itog_sale);
		chek1(rychkab, penb, sale3, Arr3, &prise_itog, &prise_itog_sale);
		chek1(rychka, pen, sale4, Arr4, &prise_itog, &prise_itog_sale);
		chek1(pencil, pencl, sale5, Arr5, &prise_itog, &prise_itog_sale);
		chek1(er, eras, sale6, Arr6, &prise_itog, &prise_itog_sale);
		chek1(penc, pencol, sale7, Arr7, &prise_itog, &prise_itog_sale);
		chek1(stick, sticker, sale8, Arr8, &prise_itog, &prise_itog_sale);
		chek1(line, line1, sale9, Arr9, &prise_itog, &prise_itog_sale);
		chek1(lin, line2, sale10, Arr10, &prise_itog, &prise_itog_sale);

		printf("\nСумма без скидки: %48d", prise_itog);
		printf("\nСумма с учётом скидки: %43d", prise_itog_sale);
		printf("\nИтого скидка по чеку: %43d", (prise_itog - prise_itog_sale));
		printf("\n\nИТОГ: %d\n", prise_itog_sale);
	}
	system("pause");
}
