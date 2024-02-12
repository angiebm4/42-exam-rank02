/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:12:00 by abarrio-          #+#    #+#             */
/*   Updated: 2024/02/12 11:07:09 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *str[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return(0);
	}
	int i;

	char c;
	i = 0;
	while (str[1][i] != '\0')
	{
		if (str[1][i] == 'z' || str[1][i] == 'Z')
			c = str[1][i] - 25;
		else if ((str[1][i] <= 'y' && str[1][i] >= 'a') || (str[1][i] <= 'Y' && str[1][i] >= 'A'))
			c = str[1][i] + 1;
		else
			c = str[1][i];
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
