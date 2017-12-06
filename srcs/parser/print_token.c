/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:09:16 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/06 14:17:24 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_token(const int fd, t_token token, va_list ap)
{
	if (token.specifier == 'D'
			|| token.specifier == 'd'
			|| token.specifier == 'i')
		return (ft_put_llint_fd(fd, token, ap));
	if (ft_strchr("uUoOxX", token.specifier))
		return (ft_put_ullint_base_fd(fd, token, ap));
	if (token.specifier == 'c')
		return (ft_putchar_fd(fd, token, ap));
	if (token.specifier == 's')
		return (ft_putstr_fd(fd, token, ap));
	if (token.specifier == 'p')
		return (ft_put_pointer_fd(fd, token, ap));
	if (token.specifier == 'n')
		return (ft_put_llint_fd(fd, token, ap));
	if (token.specifier == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}
