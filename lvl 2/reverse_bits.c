/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:24:13 by abarrio-          #+#    #+#             */
/*   Updated: 2024/02/01 11:40:51 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char byte;
	int i;

	i = 8;
	while (i > 0)
	{
		byte = byte * 2 + (octet % 2);
		octet = (octet / 2);
		i--;
	}
	return (byte);
}

int main(void)
{
	unsigned char byte;

	byte = 2;
	byte = reverse_bits(byte);
	int i;
	unsigned char byte1;

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