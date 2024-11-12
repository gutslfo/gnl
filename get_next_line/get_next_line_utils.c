/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitran <pitran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:04:19 by pitran            #+#    #+#             */
/*   Updated: 2024/11/11 10:42:13 by pitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	if (!str)
		return 0;
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
		i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*final;

	if (!s1)
	{
		s1 = (char *)malloc(1);  
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
	{
		free(s1);    
		return (NULL);
	}
	final = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);  
	if (!final)
	{
		return (NULL);
	}
	i = -1;
	j = -1;
	while (s1[++i])
		final[i] = s1[i];
	while (s2[++j])
		final[i + j] = s2[j];
	final[i + j] = '\0';
	return (final);
}

char	*ft_subline(char *str, int fd)
{
	ssize_t	text;
	char	*content;
	char	*temp;

	text = 1;
	content = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!content)
		return (NULL);

	while (!ft_strchr(str, '\n') && text > 0)
	{
		text = read(fd, content, BUFFER_SIZE);
		if (text == -1)
		{
			free(content);
			return (NULL);
		}
		content[text] = '\0';
		temp = str;
		str = ft_strjoin(str, content);
		if (!str)
		{
			free(content);
			free(temp);
			return (NULL);
		}
		free(temp);
	}

	free(content);
	return (str);
}

char	*ft_complete_line(char *str)
{
	char	*xtr;
	int		i;

	i = 0;
	if(!str || str[i] == 0)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	xtr = (char *)malloc(sizeof(char) * (i + 2));
	if(!xtr)
		return (NULL);\
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		xtr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		xtr[i] = '\n';
		i++;
	}
	xtr[i] = '\0';
	return (xtr);
}

char	*ft_remline(char *str)
{
	char	*rem;
	int		i;
	int		j;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	rem = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1 ));
	if (!rem)
		return (NULL);
	i++;
	j = 0;
	while(str[i])
		rem[j++] = str[i++];
	rem[j] = '\0';
	free(str);
	return (rem);
}



