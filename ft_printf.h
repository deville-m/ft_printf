/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:02:05 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/01 19:28:18 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

/*
** Typedefs to restore sanity
*/

typedef long long int llint;
typedef unsigned long long int ullint;

typedef struct		s_token
{
	char			flags[5];
	int				width;
	int				precision;
	char			length[3];
	char			specifier;
	struct s_token	*next;
}					t_token;

/*
** Main functions
*/

int					ft_fprintf(
						const int fd,
						const char *format,
						...);

int					ft_vfprintf(
						const int fd,
						const char *format,
						va_list ap);

int					ft_printf(
						const char *format,
						...);

/*
** Printing functions
*/

void				ft_putchar_fd(
						const int fd,
						int c,
						t_token *token);

void				ft_putstr_fd(
						const int fd,
						const char *str,
						t_token *token);

void				ft_put_llint_fd(
						const int fd,
						llint nbr,
						t_token *token);

void				ft_put_ullint_base_fd(
						const int fd,
						ullint nbr,
						const char *base,
						t_token *token);

void				ft_put_pointer_fd(
						const int fd,
						void *p,
						t_token *token);

/*
** Utilities
*/

size_t				ft_strlen(const char *str);
char				*ft_llitoa(llint nbr, t_token *token);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *str);

#endif
