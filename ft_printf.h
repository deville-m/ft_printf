/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:02:05 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/29 18:22:43 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/*
** Typedefs to restore sanity
*/

typedef struct		s_token
{
	int				flags;
	size_t			width;
	size_t			precision;
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

void				ft_put_intmax_base_fd(
						const int fd,
						intmax_t nbr,
						const char *base,
						t_token *token);

void				ft_put_uintmax_base_fd(
						const int fd,
						uintmax_t nbr,
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
size_t				ft_nbrlen(intmax_t nbr);
char				*ft_imaxtoa(intmax_t n);

#endif
