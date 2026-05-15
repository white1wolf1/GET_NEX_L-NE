#include "get_next_line.h"
#include <stdio.h>

int conditioned_strlen(char *buff)
{
    int i;

    i = 0;
    while (buff[i])
    {
        if (buff[i] == '\n')
        {
            i++;
            break;
        }
        i++;
    }
    return (i);
}
char *get_next_line(int fd)
{
    char *tmp;
    char *line;
    char *buff;
    int readed;
    int len;
    static char *storage;

    if ((fd < 0) || BUFFER_SIZE < 1)
        return (NULL);
    buff = malloc(BUFFER_SIZE + 1);
    if (!buff)
        return (NULL);
    readed = 1;
    while (1)
    {
        readed = read(fd, buff, BUFFER_SIZE);
        if (readed == -1)
        {
        free(buff);
        free(storage);      
        storage = NULL;
        return (NULL);
        }
        if (readed == 0)
        {
            free(buff);
            if (storage)
            {
                tmp = storage;
                storage = NULL;
                return tmp;
            }
            return (NULL);
        }
        buff[readed] = '\0';
        if (!storage)
        {
            storage = ft_strdup(buff);
        }
        else
        {
            tmp = ft_strjoin(storage, buff);
            free(storage);
            storage = tmp;
        }
        if (storage && ft_strchr(storage, '\n'))
        {
            tmp = storage;
            len = conditioned_strlen(tmp);
            storage = ft_substr(tmp, len, ft_strlen(tmp));
            line = ft_substr(tmp, 0, len);
            free(tmp);
            return line;
        }
    }
    return (NULL);
}

#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd;
    char *str;

    fd = open("file.txt", O_RDONLY, 777);
    str = get_next_line(fd);
    while (str)
    {
        printf("%s", str);
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
}
