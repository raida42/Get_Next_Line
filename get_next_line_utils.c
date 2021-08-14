/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raida <raida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:10:34 by raida             #+#    #+#             */
/*   Updated: 2021/06/30 17:48:03 by raida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_free(char const *s1, char const *s2, int *check)
{
	char	*new;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new)
	{
		*check = -1;
		return (NULL);
	}
	i = 0;
	j = 0;
	while (len1--)
		new[i++] = s1[j++];
	j = 0;
	while (len2--)
		new[i++] = s2[j++];
	new[i] = '\0';
	free((char *)s1);
	return (new);
}

char	*ft_strndup(const char *s, size_t len)
{
	char	*p;
	size_t	i;

	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_substr_free(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (start <= i && j < len)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = '\0';
	free((char *)s);
	return (sub);
}
