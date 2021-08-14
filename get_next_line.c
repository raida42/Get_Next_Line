/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raida <raida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:03:39 by raida             #+#    #+#             */
/*   Updated: 2021/05/04 10:09:04y raida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_strage(char *strage, int *check)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!strage)
		return (NULL);
	while (strage[i] && strage[i] != '\n')
		i++;
	if (!strage[i])
	{
		free(strage);
		return (NULL);
	}
	i++;
	p = ft_substr_free(strage, i, ft_strlen(strage) - i);
	if (!p)
		*check = -1;
	return (p);
}

char	*get_line(char *strage, int *check)
{
	size_t	i;
	char	*p;

	if (!strage)
		return (NULL);
	i = 0;
	while (strage[i] && strage[i] != '\n')
		i++;
	p = ft_strndup(strage, i);
	if (!p)
		*check = -1;
	return (p);
}

int	check_return(ssize_t byte, int *check)
{
	if (*check == -1)
		return (-1);
	if (byte == 0)
		return (0);
	return (1);
}

int	get_line_and_strage(char **strage, char **line, ssize_t byte, int *check)
{
	*line = get_line(*strage, check);
	*strage = get_strage(*strage, check);
	return (check_return(byte, check));
}

int	get_next_line(int fd, char **line)
{
	static char	*strage;
	char		*buf;
	ssize_t		byte;
	int			check;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	byte = 1;
	check = 0;
	while (!ft_strchr(strage, '\n') && byte != 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buf);
			return (-1);
		}
		buf[byte] = '\0';
		strage = ft_strjoin_free(strage, buf, &check);
	}
	free(buf);
	return (get_line_and_strage(&strage, *(&line), byte, &check));
}
