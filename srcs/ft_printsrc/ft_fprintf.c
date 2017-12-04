/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:05:18 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/04 19:24:48 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fprintf(const int fd, const char *format, ...)
{
	size_t	res;
	va_list	ap;

	va_start(ap, format);
	res = ft_vfprintf(fd, format, ap);
	va_end(ap);
	return (res);
}
