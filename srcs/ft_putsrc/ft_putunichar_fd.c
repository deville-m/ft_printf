/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunichar_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:22:35 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/08 16:17:32 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(const int fd, unsigned int c)
{
	if (c <= 0x7F)
	{
		write(fd, &c, 1);
	}
	else if (c >= 0x80 && c <= 0x7FF)
	{
		write(fd, &c, 2);
	}
	else if (c <= 0xFFFF)
	{
		write(fd, &c, 3);
	}
	else if (c <= 0x1FFFFF)
	{
		write(fd, &c, 4);
	}
}

int		ft_putunichar_fd(const int fd, t_token token, va_list *ap)
{
	unsigned int	c;
	int				cpt;

	c = (unsigned int)va_arg(*ap, wint_t);
	cpt = (token.width > 1) ? token.width - 1 : 1;
	if (!ft_strchr(token.flags, '-'))
	{
		while (token.width-- > 1)
			write(fd, " ", 1);
	}
	print(fd, c);
	while (token.width-- > 1)
		write(fd, " ", 1);
	return (cpt);
}
