#include "get_next_line.h"
#include <stdio.h>

int	conditioned_strlen(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			i++;
			break ;
		}
		if (buff[i] == '\0')
			break ;
		i++;
	}
	return (i);
}
char	*get_next_line(int fd)
{
	char *tmp;
	char		*buff;
	int			readed;
	static char	*storage;

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
			return (NULL);
		}
		if (readed == 0)
		{
			// printf("---%s\n", storage);
			// printf("---%s\n", buff);
			return(NULL);
			break ;
		}
		buff[readed] = '\0';
		if (storage && ft_strchr(storage, '\n'))
		{
			tmp = ft_substr(storage, 0, conditioned_strlen(storage));
            storage = ft_substr(storage, conditioned_strlen(storage), ft_strlen(storage));
            return(tmp);
		}
		if (!storage)
		{
		    storage = ft_strdup(buff);
		}
	    else
		{
			tmp = ft_strjoin(storage,buff);
			free(storage);
			storage = tmp;
		}
		printf("---%s\n", storage);
	}
	return (ft_substr(storage, 0, conditioned_strlen(storage)));
}

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("main.c", O_RDONLY, 777);
	str = get_next_line(fd);
	while (str)
	{
		// printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}
