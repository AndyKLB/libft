/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:19:23 by ankammer          #+#    #+#             */
/*   Updated: 2024/10/10 15:12:31 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_unsigned(unsigned int nbr, int fd)
{
	int	count;

	count = 0;
	if (nbr >= 10)
	{
		count += ft_print_unsigned(nbr / 10, fd);
		count += ft_print_unsigned(nbr % 10, fd);
	}
	else
	{
		count += ft_printchar(nbr + 48, fd);
	}
	return (count);
}
