#ifndef H_WORK
#define H_WORK

enum {
	MAX_PATH = 260
};

char *input(char *q);
int check(const char *q, char sistem);
void process(char *q);
void output(const char *q, int l, int token, char sistem);
char *number_switch(char *q, char sistem);

#endif