#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include "Good.h"
//#include <ctime>
#include <time.h>

int main() {
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("Current local time and date: %s", asctime(timeinfo));
}