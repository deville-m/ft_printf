/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:13:15 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/04 23:23:44 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar_fd(const int fd, t_token token, va_list ap)
{
	int		width;
	char	c;
	size_t	cpt;

	width = token.width;
	c = va_arg(ap, int);
	cpt = 1;
	if (!ft_strchr(token.flags, '-'))
	{
		while (width > 1)
		{
			write(fd, " ", 1);
			width--;
			cpt++;
		}
	}
	write(fd, &c, 1);
	while (width > 1)
	{
		write(fd, " ", 1);
		width--;
		cpt++;
	}
	return (cpt);
}
