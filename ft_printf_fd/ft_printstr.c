/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankammer <ankammer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:16:09 by ankammer          #+#    #+#             */
/*   Updated: 2024/10/10 15:13:13 by ankammer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printstr(char *str, int fd)
{
	if (!str)
		return (write(fd, "(null)", 6));
	else
		return (write(fd, str, ft_strlen(str)));
}
