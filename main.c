#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    int fd1 = open("test.txt", O_RDONLY);


    int i = 1;
    char *nl;
    nl = get_next_line(fd1);
    
    while (i < 10)
    {
        nl = get_next_line(fd1);
        printf("gnl:%s", nl);
        i++;
    }
    close (fd1);
}