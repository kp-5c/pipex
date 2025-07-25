/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:08:18 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/09 13:13:42 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*dest;
	size_t	len;
	size_t	i;

	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	len = 0;
	while (s2[len])
		dest[i++] = s2[len++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}

char	*ft_strchr(const char *string, int c)
{
	int	i;

	i = 0;
	if (!string)
		return (NULL);
	while (string[i] != '\0')
	{
		if ((unsigned char)string[i] == (unsigned char)c)
			return ((char *)&(string[i]));
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&(string[i]));
	return (NULL);
}

void	*ft_calloc(size_t ecount, size_t size)
{
	unsigned char	*tab;
	size_t			total;
	size_t			i;

	total = ecount * size;
	tab = malloc(ecount * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < total)
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}

char	*ft_error(char *str)
{
	free(str);
	return (NULL);
}
