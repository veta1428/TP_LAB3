#define _CRT_SECURE_NO_WARNINGS
#include "Manager.h"
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int compare(Good first, Good second)
{
	//Good* gptr1 = ptr1;
	//Good* gptr2 = ptr2;

	if (first.perUnit > second.perUnit)
	{
		return 1;
	}
	return -1;
}

Good* InputGata(int n)
{
	Good* goods = malloc(n * sizeof(Good));
	char forNumber[16];

	for (int i = 0; i < n; i++)
	{
		Good good;
		printf("Good %d", i);

		//Good name
		printf("Enter good name (less than %d): ", MAX_NAME);
		fgets(good.name, MAX_NAME, stdin);

		//Units
		printf("Enter units number: ");
		fgets(forNumber, 16, stdin);
		int units = strtol(forNumber, NULL, 10);
		
		if (units < 0 || units == 0 || units == LONG_MAX || units == LONG_MIN)
		{
			printf("Bad input. Operation failed.");
		}

		good.units = units;

		//Unit price
		printf("Enter price per unit: ");
		fgets(forNumber, 16, stdin);
		double pricePerUnit = strtod(forNumber, NULL);

		if (pricePerUnit < 0 || pricePerUnit == 0)
		{
			printf("Bad input. Operation failed.");
		}
		good.perUnit = pricePerUnit;

		//Days
		printf("Enter day: ");
		int days = strtol(forNumber, NULL, 10);

		if (days < 0 || days == 0 || days == LONG_MAX || days == LONG_MIN || !(days >= 1 && days <=31))
		{
			printf("Bad input. Operation failed.");
		}
		good.dateOfdelivery.day = days;

		//Month
		printf("Enter month: ");
		int month = strtol(forNumber, NULL, 10);

		if (month < 0 || month == 0 || month == LONG_MAX || month == LONG_MIN || !(month >= 1 && month <= 12))
		{
			printf("Bad input. Operation failed.");
		}
		good.dateOfdelivery.month = month;

		//Year
		printf("Enter month: ");
		int year = strtol(forNumber, NULL, 10);

		if (year < 0 || year == 0 || year == LONG_MAX || year == LONG_MIN || !(year >= 1950 && year <= 2022))
		{
			printf("Bad input. Operation failed.");
		}
		good.dateOfdelivery.year = year;
		
	}
	return goods;
}

double CalculateAverage(Good* goods, int n)
{
	double sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		sum += goods[i].perUnit * (int)goods[i].units;
	}
	return sum / n;
}

void SortByPricePerUnit(Good* goods, int n)
{
	qsort(goods, n, sizeof(Good), compare);
}

long long TimeNow() 
{
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	return timeinfo->tm_year * 365 + timeinfo->tm_mon * 30 + timeinfo->tm_wday;
}

void PrintOlderThan(Good* goods, int n, int month)
{
	long long timeNow = TimeNow();

}
