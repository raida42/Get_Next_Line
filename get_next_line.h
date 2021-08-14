/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raida <raida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:10:30 by raida             #+#    #+#             */
/*   Updated: 2021/06/30 16:33:36 by raida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>//read()//
# include <stdlib.h>//malloc() and free()//
# include <fcntl.h>//open()//
# include <stdio.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_free(char const *s1, char const *s2, int *check);
char	*ft_strndup(const char *s1, size_t len);
char	*ft_substr_free(char const *s, unsigned int start, size_t len);

#endif