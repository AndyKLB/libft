/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:43:50 by ankammer          #+#    #+#             */
/*   Updated: 2024/10/10 15:12:47 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printptr(unsigned long ptr, int fd)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (write(fd, "(nil)", 5));
	count += ft_printstr("0x", fd);
	count += ft_printhex(ptr, 'x', fd);
	return (count);
}
