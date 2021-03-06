/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:09:16 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/11 16:04:58 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_token(const int fd, t_token t, va_list *ap, int cpt)
{
	if (t.specifier == '%')
		return (ft_putpercent_fd(fd, t));
	else if (t.specifier == 'C' || (t.specifier == 'c' && t.length == l))
		return (ft_putunichar_fd(fd, t, ap));
	else if (t.specifier == 'c')
		return (ft_putchar_fd(fd, t, ap));
	else if (t.specifier == 'S' || (t.specifier == 's' && t.length == l))
		return (ft_putunistr_fd(fd, t, ap));
	else if (t.specifier == 's')
		return (ft_putstr_fd(fd, t, ap));
	else if (t.specifier == 'd' || t.specifier == 'D' || t.specifier == 'i')
		return (ft_putint_fd(fd, t, ap));
	else if (t.specifier == 'u' || t.specifier == 'U')
		return (ft_putuint_fd(fd, t, ap));
	else if (t.specifier == 'o' || t.specifier == 'O')
		return (ft_putoctal_fd(fd, t, ap));
	else if (t.specifier == 'x' || t.specifier == 'X')
		return (ft_puthexa_fd(fd, t, ap));
	else if (t.specifier == 'p')
		return (ft_putpointer_fd(fd, t, ap));
	else if (t.specifier == 'b' || t.specifier == 'B')
		return (ft_putbin_fd(fd, t, ap));
	else if (t.specifier == 'n')
		ft_putn_fd(cpt, ap);
	return (0);
}
