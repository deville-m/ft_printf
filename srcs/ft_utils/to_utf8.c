/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_utf8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:02:27 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/11 17:52:43 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	case_4(unsigned int unicode, char *utf8)
{
	utf8[0] = (unicode >> 16) | 0xF0;
	utf8[1] = ((unicode >> 12) & 0x3F) | 0x80;
	utf8[2] = ((unicode >> 6) & 0x3F) | 0x80;
	utf8[3] = (unicode & 0x3F) | 0x80;
	return (4);
}

static int	error(char *utf8)
{
	utf8[0] = 0xEF;
	utf8[1] = 0xBF;
	utf8[2] = 0xBD;
	return (3);
}

int			to_utf8(unsigned int unicode, char *utf8)
{
	if (unicode < 0x80 && MB_CUR_MAX >= 1)
	{
		utf8[0] = unicode;
		return (1);
	}
	if (unicode < 0x800 && MB_CUR_MAX >= 2)
	{
		utf8[0] = (unicode >> 6) | 0xC0;
		utf8[1] = (unicode & 0x3F) | 0x80;
		return (2);
	}
	if (unicode < 0x10000 && MB_CUR_MAX >= 3)
	{
		utf8[0] = (unicode >> 12) | 0xE0;
		utf8[1] = ((unicode >> 6) & 0x3F) | 0x80;
		utf8[2] = (unicode & 0x3F) | 0x80;
		return (3);
	}
	if (unicode <= 0x10FFFF && MB_CUR_MAX >= 4)
		return (case_4(unicode, utf8));
	return (error(utf8));
}
