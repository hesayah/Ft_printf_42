/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_struc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:50:22 by hesayah           #+#    #+#             */
/*   Updated: 2020/02/04 22:50:15 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags			ft_active(void)
{
	t_flags vals;

	vals.min = 0;
	vals.minus = 0;
	vals.zero = 0;
	vals.width = 0;
	vals.prec = 0;
	vals.vprec = 0;
	vals.pad = 32;
	vals.len = 0;
	vals.k = 0;
	return (vals);
}

static t_flags	ft_get_width(const char *str, int index,
va_list args, t_flags vals)
{
	vals.k = 0;
	if ((str[index] >= '0' && str[index] <= '9'))
	{
		vals.width = ft_atoi(&str[index]);
		while ((str[index + vals.k] >= '0' && str[index + vals.k] <= '9'))
			vals.k++;
	}
	else if (str[index] == '*')
	{
		vals.width = va_arg(args, int);
		vals.k++;
	}
	if (vals.width < 0)
	{
		vals.min = 1;
		vals.zero = 0;
		vals.width = -vals.width;
	}
	return (vals);
}

static t_flags	ft_get_prec(const char *str, int index,
va_list args, t_flags vals)
{
	vals.k = 0;
	vals.prec = 1;
	if ((str[index] >= '0' && str[index] <= '9'))
	{
		vals.vprec = ft_atoi(&str[index]);
		while ((str[index + vals.k] >= '0' && str[index + vals.k] <= '9'))
			vals.k++;
	}
	else if (str[index] == '*')
	{
		vals.vprec = va_arg(args, int);
		if (vals.vprec < 0)
		{
			vals.prec = 0;
			vals.vprec = 0;
		}
		vals.k++;
	}
	return (vals);
}

static t_flags	ft_get_flags(const char *str, int index, t_flags vals)
{
	if (str[index] == '0')
		vals.zero = 1;
	if (str[index] == '-')
	{
		vals.zero = 0;
		vals.min = 1;
	}
	return (vals);
}

void			ft_work_string(const char *str, int index,
int len, va_list *args)
{
	int		k;
	t_flags	vals;

	k = -1;
	vals = ft_active();
	while (k++ < len)
	{
		while (k < len && (str[index + k] == '-' || str[index + k] == '0'))
		{
			vals = ft_get_flags(str, index + k, vals);
			k++;
		}
		if (k < len && ((str[index + k] >= '0' && str[index + k] <= '9')
		|| str[index + k] == '*'))
		{
			vals = ft_get_width(str, index + k, *args, vals);
			k += vals.k;
		}
		if (k < len && str[index + k] == '.')
		{
			vals = ft_get_prec(str, index + k + 1, *args, vals);
			k += vals.k;
		}
	}
	ft_tab_fonc(str[index + len - 1], args, vals);
}
