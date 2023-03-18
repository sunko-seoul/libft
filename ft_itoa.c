/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:36:30 by sunko             #+#    #+#             */
/*   Updated: 2023/03/16 14:47:41 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	num_cnt(int n)
{
	int		cnt;

	cnt = 0;
	if (n < 0)
		cnt++;
	while (n)
	{
		n = n / 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_negative(int n)
{
	int			size;
	char		*string;
	long long	tmp;

	size = num_cnt(n);
	string = (char *)malloc(sizeof(char) * (size + 1));
	if (!string)
		return (NULL);
	string[0] = '-';
	string[size] = '\0';
	tmp = n;
	tmp *= -1;
	while (tmp)
	{
		if (size == 1)
			break ;
		string[--size] = tmp % 10 + '0';
		tmp = tmp / 10;
	}
	return (string);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*string;

	if (n < 0)
		return (ft_negative(n));
	size = num_cnt(n);
	if (n == 0)
		size = 1;
	string = (char *)malloc(sizeof(char) * (size + 1));
	if (!string)
		return (NULL);
	if (n == 0)
		string[0] = '0';
	string[size] = '\0';
	while (n)
	{
		if (size == 0)
			break ;
		string[--size] = n % 10 + '0';
		n = n / 10;
	}
	return (string);
}
