/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 01:47:37 by hesayah           #+#    #+#             */
/*   Updated: 2020/02/06 22:28:43 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
}

static void	ft_type_xxx_work(t_flags vals, char *str)
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

void		ft_type_x(va_list *args, t_flags vals)
{
	unsigned int	hexa;
	char			*str;

	hexa = va_arg(*args, unsigned long);
	str = ft_itoa_base((long long)hexa);
	if (vals.prec == 1 && vals.vprec == 0 && hexa == 0)
	{
		vals.k = -1;
		vals.width++;
	}
	if (vals.zero == 1 && vals.prec == 0)
		vals.pad = 48;
	if (vals.prec == 0)
		vals.width += -ft_strlen(str);
	else if (vals.vprec < ft_strlen(str))
		vals.vprec = ft_strlen(str);
	ft_type_xxx_work(vals, str);
	free(str);
}

void		ft_type_xx(va_list *args, t_flags vals)
{
	unsigned int	hexa;
	char			*str;

	hexa = va_arg(*args, unsigned long);
	str = ft_itoa_base((long long)hexa);
	ft_upper(str);
	if (vals.prec == 1 && vals.vprec == 0 && hexa == 0)
	{
		vals.k = -1;
		vals.width++;
	}
	if (vals.zero == 1 && vals.prec == 0)
		vals.pad = 48;
	if (vals.prec == 0)
		vals.width += -ft_strlen(str);
	else if (vals.vprec < ft_strlen(str))
		vals.vprec = ft_strlen(str);
	ft_type_xxx_work(vals, str);
	free(str);
}
