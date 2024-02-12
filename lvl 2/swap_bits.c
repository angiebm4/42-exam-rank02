/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:33:51 by abarrio-          #+#    #+#             */
/*   Updated: 2023/11/02 12:37:38 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

unsigned char swap_bits(unsigned char octet)
{
	return((octet >> 4) | (octet << 4));
}

int main(void)
{
	unsigned char byte;
	int i;
	unsigned char byte1;
	
	byte = 2;
	byte = swap_bits(byte);
	byte1 = 0;
	i = 7;
	while (i >= 0)
	{
		byte1 = (byte >> i & 1) + '0';
		write(1, &byte1, 1);
		i--;
	}
	return(0);
}