#ifndef H_WORK
#define H_WORK

enum {
	MAX_PATH = 260
};

char *input(char *q);
int check(const char *q, char sistem);
void process(char *q);
void output(char *q, int l, int token, char sistem);
void number_switch(char *q, char sistem);

#endif