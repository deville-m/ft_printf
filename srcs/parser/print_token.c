/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:09:16 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/07 10:38:18 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_token(const int fd, t_token t, va_list ap)
{
	if (t.specifier == '%')
		return (ft_putpercent_fd(fd, t));
	else if (t.specifier == 'c')
		return (ft_putchar_fd(fd, t, ap));
	else if (t.specifier == 's')
		return (ft_putstr_fd(fd, t, ap));
	else if (t.specifier == 'd' || t.specifier == 'D' || t.specifier == 'i')
		return (ft_putint_fd(fd, t, ap));
	else if (t.specifier == 'u' || t.specifier == 'U')
		return (ft_putuint_fd(fd, t, ap));
	return (0);
}
