/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 07:27:59 by abarrio-          #+#    #+#             */
/*   Updated: 2024/02/12 07:38:24 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int nb;
	char c;
	
	nb = 1;
	while (nb <= 100)
	{
		if (nb % 3 == 0 && nb % 5 == 0)
			write(1, "fizzbuzz\n", 10);
		else if (nb % 3 == 0)
			write(1, "fizz\n", 5);
		else if (nb % 5 == 0)
			write(1, "buzz\n", 5);
		else
		{
			if (nb > 9)
			{
				c =  nb / 10  + '0';
				write(1, &c, 1);
			}
			c =  nb % 10  + '0';
			write(1, &c, 1);
			write(1, "\n", 1);
		}
		nb++;
	}
	return(0);
}