/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 08:21:59 by abarrio-          #+#    #+#             */
/*   Updated: 2024/02/08 14:47:49 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <stdio.h>

int	ft_isdigit(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}
long	ft_atoi(char *str)
{
	int i;
	long nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	if (nb > INT_MAX)
		return (-1);
	return (nb);
}

int	ft_isprime(long nb)
{
	int x;
	int i;
	
	i = 1;
	x = 0;
	while (i <= nb)
	{
		if ((nb % i) == 0)
			x++;
		i++;
	}
	if (x == 2)
		return (1);
	else
		return (0);
}

void ft_putnbr(int i)
{
	char c;
	
	if (i > 9)
	{
		ft_putnbr(i / 10);
		c = (i % 10) + '0';
		write(1, &c, 1);	
	}
	else
	{	
		c = i + '0';
		write(1, &c, 1);	
	}
}
int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	long	nb = ft_atoi(argv[1]);
	if (nb == -1)
	{
		write(1, "\n", 1);
		return (0);
	}
	int i = 1;
	if (nb == 1)
	{
		write(1, "1\n", 2);
		return (0);
	}
	while (nb > 1)
	{
		i = 1;
		while (i <= nb)
		{
			if (ft_isprime(i) == 1 && nb % i == 0)
			{
				nb = nb / i;
				ft_putnbr(i);
				if (nb != 1) 
					write(1, "*", 1);
				i--;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}