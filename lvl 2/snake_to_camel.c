/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:17:32 by abarrio-          #+#    #+#             */
/*   Updated: 2024/02/12 12:07:01 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_size(char *str)
{
	int size;
	int i;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '_')
			size--;
		i++;
		size++;
	}
	return(size);
}

char	*ft_str(char *str, int size)
{
	char *new;
	int i = 0;
	int j = 0;
	
	new = malloc (sizeof(char) * size + 1);
	if (!new)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == '_' && str[i + 1] != '\0' )
		{
			i++;
			if (str[i] <= 'z' && str[i] >= 'a' && i != 1)
				new[j] = str[i] - 32;
			else
				new[j] = str[i];
		}
		else if (str[i] != '_')
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
	{
		write(1, "\n", 1);
		return(0);
	}
	int size;
	char *str;
	char c;
	int i = 0;
	
	size = ft_size(argv[1]);
	str = ft_str(argv[1], size);
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		c = str[i];
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	free(str);
	return (0);
}