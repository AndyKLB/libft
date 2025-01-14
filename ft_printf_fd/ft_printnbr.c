/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:20:06 by ankammer          #+#    #+#             */
/*   Updated: 2024/10/10 15:12:43 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printnbr(int nb, int fd)
{
	int		count;
	long	nbr;

	nbr = nb;
	count = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		count += write(fd, "-", 1);
	}
	if (nbr >= 10)
	{
		count += ft_printnbr(nbr / 10, fd);
		count += ft_printnbr(nbr % 10, fd);
	}
	else
	{
		count += ft_printchar(nbr + 48, fd);
	}
	return (count);
}
