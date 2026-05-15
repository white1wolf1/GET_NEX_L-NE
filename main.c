#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
    fd = open("file.txt", O_RDWR, 777);
    if(fd < 0)
        return 1;
	char *str;
	
	str = get_next_line(fd);
	while (str)
	{
        printf("%s",str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
    return 0;
}


