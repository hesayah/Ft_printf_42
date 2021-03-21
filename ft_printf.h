/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 03:08:23 by hesayah           #+#    #+#             */
/*   Updated: 2020/02/04 18:52:07 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

extern	int	g_result;

typedef struct	s_flags
{
	int	min;
	int	zero;
	int	width;
	int	prec;
	int	len;
	int	minus;
	int	vprec;
	int	pad;
	int	k;
}				t_flags;

int				ft_printf(const char *str, ...);
t_flags			ft_active(void);
void			ft_work_string(const char *str, int index,
int len, va_list *args);
void			ft_tab_fonc(char c, va_list *args, t_flags flags);
void			ft_type_c(va_list *args, t_flags flags);
void			ft_type_s(va_list *args, t_flags flags);
void			ft_type_d_i(va_list *args, t_flags flags);
void			ft_type_u(va_list *args, t_flags flags);
void			ft_type_p(va_list *args, t_flags flags);
void			ft_type_x(va_list *args, t_flags flags);
void			ft_type_xx(va_list *args, t_flags flags);
void			ft_type_pct(t_flags flags);
void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
int				ft_atoi(const char *str);
char			*ft_lltoa(long long n);
char			*ft_itoa_base(long long nbr);

#endif
