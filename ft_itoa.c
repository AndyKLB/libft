/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:47:52 by ankammer          #+#    #+#             */
/*   Updated: 2023/11/15 18:25:09 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nb(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*new;
	size_t	i;
	long	nb;

	nb = n;
	new = malloc(sizeof(char) * (len_nb(nb) + 1));
	if (!new)
		return (NULL);
	if (nb == 0)
		new[0] = '0';
	i = len_nb(nb);
	new[i] = '\0';
	i--;
	if (nb < 0)
	{
		new[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		new[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	return (new);
}
