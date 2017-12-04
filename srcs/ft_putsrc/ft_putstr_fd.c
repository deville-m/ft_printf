/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:48:07 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/04 23:24:06 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstr_fd(const int fd, t_token t, va_list ap)
{
	int		len;
	char	*str;
	size_t	cpt;

	str = va_arg(ap, char *);
	len = ft_strlen(str);
	len = (t.precision >= 0 && t.precision < len) ? t.precision : len;
	cpt = len;
	if (!ft_strchr(t.flags, '-'))
		while (t.width > len)
		{
			write(fd, " ", 1);
			t.width--;
			cpt++;
		}
	write(fd, str, len);
	while (t.width > len)
	{
		write(fd, " ", 1);
		t.width--;
		cpt++;
	}
	return (cpt);
}
