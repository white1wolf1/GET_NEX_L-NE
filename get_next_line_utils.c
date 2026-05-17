/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobolev <asobolev@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:02:29 by asobolev          #+#    #+#             */
/*   Updated: 2026/05/17 03:32:33 by asobolev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*p = s;

	while (*p++)
		;
	return (p - s - 1);
}

char	*ft_strdup(const char *s)
{
	char	*start;
	char	*ptr;

	ptr = malloc(ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	start = ptr;
	while (*s)
	{
		*ptr = *s;
		ptr++;
		s++;
	}
	*ptr = '\0';
	return (start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*a;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	a = malloc((len + 1) * sizeof(char));
	if (!a)
		return (NULL);
	while (i < len)
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len;
	char	*strart;

	ptr = 0;
	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	strart = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (strart);
}
