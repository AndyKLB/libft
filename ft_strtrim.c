/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:19:33 by ankammer          #+#    #+#             */
/*   Updated: 2023/11/15 18:33:22 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_start(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	int		count;

	i = 0;
	while (s1[i])
	{
		j = 0;
		count = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				count = 1;
			j++;
		}
		if (!count)
			break ;
		i++;
	}
	return ((char *)s1 + i);
}

static char	*find_end(const char *s1, const char *set, char const *start)
{
	size_t	i;
	size_t	j;
	int		count;

	i = ft_strlen(s1) - 1;
	while (s1 + i >= start)
	{
		j = 0;
		count = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				count = 1;
			j++;
		}
		if (!count)
			break ;
		i--;
	}
	return ((char *)s1 + i);
}

static char	*fill_str(const char *start, const char *end)
{
	char	*new;
	size_t	i;

	new = malloc(sizeof(char) * (end - start) + 2);
	if (!new)
		return (NULL);
	i = 0;
	while ((start + i) <= end)
	{
		new[i] = start[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	start = find_start(s1, set);
	end = find_end(s1, set, start);
	new = fill_str(start, end);
	return (new);
}
