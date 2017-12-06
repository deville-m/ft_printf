/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:28:39 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/06 11:45:46 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_nbrlen(t_ullint n, size_t base)
{
	size_t i;

	i = 1;
	while (n >= base)
	{
		n /= base;
		i += 1;
	}
	return (i);
}

static char		*ft_ullitoa(t_ullint n, const char *base)
{
	char	*res;
	size_t	nbrlen;
	size_t	blen;

	blen = ft_strlen(base);
	nbrlen = ft_nbrlen(n, blen);
	res = (char *)malloc(sizeof(char) * nbrlen + 1);
	res[nbrlen--] = '\0';
	while (n >= blen)
	{
		res[nbrlen] = base[n % blen];
		n /= blen;
	}
	res[nbrlen] = base[n];
	return (res);
}

char			*ft_ullitoa_base(t_ullint n, t_token token)
{
	char	*res;

	res = NULL;
	if (!token.precision && !n)
		return ft_strdup("");
	else if (token.specifier == 'u' || token.specifier == 'U')
	{
		res = ft_ullitoa(n, "0123456789");
		res = base_10(res, token);
	}
	else if (token.specifier == 'o' || token.specifier == 'O')
	{
		res = ft_ullitoa(n, "01234567");
		res = base_8(res, token);
	}
	else if (token.specifier == 'x' || token.specifier == 'X')
	{
		if (token.specifier == 'x')
			res = ft_ullitoa(n, "0123456789abcdef");
		else
			res = ft_ullitoa(n, "0123456789ABCDEF");
		res = base_16(res, token);
	}
	return (res);
}
