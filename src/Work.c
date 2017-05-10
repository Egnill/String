#include <stdio.h>
#include <stdlib.h>
#include "Work.h"
#include "Strings.h"

char *input(char *q)
{
	int i = 0;
    printf("Input string: ");
    while(scanf("%c", &q[i]) == 1 && i < MAX_PATH - 1) {
        if(q[i] == '\n') {
            q[i] = '\0';
            break;
        } else {
            i++;
        }
	}

	return q;
}

int check(const char *q, char sistem)
{	
	int z;

	if (slen(q, '\0') > MAX_PATH) {
		printf("Max!!\n");
		return 1;
	} else {	
		if (sistem == 'w') {
			z = sspn(q, 2);
			if (z != 0) {
				printf("ERROR, index %d\n", z);
				return 1;
			}
		}

		if (sistem == 'l') {
			z = sspn(q, 0);
			if (z != 0) {
				printf("ERROR, index %d\n", z);
				return 1;
			}
		}
	}
	
	return 0;
}

void process(char *q)
{
	q = input(q);

	char sistem;

	if (*q == '/') {
		sistem = 'l';
	
	} else {
		if (*q >= 'A' && *q <= 'Z') {
			sistem = 'w';
		
		}
	}

	int r = check(q, sistem);

	if (r == 0) {
		number_switch(q, sistem);

		int token = slen(q, '\0');

		if (sistem == 'l') {
			while (q[token] != '/') {
				--token;
			}
		} else {
			if (sistem == 'w') {
				while (q[token] != 92) {
					--token;
				}
			}
		}

		int l = slen(&q[token], '\0') - 1;
		
		output(q, l, token, sistem);
	} else {
		printf("ERROR!\n");
	}
}

void output(char *q, int l, int token, char sistem)
{
	char *q_2;
	q_2 = q;

	if (sistem == 'l') {
		printf("OS: Linux\n");
	}

	if (sistem == 'w') {
		printf("OS: Windows\n");
	}

	printf("file name: %s\n", (q + token + 1));
	printf("file name lenth: %d\n", l);

	printf("updated path: %s\n", q_2);
}

void number_switch(char *q, char sistem)
{
	int i = 0;

	if (sistem == 'l') {
		while (*(q + i) != '\0') {
			if (*(q + i) == '/'){
				if (check_number(q + i, '/') == 0) {
					number(q, i, '/');
				}
			}
			++i;
		}
	} else {
		if (sistem == 'w') {
			while (*(q + i) != '\0') {
				if (*(q + i) == 92){
					if (check_number(q + i, 92) == 0) {
						number(q, i, 92);
					}
				}
				++i;
			}
		}
	}
}