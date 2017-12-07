/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunichar_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:22:35 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/07 18:08:34 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putunichar_fd(const int fd, t_token token, va_list *ap)
{
	(void)fd;
	(void)token;
	va_arg(*ap, wint_t);
	return (0);
}
