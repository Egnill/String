#include <stdio.h>
#include "Strings.h"

int slen(const char *q, char token)
{
	int i;

	for (i = 0; q[i] != token; ++i);
	
	return i;
}

int sspn(const char *p, int u)
{
	char z[] = {'*', '?', '"', '<', '>', '|', '\0'};

	for (int i = u; p[i] != '\0'; ++i) {
		for (int j = 0; z[j] != '\0'; ++j) {
			if (p[i] == z[j]) {
				return i;
				break;
			}
		}
	}

	return 0;
}

int check_number(char *q, char token)
{
	int i = 0, o = 0;

	while (*(q + i) != token) {
		if (*(q + i) < '0' && *(q + i) > '9') {
			++o;
		}
		++i;
	}

	if (o == 0) {
		return 0;
	} else {
		return 1;
	}
}

void number(char *q, char token)
{
	int number = 0;
	int st = 1, i = 0, j = 0;

	while (*(q + i) != token) {
		++j;
		++i;
	}

	++j;

	while (*(q + i) != token) {
		number = number + *(q + i) * st;
		st *= 10;
		--i;
	}

	number += 1;

	int number_2 = number;

	while (number_2 != 0) {
		++i;
		number_2 /= 10;
	}

	++i;
	
	if (j == i) {
		while (number != 0) {
			*(q + i - 1) = (number % 10) + '0';
			number /= 10;
			--i;
		}
	} else {
		if (j > i) {
			i = slen(q, '\0');
			*(q + i + 1) = '\0';
			for ( ; i > 0; --i) {
				*(q + i) = *(q + i - 1);
			}

			while (number != 0) {
				*(q + j - 1) = (number % 10) + '0';
				number /= 10;
				--j;
			}
		}
	}
}