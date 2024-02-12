/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 07:39:42 by abarrio-          #+#    #+#             */
/*   Updated: 2024/02/12 11:17:02 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_size(char *str)
{
	int size;
	int i;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i + 1] >= 'A' && str[i + 1] <= 'Z')
			size++;
		i++;
		size++;
	}
	return(size);
}

char *ft_str(char *str, int size)
{
	char *new;
	int i;
	int j;

	i = 0;
	j = 0;
	new = malloc (sizeof(char) * size + 1);
	if (!new)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] <= 'z' && str[i] >= 'a')
			new[j] = str[i];
		else if (str[i] <= 'Z' && str[i] >= 'A')
		{
			if (i != 0)
				new[j++] = '_';
			new[j] = str[i] + 32;
		}
		else
			new[j] = str[i];
		i++;
		j++;	 
	}
	new[j] = '\0';
	return(new);		
}
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return(0);
	int size;
	// char *str;
	
	size = ft_size(argv[1]);
	printf("%s\n", ft_str(argv[1], size));
	return (0);
}