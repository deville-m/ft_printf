/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 17:10:16 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/01 19:54:55 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*zero_pad(llint n, int nlen, t_token *token)
{
	char	*res;
	int		plus;

	plus = ft_strchr(token->flags, '+') ? 1 : 0;
	if (plus)
		nlen += 1;
	if (token->width > nlen)
		nlen = token->width;
	if (!(res = (char *)malloc(sizeof(char) * (nlen + 1))))
		return (NULL);
	res[nlen--] = '\0';
	while (nlen)
	{
		res[nlen--] = (n < 0) ? (-n % 10 + '0') : (n % 10 + '0');
		n /= 10;
	}
	if (plus || n < 0)
		res[nlen] = (n < 0) ? '-' : '+';
	else
		res[nlen] = n + '0';
	return (res);
}

static char		*space_case(llint n, int nlen, t_token *token)
{
	char	*res;
	int		space;

	space = ft_strchr(token->flags, ' ') ? 1 : 0;
	if (space)
		nlen += 1;
	if (token->precision > nlen)
		nlen = token->precision;
	if (!(res = (char *)malloc(sizeof(char) * (nlen + 1))))
		return (NULL);
	res[nlen--] = '\0';
	while (nlen)
	{
		res[nlen--] = (n < 0) ? (-n % 10 + '0') : (n % 10 + '0');
		n /= 10;
	}
	if (space || n < 0)
		res[nlen] = (n < 0) ? '-' : ' ';
	else
		res[nlen] = n + '0';
	return (res);
}
static char		*plus_case(llint n, int nlen, t_token *token)
{
	char	*res;
	int		plus;

	plus = ft_strchr(token->flags, '+') ? 1 : 0;
	if (plus)
		nlen += 1;
	if (token->precision > nlen)
		nlen = token->precision;
	if (!(res = (char *)malloc(sizeof(char) * (nlen + 1))))
		return (NULL);
	res[nlen--] = '\0';
	while (nlen)
	{
		res[nlen--] = (n < 0) ? (-n % 10 + '0') : (n % 10 + '0');
		n /= 10;
	}
	if (plus || n < 0)
		res[nlen] = (n < 0) ? '-' : '+';
	else
		res[nlen] = n + '0';
	return (res);
}

static size_t	ft_nbrlen(llint nbr)
{
	size_t i;

	i = 1;
	while (nbr >= 10 || nbr <= -10)
	{
		nbr /= 10;
		i++;
	}
	return ((nbr < 0) ? i + 1 : i);
}

char			*ft_llitoa(llint n, t_token *token)
{
	int		nbrlen;

	if (n == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (n == 0 && ft_strchr(token->flags, '+') && token->precision == 0)
		return (ft_strdup("+"));
	nbrlen = ft_nbrlen(n);
	if (ft_strchr(token->flags, '0') && !ft_strchr(token->flags, '-')
		&& token->precision == 1)
		return (zero_pad(n, nbrlen, token));
	if (ft_strchr(token->flags, '+'))
		return (plus_case(n, nbrlen, token));
	return (space_case(n , nbrlen, token));
}
