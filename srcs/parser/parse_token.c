/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:36:20 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/04 19:41:43 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_length(const char *s, t_token *token)
{
	if (ft_strcmp(s, "ll") == 0)
	{
		token->length = ll;
		return (2);
	}
	else if (ft_strcmp(s, "l") == 0)
		token->length = l;
	else if (ft_strcmp(s, "hh") == 0)
	{
		token->length = hh;
		return (2);
	}
	else if (ft_strcmp(s, "h") == 0)
		token->length = h;
	else if (ft_strcmp(s, "j") == 0)
		token->length = j;
	else if (ft_strcmp(s, "z") == 0)
		token->length = z;
	else
	{
		token->length = None;
		return (0);
	}
	return (1);
}

static int	parse_precision(const char *s, t_token *token, va_list ap)
{
	size_t i;

	if (s[0] != '.' || !*s)
	{
		token->precision = 1;
		return (0);
	}
	i = 1;
	if (*s == '*')
	{
		token->precision = va_arg(ap, int);
		return (1);
	}
	token->precision = ft_atoi(s + 1);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	return (i);
}

static int	parse_width(const char *s, t_token *token, va_list ap)
{
	size_t i;

	if (!*s)
		return (0);
	i = 0;
	if (*s == '*')
	{
		token->width = va_arg(ap, int);
		return (1);
	}
	token->width = ft_atoi(s);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	return (i);
}

static int	parse_flags(const char *s, t_token *token)
{
	int		cpt;
	size_t	i;

	i = 0;
	cpt = 0;
	while (ft_strchr("# -0+", s[i]) && cpt < 4)
	{
		if (!ft_strchr(token->flags, s[i]))
			token->flags[cpt++] = s[i];
		i++;
	}
	token->flags[cpt] = '\0';
	return (i);
}

t_token		parse_token(const char *str, size_t *i, va_list ap)
{
	t_token	token;

	*i += parse_flags(str + *i, &token);
	*i += parse_width(str + *i, &token, ap);
	*i += parse_precision(str + *i, &token, ap);
	*i += parse_length(str + *i, &token);
	if (ft_strchr("sSpdDioOuUxXcCn", s[*i]))
	{
		token.specifier = s[*i];
		*i += 1;
	}
	else
		token.specifier = '\0';
	return (token);
}
