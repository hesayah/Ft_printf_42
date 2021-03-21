/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_fonc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:13:38 by hesayah           #+#    #+#             */
/*   Updated: 2020/02/04 18:54:17 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_tab_fonc(char c, va_list *args, t_flags vals)
{
	if (c == 'c')
		ft_type_c(args, vals);
	if (c == 's')
		ft_type_s(args, vals);
	if (c == 'i' || c == 'd')
		ft_type_d_i(args, vals);
	if (c == 'p')
		ft_type_p(args, vals);
	if (c == 'u')
		ft_type_u(args, vals);
	if (c == 'x')
		ft_type_x(args, vals);
	if (c == 'X')
		ft_type_xx(args, vals);
	if (c == '%')
		ft_type_pct(vals);
}
