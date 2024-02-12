/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:12:15 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/02 11:23:29 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i;
	unsigned char byte;

	byte = 0;
	i = 7;
	while (i >= 0)
	{
		byte = (octet >> i & 1) + '0';
		write(1, &byte, 1);
		i--;
	}
}

int main(void)
{
	print_bits('2');
	return(0);
}