/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:02:05 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/13 15:38:38 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>

/*
** Typedefs to restore sanity
*/

typedef long long int			t_llint;
typedef unsigned long long int	t_ullint;

typedef enum					e_length
{
	None,
	hh,
	h,
	l,
	ll,
	j,
	z
}								t_length;

typedef struct					s_token
{
	char			flags[6];
	int				width;
	int				precision;
	t_length		length;
	char			specifier;
}								t_token;

/*
** Main functions
*/

int								ft_fprintf(
									const int fd,
									const char *format,
									...);

int								ft_printf(
									const char *format,
									...);

int								ft_vprintf(
									const char *format,
									va_list ap);

int								ft_vfprintf(
									const int fd,
									const char *format,
									va_list ap);

/*
** Parsing functions
*/

t_token							parse_token(
									const char *str,
									size_t *i,
									va_list *ap);

/*
** Printing functions
*/

int								print_token(
									const int fd,
									t_token token,
									va_list *ap,
									int cpt);

int								ft_putpercent_fd(
									const int fd,
									t_token token);

int								ft_putchar_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_putstr_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_putint_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_putuint_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_putoctal_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_puthexa_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_putbin_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_putpointer_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_putunichar_fd(
									const int fd,
									t_token token,
									va_list *ap);

int								ft_putunistr_fd(
									const int fd,
									t_token token,
									va_list *ap);

void							ft_putn_fd(
									int n,
									va_list *ap);

/*
** Utilities
*/

size_t							ft_strlen(const char *str);
char							*ft_strchr(const char *s, int c);
char							*ft_strdup(const char *str);
int								ft_atoi(const char *str);
int								to_utf8(unsigned int unicode, char *utf8);
char							*ft_itoa(intmax_t n);
char							*ft_utoa_base(uintmax_t n, const char *base);
char							*ft_strcpy(char *dst, const char *src);

#endif
