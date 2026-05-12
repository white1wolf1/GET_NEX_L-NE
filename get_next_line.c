/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobolev <asobolev@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:02:12 by asobolev          #+#    #+#             */
/*   Updated: 2026/05/12 18:32:51 by asobolev         ###   ########.fr       */
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
    char *ret;

    if (storage)
        buff = ft_strdup(storage);
    else
    {
        buff = malloc(BUFFER_SIZE + 1);
        readed_num1 = read(fd, buff, BUFFER_SIZE);
        if (readed_num1 == -1 || !buff)
            return (NULL);
    }
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
        buff = ft_strjoin(buff, buff2);
        if (readed_num2 == 0)
            break;
    }

    ret = ft_substr(buff, 0, cakmastrlen(buff));
    storage = ft_substr(buff, cakmastrlen(buff) + 1, ft_strlen(&buff[cakmastrlen(buff) + 1]));
    return (ret);
}

int cakmastrlen(char *buff )
{
    int i;
    
    while (buff[i])
    {
        if (buff[i] == '\n' || buff[i] == '\0')
            break;
        i++;
    }
    return(i);
}