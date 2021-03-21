/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 01:47:28 by hesayah           #+#    #+#             */
/*   Updated: 2020/02/06 22:46:37 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ft_run_i_d(t_flags vals, char *str, int nb)
{
	if (nb == 0 && vals.prec == 1 && vals.vprec == 0)
	{
		vals.k = -1;
		vals.width++;
	}
	if (vals.zero == 1 && vals.prec <= 0)
		vals.pad = 48;
	if (vals.prec == 0)
		vals.width += -ft_strlen(str);
	else if (vals.vprec < ft_strlen(str))
		vals.vprec = ft_strlen(str);
	return (vals);
}

static void		ft_type_d_i_min(t_flags vals, char *str)
{
	int			fix;

	fix = vals.vprec;
	if (vals.minus == 1)
		ft_putchar('-');
	while (vals.vprec-- > vals.len)
		ft_putchar('0');
	if (vals.k == 1)
		ft_putstr(str);
	while (vals.width-- > fix)
		ft_putchar(' ');
}

static void		ft_type_d_i_work(t_flags vals, char *str)
{
	if (vals.min == 1)
		ft_type_d_i_min(vals, str);
	else
	{
		if (vals.minus == 1 && vals.pad == 48)
			ft_putchar('-');
		while (vals.width-- > vals.vprec)
			ft_putchar(vals.pad);
		if (vals.minus == 1 && vals.pad == 32)
			ft_putchar('-');
		while (vals.vprec-- > vals.len)
			ft_putchar('0');
		if (vals.k == 1)
			ft_putstr(str);
	}
}

void			ft_type_d_i(va_list *args, t_flags vals)
{
	char		*str;
	long		nb;

	nb = va_arg(*args, int);
	if (nb < 0)
	{
		nb = -nb;
		vals.minus = 1;
		vals.width--;
	}
	vals.k = 1;
	str = ft_lltoa(((long long)nb));
	vals.len = ft_strlen(str);
	vals = ft_run_i_d(vals, str, nb);
	ft_type_d_i_work(vals, str);
	free(str);
}
