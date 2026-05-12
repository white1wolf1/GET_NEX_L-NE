/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobolev <asobolev@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:02:41 by asobolev          #+#    #+#             */
/*   Updated: 2026/05/12 18:12:17 by asobolev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LİNE_H
# define GET_NEXT_LİNE_H
#define BUFFER_SIZE 1
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


char	*ft_substr(char const *s, unsigned int start, size_t len);
char *get_next_line(int fd);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);





#endif