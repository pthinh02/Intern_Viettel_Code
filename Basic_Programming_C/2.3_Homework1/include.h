#ifndef INCLUDE_H
#define INCLUDE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#define MAX_PEOPLE 10

typedef struct
{
	char expression[10];
	uint32_t value;
}income_t;

typedef struct
{
	char type[10];
	income_t salary;
    void (*func_ptr)();
}someone_t;

typedef enum{
    S_ANXIN,
    S_ANTROM,
    S_CONGNHAN
} type_t;




int random_integer(int minN, int maxN);

void cadge(FILE *fptr);
void stole(FILE *fptr);
void work(FILE *fptr);

void input(someone_t *human);
void output(someone_t *human1, FILE *fptr);


#endif //INCLUDE.H
