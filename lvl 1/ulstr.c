/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:16:21 by abarrio-          #+#    #+#             */
/*   Updated: 2024/02/12 08:22:01 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_do(char *str)
{
	int i;
	char c;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			c = str[i] - 32;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			c = str[i] + 32;
		else
			c = str[i];
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}
int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return(0);
	}
	ft_do(argv[1]);
	return (0);	
}