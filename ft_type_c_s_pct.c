/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c_s_pct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 01:44:33 by hesayah           #+#    #+#             */
/*   Updated: 2020/02/04 22:14:47 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_type_c(va_list *args, t_flags vals)
{
	char	c;

	c = (char)va_arg(*args, int);
	if (vals.min == 1)
	{
		ft_putchar(c);
		while (vals.width-- > 1)
			ft_putchar(' ');
	}
	else
	{
		while (vals.width-- > 1)
			ft_putchar(' ');
		ft_putchar(c);
	}
}

void		ft_type_pct(t_flags vals)
{
	if (vals.min == 1)
	{
		ft_putchar('%');
		while (vals.width-- > 1)
			ft_putchar(' ');
	}
	else
	{
		while (vals.width-- > 1)
			if (vals.zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
		ft_putchar('%');
	}
}

static void	ft_type_s_min(t_flags vals, char *str, int i)
{
	if ((vals.vprec > 0 && vals.vprec < vals.len)
	|| (vals.prec == 1 && vals.vprec <= 0))
		vals.width += -vals.vprec;
	else
		vals.width += -vals.len;
	if (vals.vprec > 0 && vals.vprec < vals.len)
		while (i++ < vals.vprec - 1)
			ft_putchar(str[i]);
	else if ((vals.vprec >= ft_strlen(str)) || vals.prec == 0)
		ft_putstr(str);
	while (vals.width-- > 0)
		ft_putchar(' ');
}

static void	ft_type_s_nomin(t_flags vals, char *str, int i)
{
	if ((vals.vprec > 0 && vals.vprec < vals.len)
	|| (vals.prec == 1 && vals.vprec <= 0))
		vals.width += -vals.vprec;
	else
		vals.width += -vals.len;
	while (vals.width-- > 0)
		ft_putchar(' ');
	if (vals.vprec > 0 && vals.vprec < vals.len)
		while (i++ < vals.vprec - 1)
			ft_putchar(str[i]);
	else if (vals.vprec >= ft_strlen(str) || vals.prec == 0)
		ft_putstr(str);
}

void		ft_type_s(va_list *args, t_flags vals)
{
	char	*str;
	int		i;

	i = -1;
	str = va_arg(*args, char *);
	if (str == NULL)
		str = "(null)";
	vals.len = ft_strlen(str);
	if (vals.prec == 1 && vals.vprec == 0)
		vals.len = 0;
	if (vals.vprec < 0)
		vals.prec = 0;
	if (vals.min == 1)
		ft_type_s_min(vals, str, i);
	else
		ft_type_s_nomin(vals, str, i);
}
