/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_llint_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:56:16 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/04 23:25:49 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

static llint	cast(va_list ap, t_token token)
{
	llint nbr;

	nbr = va_arg(ap, llint);
	if (token.length == hh)
		nbr = (char)nbr;
	if (token.length == h)
		nbr = (short int)nbr;
	if (token.length == l)
		nbr = (long int)nbr;
	if (token.length == ll)
		nbr = (long long int)nbr;
	if (token.length == j)
		nbr = (intmax_t)nbr;
	if (token.length == z)
		nbr = (size_t)nbr;
	if (token.length == None)
		nbr = (int)nbr;
	return (nbr);
}

static size_t	print_spaces(int *width, int len)
{
	size_t cpt;

	cpt = 0;
	while (*width > len)
	{
		write(1, " ", 1);
		*width -= 1;
		cpt++;
	}
	return (cpt);
}

size_t			ft_put_llint_fd(
							const int fd,
							t_token token,
							va_list ap)
{
	char	*tmp;
	int		len;
	int		cpt;
	llint	nbr;

	nbr = cast(ap, token);
	cpt = 0;
	if (!(tmp = ft_llitoa(nbr, token)))
		return (0);
	len = ft_strlen(tmp);
	cpt = len;
	if (!ft_strchr(token.flags, '-'))
		cpt += print_spaces(&token.width, len);
	write(fd, tmp, len);
	cpt += print_spaces(&token.width, len);
	free(tmp);
	return (cpt);
}
