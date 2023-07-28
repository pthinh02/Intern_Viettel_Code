#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

clock_t start;
clock_t end;
double time_used;

int main(void)
{
    start = clock();
    FILE *func_ptr;
    char my_buffer[12] = "Hello World\n";
    func_ptr = fopen("hello.txt","w");
    if (func_ptr == NULL)
    {
        printf("Open hello.txt failed.\n");
    }
    fprintf(func_ptr, my_buffer);
    fseek(func_ptr, 2, SEEK_CUR);
    fprintf(func_ptr, "I Love Viettel");
    fclose(func_ptr);
    end = clock();
    time_used = ((double) end - start) / CLOCKS_PER_SEC;
    printf("Time of using API: %f (sec)\n", time_used);
}