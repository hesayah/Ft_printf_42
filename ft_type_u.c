/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 01:47:33 by hesayah           #+#    #+#             */
/*   Updated: 2020/02/04 19:28:09 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_type_u_work(t_flags vals, char *str)
{
	if (vals.min == 1)
	{
		vals.width += -vals.vprec;
		while (vals.vprec-- > ft_strlen(str))
			ft_putchar('0');
		if (vals.k != -1)
			ft_putstr(str);
		while (vals.width-- > 0)
			ft_putchar(vals.pad);
	}
	else
	{
		while (vals.width-- > vals.vprec)
			ft_putchar(vals.pad);
		while (vals.vprec-- > ft_strlen(str))
			ft_putchar('0');
		if (vals.k != -1)
			ft_putstr(str);
	}
}

void		ft_type_u(va_list *args, t_flags vals)
{
	char			*str;
	unsigned int	nb;

	nb = va_arg(*args, unsigned int);
	str = ft_lltoa((long long)(nb));
	if (nb == 0 && vals.prec == 1 && vals.vprec <= 0)
	{
		vals.k = -1;
		vals.width++;
	}
	if (vals.zero == 1 && vals.prec == 0 && vals.min == 0)
		vals.pad = 48;
	if (vals.prec == 0)
		vals.width += -ft_strlen(str);
	else if (vals.vprec < ft_strlen(str))
		vals.vprec = ft_strlen(str);
	ft_type_u_work(vals, str);
	free(str);
}
