/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 09:01:25 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/06 11:52:54 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*zero_pad(char *str, int len, t_token token)
{
	char	*res;
	int		tmp;

	tmp = (token.width > len) ? token.width : len;
	if (!(res = (char *)malloc(sizeof(char) * (tmp + 1))))
		return (NULL);
	while (tmp >= 0)
	{
		if (len < 0)
			res[tmp--] = '0';
		else
			res[tmp--] = str[len--];
	}
	return (res);
}

static char	*normal(char *str, int len, t_token token)
{
	char	*res;
	int		tmp;

	tmp = (token.precision > len) ? token.precision : len;
	if (!(res = (char *)malloc(sizeof(char) * (tmp + 1))))
		return (NULL);
	while (tmp >= 0)
	{
		if (len < 0)
			res[tmp--] = '0';
		else
			res[tmp--] = str[len--];
	}
	return (res);
}

char		*base_10(char *str, t_token token)
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
