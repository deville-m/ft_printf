/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 09:01:25 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/06 11:52:35 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*zero_pad(char *str, int len, t_token token)
{
	char	*res;
	int		tmp;
	int		prefix;

	prefix = ft_strchr(token.flags, '#') ? 1 : 0;
	tmp = (prefix) ? len + 1 : len;
	tmp = (token.width > tmp) ? token.width : tmp;
	if (!(res = (char *)malloc(sizeof(char) * (tmp + 1))))
		return (NULL);
	while (tmp >= 0)
	{
		if (len >= 0)
			res[tmp--] = str[len--];
		else
			res[tmp--] = '0';
	}
	return (res);
}

static char	*normal(char *str, int len, t_token token)
{
	char	*res;
	int		tmp;
	int		prefix;

	prefix = ft_strchr(token.flags, '#') ? 1 : 0;
	tmp = (prefix) ? len + 2 : len;
	if (token.precision > len)
		tmp += (token.precision - len);
	if (!(res = (char *)malloc(sizeof(char) * (tmp + 1))))
		return (NULL);
	while (tmp >= 0)
	{
		if (len >= 0)
			res[tmp--] = str[len--];
		else
			res[tmp--] = '0';
	}
	return (res);
}

char		*base_8(char *str, t_token token)
{
	char	*res;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (token.precision == 1
			&& ft_strchr(token.flags, '0')
			&& !ft_strchr(token.flags, '-'))
		res = zero_pad(str, len, token);
	else
		res = normal(str, len, token);
	free(str);
	return (res);
}
