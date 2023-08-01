#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <errno.h>

// FIFO lib
#include <sys/stat.h>
#include <sys/types.h>
// system call lib
#include <fcntl.h>


// p1[0] = read()
// p1[1] = write()

int main()
{
    _execlp("ping", "ping", "google.com" , NULL);



    return 0;
}