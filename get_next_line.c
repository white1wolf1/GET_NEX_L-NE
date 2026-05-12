/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobolev <asobolev@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:02:12 by asobolev          #+#    #+#             */
/*   Updated: 2026/05/12 18:00:14 by asobolev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
    char *buff;
    char *buff2;
    static char *storage;
    int readed_num1;
    int readed_num2;
    int i;
    char *ret;

    i = 0;

    if (storage)
    {
        buff = ft_strdup(storage);
        // printf("buff :: %s---\n", buff);
    }
    else
        buff = malloc(BUFFER_SIZE + 1);
        readed_num1 = read(fd, buff, BUFFER_SIZE);
        if (readed_num1 == -1)
            return (NULL);
        if (!buff)
            return (NULL);
    while (1)
    {
        if (ft_strchr(buff, '\n'))
            break;
        buff2 = malloc(BUFFER_SIZE + 1);
        if (!buff2)
            return (NULL);
            
        readed_num2 = read(fd, buff2, BUFFER_SIZE); // şuna bir bak eğer 5 sayı okusa bile -1 döndürebilir mi,???

        if (readed_num2 == -1)
        {
            free(buff2);
            break;
        }
        // printf("buff2 :: %s\n", buff2);
        buff = ft_strjoin(buff, buff2);
        if (readed_num2 == 0)
            break;
    }

    while (buff[i])
    {
        if (buff[i] == '\n' || buff[i] == '\0')
        break;
        i++;
    }

    ret = ft_substr(buff, 0, i);

    storage = ft_substr(buff, i + 1, ft_strlen(&buff[i + 1]));
    printf("buff :: %s---\n", storage);
    return (ret);
}

int main()
{
    int fd;
    fd = open("file.txt", O_RDONLY, 777);

    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    // printf("%s\n", get_next_line(fd));
}