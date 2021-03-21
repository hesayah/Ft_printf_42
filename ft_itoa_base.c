/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:48:28 by hesayah           #+#    #+#             */
/*   Updated: 2020/02/04 19:38:23 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_rev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

char			*ft_itoa_base(long long nbr)
{
	long long	nb;
	static char	base[] = "0123456789abcdef";
	char		*hexa;
	int			i;

	if (!(hexa = malloc(sizeof(char) * 16)))
		return (NULL);
	i = 0;
	nb = nbr;
	if (nb < 0)
		nb = -nb;
	while (nb >= 16)
	{
		hexa[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	hexa[i] = base[nb % 16];
	hexa[i + 1] = '\0';
	ft_rev(hexa);
	return (hexa);
}
