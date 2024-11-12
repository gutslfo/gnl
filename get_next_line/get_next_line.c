/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitran <pitran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:03:44 by pitran            #+#    #+#             */
/*   Updated: 2024/11/11 10:17:09 by pitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char 	*get_next_line(int fd)
{
	static char	*str;
	char		*final;

	if (BUFFER_SIZE < 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		if (str)
		{
			free (str);
			str = NULL;
		}
		return (NULL);
	}
	str = ft_subline(str, fd);
	if (!str)
		return(NULL);
	final = ft_complete_line(str);
	str = ft_remline(str);
	return(final);
}
/*
int main()
{
	int fd;
	char *s;
	int i = 0;

	fd = open("loremipsum.txt", O_RDONLY);
	while (i < 15)
	{
		s = get_next_line(fd);
		printf("%d\n", fd);
		printf("Line [%02d]: %s\n", i, s);
		free(s);
		i++;
	}
	close (fd);
	return (0);
}
*/