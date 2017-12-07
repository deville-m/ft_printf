/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:33:17 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/07 14:58:10 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vfprintf(const int fd, const char *format, va_list ap)
{
	size_t	i;
	size_t	cpt;
	t_token	token;

	if (!format)
		return (-1);
	i = 0;
	cpt = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += 1;
			token = parse_token(format, &i, ap);
			cpt += print_token(fd, token, ap);
		}
		else
		{
			write(1, format + i++, 1);
			cpt += 1;
		}
	}
	return (cpt);
}
