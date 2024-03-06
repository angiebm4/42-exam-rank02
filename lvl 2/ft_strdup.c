/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:40:49 by abarrio-          #+#    #+#             */
/*   Updated: 2024/02/13 10:56:21 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ok grademe

#include <stdlib.h>

char    *ft_strdup(char *src)
{
	char *new;
	int size;

	size = 0;
	while (src[size] != '\0')
		size++;
	new = malloc (sizeof(char) * size +1);
	if (!new)
		return (NULL);
	int i;
	i = 0;
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
