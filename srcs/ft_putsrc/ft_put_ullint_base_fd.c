/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ullint_base_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:52:45 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/06 11:50:15 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_ullint	convert(t_token token, va_list ap)
{
	t_ullint n;

	n = va_arg(ap, t_ullint);
	if (token.length == hh)
		n = (unsigned char)n;
	else if (token.length == h)
		n = (unsigned short int)n;
	else if (token.length == l
			|| token.specifier == 'U'
			|| token.specifier == 'O')
		n = (unsigned long int)n;
	else if (token.length == ll)
		n = (unsigned long long)n;
	else if (token.length == j)
		n = (uintmax_t)n;
	else if (token.length == z)
		n = (size_t)n;
	else if (token.length == None)
		n = (unsigned int)n;
	return (n);
}

size_t	ft_put_ullint_base_fd(const int fd, t_token token, va_list ap)
{
	t_ullint	n;
	size_t		cpt;
	int			len;
	char		*res;

	n = convert(token, ap);
	res = ft_ullitoa_base(n, token);
	len = ft_strlen(res);
	cpt = len;
	if (!ft_strchr(token.flags, '-'))
	{
		while (token.width-- > len)
		{
			write(fd, " ", 1);
			cpt++;
		}
	}
	write(fd, res, len);
	while (token.width-- > len)
	{
		write(fd, " ", 1);
		cpt++;
	}
	free(res);
	return (cpt);
}
