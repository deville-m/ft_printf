/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:33:17 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/29 14:10:23 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vfprintf(const int fd, const char *format, va_list ap)
{
	t_token token;
	char wow[] = "coucou les gens";

	token.flags = 1;
	token.width = 1;
	token.precision = 1;
	token.specifier = 's';

	ft_putstr_fd(1, "abcdef\n", &token)
	return (1);
}
