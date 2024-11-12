/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitran <pitran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:04:04 by pitran            #+#    #+#             */
/*   Updated: 2024/11/08 13:34:28 by pitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 100
# endif

size_t	ft_strlen(char *str);
char 	*get_next_line(int fd);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_subline(char *str, int fd);
char	*ft_complete_line(char *str);
char	*ft_remline(char *str);

#endif




