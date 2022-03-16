#ifndef _GOOD_GUARD
#define _GOOD_GUARD

#include "Date.h"
#define MAX_NAME 30
typedef struct
{
	char name[MAX_NAME];
	int units;
	double perUnit;
	Date dateOfdelivery;
} Good;

#endif // _GOOD_GUARD