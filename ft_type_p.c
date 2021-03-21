/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 01:44:30 by hesayah           #+#    #+#             */
/*   Updated: 2020/02/04 19:25:13 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_type_p_min(t_flags vals, char *str)
{
	ft_putchar('0');
	ft_putchar('x');
	if (vals.k != -1)
		ft_putstr(str);
	while (vals.width-- > 2 && vals.len < vals.width)
		ft_putchar(' ');
}

void		ft_type_p(va_list *args, t_flags vals)
{
	void	*p;
	char	*str;

	if (vals.zero == 1)
		vals.pad = 48;
	p = va_arg(*args, void*);
	str = ft_itoa_base((long long)p);
	if (vals.prec == 1 && vals.vprec == 0 && p == NULL)
	{
		vals.k = -1;
		vals.width++;
	}
	vals.len = ft_strlen(str) + 1;
	if (vals.min == 1)
		ft_type_p_min(vals, str);
	else
	{
		while (vals.width-- > 2 && (vals.len < vals.width))
			ft_putchar(' ');
		ft_putchar('0');
		ft_putchar('x');
		if (vals.k != -1)
			ft_putstr(str);
	}
	free(str);
}
