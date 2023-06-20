#include "include.h"

FILE *file_ptr;



void cadge(FILE *ptr)
{
    fprintf(ptr,"lam on lam phuoc\n");
}
void stole(FILE *ptr)
{
    fprintf(ptr,"!!!\n");
}
void work(FILE *ptr)
{
    fprintf(ptr,"%d\n", 500000);
}

int random_integer(int minN, int maxN)
{
 return minN + rand() % (maxN + 1 - minN);
}

void input(someone_t *human)
{
    type_t type1 = random_integer(0,2);

    if(type1 == S_ANXIN)
    { 
        strcpy(human->type,"anxin");
        strcpy((*human).salary.expression,"tuytam");
        human->salary.value = 0;
        human->func_ptr= &cadge;
    }
    else if(type1 == S_ANTROM)
    {
        strcpy(human->type,"antrom");
        strcpy((*human).salary.expression,"henxui");
        human->salary.value = 0;
        human->func_ptr= &stole;
    }
    else if(type1 == S_CONGNHAN)
    {
        strcpy(human->type,"congnhan");
        strcpy((*human).salary.expression,"");
        human->salary.value = 500000;
        human->func_ptr = &work;
    }
}

void output(someone_t *human1, FILE *fptr)
{
    fprintf(fptr,"TYPE: %s\n",human1->type);
    fprintf(fptr,"EXPRESSION: %s\n", human1->salary.expression);
    fprintf(fptr,"VALUE: %d\n", human1->salary.value);
    fprintf(fptr,"FUNCTION: ");
    human1->func_ptr(fptr);
}