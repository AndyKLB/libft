/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:16:25 by ankammer          #+#    #+#             */
/*   Updated: 2024/10/10 15:12:22 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	check_arg(char arg, va_list ap, int fd)
{
	int	count;

	count = 0;
	if (arg == 'c')
		count += ft_printchar(va_arg(ap, int), fd);
	else if (arg == 's')
		count += ft_printstr(va_arg(ap, char *), fd);
	else if (arg == 'd' || arg == 'i')
		count += ft_printnbr(va_arg(ap, long int), fd);
	else if (arg == 'u')
		count += ft_print_unsigned(va_arg(ap, unsigned int), fd);
	else if (arg == 'x' || arg == 'X')
		count += ft_printhex(va_arg(ap, unsigned int), arg, fd);
	else if (arg == 'p')
		count += ft_printptr(va_arg(ap, long int), fd);
	else if (arg == '%')
		count += ft_printchar('%', fd);
	return (count);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	int		count;
	va_list	ap;

	if (!format || fd <= 0)
		return (-1);
	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			count += check_arg(*(format + 1), ap, fd);
			format++;
		}
		else
		{
			count += write(fd, format, 1);
		}
		format++;
	}
	va_end(ap);
	return (count);
}
