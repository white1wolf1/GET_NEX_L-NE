/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobolev <asobolev@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:02:12 by asobolev          #+#    #+#             */
/*   Updated: 2026/05/08 09:32:49 by asobolev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *buff;
	char *buff2;
	static char *storage;
	int readed_num;
	int i;
	char *ret;
	
	i = 0;
	
	buff = malloc(BUFFER_SIZE +1);
	if (!buff)
		return(NULL);
	readed_num = read(fd,buff,BUFFER_SIZE);
	if (readed_num == -1)
		return(NULL);
	buff[readed_num] = 0; 
	while (1)
	{
		if (readed_num == -1)
		{
			free (buff);
			return(NULL);
		}
		if (ft_strchr(buff,'\n'))
			break ;
		read(fd,buff2,BUFFER_SIZE);
		buff = ft_strjoin(buff,buff2);
		
		if (readed_num == 0 )
			return(buff);		
	}
	
	while (buff[i])
	{
		if (buff[i] == '\n')	
			break;
		i++;
	}
	
	ret = ft_substr(buff,0,i);
	storage = ft_substr(buff,i+1,ft_strlen(buff[i+1]));

	return (ret);
}
int main()
{
	int fd;
	fd = open("file.txt",O_CREAT | O_RDWR | O_TRUNC ,777);
	
	get_next_line(fd);
	
	
	
}