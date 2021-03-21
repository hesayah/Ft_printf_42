/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:54:44 by hesayah           #+#    #+#             */
/*   Updated: 2020/02/04 18:20:15 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_len(long long n)
{
	long long	nb;
	long long	len;

	nb = n;
	len = 1;
	if (nb < 0)
	{
		nb = -nb;
		len = 2;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*ft_strrev(char *str)
{
	long long	i;
	long long	j;
	long long	len;
	char		*temp;

	len = ft_strlen(str);
	j = len;
	if (!(temp = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	if (str[0] == '-')
	{
		temp[0] = '-';
		i = 1;
	}
	while (i < len)
	{
		temp[i] = str[j - 1];
		i++;
		j--;
	}
	temp[i] = '\0';
	free(str);
	return (temp);
}

char		*ft_lltoa(long long n)
{
	long long	len;
	long long	i;
	long long	nb;
	char		*num;

	i = 0;
	nb = n;
	len = ft_len(nb);
	if (!(num = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (nb < 0)
	{
		num[0] = '-';
		nb = -nb;
		i = 1;
	}
	while (i < len)
	{
		num[i] = (nb % 10) + 48;
		nb = nb / 10;
		i++;
	}
	num[len] = '\0';
	num = ft_strrev(num);
	return (num);
}
