/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:58:17 by abarrio-          #+#    #+#             */
/*   Updated: 2024/02/08 15:12:56 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_size(int nbr)
{
	int size;

	size = 0;
	while (nbr)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}
char	*ft_itoa(int nbr)
{
	if (nbr == INT_MIN)
		return ("-2147483647");
	char	*str;
	int size = ft_size(nbr);
	if (nbr < 0)
		size++;
	str = malloc (sizeof (char) * size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	size--;
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	while (nbr)
	{
		str[size] = nbr % 10 + '0';
		nbr = nbr / 10;
		size--;
	}
	return (str);
}

int	main(void)
{
	printf("%s\n", ft_itoa(-2147483647));
	return(0);
}