/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:17:02 by dlanzas           #+#    #+#             */
/*   Updated: 2023/06/29 09:56:01 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*gnl_extract(char *line, size_t c);
int		get_tab(char *line);
char	*gnl_buffer(char **line, size_t c, size_t len);
char	*gnl_strjoin(char **s1, char **s2, size_t chars);
char	*gnl_bzero(char *s2, size_t chars);
char	*gnl_realloc(char **line, size_t size, size_t start);
char	*gnl_strlcpy(char *dst, const char *src, size_t start, size_t end);
size_t	gnl_strlen(const char *s);
#endif
