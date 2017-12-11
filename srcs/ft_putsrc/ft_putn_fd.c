/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putn_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:05:48 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/11 16:05:09 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putn_fd(int n, va_list *ap)
{
	int *res;

	res = va_arg(*ap, int *);
	if (!res)
		return ;
	*res = n;
}
