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

int check(const char *q)
{	
	int z;

	if (slen(q, '\0') > MAX_PATH) {
		printf("Max!!\n");
		return 1;
	} else {	
		z = sspn(q);
		if (z != 0) {
			printf("ERROR, index %d\n", z + 1);
			return 1;
		}
	}
	
	return 0;
}

void process(char *q)
{
	q = input(q);

	char sistem;
	int i = 1;

	int r = check(q);

	if (r == 0) {

		if (*q == '/') {
			sistem = 'l';
		
		} else {
			while (*(q + i) != 92) {
				if (*(q + 0) >= 'A' && *(q + 0) <= 'Z' && ((*(q + i) >= 'a' && *(q + i) <= 'z') || (*(q + i) >= 'A' && *(q + i) <= 'Z') || (*(q + i) == ':'))) {
					sistem = 'w';
				}
				++i;
			}
		}

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
//printf("+\n");
	if (sistem == 'l') {
		while (*(q + i) != '\0') {
			if (*(q + i) == '/'){
				if (check_number(q, i, '/') == 0) {
					number(q, i, '/');
				}
			}
			++i;
		}
	}
	
	if (sistem == 'w') {
		//printf("+\n");
		while (*(q + i) != '\0') {
			if (*(q + i) == 92){
				if (check_number(q, i, 92) == 0) {
					number(q, i, 92);
				}
			}
			++i;
		}
	}
}