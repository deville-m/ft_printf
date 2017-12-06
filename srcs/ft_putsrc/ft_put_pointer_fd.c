/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:52:45 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/06 12:06:43 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_put_pointer_fd(const int fd, t_token token, va_list ap)
{
	t_ullint	n;
	size_t		cpt;
	int			len;
	char		*res;

	n = (t_ullint)va_arg(ap, void *);
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
