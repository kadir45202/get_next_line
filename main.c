
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(void)
{
	char *line;
	int fd;
	
	fd = open("test1", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
}