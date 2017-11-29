/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:13:15 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/29 14:10:48 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(const int fd, int c, t_token *token)
{
	int		width;

	width = token->width;
	if (token->flags == 1)
	{
		while (width > 1)
		{
			write(fd, " ", 1);
			width--;
		}
	}
	write(fd, &c, 1);
	while (width > 1)
	{
		write (fd, " ", 1);
		width--;
	}
}
