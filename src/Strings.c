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

int check_number(char *q, int i_2, char token)
{
	int i = 1, o = 0;

	while (*(q + i_2 + i) != token) {
		if (*(q + i_2 + i) >= '0' && *(q + i_2 + i) <= '9') {
			++o;
		}
		++i;
	}

	if (o == i - 1) {
		return 0;
	} else {
		return 1;
	}
}

void number(char *q_2, int i_2, char token)
{
	int number = 0;
	int st = 1, i = 1, j = 0;
	char *q;
	q = q_2;

	while (*(q + i_2 + i) != token) {
		++j;
		++i;
	}

	--i;

	while (*(q + i_2 + i) != token) {
		number = number + (*(q + i_2 + i) - '0') * st;
		st *= 10;
		--i;
	}

	i = 0;
	number += 1;

	int j_2 = 0;
	int number_2 = number;

	while (number_2 != 0) {
		++j_2;
		number_2 /= 10;
	}
	
	if (j == j_2) {
		while (number != 0) {
			*(q + i_2 + j_2) = (number % 10) + '0';
			number /= 10;
			--j_2;
		}
		q_2 = q;
		printf("%s\n", q);
	} else {
		if (j_2 > j) {
			i = slen(q + i_2, '\0');
			*(q	+ i_2 + i + 1) = '\0';
			for ( ; i > 0; --i) {
				*(q + i_2 + i) = *(q + i_2 + i - 1);
			}
			while (number != 0) {
				*(q + i_2 + j_2) = (number % 10) + '0';
				number /= 10;
				--j_2;
			}
			q_2 = q;
			printf("%s\n", q);
		}
	}
}