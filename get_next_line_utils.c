/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:21:48 by mbaj              #+#    #+#             */
/*   Updated: 2024/05/27 18:21:52 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*d;
	char	*h;
	size_t	i;

	i = 0;
	h = (char *)s;
	d = (char *)malloc((ft_strlen(h) + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != (char)c)
			i++;
		else
			return ((char *)(s + i));
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	len_s1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen((char *)s1);
	s = (char *)malloc((len_s1 + ft_strlen((char *)s2) + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	while (i < len_s1)
	{
		s[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen((char *)s2))
	{
		s[len_s1 + i] = s2[i];
		i++;
	}
	s[len_s1 + ft_strlen((char *)s2)] = '\0';
	return (free((char *)s1), s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*sub;
	size_t	i;

	if (s == NULL)
		return (NULL);
	size = ft_strlen((char *)s);
	if (start > size)
		return (ft_strdup(""));
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (size < start || sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
