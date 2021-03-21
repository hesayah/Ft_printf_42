/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:40:28 by hesayah           #+#    #+#             */
/*   Updated: 2020/02/04 22:28:02 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_w_typs(char c, char *typs)
{
	int			i;

	i = 0;
	while (typs[i])
	{
		if (c == typs[i])
			return (i);
		i++;
	}
	return (-1);
}

static	int		ft_w_flags(char c, char *flags)
{
	int		i;

	i = 0;
	while (flags[i])
	{
		if (c == flags[i])
			return (i);
		i++;
	}
	return (-1);
}

static	void	ft_check_string(const char *str, va_list *args)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			ft_putchar(str[i]);
			i++;
		}
		if (str[i] == '%')
		{
			i++;
			j = i;
			while (ft_w_flags(str[i], "-*.0123456789") != -1)
				i++;
			if (ft_w_typs(str[i], "csdiupxX%") != -1)
				ft_work_string(str, j, i - j + 1, args);
			else
				i = j;
			i++;
		}
	}
}

int				ft_printf(const char *str, ...)
{
	va_list		args;

	g_result = 0;
	if (str == NULL)
		return (-1);
	va_start(args, str);
	ft_check_string(str, &args);
	va_end(args);
	return (g_result);
}
