/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:51:53 by ankammer          #+#    #+#             */
/*   Updated: 2024/10/10 15:12:40 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printhex(unsigned long nbr, char arg, int fd)
{
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_printhex(nbr / 16, arg, fd);
		count += ft_printhex(nbr % 16, arg, fd);
	}
	else if (arg == 'x')
	{
		if (nbr < 10)
			count += ft_printchar(nbr + '0', fd);
		else
			count += ft_printchar(nbr - 10 + 'a', fd);
	}
	else if (arg == 'X')
	{
		if (nbr < 10)
			count += ft_printchar(nbr + '0', fd);
		else
			count += ft_printchar(nbr - 10 + 'A', fd);
	}
	return (count);
}
