#include <stdio.h>

#pragma pack(push)
#pragma pack(1)
struct time{
    unsigned char hours;
    unsigned int minutes;
};
#pragma pack(pop)

typedef struct time time_t;

int main()
{
    time_t var;
    

    printf("The size of time is: %ld bytes\n", sizeof(var));

    return 0;
}
