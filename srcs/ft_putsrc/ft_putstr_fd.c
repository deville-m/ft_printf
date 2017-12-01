/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:48:07 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/01 10:50:45 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(const int fd, const char *str, t_token *token)
{
	int		len;
	int		width;
	int		precision;

	width = token->width;
	precision = token->precision;
	len = ft_strlen(str);
	len = (precision >= 0 && precision < len) ? precision : len;
	if (!ft_strchr(token->flags, '-'))
		while (width > len)
		{
			write(fd, " ", 1);
			width--;
		}
	write(fd, str, len);
	while (width > len)
	{
		write(fd, " ", 1);
		width--;
	}
}
