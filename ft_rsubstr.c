/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rsubstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:32:35 by ankammer          #+#    #+#             */
/*   Updated: 2025/01/25 22:03:52 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rsubstr(char const *s, unsigned int end, size_t len)
{
	char	*new;

	if (!s)
		return (NULL);
	if (end <= 0)
		len = 0;
	else if (len > (ft_strlen(s) - ft_strlen(s + end)))
		len = ft_strlen(s) - ft_strlen(s + end);
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	new[len + 1] = '\0';
	while ((int)len >= 0)
	{
		new[len] = s[len];
		len--;
	}
	return (new);
}
