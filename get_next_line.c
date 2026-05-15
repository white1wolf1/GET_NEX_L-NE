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

static char *cleanup_on_error(char *buff, char **storage)
{
    free(buff);
    free(*storage);
    *storage = NULL;
    return (NULL);
}

static char *return_remaining_storage(char *buff, char **storage)
{
    char *tmp;

    free(buff);
    if (*storage)
    {
        tmp = *storage;
        *storage = NULL;
        return (tmp);
    }
    return (NULL);
}

static char *append_buffer(char *storage, char *buff)
{
    char *tmp;

    if (!storage)
        return (ft_strdup(buff));
    tmp = ft_strjoin(storage, buff);
    free(storage);
    return (tmp);
}

static char *extract_line(char **storage)
{
    char *tmp;
    char *line;
    int len;

    tmp = *storage;
    len = conditioned_strlen(tmp);
    *storage = ft_substr(tmp, len, ft_strlen(tmp));
    line = ft_substr(tmp, 0, len);
    free(tmp);
    return (line);
}

char *get_next_line(int fd)
{
    char *buff;
    int readed;
    static char *storage;

    if ((fd < 0) || BUFFER_SIZE < 1)
        return (NULL);
    buff = malloc(BUFFER_SIZE + 1);
    if (!buff)
        return (NULL);
    while (1)
    {
        readed = read(fd, buff, BUFFER_SIZE);
        if (readed == -1)
            return (cleanup_on_error(buff, &storage));
        if (readed == 0)
            return (return_remaining_storage(buff, &storage));
        buff[readed] = '\0';
        storage = append_buffer(storage, buff);
        if (storage && ft_strchr(storage, '\n'))
            return (extract_line(&storage));
    }
    return (NULL);
}

#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd;
    char *str;

    fd = open("main.c", O_RDONLY, 777);
    str = get_next_line(fd);
    while (str)
    {
        printf("%s", str);
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
}
