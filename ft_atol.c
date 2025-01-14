/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:51:11 by ankammer          #+#    #+#             */
/*   Updated: 2023/11/06 11:54:24 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"


char	*is_valid_input(char *str)
{
	int	i;
	int	len;
	int	j;

	len = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		return (NULL);
	if (!ft_isdigit(str[i]))
		return (NULL);
	j = i;
	while (ft_isdigit(str[i]) && str[i])
	{
		i++;
		len++;
	}
	if (len > 10)
		return (NULL);
	return (str + j);
}

long	ft_atol(char *str)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	str = is_valid_input(str);
	if (str)
	{
		while (ft_isdigit(str[i]) && str[i])
		{
			res = res * 10 + (str[i] - 48);
			i++;
		}
		if (res > INT_MAX)
			return (0);
		return (res);
	}
	return (0);
}