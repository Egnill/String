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
	}
	
	if (sistem == 'w') {
		z = sspn(q, 2);
		if (z != 0) {
			printf("ERROR, index %d", z);
			return 1;
		}
	}

	if (sistem == 'l') {
		z = sspn(q, 0);
		if (z != 0) {
			printf("ERROR, index %d", z);
			return 1;
		}
	}

	return 0;
}

void process(char *q)
{
	q = input(q);

	//if (q != NULL) {
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
		q = number_switch(q, sistem);
		
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

void output(const char *q, int l, int token, char sistem)
{
	if (sistem == 'l') {
		printf("OS: Linux\n");
	}

	if (sistem == 'w') {
		printf("OS: Windows\n");
	}

	printf("file name: %s\n", (q + token + 1));
	printf("file name lenth: %d\n", l);

	printf("updated path: %s\n", q);
}

char *number_switch(char *q, char sistem)
{
	//int i = 0;

	if (sistem == 'l') {
		while (*q != '\0') {
			if (*q == '/'){
				if (check_number(q + 1, '/') == 0) {
					number(q + 1, '/');
				}
			}
			++q;
		}
	} else {
		if (sistem == 'w') {
			while (*q != '\0') {
				if (*q == 92){
					if (check_number(q + 1, 92) == 0) {
						number(q + 1, 92);
					}
				}
				++q;
			}
		}
	}

	return q;
}