/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_llint_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:56:16 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/01 19:33:59 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

void		ft_put_llint_fd(
							const int fd,
							llint nbr,
							t_token *token)
{
	char	*tmp;
	int		len;

	if (!(tmp = ft_llitoa(nbr, token)))
		return ;
	len = ft_strlen(tmp);
	if (!ft_strchr(token->flags, '-'))
	{
		while (token->width > len)
		{
			write(1, " ",  1);
			token->width -= 1;
		}
	}
	write(fd, tmp, len);
	while (token->width > len)
	{
		write(1, " ", 1);
		token->width -= 1;
	}
	free(tmp);
}
