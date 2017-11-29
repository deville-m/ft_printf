/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 17:10:16 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/29 18:21:52 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_imaxtoa(intmax_t n)
{
	size_t	nbrlen;
	size_t	i;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nbrlen = ft_nbrlen(n);
	i = nbrlen - 1;
	res = (char *)malloc(sizeof(char) * (nbrlen + 1));
	if (!res)
		return (NULL);
	while (n <= -10 || n >= 10)
	{
		res[i] = (n < 0) ? (-n % 10 + '0') : (n % 10 + '0');
		n /= 10;
		i--;
	}
	res[i--] = (n < 0) ? (-n + '0') : (n + '0');
	if (i == 0)
		res[i] = ('-');
	res[nbrlen] = '\0';
	return (res);
}
