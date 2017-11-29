/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_intmax_base_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:56:16 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/29 19:36:19 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

void		ft_put_intmax_base_fd(
							const int fd,
							intmax_t nbr,
							const char *base,
							t_token *token)
{
	int		blen;
	int		nbrlen;
	char	*tmp;

	blen = ft_strlen(base);
	nbrlen = ft_nbrlen(nbr);
	tmp = ft_itoamax(nbr);
	
}
